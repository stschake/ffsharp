#pragma once

#include <stdint.h>
#include "wrapper/ffmpeg.h"
#include "AVOption.h"

using namespace System;
using namespace System::Collections::Generic;

namespace ffsharp
{

	public enum class AVClassCategory
	{
		Undefined = ffmpeg::AV_CLASS_CATEGORY_NA,
		Input = ffmpeg::AV_CLASS_CATEGORY_INPUT,
		Output = ffmpeg::AV_CLASS_CATEGORY_OUTPUT,
		Muxer = ffmpeg::AV_CLASS_CATEGORY_MUXER,
		Demuxer = ffmpeg::AV_CLASS_CATEGORY_DEMUXER,
		Encoder = ffmpeg::AV_CLASS_CATEGORY_ENCODER,
		Decoder = ffmpeg::AV_CLASS_CATEGORY_DECODER,
		Filter = ffmpeg::AV_CLASS_CATEGORY_FILTER,
		BitStreamFilter = ffmpeg::AV_CLASS_CATEGORY_BITSTREAM_FILTER,
		SWScaler = ffmpeg::AV_CLASS_CATEGORY_SWSCALER,
		SWResampler = ffmpeg::AV_CLASS_CATEGORY_SWRESAMPLER,
		DeviceVideoOutput = ffmpeg::AV_CLASS_CATEGORY_DEVICE_VIDEO_OUTPUT,
		DeviceVideoInput = ffmpeg::AV_CLASS_CATEGORY_DEVICE_VIDEO_INPUT,
		DeviceAudioOuput = ffmpeg::AV_CLASS_CATEGORY_DEVICE_AUDIO_OUTPUT,
		DeviceAudioInput = ffmpeg::AV_CLASS_CATEGORY_DEVICE_AUDIO_INPUT,
		DeviceOutput = ffmpeg::AV_CLASS_CATEGORY_DEVICE_OUTPUT,
		DeviceInput = ffmpeg::AV_CLASS_CATEGORY_DEVICE_INPUT
	};

	public ref class AVClass
	{
	private:
		const ffmpeg::AVClass* p;

	internal:

		property const ffmpeg::AVClass* Pointer
		{
			const ffmpeg::AVClass* get()
			{
				return p;
			}
		}

	public:

		AVClass(const ffmpeg::AVClass* p)
		{
			this->p = p;
		}

		property List<AVOption^>^ Options
		{
			List<AVOption^>^ get()
			{
				pin_ptr<const ffmpeg::AVClass*> classPtr = &p;
				auto ret = gcnew List<AVOption^>();
				const ffmpeg::AVOption* opt = nullptr;
				while ((opt = ffmpeg::av_opt_next(classPtr, opt)) != nullptr)
					ret->Add(gcnew AVOption(opt));
				return ret;
			}
		}

		property AVClassCategory Category
		{
			AVClassCategory get()
			{
				return (AVClassCategory)p->category;
			}
		}

		property String^ Name
		{
			String^ get()
			{
				return gcnew String(p->class_name);
			}
		}

		static property AVClass^ SWScale
		{
			AVClass^ get()
			{
				return gcnew AVClass(ffmpeg::sws_get_class());
			}
		}

	};

}