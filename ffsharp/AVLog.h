#pragma once

#include "wrapper/ffmpeg.h"

using namespace System;

namespace ffsharp
{

	public enum class AVLogLevel
	{
		Quiet = AV_LOG_QUIET,
		Panic = AV_LOG_PANIC,
		Fatal = AV_LOG_FATAL,
		Error = AV_LOG_ERROR,
		Warning = AV_LOG_WARNING,
		Info = AV_LOG_INFO,
		Verbose = AV_LOG_VERBOSE,
		Debug = AV_LOG_DEBUG,
		Trace = AV_LOG_TRACE,
	};

	[Flags]
	public enum class AVLogFlag
	{
		SkipRepeated = AV_LOG_SKIP_REPEATED,
		PrintLevel = AV_LOG_PRINT_LEVEL
	};

	ref class AVClass;
	public delegate void LogCallback(AVLogLevel level, String^ message);

	void log_callback(void* pClass, int level, const char* fmt, ffmpeg::va_list vl);

	public ref class AVLog
	{
	private:
		static LogCallback^ logCallback;

	public:

		static property LogCallback^ Callback
		{
			LogCallback^ get()
			{
				return logCallback;
			}
			void set(LogCallback^ cb)
			{
				logCallback = cb;
				if (cb != nullptr)
					ffmpeg::av_log_set_callback(log_callback);
				else
					ffmpeg::av_log_set_callback(ffmpeg::av_log_default_callback);
			}
		}

		static property int Level
		{
			int get()
			{
				return ffmpeg::av_log_get_level();
			}
			void set(int level)
			{
				ffmpeg::av_log_set_level(level);
			}
		}

		static property AVLogFlag Flags
		{
			AVLogFlag get()
			{
				return (AVLogFlag) ffmpeg::av_log_get_flags();
			}
			void set(AVLogFlag flags)
			{
				ffmpeg::av_log_set_flags((int)flags);
			}
		}

	};

}