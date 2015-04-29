#pragma once

#include "wrapper/ffmpeg.h"

using namespace System;

namespace ffsharp
{

	public enum class AVCodecID
	{
		None = ffmpeg::AV_CODEC_ID_NONE,
		MPEG1VIDEO = ffmpeg::AV_CODEC_ID_MPEG1VIDEO,
		MPEG2VIDEO = ffmpeg::AV_CODEC_ID_MPEG2VIDEO,
#if FF_API_XVMC
		MPEG2VIDEO_XVMC = ffmpeg::AV_CODEC_ID_MPEG2VIDEO_XVMC,
#endif /* FF_API_XVMC */
		H261 = ffmpeg::AV_CODEC_ID_H261,
		H263 = ffmpeg::AV_CODEC_ID_H263,
		RV10 = ffmpeg::AV_CODEC_ID_RV10,
		RV20 = ffmpeg::AV_CODEC_ID_RV20,
		MJPEG = ffmpeg::AV_CODEC_ID_MJPEG,
		MJPEGB = ffmpeg::AV_CODEC_ID_MJPEGB,
		LJPEG = ffmpeg::AV_CODEC_ID_LJPEG,
		SP5X = ffmpeg::AV_CODEC_ID_SP5X,
		JPEGLS = ffmpeg::AV_CODEC_ID_JPEGLS,
		MPEG4 = ffmpeg::AV_CODEC_ID_MPEG4,
		RAWVIDEO = ffmpeg::AV_CODEC_ID_RAWVIDEO,
		MSMPEG4V1 = ffmpeg::AV_CODEC_ID_MSMPEG4V1,
		MSMPEG4V2 = ffmpeg::AV_CODEC_ID_MSMPEG4V2,
		MSMPEG4V3 = ffmpeg::AV_CODEC_ID_MSMPEG4V3,
		WMV1 = ffmpeg::AV_CODEC_ID_WMV1,
		WMV2 = ffmpeg::AV_CODEC_ID_WMV2,
		H263P = ffmpeg::AV_CODEC_ID_H263P,
		H263I = ffmpeg::AV_CODEC_ID_H263I,
		FLV1 = ffmpeg::AV_CODEC_ID_FLV1,
		SVQ1 = ffmpeg::AV_CODEC_ID_SVQ1,
		SVQ3 = ffmpeg::AV_CODEC_ID_SVQ3,
		DVVIDEO = ffmpeg::AV_CODEC_ID_DVVIDEO,
		HUFFYUV = ffmpeg::AV_CODEC_ID_HUFFYUV,
		CYUV = ffmpeg::AV_CODEC_ID_CYUV,
		H264 = ffmpeg::AV_CODEC_ID_H264,
		INDEO3 = ffmpeg::AV_CODEC_ID_INDEO3,
		VP3 = ffmpeg::AV_CODEC_ID_VP3,
		THEORA = ffmpeg::AV_CODEC_ID_THEORA,
		ASV1 = ffmpeg::AV_CODEC_ID_ASV1,
		ASV2 = ffmpeg::AV_CODEC_ID_ASV2,
		FFV1 = ffmpeg::AV_CODEC_ID_FFV1,
		FourXM = ffmpeg::AV_CODEC_ID_4XM,
		VCR1 = ffmpeg::AV_CODEC_ID_VCR1,
		CLJR = ffmpeg::AV_CODEC_ID_CLJR,
		MDEC = ffmpeg::AV_CODEC_ID_MDEC,
		ROQ = ffmpeg::AV_CODEC_ID_ROQ,
		INTERPLAY_VIDEO = ffmpeg::AV_CODEC_ID_INTERPLAY_VIDEO,
		XAN_WC3 = ffmpeg::AV_CODEC_ID_XAN_WC3,
		XAN_WC4 = ffmpeg::AV_CODEC_ID_XAN_WC4,
		RPZA = ffmpeg::AV_CODEC_ID_RPZA,
		CINEPAK = ffmpeg::AV_CODEC_ID_CINEPAK,
		WS_VQA = ffmpeg::AV_CODEC_ID_WS_VQA,
		MSRLE = ffmpeg::AV_CODEC_ID_MSRLE,
		MSVIDEO1 = ffmpeg::AV_CODEC_ID_MSVIDEO1,
		IDCIN = ffmpeg::AV_CODEC_ID_IDCIN,
		EightBPS = ffmpeg::AV_CODEC_ID_8BPS,
		SMC = ffmpeg::AV_CODEC_ID_SMC,
		FLIC = ffmpeg::AV_CODEC_ID_FLIC,
		TRUEMOTION1 = ffmpeg::AV_CODEC_ID_TRUEMOTION1,
		VMDVIDEO = ffmpeg::AV_CODEC_ID_VMDVIDEO,
		MSZH = ffmpeg::AV_CODEC_ID_MSZH,
		ZLIB = ffmpeg::AV_CODEC_ID_ZLIB,
		QTRLE = ffmpeg::AV_CODEC_ID_QTRLE,
		TSCC = ffmpeg::AV_CODEC_ID_TSCC,
		ULTI = ffmpeg::AV_CODEC_ID_ULTI,
		QDRAW = ffmpeg::AV_CODEC_ID_QDRAW,
		VIXL = ffmpeg::AV_CODEC_ID_VIXL,
		QPEG = ffmpeg::AV_CODEC_ID_QPEG,
		PNG = ffmpeg::AV_CODEC_ID_PNG,
		PPM = ffmpeg::AV_CODEC_ID_PPM,
		PBM = ffmpeg::AV_CODEC_ID_PBM,
		PGM = ffmpeg::AV_CODEC_ID_PGM,
		PGMYUV = ffmpeg::AV_CODEC_ID_PGMYUV,
		PAM = ffmpeg::AV_CODEC_ID_PAM,
		FFVHUFF = ffmpeg::AV_CODEC_ID_FFVHUFF,
		RV30 = ffmpeg::AV_CODEC_ID_RV30,
		RV40 = ffmpeg::AV_CODEC_ID_RV40,
		VC1 = ffmpeg::AV_CODEC_ID_VC1,
		WMV3 = ffmpeg::AV_CODEC_ID_WMV3,
		LOCO = ffmpeg::AV_CODEC_ID_LOCO,
		WNV1 = ffmpeg::AV_CODEC_ID_WNV1,
		AASC = ffmpeg::AV_CODEC_ID_AASC,
		INDEO2 = ffmpeg::AV_CODEC_ID_INDEO2,
		FRAPS = ffmpeg::AV_CODEC_ID_FRAPS,
		TRUEMOTION2 = ffmpeg::AV_CODEC_ID_TRUEMOTION2,
		BMP = ffmpeg::AV_CODEC_ID_BMP,
		CSCD = ffmpeg::AV_CODEC_ID_CSCD,
		MMVIDEO = ffmpeg::AV_CODEC_ID_MMVIDEO,
		ZMBV = ffmpeg::AV_CODEC_ID_ZMBV,
		AVS = ffmpeg::AV_CODEC_ID_AVS,
		SMACKVIDEO = ffmpeg::AV_CODEC_ID_SMACKVIDEO,
		NUV = ffmpeg::AV_CODEC_ID_NUV,
		KMVC = ffmpeg::AV_CODEC_ID_KMVC,
		FLASHSV = ffmpeg::AV_CODEC_ID_FLASHSV,
		CAVS = ffmpeg::AV_CODEC_ID_CAVS,
		JPEG2000 = ffmpeg::AV_CODEC_ID_JPEG2000,
		VMNC = ffmpeg::AV_CODEC_ID_VMNC,
		VP5 = ffmpeg::AV_CODEC_ID_VP5,
		VP6 = ffmpeg::AV_CODEC_ID_VP6,
		VP6F = ffmpeg::AV_CODEC_ID_VP6F,
		TARGA = ffmpeg::AV_CODEC_ID_TARGA,
		DSICINVIDEO = ffmpeg::AV_CODEC_ID_DSICINVIDEO,
		TIERTEXSEQVIDEO = ffmpeg::AV_CODEC_ID_TIERTEXSEQVIDEO,
		TIFF = ffmpeg::AV_CODEC_ID_TIFF,
		GIF = ffmpeg::AV_CODEC_ID_GIF,
		DXA = ffmpeg::AV_CODEC_ID_DXA,
		DNXHD = ffmpeg::AV_CODEC_ID_DNXHD,
		THP = ffmpeg::AV_CODEC_ID_THP,
		SGI = ffmpeg::AV_CODEC_ID_SGI,
		C93 = ffmpeg::AV_CODEC_ID_C93,
		BETHSOFTVID = ffmpeg::AV_CODEC_ID_BETHSOFTVID,
		PTX = ffmpeg::AV_CODEC_ID_PTX,
		TXD = ffmpeg::AV_CODEC_ID_TXD,
		VP6A = ffmpeg::AV_CODEC_ID_VP6A,
		AMV = ffmpeg::AV_CODEC_ID_AMV,
		VB = ffmpeg::AV_CODEC_ID_VB,
		PCX = ffmpeg::AV_CODEC_ID_PCX,
		SUNRAST = ffmpeg::AV_CODEC_ID_SUNRAST,
		INDEO4 = ffmpeg::AV_CODEC_ID_INDEO4,
		INDEO5 = ffmpeg::AV_CODEC_ID_INDEO5,
		MIMIC = ffmpeg::AV_CODEC_ID_MIMIC,
		RL2 = ffmpeg::AV_CODEC_ID_RL2,
		ESCAPE124 = ffmpeg::AV_CODEC_ID_ESCAPE124,
		DIRAC = ffmpeg::AV_CODEC_ID_DIRAC,
		BFI = ffmpeg::AV_CODEC_ID_BFI,
		CMV = ffmpeg::AV_CODEC_ID_CMV,
		MOTIONPIXELS = ffmpeg::AV_CODEC_ID_MOTIONPIXELS,
		TGV = ffmpeg::AV_CODEC_ID_TGV,
		TGQ = ffmpeg::AV_CODEC_ID_TGQ,
		TQI = ffmpeg::AV_CODEC_ID_TQI,
		AURA = ffmpeg::AV_CODEC_ID_AURA,
		AURA2 = ffmpeg::AV_CODEC_ID_AURA2,
		V210X = ffmpeg::AV_CODEC_ID_V210X,
		TMV = ffmpeg::AV_CODEC_ID_TMV,
		V210 = ffmpeg::AV_CODEC_ID_V210,
		DPX = ffmpeg::AV_CODEC_ID_DPX,
		MAD = ffmpeg::AV_CODEC_ID_MAD,
		FRWU = ffmpeg::AV_CODEC_ID_FRWU,
		FLASHSV2 = ffmpeg::AV_CODEC_ID_FLASHSV2,
		CDGRAPHICS = ffmpeg::AV_CODEC_ID_CDGRAPHICS,
		R210 = ffmpeg::AV_CODEC_ID_R210,
		ANM = ffmpeg::AV_CODEC_ID_ANM,
		BINKVIDEO = ffmpeg::AV_CODEC_ID_BINKVIDEO,
		IFF_ILBM = ffmpeg::AV_CODEC_ID_IFF_ILBM,
		IFF_BYTERUN1 = ffmpeg::AV_CODEC_ID_IFF_BYTERUN1,
		KGV1 = ffmpeg::AV_CODEC_ID_KGV1,
		YOP = ffmpeg::AV_CODEC_ID_YOP,
		VP8 = ffmpeg::AV_CODEC_ID_VP8,
		PICTOR = ffmpeg::AV_CODEC_ID_PICTOR,
		ANSI = ffmpeg::AV_CODEC_ID_ANSI,
		A64_MULTI = ffmpeg::AV_CODEC_ID_A64_MULTI,
		A64_MULTI5 = ffmpeg::AV_CODEC_ID_A64_MULTI5,
		R10K = ffmpeg::AV_CODEC_ID_R10K,
		MXPEG = ffmpeg::AV_CODEC_ID_MXPEG,
		LAGARITH = ffmpeg::AV_CODEC_ID_LAGARITH,
		PRORES = ffmpeg::AV_CODEC_ID_PRORES,
		JV = ffmpeg::AV_CODEC_ID_JV,
		DFA = ffmpeg::AV_CODEC_ID_DFA,
		WMV3IMAGE = ffmpeg::AV_CODEC_ID_WMV3IMAGE,
		VC1IMAGE = ffmpeg::AV_CODEC_ID_VC1IMAGE,
		UTVIDEO = ffmpeg::AV_CODEC_ID_UTVIDEO,
		BMV_VIDEO = ffmpeg::AV_CODEC_ID_BMV_VIDEO,
		VBLE = ffmpeg::AV_CODEC_ID_VBLE,
		DXTORY = ffmpeg::AV_CODEC_ID_DXTORY,
		V410 = ffmpeg::AV_CODEC_ID_V410,
		XWD = ffmpeg::AV_CODEC_ID_XWD,
		CDXL = ffmpeg::AV_CODEC_ID_CDXL,
		XBM = ffmpeg::AV_CODEC_ID_XBM,
		ZEROCODEC = ffmpeg::AV_CODEC_ID_ZEROCODEC,
		MSS1 = ffmpeg::AV_CODEC_ID_MSS1,
		MSA1 = ffmpeg::AV_CODEC_ID_MSA1,
		TSCC2 = ffmpeg::AV_CODEC_ID_TSCC2,
		MTS2 = ffmpeg::AV_CODEC_ID_MTS2,
		CLLC = ffmpeg::AV_CODEC_ID_CLLC,
		MSS2 = ffmpeg::AV_CODEC_ID_MSS2,
		VP9 = ffmpeg::AV_CODEC_ID_VP9,
		AIC = ffmpeg::AV_CODEC_ID_AIC,
		ESCAPE130_DEPRECATED = ffmpeg::AV_CODEC_ID_ESCAPE130_DEPRECATED,
		G2M_DEPRECATED = ffmpeg::AV_CODEC_ID_G2M_DEPRECATED,
		WEBP_DEPRECATED = ffmpeg::AV_CODEC_ID_WEBP_DEPRECATED,
		HNM4_VIDEO = ffmpeg::AV_CODEC_ID_HNM4_VIDEO,
		HEVC_DEPRECATED = ffmpeg::AV_CODEC_ID_HEVC_DEPRECATED,
		FIC = ffmpeg::AV_CODEC_ID_FIC,
		ALIAS_PIX = ffmpeg::AV_CODEC_ID_ALIAS_PIX,
		BRENDER_PIX_DEPRECATED = ffmpeg::AV_CODEC_ID_BRENDER_PIX_DEPRECATED,
		PAF_VIDEO_DEPRECATED = ffmpeg::AV_CODEC_ID_PAF_VIDEO_DEPRECATED,
		EXR_DEPRECATED = ffmpeg::AV_CODEC_ID_EXR_DEPRECATED,
		VP7_DEPRECATED = ffmpeg::AV_CODEC_ID_VP7_DEPRECATED,
		SANM_DEPRECATED = ffmpeg::AV_CODEC_ID_SANM_DEPRECATED,
		SGIRLE_DEPRECATED = ffmpeg::AV_CODEC_ID_SGIRLE_DEPRECATED,
		MVC1_DEPRECATED = ffmpeg::AV_CODEC_ID_MVC1_DEPRECATED,
		MVC2_DEPRECATED = ffmpeg::AV_CODEC_ID_MVC2_DEPRECATED,
		HQX = ffmpeg::AV_CODEC_ID_HQX,
		TDSC = ffmpeg::AV_CODEC_ID_TDSC,
		HQ_HQA = ffmpeg::AV_CODEC_ID_HQ_HQA,

