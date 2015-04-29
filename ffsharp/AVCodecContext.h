#pragma once

#include "wrapper/ffmpeg.h"

#include "AVCodec.h"
#include "AVFrame.h"
#include "AVPixelFormat.h"
#include "AVClass.h"
#include "AVCodecID.h"
#include "OptionsEnabled.h"

using namespace System;

namespace ffsharp
{

	public enum class AVMediaType
	{
		Unknown = ffmpeg::AVMEDIA_TYPE_UNKNOWN,
		Video = ffmpeg::AVMEDIA_TYPE_VIDEO,
		Audio = ffmpeg::AVMEDIA_TYPE_AUDIO,
		Data = ffmpeg::AVMEDIA_TYPE_DATA,
		Subtitle = ffmpeg::AVMEDIA_TYPE_SUBTITLE,
		Attachment = ffmpeg::AVMEDIA_TYPE_ATTACHMENT
	};

	public ref class AVCodecContext : public OptionsEnabled
	{
	private:
		ffmpeg::AVCodecContext* p;

	public:

		AVCodecContext(AVCodec^ codec)
			: OptionsEnabled(nullptr)
		{
			p = ffmpeg::avcodec_alloc_context3(codec->Pointer);
			SetClassPointer(p->av_class);
		}

		AVCodecContext(ffmpeg::AVCodecContext* p)
			: OptionsEnabled(p->av_class)
		{
			this->p = p;
		}

		void Open2(AVCodec^ codec)
		{
			int r = ffmpeg::avcodec_open2(p, codec->Pointer, nullptr);
			if (r < 0)
				throw gcnew AVErrorException(r);
		}

		bool DecodeVideo2(AVPacket^ packet, AVFrame^ frame)
		{
			int ignored = 0;
			return DecodeVideo2(packet, frame, ignored);
		}

		bool DecodeVideo2(AVPacket^ packet, AVFrame^ frame, [Out] int% dataUsed)
		{
			int gotPicture = 0;
			int r = ffmpeg::avcodec_decode_video2(p, frame->Pointer, &gotPicture, packet->Pointer);
			if (r < 0)
				throw gcnew AVErrorException(r);
			dataUsed = r;
			return gotPicture != 0;
		}

		AVPacket^ EncodeVideo2(AVFrame^ frame)
		{
			AVPacket^ res = gcnew AVPacket();
			int gotPacket = 0;
			int r = ffmpeg::avcodec_encode_video2(p, res->Pointer, frame->Pointer, &gotPacket);
			if (r < 0)
				throw gcnew AVErrorException(r);
			if (!gotPacket)
				return nullptr;
			return res;
		}

		AVFrame^ DecodeVideo2(AVPacket^ packet)
		{
			AVFrame^ res = gcnew AVFrame();
			int gotPicture = DecodeVideo2(packet, res);
			if (gotPicture)
				return res;
			return nullptr;
		}

		void Close()
		{
			ffmpeg::avcodec_close(p);
		}

		property AVCodec^ Codec
		{
			AVCodec^ get()
			{
				if (p->codec == nullptr)
					return nullptr;
				return gcnew AVCodec(p->codec);
			}
		}

		property AVPixelFormat PixelFormat
		{
			AVPixelFormat get()
			{
				return (AVPixelFormat)p->pix_fmt;
			}
			void set(AVPixelFormat format)
			{
				p->pix_fmt = (ffmpeg::AVPixelFormat) format;
			}
		}

		property AVSampleFormat SampleFormat
		{
			AVSampleFormat get()
			{
				return (AVSampleFormat)p->sample_fmt;
			}
			void set(AVSampleFormat format)
			{
				p->sample_fmt = (ffmpeg::AVSampleFormat) format;
			}
		}
		
		property AVMediaType CodecType
		{
			AVMediaType get()
			{
				return (AVMediaType) p->codec_type;
			}
		}

		property AVCodecID CodecId
		{
			AVCodecID get()
			{
				return (AVCodecID) p->codec_id;
			}
		}

		property unsigned int CodecTag
		{
			unsigned int get()
			{
				return p->codec_tag;
			}
		}

		property String^ FourCC
		{
			String^ get()
			{
				unsigned int tag = CodecTag;
				char data[4];
				data[0] = tag & 0xFF;
				data[1] = (tag >> 8) & 0xFF;
				data[2] = (tag >> 16) & 0xFF;
				data[3] = (tag >> 24) & 0xFF;
				return gcnew String(data, 0, 4);
			}
		}

		property int BitRate
		{
			int get()
			{
				return p->bit_rate;
			}
		}

		property int Height
		{
			int get()
			{
				return p->height;
			}
			void set(int height)
			{
				p->height = height;
			}
		}

		property int Width
		{
			int get()
			{
				return p->width;
			}
			void set(int width)
			{
				p->width = width;
			}
		}

		property int Channels
		{
			int get()
			{
				return p->channels;
			}
		}

		property int SampleRate
		{
			int get()
			{
				return p->sample_rate;
			}
		}
	};

}