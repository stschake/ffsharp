#pragma once

#include <stdint.h>
#include "wrapper/ffmpeg.h"

using namespace System;

namespace ffsharp
{
	
	public enum class SWSColorSpace
	{
		ITU709 = SWS_CS_ITU709,
		FCC = SWS_CS_FCC,
		ITU601 = SWS_CS_ITU601,
		ITU624 = SWS_CS_ITU624,
		SMPTE170M = SWS_CS_SMPTE170M,
		SMPTE240M = SWS_CS_SMPTE240M,
		Default = SWS_CS_DEFAULT
	};

	public ref class SWScale
	{
	private:

		SWScale()
		{

		}
		
	public:

		static void ConvertPalette8ToPacked32(IntPtr src, IntPtr dst, int numPixels, IntPtr palette)
		{
			ffmpeg::sws_convertPalette8ToPacked32((uint8_t*)src.ToPointer(), (uint8_t*)dst.ToPointer(), numPixels,
				(uint8_t*)palette.ToPointer());
		}

		static void ConvertPalette8ToPacked24(IntPtr src, IntPtr dst, int numPixels, IntPtr palette)
		{
			ffmpeg::sws_convertPalette8ToPacked24((uint8_t*)src.ToPointer(), (uint8_t*)dst.ToPointer(), numPixels,
				(uint8_t*)palette.ToPointer());
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

		static property unsigned int Version
		{
			unsigned int get()
			{
				return ffmpeg::swscale_version();
			}
		}

		static property String^ Configuration
		{
			String^ get()
			{
				return gcnew String(ffmpeg::swscale_configuration());
			}
		}

		static property String^ License
		{
			String^ get()
			{
				return gcnew String(ffmpeg::swscale_license());
			}
		}

		static bool IsSupportedInput(int pixelFormat)
		{
			return ffmpeg::sws_isSupportedInput((ffmpeg::AVPixelFormat) pixelFormat) == 1;
		}

		static bool IsSupportedOutput(int pixelFormat)
		{
			return ffmpeg::sws_isSupportedOutput((ffmpeg::AVPixelFormat) pixelFormat) == 1;
		}

		static bool IsSupportedEndiannessConversion(int pixelFormat)
		{
			return ffmpeg::sws_isSupportedEndiannessConversion((ffmpeg::AVPixelFormat) pixelFormat) == 1;
		}

	};

}