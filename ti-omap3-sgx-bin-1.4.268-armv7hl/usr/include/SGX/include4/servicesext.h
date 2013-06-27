/*!****************************************************************************
@File			servicesext.h

@Title			services data structures, defines and prototypes required by 
				external drivers

@Author			Imagination Technologies

@date   		22 / 7 / 2004
 
@Copyright     	Copyright 2003-2004 by Imagination Technologies Limited.
                All rights reserved. No part of this software, either
                material or conceptual may be copied or distributed,
                transmitted, transcribed, stored in a retrieval system
                or translated into any human or computer language in any
                form by any means, electronic, mechanical, manual or
                other-wise, or disclosed to third parties without the
                express written permission of Imagination Technologies
                Limited, Unit 8, HomePark Industrial Estate,
                King's Langley, Hertfordshire, WD4 8LZ, U.K.

@Platform		generic

@Description	provides services data structures, defines and prototypes 
				required by external drivers

@DoxygenVer		

******************************************************************************/

/******************************************************************************
Modifications :-
$Log: servicesext.h $
*****************************************************************************/

#if !defined (__SERVICESEXT_H__)
#define __SERVICESEXT_H__

/*
 * Lock buffer read/write flags
 */
#define PVRSRV_LOCKFLG_READONLY     	(1)		/*!< The locking process will only read the locked surface */

/*!
 *****************************************************************************
 * Error values
 *****************************************************************************/
typedef enum _PVRSRV_ERROR_
{
	PVRSRV_OK								=  0,
	PVRSRV_ERROR_GENERIC					=  1,
	PVRSRV_ERROR_OUT_OF_MEMORY				=  2,
	PVRSRV_ERROR_TOO_FEW_BUFFERS			=  3,
	PVRSRV_ERROR_SYMBOL_NOT_FOUND			=  4,
	PVRSRV_ERROR_OUT_OF_HSPACE				=  5,
	PVRSRV_ERROR_INVALID_PARAMS				=  6,
	PVRSRV_ERROR_TILE_MAP_FAILED			=  7,
	PVRSRV_ERROR_INIT_FAILURE				=  8,
	PVRSRV_ERROR_CANT_REGISTER_CALLBACK 	=  9,
	PVRSRV_ERROR_INVALID_DEVICE				= 10,
	PVRSRV_ERROR_NOT_OWNER					= 11,
	PVRSRV_ERROR_BAD_MAPPING				= 12,
	PVRSRV_ERROR_TIMEOUT					= 13,
	PVRSRV_ERROR_NO_PRIMARY					= 14,
	PVRSRV_ERROR_FLIP_CHAIN_EXISTS			= 15,
	PVRSRV_ERROR_CANNOT_ACQUIRE_SYSDATA 	= 16,
	PVRSRV_ERROR_SCENE_INVALID				= 17,
	PVRSRV_ERROR_STREAM_ERROR				= 18,
	PVRSRV_ERROR_INVALID_INTERRUPT      	= 19,
	PVRSRV_ERROR_FAILED_DEPENDENCIES		= 20,
	PVRSRV_ERROR_CMD_NOT_PROCESSED			= 21,
	PVRSRV_ERROR_CMD_TOO_BIG				= 22,
	PVRSRV_ERROR_DEVICE_REGISTER_FAILED 	= 23,
	PVRSRV_ERROR_FIFO_SPACE					= 24,
	PVRSRV_ERROR_TA_RECOVERY				= 25,
	PVRSRV_ERROR_INDOSORLOWPOWER			= 26,
	PVRSRV_ERROR_TOOMANYBUFFERS				= 27,
	PVRSRV_ERROR_NOT_SUPPORTED				= 28,
	PVRSRV_ERROR_PROCESSING_BLOCKED			= 29,


	PVRSRV_ERROR_CANNOT_FLUSH_QUEUE			= 31,
	PVRSRV_ERROR_CANNOT_GET_QUEUE_SPACE		= 32,
	PVRSRV_ERROR_CANNOT_GET_RENDERDETAILS	= 33,
	PVRSRV_ERROR_RETRY						= 34,

	PVRSRV_ERROR_DDK_VERSION_MISMATCH		= 35,
	PVRSRV_ERROR_BUILD_MISMATCH				= 36,

	PVRSRV_ERROR_FORCE_I32 = 0x7fffffff

} PVRSRV_ERROR;


