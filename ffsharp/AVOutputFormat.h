#pragma once

#include "wrapper/ffmpeg.h"
#include "AVCodecID.h"
#include "OptionsEnabled.h"

using namespace System;

namespace ffsharp
{

	public ref class AVOutputFormat : public OptionsEnabled
	{
	private:
		ffmpeg::AVOutputFormat* p;

	public:

		AVOutputFormat(ffmpeg::AVOutputFormat* p)
			: OptionsEnabled(p->priv_class)
		{
			this->p = p;
		}

		property String^ Name
		{
			String^ get()
			{
				return gcnew String(p->name);
			}
		}

		property String^ LongName
		{
			String^ get()
			{
				return gcnew String(p->long_name);
			}
		}

		property array<String^>^ Extensions
		{
			array<String^>^ get()
			{
				return (gcnew String(p->extensions))->Split(',');
			}
		}

		property AVCodecID DataCodecID
		{
			AVCodecID get()
			{
				return (AVCodecID)p->data_codec;
			}
		}

		property AVCodecID AudioCodecID
		{
			AVCodecID get()
			{
				return (AVCodecID)p->audio_codec;
			}
		}

		property AVCodecID VideoCodecID
		{
			AVCodecID get()
			{
				return (AVCodecID)p->video_codec;
			}
		}

		property AVCodecID SubtitleCodecID
		{
			AVCodecID get()
			{
				return (AVCodecID)p->subtitle_codec;
			}
		}

	};

}