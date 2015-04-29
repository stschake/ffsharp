#pragma once

#include "wrapper/ffmpeg.h"
#include "OptionsEnabled.h"

using namespace System;
using namespace System::Collections::Generic;

namespace ffsharp
{

	public ref class AVInputFormat : public OptionsEnabled
	{
	private:
		ffmpeg::AVInputFormat* p;

	public:

		AVInputFormat(ffmpeg::AVInputFormat* p)
			: OptionsEnabled(p->priv_class)
		{
			this->p = p;
		}

		property String^ NameRaw
		{
			String^ get()
			{
				return gcnew String(p->name);
			}
		}

		property array<String^>^ ShortNames
		{
			array<String^>^ get()
			{
				return NameRaw->Split(',');
			}
		}

		property array<String^>^ MimeTypes
		{
			array<String^>^ get()
			{
				return (gcnew String(p->mime_type))->Split(',');
			}
		}

		property String^ LongName
		{
			String^ get()
			{
				return gcnew String(p->long_name);
			}
		}

	};

}