/*!
 *****************************************************************************
 * List of known device classes.
 *****************************************************************************/
typedef enum _PVRSRV_DEVICE_CLASS_
{
	PVRSRV_DEVICE_CLASS_3D				= 0 ,
	PVRSRV_DEVICE_CLASS_DISPLAY			= 1 ,
	PVRSRV_DEVICE_CLASS_BUFFER			= 2 ,
	PVRSRV_DEVICE_CLASS_VIDEO			= 3 ,

	PVRSRV_DEVICE_CLASS_FORCE_I32 		= 0x7fffffff

} PVRSRV_DEVICE_CLASS;


/*!
 *****************************************************************************
 *	States for power management
 *****************************************************************************/ 
typedef enum _PVRSRV_POWER_STATE_
{
	PVRSRV_POWER_Unspecified			= -1,	/*!< Unspecified : Uninitialised */
	PVRSRV_POWER_STATE_D0				= 0,	/*!< On, */
	PVRSRV_POWER_STATE_D1				= 1,	/*!< User Idle */
	PVRSRV_POWER_STATE_D2				= 2,	/*!< System Idle / sleep */
	PVRSRV_POWER_STATE_D3				= 3,	/*!< Suspend / Hibernate */
	PVRSRV_POWER_STATE_D4				= 4,	/*!< shutdown */

	PVRSRV_POWER_STATE_FORCE_I32 = 0x7fffffff

} PVR_POWER_STATE, *PPVR_POWER_STATE;


/* Power transition handler prototypes */
typedef PVRSRV_ERROR (*PFN_PRE_POWER) (IMG_HANDLE, PVR_POWER_STATE, PVR_POWER_STATE);
typedef PVRSRV_ERROR (*PFN_POST_POWER) (IMG_HANDLE, PVR_POWER_STATE, PVR_POWER_STATE);

/* Clock speed handler prototypes */
typedef PVRSRV_ERROR (*PFN_PRE_CLOCKSPEED_CHANGE) (IMG_HANDLE, IMG_BOOL, PVR_POWER_STATE);
typedef PVRSRV_ERROR (*PFN_POST_CLOCKSPEED_CHANGE) (IMG_HANDLE, IMG_BOOL, PVR_POWER_STATE);


/*!
 *****************************************************************************
 * Enumeration of all possible pixel types. 
 * Where applicable, Ordering of name is in reverse order of memory bytes. (i.e. as a word in little endian)
 * e.g. A8R8G8B8 is in memory as 4 bytes in order: BB GG RR AA
  *****************************************************************************/
