#pragma once

#include <stdint.h>
#include "wrapper/ffmpeg.h"
#include "AVRational.h"
#include "AVPixelFormat.h"
#include "AVCodecID.h"
#include "AVFrame.h"
#include "OptionsEnabled.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

namespace ffsharp
{

	[Flags]
	public enum class CodecCapability : uint32_t
	{
		DrawHorizBand = CODEC_CAP_DRAW_HORIZ_BAND,
		DR1 = CODEC_CAP_DR1,
		Truncated = CODEC_CAP_TRUNCATED,
		HWAccel = CODEC_CAP_HWACCEL,
		Delay = CODEC_CAP_DELAY,
		SmallLastFrame = CODEC_CAP_SMALL_LAST_FRAME,
		HWAccelVDPAU = CODEC_CAP_HWACCEL_VDPAU,
		Subframes = CODEC_CAP_SUBFRAMES,
		Experimental = CODEC_CAP_EXPERIMENTAL,
		ChannelConf = CODEC_CAP_CHANNEL_CONF,
		FrameThreads = CODEC_CAP_FRAME_THREADS,
		SliceThreads = CODEC_CAP_SLICE_THREADS,
		ParamChange = CODEC_CAP_PARAM_CHANGE,
		AutoThreads = CODEC_CAP_AUTO_THREADS,
		VariableFrameSize = CODEC_CAP_VARIABLE_FRAME_SIZE,
		IntraOnly = CODEC_CAP_INTRA_ONLY,
		Lossless = CODEC_CAP_LOSSLESS
	};


	public ref class AVCodec : public OptionsEnabled
	{
	private:
		const ffmpeg::AVCodec* p;

		template<typename T, typename S>
		static List<S>^ readList(T terminator, const T* list)
		{
			if (list == nullptr)
				return nullptr;

			List<S>^ ret = gcnew List<S>();
			for (int i = 0;; i++)
			{
				if (list[i] == terminator)
					break;
				ret->Add((S) list[i]);
			}
			return ret;
		}

	internal:

		property const ffmpeg::AVCodec* Pointer
		{
			const ffmpeg::AVCodec* get()
			{
				return p;
			}
		}

	public:

		AVCodec(const ffmpeg::AVCodec* p)
			: OptionsEnabled(p->priv_class)
		{
			this->p = p;
		}

		property List<AVPixelFormat>^ SupportedPixelFormats
		{
			List<AVPixelFormat>^ get()
			{
				return readList<ffmpeg::AVPixelFormat, AVPixelFormat>((ffmpeg::AVPixelFormat) - 1, p->pix_fmts);
			}
		}

		property List<AVRational^>^ SupportedFramerates
		{
			List<AVRational^>^ get()
			{
				if (p->supported_framerates == nullptr)
					return nullptr;

				auto ret = gcnew List<AVRational^>();
				for (int i = 0;; i++)
				{
					ffmpeg::AVRational rational = p->supported_framerates[i];
					if (rational.den == 0 && rational.num == 0)
						break;
					ret->Add(gcnew AVRational(const_cast<ffmpeg::AVRational*>(&p->supported_framerates[i])));
				}
				return ret;
			}
		}

		property List<int>^ SupportedSampleRates
		{
			List<int>^ get()
			{
				return readList<int, int>(0, p->supported_samplerates);
			}
		}

		property List<AVSampleFormat>^ SupportedSampleFormats
		{
			List<AVSampleFormat>^ get()
			{
				return readList<ffmpeg::AVSampleFormat, AVSampleFormat>((ffmpeg::AVSampleFormat) - 1, p->sample_fmts);
			}
		}

		property List<uint64_t>^ SupportedChannelLayouts
		{
			List<uint64_t>^ get()
			{
				return readList<uint64_t, uint64_t>((uint64_t) 0, p->channel_layouts);
			}
		}

		property uint8_t MaximumLowRes
		{
			uint8_t get()
			{
				return ffmpeg::av_codec_get_max_lowres(p);
			}
		}

		property AVCodecID ID
		{
			AVCodecID get()
			{
				return (AVCodecID)p->id;
			}
		}

		property CodecCapability Capabilities
		{
			CodecCapability get()
			{
				return (CodecCapability)p->capabilities;
			}
		}

		property String^ Name
		{
			String^ get()
			{
				return gcnew String(p->name);
			}
		}

		property String^ LongName
		{
			String^ get()
			{
				return gcnew String(p->long_name);
			}
		}

		static AVCodec^ FindDecoderByName(String^ name)
		{
			auto namePtr = Marshal::StringToHGlobalAnsi(name);
			try
			{
				auto p = ffmpeg::avcodec_find_decoder_by_name((const char*)namePtr.ToPointer());
				if (p == nullptr)
					return nullptr;
				return gcnew AVCodec(p);
			}
			finally
			{
				if (namePtr.ToPointer() != nullptr)
					Marshal::FreeHGlobal(namePtr);
			}
		}

		static AVCodec^ FindEncoderByName(String^ name)
		{
			auto namePtr = Marshal::StringToHGlobalAnsi(name);
			try
			{
				auto p = ffmpeg::avcodec_find_encoder_by_name((const char*)namePtr.ToPointer());
				if (p == nullptr)
					return nullptr;
				return gcnew AVCodec(p);
			}
			finally
			{
				if (namePtr.ToPointer() != nullptr)
					Marshal::FreeHGlobal(namePtr);
			}
		}

		static AVCodec^ FindDecoder(AVCodecID id)
		{
			auto p = ffmpeg::avcodec_find_decoder((ffmpeg::AVCodecID) id);
			if (p == nullptr)
				return nullptr;
			return gcnew AVCodec(p);
		}

		static AVCodec^ FindEncoder(AVCodecID id)
		{
			auto p = ffmpeg::avcodec_find_encoder((ffmpeg::AVCodecID) id);
			if (p == nullptr)
				return nullptr;
			return gcnew AVCodec(p);
		}
	};

}