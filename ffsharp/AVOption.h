#pragma once

#include "wrapper/ffmpeg.h"
#include "AVRational.h"

using namespace System;

namespace ffsharp
{

	public enum class AVOptionType
	{
		Flags = ffmpeg::AV_OPT_TYPE_FLAGS,
		Int = ffmpeg::AV_OPT_TYPE_INT,
		Int64 = ffmpeg::AV_OPT_TYPE_INT64,
		Double = ffmpeg::AV_OPT_TYPE_DOUBLE,
		Float = ffmpeg::AV_OPT_TYPE_FLOAT,
		String = ffmpeg::AV_OPT_TYPE_STRING,
		Rational = ffmpeg::AV_OPT_TYPE_RATIONAL,
		Binary = ffmpeg::AV_OPT_TYPE_BINARY,
		Dictionary = ffmpeg::AV_OPT_TYPE_DICT,
		Constant = ffmpeg::AV_OPT_TYPE_CONST,
		ImageSize = ffmpeg::AV_OPT_TYPE_IMAGE_SIZE,
		PixelFormat = ffmpeg::AV_OPT_TYPE_PIXEL_FMT,
		SampleFormat = ffmpeg::AV_OPT_TYPE_SAMPLE_FMT,
		VideoRate = ffmpeg::AV_OPT_TYPE_VIDEO_RATE,
		Duration = ffmpeg::AV_OPT_TYPE_DURATION,
		Color = ffmpeg::AV_OPT_TYPE_COLOR,
		ChannelLayout = ffmpeg::AV_OPT_TYPE_CHANNEL_LAYOUT
	};

	[Flags]
	public enum class AVOptionFlag
	{
		EncodingParam = AV_OPT_FLAG_ENCODING_PARAM,
		DecodingParam = AV_OPT_FLAG_DECODING_PARAM,
		Metadata = AV_OPT_FLAG_METADATA,
		AudioParam = AV_OPT_FLAG_AUDIO_PARAM,
		VideoParam = AV_OPT_FLAG_VIDEO_PARAM,
		SubtitleParam = AV_OPT_FLAG_SUBTITLE_PARAM,
		Export = AV_OPT_FLAG_EXPORT,
		ReadOnly = AV_OPT_FLAG_READONLY,
		FilteringParam = AV_OPT_FLAG_FILTERING_PARAM,
	};

	public ref class AVOption
	{
	private:
		const ffmpeg::AVOption* p;

	public:

		AVOption(const ffmpeg::AVOption* p)
		{
			this->p = p;
		}

		property String^ Name
		{
			String^ get()
			{
				return gcnew String(p->name);
			}
		}

		property String^ Unit
		{
			String^ get()
			{
				return gcnew String(p->unit);
			}
		}

		property AVOptionFlag Flags
		{
			AVOptionFlag get()
			{
				return (AVOptionFlag) p->flags;
			}
		}

		property String^ Help
		{
			String^ get()
			{
				return gcnew String(p->help);
			}
		}

		property int Offset
		{
			int get()
			{
				return p->offset;
			}
		}
		
		property long long DefaultInt64
		{
			long long get()
			{
				return p->default_val.i64;
			}
		}

		property double DefaultDouble
		{
			double get()
			{
				return p->default_val.dbl;
			}
		}

		property String^ DefaultString
		{
			String^ get()
			{
				return gcnew String(p->default_val.str);
			}
		}

		property AVRational^ DefaultRational
		{
			AVRational^ get()
			{
				return gcnew AVRational(const_cast<ffmpeg::AVRational*>(&p->default_val.q));
			}
		}

		property double Minimum
		{
			double get()
			{
				return p->min;
			}
		}

		property double Maximum
		{
			double get()
			{
				return p->max;
			}
		}

		property AVOptionType Type
		{
			AVOptionType get()
			{
				return (AVOptionType)p->type;
			}
		}

	};

}