typedef enum _PVRSRV_PIXEL_FORMAT_ {
	/* Basic types */
	PVRSRV_PIXEL_FORMAT_UNKNOWN			=  0,
	PVRSRV_PIXEL_FORMAT_RGB565			=  1,
	PVRSRV_PIXEL_FORMAT_RGB555			=  2,
	PVRSRV_PIXEL_FORMAT_RGB888			=  3,	/*!< 24bit */
	PVRSRV_PIXEL_FORMAT_BGR888			=  4,	/*!< 24bit */
	PVRSRV_PIXEL_FORMAT_GREY_SCALE		=  8,
	PVRSRV_PIXEL_FORMAT_PAL12			= 13,
	PVRSRV_PIXEL_FORMAT_PAL8			= 14,
	PVRSRV_PIXEL_FORMAT_PAL4			= 15,
	PVRSRV_PIXEL_FORMAT_PAL2			= 16,
	PVRSRV_PIXEL_FORMAT_PAL1			= 17,
	PVRSRV_PIXEL_FORMAT_ARGB1555		= 18,
	PVRSRV_PIXEL_FORMAT_ARGB4444		= 19, 
	PVRSRV_PIXEL_FORMAT_ARGB8888		= 20,
	PVRSRV_PIXEL_FORMAT_ABGR8888		= 21,
	PVRSRV_PIXEL_FORMAT_YV12			= 22,
	PVRSRV_PIXEL_FORMAT_I420			= 23,
    PVRSRV_PIXEL_FORMAT_IMC2            = 25,
	PVRSRV_PIXEL_FORMAT_XRGB8888,
	PVRSRV_PIXEL_FORMAT_XBGR8888,
	PVRSRV_PIXEL_FORMAT_XRGB4444,
	PVRSRV_PIXEL_FORMAT_ARGB8332,
	PVRSRV_PIXEL_FORMAT_A2RGB10,		/*!< 32bpp, 10 bits for R, G, B, 2 bits for A */
	PVRSRV_PIXEL_FORMAT_A2BGR10,		/*!< 32bpp, 10 bits for B, G, R, 2 bits for A */
	PVRSRV_PIXEL_FORMAT_P8,
	PVRSRV_PIXEL_FORMAT_L8,
	PVRSRV_PIXEL_FORMAT_A8L8,
	PVRSRV_PIXEL_FORMAT_A4L4,
	PVRSRV_PIXEL_FORMAT_L16,
	PVRSRV_PIXEL_FORMAT_L6V5U5,
	PVRSRV_PIXEL_FORMAT_V8U8,
	PVRSRV_PIXEL_FORMAT_V16U16,
	PVRSRV_PIXEL_FORMAT_QWVU8888,
	PVRSRV_PIXEL_FORMAT_XLVU8888,
	PVRSRV_PIXEL_FORMAT_QWVU16,
	PVRSRV_PIXEL_FORMAT_D16,
	PVRSRV_PIXEL_FORMAT_D24S8,
	PVRSRV_PIXEL_FORMAT_D24X8,

	/* Added to ensure TQ build */
	PVRSRV_PIXEL_FORMAT_ABGR16,
	PVRSRV_PIXEL_FORMAT_ABGR16F,
	PVRSRV_PIXEL_FORMAT_ABGR32,
	PVRSRV_PIXEL_FORMAT_ABGR32F,
	PVRSRV_PIXEL_FORMAT_B10GR11,
	PVRSRV_PIXEL_FORMAT_GR88,
	PVRSRV_PIXEL_FORMAT_BGR32,
	PVRSRV_PIXEL_FORMAT_GR32,
	PVRSRV_PIXEL_FORMAT_E5BGR9,

	/* DXT types */
	PVRSRV_PIXEL_FORMAT_DXT1,
	PVRSRV_PIXEL_FORMAT_DXT23,
	PVRSRV_PIXEL_FORMAT_DXT45,	

	/* RGB space packed formats */
	PVRSRV_PIXEL_FORMAT_R8G8_B8G8,
	PVRSRV_PIXEL_FORMAT_G8R8_G8B8,

	/* YUV space planar formats */
	PVRSRV_PIXEL_FORMAT_NV11,
	PVRSRV_PIXEL_FORMAT_NV12,

	/* YUV space packed formats */
	PVRSRV_PIXEL_FORMAT_YUY2,
	PVRSRV_PIXEL_FORMAT_YUV420,
	PVRSRV_PIXEL_FORMAT_YUV444,
	PVRSRV_PIXEL_FORMAT_VUY444,
	PVRSRV_PIXEL_FORMAT_YUYV,
	PVRSRV_PIXEL_FORMAT_YVYU,
	PVRSRV_PIXEL_FORMAT_UYVY,
	PVRSRV_PIXEL_FORMAT_VYUY,

	PVRSRV_PIXEL_FORMAT_FOURCC_ORG_UYVY, /*!< See http://www.fourcc.org/yuv.php#UYVY */
	PVRSRV_PIXEL_FORMAT_FOURCC_ORG_YUYV, /*!< See http://www.fourcc.org/yuv.php#YUYV */
	PVRSRV_PIXEL_FORMAT_FOURCC_ORG_YVYU, /*!< See http://www.fourcc.org/yuv.php#YVYU */
	PVRSRV_PIXEL_FORMAT_FOURCC_ORG_VYUY, /*!< No fourcc.org link */

	/* 4 component, 32 bits per component types */
	PVRSRV_PIXEL_FORMAT_A32B32G32R32,			/*!< type unspecified */
	PVRSRV_PIXEL_FORMAT_A32B32G32R32F,		/*!< float type */
	PVRSRV_PIXEL_FORMAT_A32B32G32R32_UINT,	/*!< uint type */
	PVRSRV_PIXEL_FORMAT_A32B32G32R32_SINT,	/*!< sint type */

	/* 3 component, 32 bits per component types */
	PVRSRV_PIXEL_FORMAT_B32G32R32,			/*!< type unspecified */
	PVRSRV_PIXEL_FORMAT_B32G32R32F,			/*!< float data */
	PVRSRV_PIXEL_FORMAT_B32G32R32_UINT,		/*!< uint data */
	PVRSRV_PIXEL_FORMAT_B32G32R32_SINT,		/*!< signed int data */

	/* 2 component, 32 bits per component types */
	PVRSRV_PIXEL_FORMAT_G32R32,			/*!< type unspecified */
	PVRSRV_PIXEL_FORMAT_G32R32F,			/*!< float */
	PVRSRV_PIXEL_FORMAT_G32R32_UINT,		/*!< uint */
	PVRSRV_PIXEL_FORMAT_G32R32_SINT,		/*!< signed int */

	/* 1 component, 32 bits per component types */
	PVRSRV_PIXEL_FORMAT_D32F,			/*!< float depth */
	PVRSRV_PIXEL_FORMAT_R32,			/*!< type unspecified */
	PVRSRV_PIXEL_FORMAT_R32F,			/*!< float type */
	PVRSRV_PIXEL_FORMAT_R32_UINT,		/*!< unsigned int type */
	PVRSRV_PIXEL_FORMAT_R32_SINT,		/*!< signed int type */

	/* 4 component, 16 bits per component types */
	PVRSRV_PIXEL_FORMAT_A16B16G16R16,			/*!< type unspecified */
	PVRSRV_PIXEL_FORMAT_A16B16G16R16F,		/*!< type float */
	PVRSRV_PIXEL_FORMAT_A16B16G16R16_SINT,	/*!< signed ints */
	PVRSRV_PIXEL_FORMAT_A16B16G16R16_SNORM,	/*!< signed normalised int */
	PVRSRV_PIXEL_FORMAT_A16B16G16R16_UINT,	/*!< unsigned ints */
	PVRSRV_PIXEL_FORMAT_A16B16G16R16_UNORM,	/*!< normalised unsigned int */

	/* 2 component, 16 bits per component types */
	PVRSRV_PIXEL_FORMAT_G16R16,			/*!< unspecified type */
	PVRSRV_PIXEL_FORMAT_G16R16F,		/*!< float type */
	PVRSRV_PIXEL_FORMAT_G16R16_UINT,	/*!< unsigned int type */
	PVRSRV_PIXEL_FORMAT_G16R16_UNORM,	/*!< unsigned normalised */
	PVRSRV_PIXEL_FORMAT_G16R16_SINT,	/*!< signed int  */
	PVRSRV_PIXEL_FORMAT_G16R16_SNORM,	/*!< signed normalised */

	/* 1 component, 16 bits per component types */
	PVRSRV_PIXEL_FORMAT_R16,			/*!< type unspecified */
	PVRSRV_PIXEL_FORMAT_R16F,			/*!< float type */
	PVRSRV_PIXEL_FORMAT_R16_UINT,		/*!< unsigned int type */
	PVRSRV_PIXEL_FORMAT_R16_UNORM,		/*!< unsigned normalised int type */
	PVRSRV_PIXEL_FORMAT_R16_SINT,		/*!< signed int type */
	PVRSRV_PIXEL_FORMAT_R16_SNORM,		/*!< signed normalised int type */

	/* 4 component, 8 bits per component types */
	PVRSRV_PIXEL_FORMAT_A8B8G8R8,		/*!< type unspecified */
	PVRSRV_PIXEL_FORMAT_A8B8G8R8_UINT,	/*!< unsigned int */
	PVRSRV_PIXEL_FORMAT_A8B8G8R8_UNORM,	/*!< normalised unsigned int */
	PVRSRV_PIXEL_FORMAT_A8B8G8R8_SINT,	/*!< signed int */
	PVRSRV_PIXEL_FORMAT_A8B8G8R8_SNORM,	/*!< normalised signed int */

	/* 2 component, 8 bits per component types */
	PVRSRV_PIXEL_FORMAT_G8R8,			/*!< type unspecified */
	PVRSRV_PIXEL_FORMAT_G8R8_UINT,		/*!< unsigned int type */
	PVRSRV_PIXEL_FORMAT_G8R8_UNORM,		/*!< unsigned int normalised */
	PVRSRV_PIXEL_FORMAT_G8R8_SINT,		/*!< signed int type */
	PVRSRV_PIXEL_FORMAT_G8R8_SNORM,		/*!< signed int normalised */

	/* 1 component, 8 bits per component types */
	PVRSRV_PIXEL_FORMAT_A8,				/*!< type unspecified, alpha channel */
	PVRSRV_PIXEL_FORMAT_R8,				/*!< type unspecified */
	PVRSRV_PIXEL_FORMAT_R8_UINT,		/*!< unsigned int */
	PVRSRV_PIXEL_FORMAT_R8_UNORM,		/*!< unsigned normalised int */
	PVRSRV_PIXEL_FORMAT_R8_SINT,		/*!< signed int */
	PVRSRV_PIXEL_FORMAT_R8_SNORM,		/*!< signed normalised int */

	/* A2RGB10 types */
	PVRSRV_PIXEL_FORMAT_A2B10G10R10,		/*!< Type unspecified */
	PVRSRV_PIXEL_FORMAT_A2B10G10R10_UNORM,	/*!< normalised unsigned int */
	PVRSRV_PIXEL_FORMAT_A2B10G10R10_UINT,	/*!< unsigned int */

	/* F11F11F10 types */
	PVRSRV_PIXEL_FORMAT_B10G11R11,		/*!< type unspecified */
	PVRSRV_PIXEL_FORMAT_B10G11R11F,		/*!< float type */

	/* esoteric types */
	PVRSRV_PIXEL_FORMAT_X24G8R32,		/*!< 64 bit, type unspecified (Usually typed to D32S8 style) */
	PVRSRV_PIXEL_FORMAT_G8R24,			/*!< 32 bit, type unspecified (Usually typed to D24S8 style) */
	PVRSRV_PIXEL_FORMAT_E5B9G9R9,			/*!< 32 bit, shared exponent (RGBE). */
	PVRSRV_PIXEL_FORMAT_R1,				/*!< 1 bit monochrome */

	PVRSRV_PIXEL_FORMAT_BC1,			/*!< 64 bit DX10 Block compression format (replaces DXT1) */
	PVRSRV_PIXEL_FORMAT_BC1_UNORM,		/*!< unsigned normalised type */
	PVRSRV_PIXEL_FORMAT_BC1_SRGB,		/*!< unsigned normalised type in sRGB space */
	PVRSRV_PIXEL_FORMAT_BC2,			/*!< 128 bit DX10 Block compression format (replaces DXT2/3) */
	PVRSRV_PIXEL_FORMAT_BC2_UNORM,		/*!< unsigned normalised type */
	PVRSRV_PIXEL_FORMAT_BC2_SRGB,		/*!< unsigned normalised type in sRGB space */
	PVRSRV_PIXEL_FORMAT_BC3,			/*!< 128 bit DX10 Block compression format (replaces DXT4/5) */
	PVRSRV_PIXEL_FORMAT_BC3_UNORM,		/*!< unsigned normalised type */
	PVRSRV_PIXEL_FORMAT_BC3_SRGB,		/*!< unsigned normalised type in sRGB space */
	PVRSRV_PIXEL_FORMAT_BC4,			/*!< 64 bit DX10 Block compression format */
	PVRSRV_PIXEL_FORMAT_BC4_UNORM,		/*!< unsigned normalised type */
	PVRSRV_PIXEL_FORMAT_BC4_SNORM,		/*!< unsigned normalised type */
	PVRSRV_PIXEL_FORMAT_BC5,			/*!< 128 bit DX10 Block compression format */
	PVRSRV_PIXEL_FORMAT_BC5_UNORM,
	PVRSRV_PIXEL_FORMAT_BC5_SNORM,

        /* ETC block compression types */
        PVRSRV_PIXEL_FORMAT_ETC1RGB,		/*!< ETC1 4 bit compression format */

	PVRSRV_PIXEL_FORMAT_FORCE_I32 = 0x7fffffff,
} PVRSRV_PIXEL_FORMAT;

