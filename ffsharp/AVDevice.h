#pragma once

#include <stdint.h>
#include "wrapper/ffmpeg.h"

#include "AVInputFormat.h"
#include "AVOutputFormat.h"

using namespace System;
using namespace System::Collections::Generic;

namespace ffsharp
{
	
	public ref class AVDevice
	{
	private:

		AVDevice()
		{

		}

		template<typename T, typename S>
		static List<S^>^ getLinkedList(T* (*funNext)(T*))
		{
			List<S^>^ ret = gcnew List<S^>();
			T* item = nullptr;
			while ((item = funNext(item)) != nullptr)
				ret->Add(gcnew S(item));
			return ret;
		}

	public:

		static property List<AVInputFormat^>^ AudioInputDevices
		{
			List<AVInputFormat^>^ get()
			{
				return getLinkedList<ffmpeg::AVInputFormat, AVInputFormat>(ffmpeg::av_input_audio_device_next);
			}
		}

		static property List<AVInputFormat^>^ VideoInputDevices
		{
			List<AVInputFormat^>^ get()
			{
				return getLinkedList<ffmpeg::AVInputFormat, AVInputFormat>(ffmpeg::av_input_video_device_next);
			}
		}

		static property List<AVOutputFormat^>^ AudioOutputDevices
		{
			List<AVOutputFormat^>^ get()
			{
				return getLinkedList<ffmpeg::AVOutputFormat, AVOutputFormat>(ffmpeg::av_output_audio_device_next);
			}
		}

		static property List<AVOutputFormat^>^ VideoOutputDevices
		{
			List<AVOutputFormat^>^ get()
			{
				return getLinkedList<ffmpeg::AVOutputFormat, AVOutputFormat>(ffmpeg::av_output_video_device_next);
			}
		}

		static void RegisterAll()
		{
			ffmpeg::avdevice_register_all();
		}

		static property uint32_t Version
		{
			uint32_t get()
			{
				return ffmpeg::avdevice_version();
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
				return gcnew String(ffmpeg::avdevice_configuration());
			}
		}

		static property String^ License
		{
			String^ get()
			{
				return gcnew String(ffmpeg::avdevice_license());
			}
		}

	};

}