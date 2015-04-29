#pragma once

#include <stdint.h>
#include "wrapper/ffmpeg.h"

#include "AVRational.h"
#include "AVCodecContext.h"

using namespace System;

namespace ffsharp
{

	public ref class AVUtil
	{
	private:

		AVUtil();

	public:

		static wchar_t GetPictureTypeString(AVPictureType pictureType)
		{
			return ffmpeg::av_get_picture_type_char((ffmpeg::AVPictureType) pictureType);
		}

		static String^ GetMediaTypeString(AVMediaType mediaType)
		{
			const char* r = ffmpeg::av_get_media_type_string((ffmpeg::AVMediaType) mediaType);
			if (r == nullptr)
				return nullptr;
			return gcnew String(r);
		}

		static property int64_t NoPTSValue
		{
			int64_t get()
			{
				return AV_NOPTS_VALUE;
			}
		}

		static AVRational^ GetInternalTimeBase()
		{
			ffmpeg::AVRational* r = (ffmpeg::AVRational*) ffmpeg::av_malloc(sizeof(ffmpeg::AVRational));
			*r = ffmpeg::av_get_time_base_q();
			return gcnew AVRational(r);
		}

		static property uint32_t Version
		{
			uint32_t get()
			{
				return ffmpeg::avutil_version();
			}
		}

		static property int MajorVersion
		{
			int get()
			{
				return Version >> 16;
			}
		}

		static property int MinorVersion
		{
			int get()
			{
				return (Version >> 8) & 0xFF;
			}
		}

		static property int MicroVersion
		{
			int get()
			{
				return Version & 0xFF;
			}
		}

		static property String^ Configuration
		{
			String^ get()
			{
				return gcnew String(ffmpeg::avutil_configuration());
			}
		}

		static property String^ License
		{
			String^ get()
			{
				return gcnew String(ffmpeg::avutil_license());
			}
		}
	};

}