/*!
 *****************************************************************************
 * Enumeration of possible alpha types. 
 *****************************************************************************/
typedef enum _PVRSRV_ALPHA_FORMAT_ {
	PVRSRV_ALPHA_FORMAT_UNKNOWN		=  0x00000000,
	PVRSRV_ALPHA_FORMAT_PRE			=  0x00000001,
	PVRSRV_ALPHA_FORMAT_NONPRE		=  0x00000002,
	PVRSRV_ALPHA_FORMAT_MASK		=  0x0000000F,
} PVRSRV_ALPHA_FORMAT;

/*!
 *****************************************************************************
 * Enumeration of possible alpha types. 
 *****************************************************************************/
typedef enum _PVRSRV_COLOURSPACE_FORMAT_ {
	PVRSRV_COLOURSPACE_FORMAT_UNKNOWN		=  0x00000000,
	PVRSRV_COLOURSPACE_FORMAT_LINEAR		=  0x00010000,
	PVRSRV_COLOURSPACE_FORMAT_NONLINEAR		=  0x00020000,
	PVRSRV_COLOURSPACE_FORMAT_MASK			=  0x000F0000,
} PVRSRV_COLOURSPACE_FORMAT;


/*
 * Drawable orientation (in degrees clockwise).
 * Opposite sense from WSEGL.
 */
