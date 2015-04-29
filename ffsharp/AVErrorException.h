#pragma once

#include "wrapper/ffmpeg.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace ffsharp
{

	public ref class AVErrorException : Exception
	{
	private:
		int code;

	public:

		AVErrorException(int _code)
			: code(_code)
		{
			Exception(Description);
		}

		property int Code
		{
			int get()
			{
				return code;
			}
		}

		property String^ Description
		{
			String^ get()
			{
				IntPtr buf = Marshal::AllocHGlobal(128);
				try
				{
					ffmpeg::av_strerror(code, (char*)buf.ToPointer(), 128);
					return gcnew String((char*)buf.ToPointer());
				}
				finally
				{
					if (buf.ToPointer() != nullptr)
						Marshal::FreeHGlobal(buf);
				}
			}
		}
	};

}