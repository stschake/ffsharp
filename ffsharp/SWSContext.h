#pragma once

#include <stdint.h>
#include "wrapper/ffmpeg.h"
#include "AVPixelFormat.h"
#include "AVFrame.h"
#include "AVPicture.h"

using namespace System;

namespace ffsharp
{

	public ref class SWSVector
	{
	private:
		ffmpeg::SwsVector* p;

	public:

		SWSVector(int length)
		{
			p = ffmpeg::sws_allocVec(length);
		}

		SWSVector(ffmpeg::SwsVector* p)
		{
			this->p = p;
		}

		~SWSVector()
		{
			ffmpeg::sws_freeVec(p);
		}

		void Scale(double scalar)
		{
			ffmpeg::sws_scaleVec(p, scalar);
		}

		void Normalize(double height)
		{
			ffmpeg::sws_normalizeVec(p, height);
		}

		void Conv(SWSVector^ b)
		{
			ffmpeg::sws_convVec(p, b->p);
		}

		void Add(SWSVector^ b)
		{
			ffmpeg::sws_addVec(p, b->p);
		}

		void Sub(SWSVector^ b)
		{
			ffmpeg::sws_subVec(p, b->p);
		}

		void Shift(int shift)
		{
			ffmpeg::sws_shiftVec(p, shift);
		}

		SWSVector^ Clone()
		{
			return gcnew SWSVector(ffmpeg::sws_cloneVec(p));
		}

		double GetCoefficient(int index)
		{
			return p->coeff[index];
		}

		property int Length
		{
			int get()
			{
				return p->length;
			}
		}

		static SWSVector^ GetGaussianVec(double variance, double quality)
		{
			return gcnew SWSVector(ffmpeg::sws_getGaussianVec(variance, quality));
		}

		static SWSVector^ GetConstVec(double c, int length)
		{
			return gcnew SWSVector(ffmpeg::sws_getConstVec(c, length));
		}

		static SWSVector^ GetIdentityVec()
		{
			return gcnew SWSVector(ffmpeg::sws_getIdentityVec());
		}

	};

	public ref class SWSFilter
	{
	private:
		ffmpeg::SwsFilter* p;

	internal:

		property ffmpeg::SwsFilter* Pointer
		{
			ffmpeg::SwsFilter* get()
			{
				return p;
			}
		}

	public:

		SWSFilter(ffmpeg::SwsFilter* p)
		{
			this->p = p;
		}

		~SWSFilter()
		{
			ffmpeg::sws_freeFilter(p);
		}

		property SWSVector^ LumH
		{
			SWSVector^ get()
			{
				return gcnew SWSVector(p->lumH);
			}
		}

		property SWSVector^ LumV
		{
			SWSVector^ get()
			{
				return gcnew SWSVector(p->lumV);
			}
		}

		property SWSVector^ ChrH
		{
			SWSVector^ get()
			{
				return gcnew SWSVector(p->chrH);
			}
		}

		property SWSVector^ ChrV
		{
			SWSVector^ get()
			{
				return gcnew SWSVector(p->chrV);
			}
		}

		static SWSFilter^ GetDefaultFilter(float lumaGBlur, float chromaGBlur,
			float lumaSharpen, float chromaSharpen,
			float chromaHShift, float chromaVShift)
		{
			return gcnew SWSFilter(ffmpeg::sws_getDefaultFilter(lumaGBlur, chromaGBlur, lumaSharpen, chromaSharpen,
				chromaHShift, chromaVShift, 0));
		}

	};

	public ref class SWSContext
	{
	private:
		ffmpeg::SwsContext* p;

	public:

		SWSContext(ffmpeg::SwsContext* p)
		{
			this->p = p;
		}

		SWSContext()
		{
			p = ffmpeg::sws_alloc_context();
		}

		void Scale(IntPtr src, IntPtr stride, int srcSliceY, int srcSliceH, IntPtr dst, IntPtr dstStride);

		void Scale(AVPicture^ src, AVPicture^ dest, int srcSliceY, int srcSliceH);

		~SWSContext()
		{
			ffmpeg::sws_freeContext(p);
		}

		static SWSContext^ GetContext(int srcWidth, int srcHeight, AVPixelFormat pixelFormat, int dstWidth, int dstHeight)
		{
			return GetContext(srcWidth, srcHeight, pixelFormat, dstWidth, dstHeight, pixelFormat);
		}

		static SWSContext^ GetContext(int width, int height, AVPixelFormat srcPixelFormat, AVPixelFormat dstPixelFormat)
		{
			return GetContext(width, height, srcPixelFormat, width, height, dstPixelFormat);
		}

		static SWSContext^ GetContext(int srcWidth, int srcHeight, AVPixelFormat srcPixelFormat,
			int dstWidth, int dstHeight, AVPixelFormat dstPixelFormat)
		{
			return GetContext(srcWidth, srcHeight, srcPixelFormat, dstWidth, dstHeight, dstPixelFormat, 0, nullptr, nullptr);
		}

		static SWSContext^ GetContext(int srcWidth, int srcHeight, AVPixelFormat srcPixelFormat,
			int dstWidth, int dstHeight, AVPixelFormat dstPixelFormat, int flags)
		{
			return GetContext(srcWidth, srcHeight, srcPixelFormat, dstWidth, dstHeight, dstPixelFormat, flags, nullptr, nullptr);
		}

		static SWSContext^ GetContext(int srcWidth, int srcHeight, AVPixelFormat srcPixelFormat,
			int dstWidth, int dstHeight, AVPixelFormat dstPixelFormat,
			int flags, SWSFilter^ srcFilter, SWSFilter^ dstFilter)
		{
			ffmpeg::SwsFilter *srcFilterPtr = nullptr, *dstFilterPtr = nullptr;
			if (srcFilter != nullptr)
				srcFilterPtr = srcFilter->Pointer;
			if (dstFilter != nullptr)
				dstFilterPtr = dstFilter->Pointer;

			ffmpeg::SwsContext* c = ffmpeg::sws_getContext(srcWidth, srcHeight, (ffmpeg::AVPixelFormat) srcPixelFormat,
				dstWidth, dstHeight, (ffmpeg::AVPixelFormat) dstPixelFormat, flags, srcFilterPtr, dstFilterPtr, nullptr);

			if (c == nullptr)
				return nullptr;
			return gcnew SWSContext(c);
		}

	};

}