typedef enum _PVRSRV_ROTATION_ {
	PVRSRV_ROTATE_0		=	0,
	PVRSRV_ROTATE_90	=	1,
	PVRSRV_ROTATE_180	=	2,
	PVRSRV_ROTATE_270	=	3,
	PVRSRV_FLIP_Y

} PVRSRV_ROTATION;

/*!
 * Flags for DisplayClassCreateSwapChain.
 */
#define PVRSRV_CREATE_SWAPCHAIN_SHARED		(1<<0)
#define PVRSRV_CREATE_SWAPCHAIN_QUERY		(1<<1)
#define PVRSRV_CREATE_SWAPCHAIN_OEMOVERLAY	(1<<2)

/*!
 *****************************************************************************
 * Structure providing implementation details for serialisation and 
 * synchronisation of operations. This is the fundamental unit on which operations
 * are synced, and would typically be included in any data structures that require
 * serialised accesses etc. e.g. MEM_INFO structures
 *
 *****************************************************************************/
/*
	Sync Data to be shared/mapped between user/kernel
*/
typedef struct _PVRSRV_SYNC_DATA_
{
	/* CPU accessible WriteOp Info */
	IMG_UINT32					ui32WriteOpsPending;
	volatile IMG_UINT32			ui32WriteOpsComplete;

	/* CPU accessible ReadOp Info */
	IMG_UINT32					ui32ReadOpsPending;
	volatile IMG_UINT32			ui32ReadOpsComplete;
	
	/* pdump specific value */
	IMG_UINT32					ui32LastOpDumpVal;
	IMG_UINT32					ui32LastReadOpDumpVal;

} PVRSRV_SYNC_DATA;