		BRENDER_PIX = ffmpeg::AV_CODEC_ID_BRENDER_PIX,
		Y41P = ffmpeg::AV_CODEC_ID_Y41P,
		ESCAPE130 = ffmpeg::AV_CODEC_ID_ESCAPE130,
		EXR = ffmpeg::AV_CODEC_ID_EXR,
		AVRP = ffmpeg::AV_CODEC_ID_AVRP,

		Zero12V = ffmpeg::AV_CODEC_ID_012V,
		G2M = ffmpeg::AV_CODEC_ID_G2M,
		AVUI = ffmpeg::AV_CODEC_ID_AVUI,
		AYUV = ffmpeg::AV_CODEC_ID_AYUV,
		TARGA_Y216 = ffmpeg::AV_CODEC_ID_TARGA_Y216,
		V308 = ffmpeg::AV_CODEC_ID_V308,
		V408 = ffmpeg::AV_CODEC_ID_V408,
		YUV4 = ffmpeg::AV_CODEC_ID_YUV4,
		SANM = ffmpeg::AV_CODEC_ID_SANM,
		PAF_VIDEO = ffmpeg::AV_CODEC_ID_PAF_VIDEO,
		AVRN = ffmpeg::AV_CODEC_ID_AVRN,
		CPIA = ffmpeg::AV_CODEC_ID_CPIA,
		XFACE = ffmpeg::AV_CODEC_ID_XFACE,
		SGIRLE = ffmpeg::AV_CODEC_ID_SGIRLE,
		MVC1 = ffmpeg::AV_CODEC_ID_MVC1,
		MVC2 = ffmpeg::AV_CODEC_ID_MVC2,
		SNOW = ffmpeg::AV_CODEC_ID_SNOW,
		WEBP = ffmpeg::AV_CODEC_ID_WEBP,
		SMVJPEG = ffmpeg::AV_CODEC_ID_SMVJPEG,
		HEVC = ffmpeg::AV_CODEC_ID_HEVC,
		VP7 = ffmpeg::AV_CODEC_ID_VP7,
		APNG = ffmpeg::AV_CODEC_ID_APNG,
		PCM_S16LE = ffmpeg::AV_CODEC_ID_PCM_S16LE,
		PCM_S16BE = ffmpeg::AV_CODEC_ID_PCM_S16BE,
		PCM_U16LE = ffmpeg::AV_CODEC_ID_PCM_U16LE,
		PCM_U16BE = ffmpeg::AV_CODEC_ID_PCM_U16BE,
		PCM_S8 = ffmpeg::AV_CODEC_ID_PCM_S8,
		PCM_U8 = ffmpeg::AV_CODEC_ID_PCM_U8,
		PCM_MULAW = ffmpeg::AV_CODEC_ID_PCM_MULAW,
		PCM_ALAW = ffmpeg::AV_CODEC_ID_PCM_ALAW,
		PCM_S32LE = ffmpeg::AV_CODEC_ID_PCM_S32LE,
		PCM_S32BE = ffmpeg::AV_CODEC_ID_PCM_S32BE,
		PCM_U32LE = ffmpeg::AV_CODEC_ID_PCM_U32LE,
		PCM_U32BE = ffmpeg::AV_CODEC_ID_PCM_U32BE,
		PCM_S24LE = ffmpeg::AV_CODEC_ID_PCM_S24LE,
		PCM_S24BE = ffmpeg::AV_CODEC_ID_PCM_S24BE,
		PCM_U24LE = ffmpeg::AV_CODEC_ID_PCM_U24LE,
		PCM_U24BE = ffmpeg::AV_CODEC_ID_PCM_U24BE,
		PCM_S24DAUD = ffmpeg::AV_CODEC_ID_PCM_S24DAUD,
		PCM_ZORK = ffmpeg::AV_CODEC_ID_PCM_ZORK,
		PCM_S16LE_PLANAR = ffmpeg::AV_CODEC_ID_PCM_S16LE_PLANAR,
		PCM_DVD = ffmpeg::AV_CODEC_ID_PCM_DVD,
		PCM_F32BE = ffmpeg::AV_CODEC_ID_PCM_F32BE,
		PCM_F32LE = ffmpeg::AV_CODEC_ID_PCM_F32LE,
		PCM_F64BE = ffmpeg::AV_CODEC_ID_PCM_F64BE,
		PCM_F64LE = ffmpeg::AV_CODEC_ID_PCM_F64LE,
		PCM_BLURAY = ffmpeg::AV_CODEC_ID_PCM_BLURAY,
		PCM_LXF = ffmpeg::AV_CODEC_ID_PCM_LXF,
		S302M = ffmpeg::AV_CODEC_ID_S302M,
		PCM_S8_PLANAR = ffmpeg::AV_CODEC_ID_PCM_S8_PLANAR,
		PCM_S24LE_PLANAR_DEPRECATED = ffmpeg::AV_CODEC_ID_PCM_S24LE_PLANAR_DEPRECATED,
		PCM_S32LE_PLANAR_DEPRECATED = ffmpeg::AV_CODEC_ID_PCM_S32LE_PLANAR_DEPRECATED,
		PCM_S24LE_PLANAR = ffmpeg::AV_CODEC_ID_PCM_S24LE_PLANAR,
		PCM_S32LE_PLANAR = ffmpeg::AV_CODEC_ID_PCM_S32LE_PLANAR,
		PCM_S16BE_PLANAR = ffmpeg::AV_CODEC_ID_PCM_S16BE_PLANAR,
		ADPCM_IMA_QT = ffmpeg::AV_CODEC_ID_ADPCM_IMA_QT,
		ADPCM_IMA_WAV = ffmpeg::AV_CODEC_ID_ADPCM_IMA_WAV,
		ADPCM_IMA_DK3 = ffmpeg::AV_CODEC_ID_ADPCM_IMA_DK3,
		ADPCM_IMA_DK4 = ffmpeg::AV_CODEC_ID_ADPCM_IMA_DK4,
		ADPCM_IMA_WS = ffmpeg::AV_CODEC_ID_ADPCM_IMA_WS,
		ADPCM_IMA_SMJPEG = ffmpeg::AV_CODEC_ID_ADPCM_IMA_SMJPEG,
		ADPCM_MS = ffmpeg::AV_CODEC_ID_ADPCM_MS,
		ADPCM_4XM = ffmpeg::AV_CODEC_ID_ADPCM_4XM,
		ADPCM_XA = ffmpeg::AV_CODEC_ID_ADPCM_XA,
		ADPCM_ADX = ffmpeg::AV_CODEC_ID_ADPCM_ADX,
		ADPCM_EA = ffmpeg::AV_CODEC_ID_ADPCM_EA,
		ADPCM_G726 = ffmpeg::AV_CODEC_ID_ADPCM_G726,
		ADPCM_CT = ffmpeg::AV_CODEC_ID_ADPCM_CT,
		ADPCM_SWF = ffmpeg::AV_CODEC_ID_ADPCM_SWF,
		ADPCM_YAMAHA = ffmpeg::AV_CODEC_ID_ADPCM_YAMAHA,
		ADPCM_SBPRO_4 = ffmpeg::AV_CODEC_ID_ADPCM_SBPRO_4,
		ADPCM_SBPRO_3 = ffmpeg::AV_CODEC_ID_ADPCM_SBPRO_3,
		ADPCM_SBPRO_2 = ffmpeg::AV_CODEC_ID_ADPCM_SBPRO_2,
		ADPCM_THP = ffmpeg::AV_CODEC_ID_ADPCM_THP,
		ADPCM_IMA_AMV = ffmpeg::AV_CODEC_ID_ADPCM_IMA_AMV,
		ADPCM_EA_R1 = ffmpeg::AV_CODEC_ID_ADPCM_EA_R1,
		ADPCM_EA_R3 = ffmpeg::AV_CODEC_ID_ADPCM_EA_R3,
		ADPCM_EA_R2 = ffmpeg::AV_CODEC_ID_ADPCM_EA_R2,
		ADPCM_IMA_EA_SEAD = ffmpeg::AV_CODEC_ID_ADPCM_IMA_EA_SEAD,
		ADPCM_IMA_EA_EACS = ffmpeg::AV_CODEC_ID_ADPCM_IMA_EA_EACS,
		ADPCM_EA_XAS = ffmpeg::AV_CODEC_ID_ADPCM_EA_XAS,
		ADPCM_EA_MAXIS_XA = ffmpeg::AV_CODEC_ID_ADPCM_EA_MAXIS_XA,
		ADPCM_IMA_ISS = ffmpeg::AV_CODEC_ID_ADPCM_IMA_ISS,
		ADPCM_G722 = ffmpeg::AV_CODEC_ID_ADPCM_G722,
		ADPCM_IMA_APC = ffmpeg::AV_CODEC_ID_ADPCM_IMA_APC,
		ADPCM_VIMA_DEPRECATED = ffmpeg::AV_CODEC_ID_ADPCM_VIMA_DEPRECATED,
		ADPCM_VIMA = ffmpeg::AV_CODEC_ID_ADPCM_VIMA,
#if FF_API_VIMA_DECODER
		VIMA = ffmpeg::AV_CODEC_ID_VIMA,
#endif
		ADPCM_AFC = ffmpeg::AV_CODEC_ID_ADPCM_AFC,
		ADPCM_IMA_OKI = ffmpeg::AV_CODEC_ID_ADPCM_IMA_OKI,
		ADPCM_DTK = ffmpeg::AV_CODEC_ID_ADPCM_DTK,
		ADPCM_IMA_RAD = ffmpeg::AV_CODEC_ID_ADPCM_IMA_RAD,
		ADPCM_G726LE = ffmpeg::AV_CODEC_ID_ADPCM_G726LE,
		AMR_NB = ffmpeg::AV_CODEC_ID_AMR_NB,
		AMR_WB = ffmpeg::AV_CODEC_ID_AMR_WB,
		RA_144 = ffmpeg::AV_CODEC_ID_RA_144,
		RA_288 = ffmpeg::AV_CODEC_ID_RA_288,
		ROQ_DPCM = ffmpeg::AV_CODEC_ID_ROQ_DPCM,
		INTERPLAY_DPCM = ffmpeg::AV_CODEC_ID_INTERPLAY_DPCM,
		XAN_DPCM = ffmpeg::AV_CODEC_ID_XAN_DPCM,
		SOL_DPCM = ffmpeg::AV_CODEC_ID_SOL_DPCM,
		MP2 = ffmpeg::AV_CODEC_ID_MP2,
		MP3 = ffmpeg::AV_CODEC_ID_MP3, 
		AAC = ffmpeg::AV_CODEC_ID_AAC,
		AC3 = ffmpeg::AV_CODEC_ID_AC3,
		DTS = ffmpeg::AV_CODEC_ID_DTS,
		VORBIS = ffmpeg::AV_CODEC_ID_VORBIS,
		DVAUDIO = ffmpeg::AV_CODEC_ID_DVAUDIO,
		WMAV1 = ffmpeg::AV_CODEC_ID_WMAV1,
		WMAV2 = ffmpeg::AV_CODEC_ID_WMAV2,
		MACE3 = ffmpeg::AV_CODEC_ID_MACE3,
		MACE6 = ffmpeg::AV_CODEC_ID_MACE6,
		VMDAUDIO = ffmpeg::AV_CODEC_ID_VMDAUDIO,
		FLAC = ffmpeg::AV_CODEC_ID_FLAC,
		MP3ADU = ffmpeg::AV_CODEC_ID_MP3ADU,
		MP3ON4 = ffmpeg::AV_CODEC_ID_MP3ON4,
		SHORTEN = ffmpeg::AV_CODEC_ID_SHORTEN,
		ALAC = ffmpeg::AV_CODEC_ID_ALAC,
		WESTWOOD_SND1 = ffmpeg::AV_CODEC_ID_WESTWOOD_SND1,
		GSM = ffmpeg::AV_CODEC_ID_GSM, 
		QDM2 = ffmpeg::AV_CODEC_ID_QDM2,
		COOK = ffmpeg::AV_CODEC_ID_COOK,
		TRUESPEECH = ffmpeg::AV_CODEC_ID_TRUESPEECH,
		TTA = ffmpeg::AV_CODEC_ID_TTA,
		SMACKAUDIO = ffmpeg::AV_CODEC_ID_SMACKAUDIO,
		QCELP = ffmpeg::AV_CODEC_ID_QCELP,
		WAVPACK = ffmpeg::AV_CODEC_ID_WAVPACK,
		DSICINAUDIO = ffmpeg::AV_CODEC_ID_DSICINAUDIO,
		IMC = ffmpeg::AV_CODEC_ID_IMC,
		MUSEPACK7 = ffmpeg::AV_CODEC_ID_MUSEPACK7,
		MLP = ffmpeg::AV_CODEC_ID_MLP,
		GSM_MS = ffmpeg::AV_CODEC_ID_GSM_MS,
		ATRAC3 = ffmpeg::AV_CODEC_ID_ATRAC3,
#if FF_API_VOXWARE
		VOXWARE = ffmpeg::AV_CODEC_ID_VOXWARE,
#endif
		APE = ffmpeg::AV_CODEC_ID_APE,
		NELLYMOSER = ffmpeg::AV_CODEC_ID_NELLYMOSER,
		MUSEPACK8 = ffmpeg::AV_CODEC_ID_MUSEPACK8,
		SPEEX = ffmpeg::AV_CODEC_ID_SPEEX,
		WMAVOICE = ffmpeg::AV_CODEC_ID_WMAVOICE,
		WMAPRO = ffmpeg::AV_CODEC_ID_WMAPRO,
		WMALOSSLESS = ffmpeg::AV_CODEC_ID_WMALOSSLESS,
		ATRAC3P = ffmpeg::AV_CODEC_ID_ATRAC3P,
		EAC3 = ffmpeg::AV_CODEC_ID_EAC3,
		SIPR = ffmpeg::AV_CODEC_ID_SIPR,
		MP1 = ffmpeg::AV_CODEC_ID_MP1,
		TWINVQ = ffmpeg::AV_CODEC_ID_TWINVQ,
		TRUEHD = ffmpeg::AV_CODEC_ID_TRUEHD,
		MP4ALS = ffmpeg::AV_CODEC_ID_MP4ALS,
		ATRAC1 = ffmpeg::AV_CODEC_ID_ATRAC1,
		BINKAUDIO_RDFT = ffmpeg::AV_CODEC_ID_BINKAUDIO_RDFT,
		BINKAUDIO_DCT = ffmpeg::AV_CODEC_ID_BINKAUDIO_DCT,
		AAC_LATM = ffmpeg::AV_CODEC_ID_AAC_LATM,
		QDMC = ffmpeg::AV_CODEC_ID_QDMC,
		CELT = ffmpeg::AV_CODEC_ID_CELT,
		G723_1 = ffmpeg::AV_CODEC_ID_G723_1,
		G729 = ffmpeg::AV_CODEC_ID_G729,
		EightSVX_EXP = ffmpeg::AV_CODEC_ID_8SVX_EXP,
		EightSVX_FIB = ffmpeg::AV_CODEC_ID_8SVX_FIB,
		BMV_AUDIO = ffmpeg::AV_CODEC_ID_BMV_AUDIO,
		RALF = ffmpeg::AV_CODEC_ID_RALF,
		IAC = ffmpeg::AV_CODEC_ID_IAC,
		ILBC = ffmpeg::AV_CODEC_ID_ILBC,
		OPUS_DEPRECATED = ffmpeg::AV_CODEC_ID_OPUS_DEPRECATED,
		COMFORT_NOISE = ffmpeg::AV_CODEC_ID_COMFORT_NOISE,
		TAK_DEPRECATED = ffmpeg::AV_CODEC_ID_TAK_DEPRECATED,
		METASOUND = ffmpeg::AV_CODEC_ID_METASOUND,
		PAF_AUDIO_DEPRECATED = ffmpeg::AV_CODEC_ID_PAF_AUDIO_DEPRECATED,
		ON2AVC = ffmpeg::AV_CODEC_ID_ON2AVC,
		DSS_SP = ffmpeg::AV_CODEC_ID_DSS_SP,
		FFWAVESYNTH = ffmpeg::AV_CODEC_ID_FFWAVESYNTH,
		SONIC = ffmpeg::AV_CODEC_ID_SONIC,
		SONIC_LS = ffmpeg::AV_CODEC_ID_SONIC_LS,
		PAF_AUDIO = ffmpeg::AV_CODEC_ID_PAF_AUDIO,
		OPUS = ffmpeg::AV_CODEC_ID_OPUS,
		TAK = ffmpeg::AV_CODEC_ID_TAK,
		EVRC = ffmpeg::AV_CODEC_ID_EVRC,
		SMV = ffmpeg::AV_CODEC_ID_SMV,
		DSD_LSBF = ffmpeg::AV_CODEC_ID_DSD_LSBF,
		DSD_MSBF = ffmpeg::AV_CODEC_ID_DSD_MSBF,
		DSD_LSBF_PLANAR = ffmpeg::AV_CODEC_ID_DSD_LSBF_PLANAR,
		DSD_MSBF_PLANAR = ffmpeg::AV_CODEC_ID_DSD_MSBF_PLANAR,
		FIRST_SUBTITLE = ffmpeg::AV_CODEC_ID_FIRST_SUBTITLE,          
		DVD_SUBTITLE = ffmpeg::AV_CODEC_ID_DVD_SUBTITLE,
		DVB_SUBTITLE = ffmpeg::AV_CODEC_ID_DVB_SUBTITLE,
		TEXT = ffmpeg::AV_CODEC_ID_TEXT,  
		XSUB = ffmpeg::AV_CODEC_ID_XSUB,
		SSA = ffmpeg::AV_CODEC_ID_SSA,
		MOV_TEXT = ffmpeg::AV_CODEC_ID_MOV_TEXT,
		HDMV_PGS_SUBTITLE = ffmpeg::AV_CODEC_ID_HDMV_PGS_SUBTITLE,
		DVB_TELETEXT = ffmpeg::AV_CODEC_ID_DVB_TELETEXT,
		SRT = ffmpeg::AV_CODEC_ID_SRT,
		MICRODVD = ffmpeg::AV_CODEC_ID_MICRODVD,
		EIA_608 = ffmpeg::AV_CODEC_ID_EIA_608,
		JACOSUB = ffmpeg::AV_CODEC_ID_JACOSUB,
		SAMI = ffmpeg::AV_CODEC_ID_SAMI,
		REALTEXT = ffmpeg::AV_CODEC_ID_REALTEXT,
		STL = ffmpeg::AV_CODEC_ID_STL,
		SUBVIEWER1 = ffmpeg::AV_CODEC_ID_SUBVIEWER1,
		SUBVIEWER = ffmpeg::AV_CODEC_ID_SUBVIEWER,
		SUBRIP = ffmpeg::AV_CODEC_ID_SUBRIP,
		WEBVTT = ffmpeg::AV_CODEC_ID_WEBVTT,
		MPL2 = ffmpeg::AV_CODEC_ID_MPL2,
		VPLAYER = ffmpeg::AV_CODEC_ID_VPLAYER,
		PJS = ffmpeg::AV_CODEC_ID_PJS,
		ASS = ffmpeg::AV_CODEC_ID_ASS,  
		FIRST_UNKNOWN = ffmpeg::AV_CODEC_ID_FIRST_UNKNOWN,           
		TTF = ffmpeg::AV_CODEC_ID_TTF,
		BINTEXT = ffmpeg::AV_CODEC_ID_BINTEXT,
		XBIN = ffmpeg::AV_CODEC_ID_XBIN,
		IDF = ffmpeg::AV_CODEC_ID_IDF,
		OTF = ffmpeg::AV_CODEC_ID_OTF,
		SMPTE_KLV = ffmpeg::AV_CODEC_ID_SMPTE_KLV,
		DVD_NAV = ffmpeg::AV_CODEC_ID_DVD_NAV,
		TIMED_ID3 = ffmpeg::AV_CODEC_ID_TIMED_ID3,
		BIN_DATA = ffmpeg::AV_CODEC_ID_BIN_DATA,
		PROBE = ffmpeg::AV_CODEC_ID_PROBE,
		MPEG2TS = ffmpeg::AV_CODEC_ID_MPEG2TS,
		MPEG4SYSTEMS = ffmpeg::AV_CODEC_ID_MPEG4SYSTEMS,
		FFMETADATA = ffmpeg::AV_CODEC_ID_FFMETADATA,
	};

}