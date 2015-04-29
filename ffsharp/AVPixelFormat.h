#pragma once

#include "wrapper/ffmpeg.h"

using namespace System;

namespace ffsharp
{

	public enum class AVPixelFormat
	{
 		Undefined = ffmpeg::AV_PIX_FMT_NONE,
		YUV420P = ffmpeg::AV_PIX_FMT_YUV420P,   
		YUYV422 = ffmpeg::AV_PIX_FMT_YUYV422,   
		RGB24 = ffmpeg::AV_PIX_FMT_RGB24,     
		BGR24 = ffmpeg::AV_PIX_FMT_BGR24,     
		YUV422P = ffmpeg::AV_PIX_FMT_YUV422P,   
		YUV444P = ffmpeg::AV_PIX_FMT_YUV444P,   
		YUV410P = ffmpeg::AV_PIX_FMT_YUV410P,   
		YUV411P = ffmpeg::AV_PIX_FMT_YUV411P,   
		GRAY8 = ffmpeg::AV_PIX_FMT_GRAY8,     
		MONOWHITE = ffmpeg::AV_PIX_FMT_MONOWHITE, 
		MONOBLACK = ffmpeg::AV_PIX_FMT_MONOBLACK, 
		PAL8 = ffmpeg::AV_PIX_FMT_PAL8,      
		YUVJ420P = ffmpeg::AV_PIX_FMT_YUVJ420P,  
		YUVJ422P = ffmpeg::AV_PIX_FMT_YUVJ422P,  
		YUVJ444P = ffmpeg::AV_PIX_FMT_YUVJ444P,  
		XVMC_MPEG2_MC = ffmpeg::AV_PIX_FMT_XVMC_MPEG2_MC,
		XVMC_MPEG2_IDCT = ffmpeg::AV_PIX_FMT_XVMC_MPEG2_IDCT,
		UYVY422 = ffmpeg::AV_PIX_FMT_UYVY422,   
		UYYVYY411 = ffmpeg::AV_PIX_FMT_UYYVYY411, 
		BGR8 = ffmpeg::AV_PIX_FMT_BGR8,      
		BGR4 = ffmpeg::AV_PIX_FMT_BGR4,      
		BGR4_BYTE = ffmpeg::AV_PIX_FMT_BGR4_BYTE, 
		RGB8 = ffmpeg::AV_PIX_FMT_RGB8,      
		RGB4 = ffmpeg::AV_PIX_FMT_RGB4,      
		RGB4_BYTE = ffmpeg::AV_PIX_FMT_RGB4_BYTE, 
		NV12 = ffmpeg::AV_PIX_FMT_NV12,      
		NV21 = ffmpeg::AV_PIX_FMT_NV21,      
		ARGB = ffmpeg::AV_PIX_FMT_ARGB,      
		RGBA = ffmpeg::AV_PIX_FMT_RGBA,      
		ABGR = ffmpeg::AV_PIX_FMT_ABGR,      
		BGRA = ffmpeg::AV_PIX_FMT_BGRA,      
		GRAY16BE = ffmpeg::AV_PIX_FMT_GRAY16BE,  
		GRAY16LE = ffmpeg::AV_PIX_FMT_GRAY16LE,  
		YUV440P = ffmpeg::AV_PIX_FMT_YUV440P,   
		YUVJ440P = ffmpeg::AV_PIX_FMT_YUVJ440P,  
		YUVA420P = ffmpeg::AV_PIX_FMT_YUVA420P,  
		VDPAU_H264 = ffmpeg::AV_PIX_FMT_VDPAU_H264,
		VDPAU_MPEG1 = ffmpeg::AV_PIX_FMT_VDPAU_MPEG1,
		VDPAU_MPEG2 = ffmpeg::AV_PIX_FMT_VDPAU_MPEG2,
		VDPAU_WMV3 = ffmpeg::AV_PIX_FMT_VDPAU_WMV3,
		VDPAU_VC1 = ffmpeg::AV_PIX_FMT_VDPAU_VC1, 
		RGB48BE = ffmpeg::AV_PIX_FMT_RGB48BE,   
		RGB48LE = ffmpeg::AV_PIX_FMT_RGB48LE,   
		RGB565BE = ffmpeg::AV_PIX_FMT_RGB565BE,  
		RGB565LE = ffmpeg::AV_PIX_FMT_RGB565LE,  
		RGB555BE = ffmpeg::AV_PIX_FMT_RGB555BE,  
		RGB555LE = ffmpeg::AV_PIX_FMT_RGB555LE,  
		BGR565BE = ffmpeg::AV_PIX_FMT_BGR565BE,  
		BGR565LE = ffmpeg::AV_PIX_FMT_BGR565LE,  
		BGR555BE = ffmpeg::AV_PIX_FMT_BGR555BE,  
		BGR555LE = ffmpeg::AV_PIX_FMT_BGR555LE,  
		VAAPI_MOCO = ffmpeg::AV_PIX_FMT_VAAPI_MOCO, 
		VAAPI_IDCT = ffmpeg::AV_PIX_FMT_VAAPI_IDCT, 
		VAAPI_VLD = ffmpeg::AV_PIX_FMT_VAAPI_VLD,  
		YUV420P16LE = ffmpeg::AV_PIX_FMT_YUV420P16LE,  
		YUV420P16BE = ffmpeg::AV_PIX_FMT_YUV420P16BE,  
		YUV422P16LE = ffmpeg::AV_PIX_FMT_YUV422P16LE,  
		YUV422P16BE = ffmpeg::AV_PIX_FMT_YUV422P16BE,  
		YUV444P16LE = ffmpeg::AV_PIX_FMT_YUV444P16LE,  
		YUV444P16BE = ffmpeg::AV_PIX_FMT_YUV444P16BE,  
		VDPAU_MPEG4 = ffmpeg::AV_PIX_FMT_VDPAU_MPEG4,  
		DXVA2_VLD = ffmpeg::AV_PIX_FMT_DXVA2_VLD,    
		RGB444LE = ffmpeg::AV_PIX_FMT_RGB444LE,  
		RGB444BE = ffmpeg::AV_PIX_FMT_RGB444BE,  
		BGR444LE = ffmpeg::AV_PIX_FMT_BGR444LE,  
		BGR444BE = ffmpeg::AV_PIX_FMT_BGR444BE,  
		YA8 = ffmpeg::AV_PIX_FMT_YA8,       
		Y400A = ffmpeg::AV_PIX_FMT_Y400A, 
 		GRAY8A = ffmpeg::AV_PIX_FMT_GRAY8A, 
		BGR48BE = ffmpeg::AV_PIX_FMT_BGR48BE,   
		BGR48LE = ffmpeg::AV_PIX_FMT_BGR48LE,   
		YUV420P9BE = ffmpeg::AV_PIX_FMT_YUV420P9BE, 
		YUV420P9LE = ffmpeg::AV_PIX_FMT_YUV420P9LE, 
		YUV420P10BE = ffmpeg::AV_PIX_FMT_YUV420P10BE,
		YUV420P10LE = ffmpeg::AV_PIX_FMT_YUV420P10LE,
		YUV422P10BE = ffmpeg::AV_PIX_FMT_YUV422P10BE,
		YUV422P10LE = ffmpeg::AV_PIX_FMT_YUV422P10LE,
		YUV444P9BE = ffmpeg::AV_PIX_FMT_YUV444P9BE, 
		YUV444P9LE = ffmpeg::AV_PIX_FMT_YUV444P9LE, 
		YUV444P10BE = ffmpeg::AV_PIX_FMT_YUV444P10BE,
		YUV444P10LE = ffmpeg::AV_PIX_FMT_YUV444P10LE,
		YUV422P9BE = ffmpeg::AV_PIX_FMT_YUV422P9BE, 
		YUV422P9LE = ffmpeg::AV_PIX_FMT_YUV422P9LE, 
		VDA_VLD = ffmpeg::AV_PIX_FMT_VDA_VLD,    
		GBRP = ffmpeg::AV_PIX_FMT_GBRP,      
		GBRP9BE = ffmpeg::AV_PIX_FMT_GBRP9BE,   
		GBRP9LE = ffmpeg::AV_PIX_FMT_GBRP9LE,   
		GBRP10BE = ffmpeg::AV_PIX_FMT_GBRP10BE,  
		GBRP10LE = ffmpeg::AV_PIX_FMT_GBRP10LE,  
		GBRP16BE = ffmpeg::AV_PIX_FMT_GBRP16BE,  
		GBRP16LE = ffmpeg::AV_PIX_FMT_GBRP16LE,  
		YUVA422P_LIBAV = ffmpeg::AV_PIX_FMT_YUVA422P_LIBAV,  
		YUVA444P_LIBAV = ffmpeg::AV_PIX_FMT_YUVA444P_LIBAV,  
		YUVA420P9BE = ffmpeg::AV_PIX_FMT_YUVA420P9BE,  
		YUVA420P9LE = ffmpeg::AV_PIX_FMT_YUVA420P9LE,  
		YUVA422P9BE = ffmpeg::AV_PIX_FMT_YUVA422P9BE,  
		YUVA422P9LE = ffmpeg::AV_PIX_FMT_YUVA422P9LE,  
		YUVA444P9BE = ffmpeg::AV_PIX_FMT_YUVA444P9BE,  
		YUVA444P9LE = ffmpeg::AV_PIX_FMT_YUVA444P9LE,  
		YUVA420P10BE = ffmpeg::AV_PIX_FMT_YUVA420P10BE, 
		YUVA420P10LE = ffmpeg::AV_PIX_FMT_YUVA420P10LE, 
		YUVA422P10BE = ffmpeg::AV_PIX_FMT_YUVA422P10BE, 
		YUVA422P10LE = ffmpeg::AV_PIX_FMT_YUVA422P10LE, 
		YUVA444P10BE = ffmpeg::AV_PIX_FMT_YUVA444P10BE, 
		YUVA444P10LE = ffmpeg::AV_PIX_FMT_YUVA444P10LE, 
		YUVA420P16BE = ffmpeg::AV_PIX_FMT_YUVA420P16BE, 
		YUVA420P16LE = ffmpeg::AV_PIX_FMT_YUVA420P16LE, 
		YUVA422P16BE = ffmpeg::AV_PIX_FMT_YUVA422P16BE, 
		YUVA422P16LE = ffmpeg::AV_PIX_FMT_YUVA422P16LE, 
		YUVA444P16BE = ffmpeg::AV_PIX_FMT_YUVA444P16BE, 
		YUVA444P16LE = ffmpeg::AV_PIX_FMT_YUVA444P16LE, 
		VDPAU = ffmpeg::AV_PIX_FMT_VDPAU,     
		XYZ12LE = ffmpeg::AV_PIX_FMT_XYZ12LE,      
		XYZ12BE = ffmpeg::AV_PIX_FMT_XYZ12BE,      
		NV16 = ffmpeg::AV_PIX_FMT_NV16,         
		NV20LE = ffmpeg::AV_PIX_FMT_NV20LE,       
		NV20BE = ffmpeg::AV_PIX_FMT_NV20BE,       
		RGBA64BE_LIBAV = ffmpeg::AV_PIX_FMT_RGBA64BE_LIBAV,     
		RGBA64LE_LIBAV = ffmpeg::AV_PIX_FMT_RGBA64LE_LIBAV,     
		BGRA64BE_LIBAV = ffmpeg::AV_PIX_FMT_BGRA64BE_LIBAV,     
		BGRA64LE_LIBAV = ffmpeg::AV_PIX_FMT_BGRA64LE_LIBAV,     
		YVYU422 = ffmpeg::AV_PIX_FMT_YVYU422,   
		VDA = ffmpeg::AV_PIX_FMT_VDA,          
		YA16BE = ffmpeg::AV_PIX_FMT_YA16BE,       
		YA16LE = ffmpeg::AV_PIX_FMT_YA16LE,       
		GBRAP_LIBAV = ffmpeg::AV_PIX_FMT_GBRAP_LIBAV,        
		GBRAP16BE_LIBAV = ffmpeg::AV_PIX_FMT_GBRAP16BE_LIBAV,    
		GBRAP16LE_LIBAV = ffmpeg::AV_PIX_FMT_GBRAP16LE_LIBAV,    
		QSV = ffmpeg::AV_PIX_FMT_QSV,
		MMAL = ffmpeg::AV_PIX_FMT_MMAL,
		RGBA64BE = ffmpeg::AV_PIX_FMT_RGBA64BE,  
		RGBA64LE = ffmpeg::AV_PIX_FMT_RGBA64LE,  
		BGRA64BE = ffmpeg::AV_PIX_FMT_BGRA64BE,  
		BGRA64LE = ffmpeg::AV_PIX_FMT_BGRA64LE,  
 		ZeroRGB = ffmpeg::AV_PIX_FMT_0RGB,
		RGB0 = ffmpeg::AV_PIX_FMT_RGB0,        
		ZeroBGR = ffmpeg::AV_PIX_FMT_0BGR,        
		BGR0 = ffmpeg::AV_PIX_FMT_BGR0,        
		YUVA444P = ffmpeg::AV_PIX_FMT_YUVA444P,  
		YUVA422P = ffmpeg::AV_PIX_FMT_YUVA422P,  
		YUV420P12BE = ffmpeg::AV_PIX_FMT_YUV420P12BE, 
		YUV420P12LE = ffmpeg::AV_PIX_FMT_YUV420P12LE, 
		YUV420P14BE = ffmpeg::AV_PIX_FMT_YUV420P14BE, 
		YUV420P14LE = ffmpeg::AV_PIX_FMT_YUV420P14LE, 
		YUV422P12BE = ffmpeg::AV_PIX_FMT_YUV422P12BE, 
		YUV422P12LE = ffmpeg::AV_PIX_FMT_YUV422P12LE, 
		YUV422P14BE = ffmpeg::AV_PIX_FMT_YUV422P14BE, 
		YUV422P14LE = ffmpeg::AV_PIX_FMT_YUV422P14LE, 
		YUV444P12BE = ffmpeg::AV_PIX_FMT_YUV444P12BE, 
		YUV444P12LE = ffmpeg::AV_PIX_FMT_YUV444P12LE, 
		YUV444P14BE = ffmpeg::AV_PIX_FMT_YUV444P14BE, 
		YUV444P14LE = ffmpeg::AV_PIX_FMT_YUV444P14LE, 
		GBRP12BE = ffmpeg::AV_PIX_FMT_GBRP12BE,    
		GBRP12LE = ffmpeg::AV_PIX_FMT_GBRP12LE,    
		GBRP14BE = ffmpeg::AV_PIX_FMT_GBRP14BE,    
		GBRP14LE = ffmpeg::AV_PIX_FMT_GBRP14LE,    
		GBRAP = ffmpeg::AV_PIX_FMT_GBRAP,       
		GBRAP16BE = ffmpeg::AV_PIX_FMT_GBRAP16BE,   
		GBRAP16LE = ffmpeg::AV_PIX_FMT_GBRAP16LE,   
		YUVJ411P = ffmpeg::AV_PIX_FMT_YUVJ411P,    
		BAYER_BGGR8 = ffmpeg::AV_PIX_FMT_BAYER_BGGR8,    
		BAYER_RGGB8 = ffmpeg::AV_PIX_FMT_BAYER_RGGB8,    
		BAYER_GBRG8 = ffmpeg::AV_PIX_FMT_BAYER_GBRG8,    
		BAYER_GRBG8 = ffmpeg::AV_PIX_FMT_BAYER_GRBG8,    
		BAYER_BGGR16LE = ffmpeg::AV_PIX_FMT_BAYER_BGGR16LE, 
		BAYER_BGGR16BE = ffmpeg::AV_PIX_FMT_BAYER_BGGR16BE, 
		BAYER_RGGB16LE = ffmpeg::AV_PIX_FMT_BAYER_RGGB16LE, 
		BAYER_RGGB16BE = ffmpeg::AV_PIX_FMT_BAYER_RGGB16BE, 
		BAYER_GBRG16LE = ffmpeg::AV_PIX_FMT_BAYER_GBRG16LE, 
		BAYER_GBRG16BE = ffmpeg::AV_PIX_FMT_BAYER_GBRG16BE, 
		BAYER_GRBG16LE = ffmpeg::AV_PIX_FMT_BAYER_GRBG16LE, 
		BAYER_GRBG16BE = ffmpeg::AV_PIX_FMT_BAYER_GRBG16BE, 
	};

}