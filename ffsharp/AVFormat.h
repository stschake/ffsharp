#pragma once

#include <stdint.h>

#include "wrapper/ffmpeg.h"
#include "AVFormatContext.h"
#include "AVErrorException.h"
#include "AVInputFormat.h"
#include "AVOutputFormat.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Collections::Generic;

namespace ffsharp
{

	public ref class AVFormat
	{
	private:

		AVFormat()
		{
		}

		template<typename T, typename S>
		static List<S^>^ getLinkedList(T* (*funNext)(const T*))
		{
			List<S^>^ ret = gcnew List<S^>();
			T* item = nullptr;
			while ((item = funNext(item)) != nullptr)
				ret->Add(gcnew S(item));
			return ret;
		}

	public:
		
		static AVFormatContext^ OpenInput(String^ filename)
		{
			ffmpeg::AVFormatContext *ctx;
			auto filenameAnsi = Marshal::StringToHGlobalAnsi(filename);
			try
			{
				int r = ffmpeg::avformat_open_input(&ctx, (const char*) filenameAnsi.ToPointer(), nullptr, nullptr);
				if (r < 0)
					throw gcnew AVErrorException(r);
				return gcnew AVFormatContext(ctx);
			}
			finally
			{
				if (filenameAnsi.ToPointer() != nullptr)
					Marshal::FreeHGlobal(filenameAnsi);
			}
		}

		static property List<AVInputFormat^>^ InputFormats
		{
			List<AVInputFormat^>^ get()
			{
				return getLinkedList<ffmpeg::AVInputFormat, AVInputFormat>(ffmpeg::av_iformat_next);
			}
		}

		static property List<AVOutputFormat^>^ OutputFormats
		{
			List<AVOutputFormat^>^ get()
			{
				return getLinkedList<ffmpeg::AVOutputFormat, AVOutputFormat>(ffmpeg::av_oformat_next);
			}
		}

		static void RegisterAll()
		{
			ffmpeg::av_register_all();
		}

		static void NetworkInit()
		{
			ffmpeg::avformat_network_init();
		}

		static void NetworkDeInit()
		{
			ffmpeg::avformat_network_deinit();
		}

		static property uint32_t Version
		{
			uint32_t get()
			{
				return ffmpeg::avformat_version();
			}
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

		static property String^ Configuration
		{
			String^ get()
			{
				return gcnew String(ffmpeg::avformat_configuration());
			}
		}

		static property String^ License
		{
			String^ get()
			{
				return gcnew String(ffmpeg::avformat_license());
			}
		}
	};

}