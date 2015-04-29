#include "AVPicture.h"
#include "AVFrame.h"

namespace ffsharp
{

	AVFrame^ AVPicture::AsFrame()
	{
		return gcnew AVFrame((ffmpeg::AVFrame*) p);
	}

}