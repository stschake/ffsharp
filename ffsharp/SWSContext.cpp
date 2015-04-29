#include "SWSContext.h"
#include "AVErrorException.h"

namespace ffsharp
{

	void SWSContext::Scale(IntPtr src, IntPtr stride, int srcSliceY, int srcSliceH, IntPtr dst, IntPtr dstStride)
	{
		int r = ffmpeg::sws_scale(p, (uint8_t**)src.ToPointer(), (int*)stride.ToPointer(), srcSliceY, srcSliceH, (uint8_t**)dst.ToPointer(), (int*)dstStride.ToPointer());
		if (r < 0)
			throw gcnew AVErrorException(r);
	}

	void SWSContext::Scale(AVPicture^ src, AVPicture^ dst, int srcSliceY, int srcSliceH)
	{
		int r = ffmpeg::sws_scale(p, src->Pointer->data, src->Pointer->linesize, srcSliceY, srcSliceH, dst->Pointer->data, dst->Pointer->linesize);
		if (r < 0)
			throw gcnew AVErrorException(r);
	}

}