#pragma once

namespace ffmpeg
{
	extern "C"
	{
#pragma managed(push, off)
		#include <libavcodec/avcodec.h>
		#include <libavformat/avformat.h>
		#include <libswscale/swscale.h>
		#include <libavutil/avutil.h>
		#include <libavutil/opt.h>
		#include <libavdevice/avdevice.h>

		// come on ffmpeg developers..
		#undef PixelFormat
#pragma managed(pop)
	}
}
