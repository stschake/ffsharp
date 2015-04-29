#pragma once

#include "wrapper/ffmpeg.h"

#include "AVClass.h"
#include "AVOption.h"

using namespace System;

namespace ffsharp
{

	public ref class OptionsEnabled abstract
	{
	private:
		const ffmpeg::AVClass* classPtr;

	internal:

		OptionsEnabled(const ffmpeg::AVClass* classPtr)
		{
			SetClassPointer(classPtr);
		}

		void SetClassPointer(const ffmpeg::AVClass* classPtr)
		{
			this->classPtr = classPtr;
		}

	public:

		property AVClass^ Class
		{
			AVClass^ get()
			{
				return gcnew AVClass(this->classPtr);
			}
		}

		property List<AVOption^>^ Options
		{
			List<AVOption^>^ get()
			{
				return Class->Options;
			}
		}
	};

}