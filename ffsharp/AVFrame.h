#pragma once

#include <stdint.h>

#include "AVPixelFormat.h"
#include "wrapper/ffmpeg.h"

#include "AVDictionary.h"
#include "AVPicture.h"

using namespace System;

namespace ffsharp
{

	public enum class AVPictureType
	{
		Undefined = ffmpeg::AV_PICTURE_TYPE_NONE,
		Intra = ffmpeg::AV_PICTURE_TYPE_I,
		Predicted = ffmpeg::AV_PICTURE_TYPE_P,
		BiDirPredicted = ffmpeg::AV_PICTURE_TYPE_B,
		S = ffmpeg::AV_PICTURE_TYPE_S,
		SwitchingIntra = ffmpeg::AV_PICTURE_TYPE_SI,
		SwitchingPredicted = ffmpeg::AV_PICTURE_TYPE_SP,
		BI = ffmpeg::AV_PICTURE_TYPE_BI,
	};

	public enum class AVSampleFormat
	{
		Undefined = ffmpeg::AV_SAMPLE_FMT_NONE,
		U8 = ffmpeg::AV_SAMPLE_FMT_U8,
		S16 = ffmpeg::AV_SAMPLE_FMT_S16,
		S32 = ffmpeg::AV_SAMPLE_FMT_S32,
		FLT = ffmpeg::AV_SAMPLE_FMT_FLT,
		DBL = ffmpeg::AV_SAMPLE_FMT_DBL,
		U8P = ffmpeg::AV_SAMPLE_FMT_U8P,
		S16P = ffmpeg::AV_SAMPLE_FMT_S16P,
		S32P = ffmpeg::AV_SAMPLE_FMT_S32P,
		FLTP = ffmpeg::AV_SAMPLE_FMT_FLTP,
		DBLP = ffmpeg::AV_SAMPLE_FMT_DBLP,
	};

	public ref class AVFrame : public AVPicture
	{
	private:
		ffmpeg::AVFrame* p;

	internal:

		property ffmpeg::AVFrame* Pointer
		{
			ffmpeg::AVFrame* get()
			{
				return p;
			}
		}

	public:

		AVFrame()
			: p(ffmpeg::av_frame_alloc()), AVPicture(p)
		{
		}

		AVFrame(ffmpeg::AVFrame* p)
			: AVPicture(p)
		{
			this->p = p;
		}

		property bool IsWritable
		{
			bool get()
			{
				return ffmpeg::av_frame_is_writable(p) != 0;
			}
		}

		int GetLineSize(int index)
		{
			return p->linesize[index];
		}

		IntPtr GetData(int index)
		{
			return IntPtr(p->data[index]);
		}

		property AVPictureType PictureType
		{
			AVPictureType get()
			{
				return (AVPictureType) p->pict_type;
			}
		}

		property AVPixelFormat PixelFormat
		{
			AVPixelFormat get()
			{
				return (AVPixelFormat) p->format;
			}
		}

		property AVSampleFormat SampleFormat
		{
			AVSampleFormat get()
			{
				return (AVSampleFormat) p->format;
			}
		}

		property int Width
		{
			int get()
			{
				return p->width;
			}
		}

		property int Height
		{
			int get()
			{
				return p->height;
			}
		}

		property AVDictionary^ Metadata
		{
			AVDictionary^ get()
			{
				return gcnew AVDictionary(ffmpeg::av_frame_get_metadata(p));
			}
		}

		property long long BestEffortTimestamp
		{
			long long get()
			{
				return ffmpeg::av_frame_get_best_effort_timestamp(p);
			}
			void set(long long bestEffortTimestamp)
			{
				ffmpeg::av_frame_set_best_effort_timestamp(p, bestEffortTimestamp);
			}
		}

		property int PktSize
		{
			int get()
			{
				return ffmpeg::av_frame_get_pkt_size(p);
			}
			void set(int pktSize)
			{
				ffmpeg::av_frame_set_pkt_size(p, pktSize);
			}
		}

		property long long PktPos
		{
			long long get()
			{
				return ffmpeg::av_frame_get_pkt_pos(p);
			}
			void set(long long pktPos)
			{
				ffmpeg::av_frame_set_pkt_pos(p, pktPos);
			}
		}

		property long long PktDuration
		{
			long long get()
			{
				return ffmpeg::av_frame_get_pkt_duration(p);
			}
			void set(long long pktDur)
			{
				ffmpeg::av_frame_set_pkt_duration(p, pktDur);
			}
		}

		property long long ChannelLayout
		{
			long long get()
			{
				return ffmpeg::av_frame_get_channel_layout(p);
			}
			void set(long long channelLayout)
			{
				ffmpeg::av_frame_set_channel_layout(p, channelLayout);
			}
		}

		property int Channels
		{
			int get()
			{
				return ffmpeg::av_frame_get_channels(p);
			}
			void set(int channels)
			{
				ffmpeg::av_frame_set_channels(p, channels);
			}
		}

		property int SampleRate
		{
			int get()
			{
				return ffmpeg::av_frame_get_sample_rate(p);
			}
			void set(int sampleRate)
			{
				ffmpeg::av_frame_set_sample_rate(p, sampleRate);
			}
		}

		property int NumberSamples
		{
			int get()
			{
				return p->nb_samples;
			}
		}

		property long long PTS
		{
			long long get()
			{
				return p->pts;
			}
		}

		property bool IsKeyFrame
		{
			bool get()
			{
				return p->key_frame != 0;
			}
		}

	};

}