#pragma once

#include <stdint.h>

#include "wrapper/ffmpeg.h"
#include "AVRational.h"
#include "AVCodecContext.h"

namespace ffsharp
{

	public ref class AVStream
	{
	private:
		ffmpeg::AVStream* p;

	public:

		AVStream(ffmpeg::AVStream* p)
		{
			this->p = p;
		}

		property AVCodecContext^ CodecContext
		{
			AVCodecContext^ get()
			{
				return gcnew AVCodecContext(p->codec);
			}
		}

		property AVRational^ TimeBase
		{
			AVRational^ get()
			{
				return gcnew AVRational(&p->time_base);
			}
		}

		property int Id
		{
			int get()
			{
				return p->id;
			}
		}

		property int Index
		{
			int get()
			{
				return p->index;
			}
		}

		property int64_t StartTime
		{
			int64_t get()
			{
				return p->start_time;
			}
		}

		property int64_t Duration
		{
			int64_t get()
			{
				return p->duration;
			}
		}

		property int64_t NumberFrames
		{
			int64_t get()
			{
				return p->nb_frames;
			}
		}

		property int64_t FirstDTS
		{
			int64_t get()
			{
				return p->first_dts;
			}
		}

		property int64_t CurrentDTS
		{
			int64_t get()
			{
				return p->cur_dts;
			}
		}

	};

}