/*
	Client Sync Info structure
*/
typedef struct _PVRSRV_CLIENT_SYNC_INFO_
{
	/* mapping of the kernel sync data */
	PVRSRV_SYNC_DATA			*psSyncData;

	/*
		FIXME: these should not be accessible by clients but the HAL is 
		using them everywhere - remove when ready!!!
	*/
	/* Device accessible WriteOp Info */
	IMG_DEV_VIRTADDR		sWriteOpsCompleteDevVAddr;

	/* Device accessible ReadOp Info */
	IMG_DEV_VIRTADDR		sReadOpsCompleteDevVAddr;

	/* handle to client mapping data (OS specific) */
	IMG_HANDLE					hMappingInfo;

	/* handle to kernel sync info */
	IMG_HANDLE					hKernelSyncInfo;
	
} PVRSRV_CLIENT_SYNC_INFO, *PPVRSRV_CLIENT_SYNC_INFO;


/*! 
 *****************************************************************************
 * Resource locking structure
 *****************************************************************************/
typedef struct PVRSRV_RESOURCE_TAG 
{
	volatile IMG_UINT32 ui32Lock;
	IMG_UINT32 			ui32ID;
}PVRSRV_RESOURCE;
typedef PVRSRV_RESOURCE PVRSRV_RES_HANDLE;


