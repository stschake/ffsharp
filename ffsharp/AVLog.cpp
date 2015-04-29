#include "AVLog.h"
#include "AVClass.h"

namespace ffsharp
{

	// TODO: this callback is supposed to be thread-safe
	void log_callback(void* pClass, int level, const char* fmt, ffmpeg::va_list vl)
	{
		static int printPrefix = 1;
		char data[1024];
		ffmpeg::av_log_format_line(pClass, level, fmt, vl, data, 1024, &printPrefix);
		if (AVLog::Callback != nullptr)
			AVLog::Callback((AVLogLevel)level, gcnew String(data));
	}

}