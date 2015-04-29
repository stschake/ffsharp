#pragma once

#include <stdint.h>
#include "wrapper/ffmpeg.h"

namespace ffsharp
{
	
	public ref class AVPacket
	{
	private:
		ffmpeg::AVPacket *p;

	internal:

		property ffmpeg::AVPacket* Pointer
		{
			ffmpeg::AVPacket* get()
			{
				return p;
			}
		}

	public:

		AVPacket()
		{
			p = (ffmpeg::AVPacket*) ffmpeg::av_malloc(sizeof(ffmpeg::AVPacket));
			ffmpeg::av_init_packet(p);
			p->data = nullptr;
			p->size = 0;
		}

		AVPacket(ffmpeg::AVPacket* p)
		{
			this->p = p;
		}

		property int Size
		{
			int get()
			{
				return p->size;
			}

			void set(int v)
			{
				p->size = v;
			}
		}

		property IntPtr Data
		{
			IntPtr get()
			{
				return IntPtr(p->data);
			}

			void set(IntPtr data)
			{
				p->data = (uint8_t*)data.ToPointer();
			}
		}

		property int StreamIndex
		{
			int get()
			{
				return p->stream_index;
			}
		}

		property int64_t DTS
		{
			int64_t get()
			{
				return p->dts;
			}
		}

		property int64_t PTS
		{
			int64_t get()
			{
				return p->pts;
			}
		}

		property int Duration
		{
			int get()
			{
				return p->duration;
			}
		}

		~AVPacket()
		{
			if (p != nullptr)
				ffmpeg::av_free_packet(p);
		}

	};

}