/* command complete callback pfn prototype */
typedef IMG_VOID (*PFN_CMD_COMPLETE) (IMG_HANDLE);
typedef IMG_VOID (**PPFN_CMD_COMPLETE) (IMG_HANDLE);

/* private command handler prototype */
typedef IMG_BOOL (*PFN_CMD_PROC) (IMG_HANDLE, IMG_UINT32, IMG_VOID*); 
typedef IMG_BOOL (**PPFN_CMD_PROC) (IMG_HANDLE, IMG_UINT32, IMG_VOID*); 


/* 
	rectangle structure required by Lock API 
*/
typedef struct _IMG_RECT_
{
	IMG_INT32	x0;
	IMG_INT32	y0;	
	IMG_INT32	x1;	
	IMG_INT32	y1;	
}IMG_RECT;

typedef struct _IMG_RECT_16_
{
	IMG_INT16	x0;
	IMG_INT16	y0;	
	IMG_INT16	x1;	
	IMG_INT16	y1;	
}IMG_RECT_16;


/* common pfn between BC/DC */
typedef PVRSRV_ERROR (*PFN_GET_BUFFER_ADDR)(IMG_HANDLE, 
											IMG_HANDLE, 
											IMG_SYS_PHYADDR**, 
											IMG_UINT32*, 
											IMG_VOID**, 
											IMG_HANDLE*, 
											IMG_BOOL*);


/*
	Display dimension structure definition
*/
typedef struct DISPLAY_DIMS_TAG
{
	IMG_UINT32	ui32ByteStride;
	IMG_UINT32	ui32Width;
	IMG_UINT32	ui32Height;
} DISPLAY_DIMS;


/*
	Display format structure definition
*/
typedef struct DISPLAY_FORMAT_TAG
{
	/* pixel format type */
	PVRSRV_PIXEL_FORMAT		pixelformat;
} DISPLAY_FORMAT;

/*
	Display Surface Attributes structure definition
*/
typedef struct DISPLAY_SURF_ATTRIBUTES_TAG
{
	/* pixel format type */
	PVRSRV_PIXEL_FORMAT		pixelformat;
	/* dimensions information structure array */
	DISPLAY_DIMS			sDims;
} DISPLAY_SURF_ATTRIBUTES;


/*
	Display Mode information structure definition
*/
typedef struct DISPLAY_MODE_INFO_TAG
{
	/* pixel format type */
	PVRSRV_PIXEL_FORMAT		pixelformat;
	/* dimensions information structure array */
	DISPLAY_DIMS			sDims;
	/* refresh rate of the display */
	IMG_UINT32				ui32RefreshHZ;
	/* OEM specific flags */
	IMG_UINT32				ui32OEMFlags;
} DISPLAY_MODE_INFO;



#define MAX_DISPLAY_NAME_SIZE	(50) /* arbitrary choice! */

/*
	Display info structure definition
*/
typedef struct DISPLAY_INFO_TAG
{
	IMG_UINT32 ui32MaxSwapChains;
	
	IMG_UINT32 ui32MaxSwapChainBuffers;

	IMG_UINT32 ui32MinSwapInterval;

	IMG_UINT32 ui32MaxSwapInterval;

	IMG_CHAR	szDisplayName[MAX_DISPLAY_NAME_SIZE];

#if defined(SUPPORT_HW_CURSOR)
	IMG_UINT16	ui32CursorWidth;
	IMG_UINT16	ui32CursorHeight;
#endif
	
} DISPLAY_INFO;

