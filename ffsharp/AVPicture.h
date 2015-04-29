#pragma once

#include "wrapper/ffmpeg.h"
#include "AVPixelFormat.h"
#include "AVErrorException.h"

using namespace System;

namespace ffsharp
{

	ref class AVFrame;

	public ref class AVPicture
	{
	private:
		ffmpeg::AVPicture* p;
		bool owned = true;

	internal:

		property ffmpeg::AVPicture* Pointer
		{
			ffmpeg::AVPicture* get()
			{
				return p;
			}
		}

		AVPicture(ffmpeg::AVFrame* p)
		{
			this->p = (ffmpeg::AVPicture*) p;
			owned = false;
		}

	public:

		AVPicture(AVPixelFormat pixelFormat, int width, int height)
		{
			p = (ffmpeg::AVPicture*) ffmpeg::av_frame_alloc();
			int r = ffmpeg::avpicture_alloc(p, (ffmpeg::AVPixelFormat) pixelFormat, width, height);
			((ffmpeg::AVFrame*) p)->format = (ffmpeg::AVPixelFormat) pixelFormat;
			((ffmpeg::AVFrame*) p)->width = width;
			((ffmpeg::AVFrame*) p)->height = height;
		}

		~AVPicture()
		{
			if (owned)
				ffmpeg::avpicture_free(p);
		}

		AVFrame^ AsFrame();

		void Layout(AVPixelFormat pixelFormat, int width, int height, IntPtr dest, int destSize)
		{
			int r = ffmpeg::avpicture_layout(p, (ffmpeg::AVPixelFormat) pixelFormat, width, height, (unsigned char*)dest.ToPointer(), destSize);
			if (r < 0)
				throw gcnew AVErrorException(r);
		}

		static int GetSize(AVPixelFormat pixelFormat, int width, int height)
		{
			return ffmpeg::avpicture_get_size((ffmpeg::AVPixelFormat) pixelFormat, width, height);
		}

		static void Copy(AVPicture^ dst, AVPicture^ src, AVPixelFormat pixelFormat, int width, int height)
		{
			ffmpeg::av_picture_copy(dst->Pointer, src->Pointer, (ffmpeg::AVPixelFormat) pixelFormat, width, height);
		}

		static void Crop(AVPicture^ dst, AVPicture^ src, AVPixelFormat pixelFormat, int topBand, int leftBand)
		{
			int r = ffmpeg::av_picture_crop(dst->Pointer, src->Pointer, (ffmpeg::AVPixelFormat) pixelFormat, topBand, leftBand);
			if (r < 0)
				throw gcnew AVErrorException(r);
		}

		static void Pad(AVPicture^ dst, AVPicture^ src, int height, int width, AVPixelFormat pixelFormat, int padTop, int padBottom, int padLeft, int padRight, IntPtr color)
		{
			int r = ffmpeg::av_picture_pad(dst->Pointer, src->Pointer, height, width, (ffmpeg::AVPixelFormat) pixelFormat, padTop, padBottom, padLeft, padRight, (int*)color.ToPointer());
			if (r < 0)
				throw gcnew AVErrorException(r);
		}
	};

}