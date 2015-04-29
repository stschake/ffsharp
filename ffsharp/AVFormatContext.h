#pragma once

#include "wrapper/ffmpeg.h"

#include "AVErrorException.h"
#include "AVPacket.h"
#include "AVStream.h"
#include "AVDictionary.h"
#include "AVClass.h"
#include "OptionsEnabled.h"

using namespace System;
using namespace System::Collections::Generic;

namespace ffsharp
{
	
	public ref class AVFormatContext : public OptionsEnabled
	{
	private:
		ffmpeg::AVFormatContext* p;
		bool findCalled = false;

	public:
		
		AVFormatContext(ffmpeg::AVFormatContext* p)
			: OptionsEnabled(p->av_class)
		{
			this->p = p;
		}

		void FindStreamInfo()
		{
			if (findCalled)
				return;
			
			int r = ffmpeg::avformat_find_stream_info(p, nullptr);
			if (r < 0)
				throw gcnew AVErrorException(r);
			findCalled = true;
		}

		property int NumberStreams
		{
			int get()
			{
				return p->nb_streams;
			}
		}

		property AVDictionary^ Metadata
		{
			AVDictionary^ get()
			{
				return gcnew AVDictionary(p->metadata);
			}
		}

		property List<AVStream^>^ Streams
		{
			List<AVStream^>^ get()
			{
				auto ret = gcnew List<AVStream^>(NumberStreams);
				for (int i = 0; i < NumberStreams; i++)
					ret->Add(gcnew AVStream(p->streams[i]));
				return ret;
			}
		}

		AVStream^ FindBestStream(AVMediaType mediaType)
		{
			int r = ffmpeg::av_find_best_stream(p, (ffmpeg::AVMediaType) mediaType, -1, -1, nullptr, 0);
			if (r < 0)
				return nullptr;
			return GetStream(r);
		}

		AVStream^ GetStream(int index)
		{
			if (index >= NumberStreams || index < 0)
				throw gcnew IndexOutOfRangeException();
			return gcnew AVStream(p->streams[index]);
		}

		void Close()
		{
			pin_ptr<ffmpeg::AVFormatContext*> pinned = &p;
			ffmpeg::avformat_close_input(pinned);
			p = nullptr;
		}

		AVPacket^ ReadFrame()
		{
			ffmpeg::AVPacket* packet = (ffmpeg::AVPacket*) ffmpeg::av_malloc(sizeof(ffmpeg::AVPacket));
			ffmpeg::av_init_packet(packet);
			int r = ffmpeg::av_read_frame(p, packet);
			if (r < 0)
			{
				ffmpeg::av_free(packet);
				if (r == AVERROR_EOF)
					return nullptr;
				throw gcnew AVErrorException(r);
			}
			return gcnew AVPacket(packet);
		}

		~AVFormatContext()
		{
			Close();
		}
	};
	
}