typedef struct ACCESS_INFO_TAG
{
	IMG_UINT32		ui32Size;
	IMG_UINT32  	ui32FBPhysBaseAddress;
	IMG_UINT32		ui32FBMemAvailable;			/* size of usable FB memory */
	IMG_UINT32  	ui32SysPhysBaseAddress;
	IMG_UINT32		ui32SysSize;
	IMG_UINT32		ui32DevIRQ;
}ACCESS_INFO; 


/*
    Cursor shape structure definition
*/
typedef struct PVRSRV_CURSOR_SHAPE_TAG
{
	IMG_UINT16			ui16Width;
	IMG_UINT16			ui16Height;
	IMG_INT16			i16XHot;
	IMG_INT16			i16YHot;
	
	/* AND/XOR Mask CPU Virtual Address and Stride */
	IMG_VOID*   		pvMask;
	IMG_INT16  			i16MaskByteStride;
	
	/* Colour Surface CPU Virtual Address, Stride and pixelformat */
	IMG_VOID*			pvColour;
	IMG_INT16			i16ColourByteStride;
	PVRSRV_PIXEL_FORMAT	eColourPixelFormat; 
} PVRSRV_CURSOR_SHAPE;

/*
    Cursor info structure state present flags
*/
#define PVRSRV_SET_CURSOR_VISIBILITY	(1<<0)
#define PVRSRV_SET_CURSOR_POSITION		(1<<1)
#define PVRSRV_SET_CURSOR_SHAPE			(1<<2)
#define PVRSRV_SET_CURSOR_ROTATION		(1<<3)

/*
    Cursor info structure definition
*/
typedef struct PVRSRV_CURSOR_INFO_TAG
{
	/* state present flags word */
	IMG_UINT32 ui32Flags;
	
	/* visibility */
	IMG_BOOL bVisible;
	
	/* cursor position */
	IMG_INT16 i16XPos;
	IMG_INT16 i16YPos;
	
	/* Cursor Shape Information */
	PVRSRV_CURSOR_SHAPE sCursorShape;
	
	/* rotation mode (0,90,180,270) */
	IMG_UINT32 ui32Rotation;
 
} PVRSRV_CURSOR_INFO;


/*! 
 *****************************************************************************
 * This structure is used for OS independent registry (profile) access
 *****************************************************************************/
typedef struct _PVRSRV_REGISTRY_INFO_
{
    IMG_UINT32		ui32DevCookie;
    IMG_PCHAR		pszKey;
    IMG_PCHAR		pszValue;
    IMG_PCHAR		pszBuf;
    IMG_UINT32		ui32BufSize;
} PVRSRV_REGISTRY_INFO, *PPVRSRV_REGISTRY_INFO;


PVRSRV_ERROR IMG_CALLCONV PVRSRVReadRegistryString (PPVRSRV_REGISTRY_INFO psRegInfo);
PVRSRV_ERROR IMG_CALLCONV PVRSRVWriteRegistryString (PPVRSRV_REGISTRY_INFO psRegInfo);


#define PVRSRV_BC_FLAGS_YUVCSC_CONFORMANT_RANGE	(0 << 0)
#define PVRSRV_BC_FLAGS_YUVCSC_FULL_RANGE		(1 << 0)

#define PVRSRV_BC_FLAGS_YUVCSC_BT601			(0 << 1)
#define PVRSRV_BC_FLAGS_YUVCSC_BT709			(1 << 1)

/* buffer information structure */
typedef struct BUFFER_INFO_TAG
{
	IMG_UINT32 			ui32BufferCount;
	IMG_UINT32			ui32BufferDeviceID;
	PVRSRV_PIXEL_FORMAT	pixelformat;
	IMG_UINT32			ui32ByteStride;
	IMG_UINT32			ui32Width;
	IMG_UINT32			ui32Height;
	IMG_UINT32			ui32Flags;
} BUFFER_INFO;

typedef enum _OVERLAY_DEINTERLACE_MODE_
{
	WEAVE=0x0,
	BOB_ODD,
	BOB_EVEN,
	BOB_EVEN_NONINTERLEAVED
} OVERLAY_DEINTERLACE_MODE;

#endif /* __SERVICESEXT_H__ */
/*****************************************************************************
 End of file (servicesext.h)
*****************************************************************************/
