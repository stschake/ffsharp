#pragma once

#include "wrapper/ffmpeg.h"

namespace ffsharp
{

	public ref class AVRational
	{
	private:
		ffmpeg::AVRational* p;
		
	public:

		AVRational(ffmpeg::AVRational* p)
		{
			this->p = p;
		}

		property int Numerator
		{
			int get()
			{
				return p->num;
			}
		}

		property int Denominator
		{
			int get()
			{
				return p->den;
			}
		}

		double ToDouble()
		{
			return ffmpeg::av_q2d(*p);
		}
	};

}