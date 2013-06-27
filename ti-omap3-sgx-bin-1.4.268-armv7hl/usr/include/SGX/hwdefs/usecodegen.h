/*****************************************************************************
 Name			: usecodegen.h
 
 Title			: USE instruction generation functions.
 
 C Author 		: Christopher James Plant
 
 Created  		: 12/01/2005
 
 Copyright		: 2006 by Imagination Technologies Limited. All rights reserved.
				  No part of this software, either material or conceptual	
				  may be copied or distributed, transmitted, transcribed,
				  stored in a retrieval system or translated into any	
				  human or computer language in any form by any means,
				  electronic, mechanical, manual or other-wise, or 
				  disclosed to third parties without the express written
				  permission of Imagination Technologies Limited, HomePark
				  Industrial Estate, King's Langley, Hertfordshire,
				  WD4 8LZ, U.K.

 Description 	: A bunch of inline functions for generating USE instruction words.
   
 Program Type	: 32-bit DLL

 Version	 	: $Revision: 1.15 $

 Modifications	:
 $Log: usecodegen.h $
 
*****************************************************************************/

#ifndef _usecodegen_h_
#define _usecodegen_h_

#include "pvr_debug.h"

/*
	USE instruction typedef
*/
typedef struct _PVR_USE_INST_
{
	IMG_UINT32	ui32Word0;
	IMG_UINT32	ui32Word1;
} PVR_USE_INST, *PPVR_USE_INST;

/*
	Internal (source/dest independent) register-types passed to USE instruction
	setup macros.
*/
typedef enum _USE_REGTYPE_
{
	USE_REGTYPE_TEMP		= 0,
	USE_REGTYPE_PRIMATTR	= 1,
	USE_REGTYPE_SECATTR		= 2,
	USE_REGTYPE_OUTPUT		= 3,
	USE_REGTYPE_FPINTERNAL	= 4,
	USE_REGTYPE_INDEXED		= 5,
	USE_REGTYPE_IDX			= 6,
	USE_REGTYPE_SPECIAL		= 7,
	USE_REGTYPE_IMMEDIATE	= 8
} USE_REGTYPE, *PUSE_REGTYPE;

/*
	Tables to map USE_REGTYPE to USE-instruction destination register bank types.
*/
static const IMG_UINT32 aui32RegTypeToUSE1DestBank[] = 
{
	EURASIA_USE1_D1STDBANK_TEMP,			/* USE_REGTYPE_TEMP		*/
	EURASIA_USE1_D1STDBANK_PRIMATTR,		/* USE_REGTYPE_PA			*/
	EURASIA_USE1_D1EXTBANK_SECATTR,			/* USE_REGTYPE_SA			*/
	EURASIA_USE1_D1STDBANK_OUTPUT,			/* USE_REGTYPE_OUTPUT		*/
	EURASIA_USE1_D1EXTBANK_FPINTERNAL,		/* USE_REGTYPE_FPINTERNAL	*/
	EURASIA_USE1_D1STDBANK_INDEXED,			/* USE_REGTYPE_INDEXED	*/	
	EURASIA_USE1_D1EXTBANK_INDEX,			/* USE_REGTYPE_IDX		*/	
	EURASIA_USE1_D1EXTBANK_SPECIAL,			/* USE_REGTYPE_SPECIAL	*/	
	0										/* USE_REGTYPE_IMMEDIATE	*/
};

static const IMG_UINT32 aui32RegTypeToUSE1DestBExt[] = 
{
	0,						/* USE_REGTYPE_TEMP		*/
	0,						/* USE_REGTYPE_PA			*/	
	EURASIA_USE1_DBEXT,		/* USE_REGTYPE_SA			*/	
	0,						/* USE_REGTYPE_OUTPUT		*/	
	EURASIA_USE1_DBEXT,		/* USE_REGTYPE_FPINTERNAL	*/	
	0,						/* USE_REGTYPE_INDEXED	*/	
	EURASIA_USE1_DBEXT,		/* USE_REGTYPE_IDX		*/	
	EURASIA_USE1_DBEXT,		/* USE_REGTYPE_SPECIAL	*/	
	0						/* USE_REGTYPE_IMMEDIATE	*/	
};

/*
	Tables to map USE_REGTYPE to USE-instruction source 0 register bank types.
*/
static const IMG_UINT32 aui32RegTypeToUSE1Src0Bank[] = 
{
	EURASIA_USE1_S0STDBANK_TEMP,		/* USE_REGTYPE_TEMP		*/
	EURASIA_USE1_S0STDBANK_PRIMATTR,	/* USE_REGTYPE_PA			*/	
	EURASIA_USE1_S0EXTBANK_SECATTR,		/* USE_REGTYPE_SA			*/	
	EURASIA_USE1_S0EXTBANK_OUTPUT,		/* USE_REGTYPE_OUTPUT		*/	
	0,									/* USE_REGTYPE_FPINTERNAL	*/	
	0,									/* USE_REGTYPE_INDEXED	*/	
	0,									/* USE_REGTYPE_IDX		*/	
	0,									/* USE_REGTYPE_SPECIAL	*/	
	0									/* USE_REGTYPE_IMMEDIATE	*/	
};

static const IMG_UINT32 aui32RegTypeToUSE1Src0BExt[] = 
{
	0,						/* USE_REGTYPE_TEMP		*/
	0,						/* USE_REGTYPE_PA			*/
	EURASIA_USE1_S0BEXT,	/* USE_REGTYPE_SA			*/
	EURASIA_USE1_S0BEXT,	/* USE_REGTYPE_OUTPUT		*/
	0,						/* USE_REGTYPE_FPINTERNAL	*/
	0,						/* USE_REGTYPE_INDEXED	*/
	0,						/* USE_REGTYPE_IDX		*/
	0,						/* USE_REGTYPE_SPECIAL	*/
	0						/* USE_REGTYPE_IMMEDIATE	*/
};

static const IMG_UINT32 aui32RegTypeToUSE1Src0BExt_EMIT[] = 
{
	0,						/* USE_REGTYPE_TEMP		*/
	0,						/* USE_REGTYPE_PA			*/
	EURASIA_USE1_DBEXT,		/* USE_REGTYPE_SA			*/
	EURASIA_USE1_DBEXT,		/* USE_REGTYPE_OUTPUT		*/
	0,						/* USE_REGTYPE_FPINTERNAL	*/
	0,						/* USE_REGTYPE_INDEXED	*/
	0,						/* USE_REGTYPE_IDX		*/
	0,						/* USE_REGTYPE_SPECIAL	*/
	0						/* USE_REGTYPE_IMMEDIATE	*/
};

/*
	Tables to map USE_REGTYPE to USE-instruction source 1 register bank types.
*/
static const IMG_UINT32 aui32RegTypeToUSE0Src1Bank[] = 
{
	EURASIA_USE0_S1STDBANK_TEMP,		/* USE_REGTYPE_TEMP		*/
	EURASIA_USE0_S1STDBANK_PRIMATTR,	/* USE_REGTYPE_PA			*/
	EURASIA_USE0_S1STDBANK_SECATTR,		/* USE_REGTYPE_SA			*/
	EURASIA_USE0_S1STDBANK_OUTPUT,		/* USE_REGTYPE_OUTPUT		*/
	EURASIA_USE0_S1EXTBANK_FPINTERNAL,	/* USE_REGTYPE_FPINTERNAL	*/
	EURASIA_USE0_S1EXTBANK_INDEXED,		/* USE_REGTYPE_INDEXED	*/
	0,									/* USE_REGTYPE_IDX		*/
	EURASIA_USE0_S1EXTBANK_SPECIAL,		/* USE_REGTYPE_SPECIAL	*/
	EURASIA_USE0_S1EXTBANK_IMMEDIATE	/* USE_REGTYPE_IMMEDIATE	*/
};

static const IMG_UINT32 aui32RegTypeToUSE1Src1BExt[] = 
{
	0,						/* USE_REGTYPE_TEMP		*/
	0,						/* USE_REGTYPE_PA			*/
	0,						/* USE_REGTYPE_SA			*/
	0,						/* USE_REGTYPE_OUTPUT		*/
	EURASIA_USE1_S1BEXT,	/* USE_REGTYPE_FPINTERNAL	*/
	EURASIA_USE1_S1BEXT,	/* USE_REGTYPE_INDEXED	*/
	0,						/* USE_REGTYPE_IDX		*/
	EURASIA_USE1_S1BEXT,	/* USE_REGTYPE_SPECIAL	*/
	EURASIA_USE1_S1BEXT		/* USE_REGTYPE_IMMEDIATE	*/
};

/*
	Tables to map USE_REGTYPE to USE-instruction source 2 register bank types.
*/
static const IMG_UINT32 aui32RegTypeToUSE0Src2Bank[] = 
{
	EURASIA_USE0_S2STDBANK_TEMP,		/* USE_REGTYPE_TEMP		*/
	EURASIA_USE0_S2STDBANK_PRIMATTR,	/* USE_REGTYPE_PA			*/	
	EURASIA_USE0_S2STDBANK_SECATTR,		/* USE_REGTYPE_SA			*/	
	EURASIA_USE0_S2STDBANK_OUTPUT,		/* USE_REGTYPE_OUTPUT		*/	
	EURASIA_USE0_S2EXTBANK_FPINTERNAL,	/* USE_REGTYPE_FPINTERNAL	*/	
	EURASIA_USE0_S2EXTBANK_INDEXED,		/* USE_REGTYPE_INDEXED	*/	
	0,									/* USE_REGTYPE_IDX		*/	
	EURASIA_USE0_S2EXTBANK_SPECIAL,		/* USE_REGTYPE_SPECIAL	*/	
	EURASIA_USE0_S2EXTBANK_IMMEDIATE	/* USE_REGTYPE_IMMEDIATE	*/	
};

static const IMG_UINT32 aui32RegTypeToUSE1Src2BExt[] = 
{
	0,						/* USE_REGTYPE_TEMP		*/
	0,						/* USE_REGTYPE_PA			*/
	0,						/* USE_REGTYPE_SA			*/
	0,						/* USE_REGTYPE_OUTPUT		*/
	EURASIA_USE1_S2BEXT,	/* USE_REGTYPE_FPINTERNAL	*/
	EURASIA_USE1_S2BEXT,	/* USE_REGTYPE_INDEXED	*/
	0,						/* USE_REGTYPE_IDX		*/
	EURASIA_USE1_S2BEXT,	/* USE_REGTYPE_SPECIAL	*/
	EURASIA_USE1_S2BEXT		/* USE_REGTYPE_IMMEDIATE	*/
};

static const IMG_UINT32 aui32RegTypeToLDDestBank[] = 
{
	EURASIA_USE1_LDST_DBANK_TEMP,		/* USE_REGTYPE_TEMP		*/
	EURASIA_USE1_LDST_DBANK_PRIMATTR,	/* USE_REGTYPE_PA			*/
	0,									/* USE_REGTYPE_SA			*/
	0,									/* USE_REGTYPE_OUTPUT		*/
	0,									/* USE_REGTYPE_FPINTERNAL	*/
	0,									/* USE_REGTYPE_INDEXED	*/
	0,									/* USE_REGTYPE_IDX		*/
	0,									/* USE_REGTYPE_SPECIAL	*/
	0									/* USE_REGTYPE_IMMEDIATE	*/
};


/* Define for number of bytes between consecutive code base registers */
#define SGX_USE_CODE_SEGMENT_RANGE_BITS		19

#ifdef INLINE_IS_PRAGMA
#pragma inline(SetUSEExecutionAddress)
#endif
FORCE_INLINE IMG_VOID SetUSEExecutionAddress(IMG_UINT32 *pui32DOutU,
											 IMG_UINT32 ui32Phase, 
											 IMG_DEV_VIRTADDR uExecutionAddress,
											 IMG_DEV_VIRTADDR uCodeHeapBase,
											 IMG_UINT32 ui32CodeHeapBaseIndex)
{
	IMG_UINT32 ui32CodeBaseReg;
	IMG_UINT32 ui32ExeAddr;
#if !defined(SGX_FEATURE_USE_UNLIMITED_PHASES)
    IMG_UINT32 ui32CodeOffset;
#endif /* !defined(SGX_FEATURE_USE_UNLIMITED_PHASES) */

	ui32CodeBaseReg = (uExecutionAddress.uiAddr - uCodeHeapBase.uiAddr) >> SGX_USE_CODE_SEGMENT_RANGE_BITS;
	ui32ExeAddr = uExecutionAddress.uiAddr - uCodeHeapBase.uiAddr - (ui32CodeBaseReg << SGX_USE_CODE_SEGMENT_RANGE_BITS);
	ui32CodeBaseReg += ui32CodeHeapBaseIndex;

	PVR_ASSERT(ui32CodeBaseReg <= EURASIA_PDS_DOUTU0_CBASE_MAX);
	PVR_ASSERT(ui32ExeAddr < (1UL << SGX_USE_CODE_SEGMENT_RANGE_BITS));
	PVR_ASSERT((ui32ExeAddr & ((1UL << EURASIA_PDS_DOUTU0_EXE_ALIGNSHIFT) - 1)) == 0);

	/*
		Set the bits of the code base register.
	*/
	pui32DOutU[0] |= (ui32CodeBaseReg << EURASIA_PDS_DOUTU0_CBASE_SHIFT) & ~EURASIA_PDS_DOUTU0_CBASE_CLRMSK;

#if defined(SGX_FEATURE_USE_UNLIMITED_PHASES)

	PVR_UNREFERENCED_PARAMETER(ui32Phase);

	/*
		Set the bits of the address.
	*/
	pui32DOutU[0] |= ((ui32ExeAddr >> EURASIA_PDS_DOUTU0_EXE_ALIGNSHIFT) << EURASIA_PDS_DOUTU0_EXE_SHIFT) & ~EURASIA_PDS_DOUTU0_EXE_CLRMSK;
	
#else /* defined(SGX_FEATURE_USE_UNLIMITED_PHASES) */

	/*
		Set the higher bits of the address.
	*/
	ui32CodeOffset = ui32ExeAddr >> EURASIA_PDS_DOUTU0_COFF_ALIGNSHIFT;
	
	PVR_ASSERT(ui32CodeOffset <= EURASIA_PDS_DOUTU0_COFF_MAX);

	pui32DOutU[0] |= (ui32CodeOffset << EURASIA_PDS_DOUTU0_COFF_SHIFT) & ~EURASIA_PDS_DOUTU0_COFF_CLRMSK;

	/*
		Set the lower bits of the address.
	*/
	
	switch (ui32Phase)
	{
		case 0:
		{
			pui32DOutU[0] |= ((ui32ExeAddr >> EURASIA_PDS_DOUTU0_EXE_ALIGNSHIFT) << EURASIA_PDS_DOUTU0_EXE_SHIFT) & ~EURASIA_PDS_DOUTU0_EXE_CLRMSK; 
			break;
		}
		case 1: 
		{
			pui32DOutU[1] |= (((ui32ExeAddr >> EURASIA_PDS_DOUTU1_EXE1_ALIGNSHIFT) << EURASIA_PDS_DOUTU1_EXE1_SHIFT) & 
								~EURASIA_PDS_DOUTU1_EXE1_CLRMSK) | EURASIA_PDS_DOUTU1_EXE1VALID;
			break;
		}
		case 2: 
		{
			pui32DOutU[1] |= (((ui32ExeAddr >> EURASIA_PDS_DOUTU1_EXE2_ALIGNSHIFT) << EURASIA_PDS_DOUTU1_EXE2_SHIFT) & 
								~EURASIA_PDS_DOUTU1_EXE2_CLRMSK) | EURASIA_PDS_DOUTU1_EXE2VALID;
			break;
		}
		default:
		{
			break;
		}
	}
#endif /* defined(SGX_FEATURE_USE_UNLIMITED_PHASES) */
}


#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildUSEDest)
#endif
FORCE_INLINE void BuildUSEDest(IMG_PUINT32		pui32Inst,
						   USE_REGTYPE		eDestType,
						   IMG_UINT32		ui32DestIdx)
{
	pui32Inst[0] |= ui32DestIdx << EURASIA_USE0_DST_SHIFT;

	pui32Inst[1] |= aui32RegTypeToUSE1DestBank[eDestType];
}

#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildUSELDSMPDest)
#endif
FORCE_INLINE void BuildUSELDSMPDest(IMG_PUINT32		pui32Inst,
								USE_REGTYPE		eDestType,
								IMG_UINT32		ui32DestIdx)
{
	PVR_ASSERT(eDestType == USE_REGTYPE_TEMP || eDestType == USE_REGTYPE_PRIMATTR);

	pui32Inst[0] |= ui32DestIdx << EURASIA_USE0_DST_SHIFT;

	pui32Inst[1] |= aui32RegTypeToLDDestBank[eDestType];
}


#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildUSESrc0)
#endif
FORCE_INLINE void BuildUSESrc0(IMG_PUINT32		pdwInst,
						   USE_REGTYPE		eSrc0Type,
						   IMG_UINT32		dwSrc0Idx)
{
	PVR_ASSERT(eSrc0Type == USE_REGTYPE_TEMP || eSrc0Type == USE_REGTYPE_PRIMATTR);

	pdwInst[0] |= (dwSrc0Idx << EURASIA_USE0_SRC0_SHIFT);

	pdwInst[1] |= (aui32RegTypeToUSE1Src0BExt[eSrc0Type]) |
				  (aui32RegTypeToUSE1Src0Bank[eSrc0Type] << EURASIA_USE1_S0BANK_SHIFT);
}

#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildUSESrc1)
#endif
FORCE_INLINE void BuildUSESrc1(IMG_PUINT32			pdwInst,
						   USE_REGTYPE		eSrc1Type,
						   IMG_UINT32			dwSrc1Idx)
{
	pdwInst[0] |= (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
				  (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT);

	pdwInst[1] |= (aui32RegTypeToUSE1Src1BExt[eSrc1Type]);
}

#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildUSESrc2)
#endif
FORCE_INLINE void BuildUSESrc2(IMG_PUINT32			pdwInst,
						   USE_REGTYPE		eSrc2Type,
						   IMG_UINT32			dwSrc2Idx)
{
	pdwInst[0] |= (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
				  (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT);

	pdwInst[1] |= (aui32RegTypeToUSE1Src2BExt[eSrc2Type]);
}

/*
	Helper to construct a ST USE instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildST)
#endif
FORCE_INLINE void BuildST(PPVR_USE_INST		psUSEInst,
					  IMG_UINT32					dwEPRED,
					  IMG_UINT32					dwRCount,
				  	  IMG_UINT32					dwFlags,
					  IMG_UINT32					dwDataType,
					  IMG_UINT32					dwAddressMode,
					  IMG_UINT32					dwIncrementMode,
				  	  USE_REGTYPE			eSrc0Type,
				  	  IMG_UINT32					dwSrc0Idx,
				  	  USE_REGTYPE			eSrc1Type,
				  	  IMG_UINT32					dwSrc1Idx,
				  	  USE_REGTYPE			eSrc2Type,
				  	  IMG_UINT32					dwSrc2Idx,
					  IMG_BOOL					bBypassCache)
{
	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwSrc0Idx << EURASIA_USE0_SRC0_SHIFT) |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT);

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_ST << EURASIA_USE1_OP_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (dwRCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						 (dwFlags) |
						 EURASIA_USE1_SKIPINV |
						 (aui32RegTypeToUSE1Src0BExt[eSrc0Type]) |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (aui32RegTypeToUSE1Src2BExt[eSrc2Type]) |
						 (dwDataType << EURASIA_USE1_LDST_DTYPE_SHIFT) |
						 (dwAddressMode << EURASIA_USE1_LDST_AMODE_SHIFT) | 
						 (dwIncrementMode << EURASIA_USE1_LDST_IMODE_SHIFT) |
						 (aui32RegTypeToUSE1Src0Bank[eSrc0Type] << EURASIA_USE1_S0BANK_SHIFT);

	if (bBypassCache)
	{
		#if defined(SGX_FEATURE_USE_LDST_EXTENDED_CACHE_MODES)
		psUSEInst->ui32Word1 |= EURASIA_USE1_LDST_DCCTL_STDBYPASSL1L2;
		#else /* defined(SGX_FEATURE_USE_LDST_EXTENDED_CACHE_MODES) */
		psUSEInst->ui32Word1 |= EURASIA_USE1_LDST_BPCACHE;
		#endif /* defined(SGX_FEATURE_USE_LDST_EXTENDED_CACHE_MODES) */
	}
}

/*
	Helper to construct a LD USE instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildLD)
#endif
FORCE_INLINE void BuildLD(PPVR_USE_INST		psUSEInst,
					  IMG_UINT32					dwEPRED,
					  IMG_UINT32					dwRCount,
				  	  IMG_UINT32					dwFlags,
					  IMG_UINT32					dwDRCIdx,
					  IMG_UINT32					dwDataType,
					  IMG_UINT32					dwAddressMode,
					  IMG_UINT32					dwIncrementMode,
				  	  USE_REGTYPE			eDestType,
				  	  IMG_UINT32					dwDestIdx,
				  	  USE_REGTYPE			eSrc0Type,
				  	  IMG_UINT32					dwSrc0Idx,
				  	  USE_REGTYPE			eSrc1Type,
				  	  IMG_UINT32					dwSrc1Idx,
				  	  USE_REGTYPE			eSrc2Type,
				  	  IMG_UINT32					dwSrc2Idx,
					  IMG_BOOL					bBypassCache)
{
	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						 (dwSrc0Idx << EURASIA_USE0_SRC0_SHIFT) |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT);

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_LD << EURASIA_USE1_OP_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (dwRCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						 (dwFlags) |
						 EURASIA_USE1_SKIPINV |
						 (aui32RegTypeToUSE1Src0BExt[eSrc0Type]) |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (aui32RegTypeToUSE1Src2BExt[eSrc2Type]) |
						 (dwDataType << EURASIA_USE1_LDST_DTYPE_SHIFT) |
						 (dwAddressMode << EURASIA_USE1_LDST_AMODE_SHIFT) | 
						 (dwIncrementMode << EURASIA_USE1_LDST_IMODE_SHIFT) |
						 (aui32RegTypeToLDDestBank[eDestType]) |
						 (aui32RegTypeToUSE1Src0Bank[eSrc0Type] << EURASIA_USE1_S0BANK_SHIFT) |
						 (dwDRCIdx << EURASIA_USE1_LDST_DRCSEL_SHIFT);

	if (bBypassCache)
	{
		#if defined(SGX_FEATURE_USE_LDST_EXTENDED_CACHE_MODES)
		psUSEInst->ui32Word1 |= EURASIA_USE1_LDST_DCCTL_STDBYPASSL1L2;
		#else /* defined(SGX_FEATURE_USE_LDST_EXTENDED_CACHE_MODES) */
		psUSEInst->ui32Word1 |= EURASIA_USE1_LDST_BPCACHE;
		#endif /* defined(SGX_FEATURE_USE_LDST_EXTENDED_CACHE_MODES) */
	}
}

/*
  Helper to construct a SOP2 with write mask USE instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildSOP2WM)
#endif
FORCE_INLINE void BuildSOP2WM(PPVR_USE_INST		psUSEInst,
						  IMG_BOOL			bEnd,
						  IMG_UINT32		ui32SPRED,
						  USE_REGTYPE		eDestType,
						  IMG_UINT32		ui32DestIdx,
						  USE_REGTYPE		eSrc0Type,
						  IMG_UINT32		ui32Src0Idx,
						  USE_REGTYPE		eSrc1Type,
						  IMG_UINT32		ui32Src1Idx,
						  USE_REGTYPE		eSrc2Type,
						  IMG_UINT32		ui32Src2Idx,
						  IMG_UINT32		ui32COp,
						  IMG_UINT32		ui32AOp,
						  IMG_UINT32		ui32Sel1,
						  IMG_UINT32		ui32Sel1Mod,
						  IMG_UINT32		ui32Sel2,
						  IMG_UINT32		ui32Sel2Mod,
						  IMG_UINT32		ui32WriteMask)
{
	psUSEInst->ui32Word0 =
		(aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
		(aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
		(ui32DestIdx << EURASIA_USE0_DST_SHIFT) |
		(ui32Src0Idx << EURASIA_USE0_SRC0_SHIFT) |
		(ui32Src1Idx << EURASIA_USE0_SRC1_SHIFT) |
		(ui32Src2Idx << EURASIA_USE0_SRC2_SHIFT);

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_SOPWM << EURASIA_USE1_OP_SHIFT) |
		EURASIA_USE1_SKIPINV |
		(ui32SPRED << EURASIA_USE1_SPRED_SHIFT) |
		(bEnd ? EURASIA_USE1_END : 0) |
		(aui32RegTypeToUSE1Src0Bank[eSrc0Type] << EURASIA_USE1_S0BANK_SHIFT) |
		(aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
		aui32RegTypeToUSE1DestBExt[eDestType] |
		aui32RegTypeToUSE1Src1BExt[eSrc1Type] |
		aui32RegTypeToUSE1Src2BExt[eSrc2Type];

	psUSEInst->ui32Word1 |= ui32COp << EURASIA_USE1_SOP2WM_COP_SHIFT |
		ui32AOp << EURASIA_USE1_SOP2WM_AOP_SHIFT |
		ui32Sel1 << EURASIA_USE1_SOP2WM_SEL1_SHIFT |
		ui32Sel1Mod << EURASIA_USE1_SOP2WM_MOD1_SHIFT |
		ui32Sel2 << EURASIA_USE1_SOP2WM_SEL2_SHIFT |
		ui32Sel2Mod << EURASIA_USE1_SOP2WM_MOD2_SHIFT |
		ui32WriteMask << EURASIA_USE1_SOP2WM_WRITEMASK_SHIFT;

}


/*
  Helper to construct a SOP2 USE instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildSOP2)
#endif
FORCE_INLINE void BuildSOP2(PPVR_USE_INST	psUSEInst,
						IMG_BOOL		bEnd,
						IMG_UINT32		ui32SPRED,
						USE_REGTYPE		eDestType,
						IMG_UINT32		ui32DestIdx,
						USE_REGTYPE		eSrc1Type,
						IMG_UINT32		ui32Src1Idx,
						USE_REGTYPE		eSrc2Type,
						IMG_UINT32		ui32Src2Idx,
						IMG_UINT32		ui32COp,
						IMG_UINT32		ui32AOp,
						IMG_UINT32		ui32CSrcMod,
						IMG_UINT32		ui32ASrcMod,
						IMG_UINT32		ui32CSel1,
						IMG_UINT32		ui32CSel1Mod,
						IMG_UINT32		ui32CSel2,
						IMG_UINT32		ui32CSel2Mod,
						IMG_UINT32		ui32ASel1,
						IMG_UINT32		ui32ASel1Mod,
						IMG_UINT32		ui32ASel2,
						IMG_UINT32		ui32ASel2Mod)
{
	psUSEInst->ui32Word0 =
		(aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
		(aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
		(ui32DestIdx << EURASIA_USE0_DST_SHIFT) |
		(ui32Src1Idx << EURASIA_USE0_SRC1_SHIFT) |
		(ui32Src2Idx << EURASIA_USE0_SRC2_SHIFT);

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_SOP2 << EURASIA_USE1_OP_SHIFT) |
		EURASIA_USE1_SKIPINV |
		(ui32SPRED << EURASIA_USE1_SPRED_SHIFT) |
		(bEnd ? EURASIA_USE1_END : 0) |
		(aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
		aui32RegTypeToUSE1DestBExt[eDestType] |
		aui32RegTypeToUSE1Src1BExt[eSrc1Type] |
		aui32RegTypeToUSE1Src2BExt[eSrc2Type];

	psUSEInst->ui32Word0 |=
		ui32CSrcMod << EURASIA_USE0_SOP2_SRC1MOD_SHIFT |
		ui32COp << EURASIA_USE0_SOP2_COP_SHIFT |
		ui32AOp << EURASIA_USE0_SOP2_AOP_SHIFT |
		ui32ASrcMod << EURASIA_USE0_SOP2_ASRC1MOD_SHIFT;

	psUSEInst->ui32Word1 |=
		ui32CSel1Mod << EURASIA_USE1_SOP2_CMOD1_SHIFT |
		ui32ASel1 << EURASIA_USE1_SOP2_ASEL1_SHIFT |
		ui32CSel2Mod << EURASIA_USE1_SOP2_CMOD2_SHIFT |
		ui32ASel1Mod << EURASIA_USE1_SOP2_AMOD1_SHIFT |
		ui32ASel2 << EURASIA_USE1_SOP2_ASEL2_SHIFT |
		ui32CSel1 << EURASIA_USE1_SOP2_CSEL1_SHIFT |
		ui32CSel2 << EURASIA_USE1_SOP2_CSEL2_SHIFT |
		ui32ASel2Mod << EURASIA_USE1_SOP2_AMOD2_SHIFT;

}

/*
  Helper to construct a SMP2D USE instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildSMP2D)
#endif
FORCE_INLINE void BuildSMP2D(PPVR_USE_INST	psUSEInst,
						 IMG_UINT32		ui32Flags,
						 IMG_UINT32		ui32RCount,
						 IMG_UINT32		ui32EPRED,
						 USE_REGTYPE	eDestType,
						 IMG_UINT32		ui32DestIdx,
						 USE_REGTYPE	eSrc0Type,
						 IMG_UINT32		ui32Src0Idx,
						 USE_REGTYPE	eSrc1Type,
						 IMG_UINT32		ui32Src1Idx,
						 USE_REGTYPE	eSrc2Type,
						 IMG_UINT32		ui32Src2Idx,
						 IMG_UINT32		ui32DRCIdx)
{
	psUSEInst->ui32Word0 =
		(aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
		(aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
		(ui32DestIdx << EURASIA_USE0_DST_SHIFT) |
		(ui32Src0Idx << EURASIA_USE0_SRC0_SHIFT) |
		(ui32Src1Idx << EURASIA_USE0_SRC1_SHIFT) |
		(ui32Src2Idx << EURASIA_USE0_SRC2_SHIFT);


	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_SMP << EURASIA_USE1_OP_SHIFT) |
		ui32Flags | EURASIA_USE1_SKIPINV |
		(ui32EPRED << EURASIA_USE1_EPRED_SHIFT) |
		(ui32RCount << EURASIA_USE1_RMSKCNT_SHIFT) |
		(EURASIA_USE1_SMP_CDIM_UV << EURASIA_USE1_SMP_CDIM_SHIFT) |
		(aui32RegTypeToUSE1Src0Bank[eSrc0Type] << EURASIA_USE1_S0BANK_SHIFT) |
		(aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
		aui32RegTypeToUSE1DestBExt[eDestType] |
		aui32RegTypeToUSE1Src1BExt[eSrc1Type] |
		aui32RegTypeToUSE1Src2BExt[eSrc2Type] |
		(ui32DRCIdx << EURASIA_USE1_SMP_DRCSEL_SHIFT);
}

/*
  Helper to construct a IDF USE instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildIDF)
#endif
FORCE_INLINE void BuildIDF(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwDRCIdx,
					   IMG_UINT32 		dwPath)
{
	psUSEInst->ui32Word0 = 0;
	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_SPECIAL << EURASIA_USE1_OP_SHIFT) |
						 (EURASIA_USE1_SPECIAL_OPCAT_OTHER << EURASIA_USE1_SPECIAL_OPCAT_SHIFT) |
						 (EURASIA_USE1_OTHER_OP2_IDF << EURASIA_USE1_OTHER_OP2_SHIFT) |
						 (dwDRCIdx << EURASIA_USE1_IDFWDF_DRCSEL_SHIFT) |
						 (dwPath << EURASIA_USE1_IDF_PATH_SHIFT);
}

/*
	Helper to construct a WDF USE instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildWDF)
#endif
FORCE_INLINE void BuildWDF(PPVR_USE_INST	psUSEInst,
						  IMG_UINT32		ui32DRCIdx)
{
	psUSEInst->ui32Word0 = 0;
	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_SPECIAL << EURASIA_USE1_OP_SHIFT) |
						   (EURASIA_USE1_SPECIAL_OPCAT_OTHER << EURASIA_USE1_SPECIAL_OPCAT_SHIFT) |
						   (EURASIA_USE1_OTHER_OP2_WDF << EURASIA_USE1_OTHER_OP2_SHIFT) |
						   (ui32DRCIdx << EURASIA_USE1_IDFWDF_DRCSEL_SHIFT);
}

/*
	Helper to construct a general EFO USE instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildEFO)
#endif
FORCE_INLINE void BuildEFO(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
				  	   IMG_UINT32		dwFlags,
				  	   IMG_UINT32		dwMSRC,
				  	   IMG_UINT32		dwASRC,
				  	   IMG_UINT32		dwISRC,
				  	   IMG_UINT32		dwDSRC,
				  	   USE_REGTYPE	eDestType,
				  	   IMG_UINT32		dwDestIdx,
				  	   USE_REGTYPE	eSrc0Type,
				  	   IMG_UINT32		dwSrc0Idx,
				  	   IMG_UINT32		dwSrc0Mod,
				  	   USE_REGTYPE	eSrc1Type,
				  	   IMG_UINT32		dwSrc1Idx,
				  	   IMG_UINT32		dwSrc1Mod,
				  	   USE_REGTYPE	eSrc2Type,
				  	   IMG_UINT32		dwSrc2Idx,
				  	   IMG_UINT32		dwSrc2Mod)
{
	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						 (dwSrc0Idx << EURASIA_USE0_SRC0_SHIFT) |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT);

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_EFO << EURASIA_USE1_OP_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (dwDSRC << EURASIA_USE1_EFO_DSRC_SHIFT) |
						 (dwISRC << EURASIA_USE1_EFO_ISRC_SHIFT) |
						 (dwASRC << EURASIA_USE1_EFO_ASRC_SHIFT) |
						 (dwMSRC << EURASIA_USE1_EFO_MSRC_SHIFT) |
						 (dwRCount << EURASIA_USE1_EFO_RCOUNT_SHIFT) |
						 (dwSrc0Mod << EURASIA_USE1_SRC0MOD_SHIFT) |
						 (dwSrc1Mod << EURASIA_USE1_SRC1MOD_SHIFT) |
						 (dwSrc2Mod << EURASIA_USE1_SRC2MOD_SHIFT) |
						 (aui32RegTypeToUSE1Src0Bank[eSrc0Type] << EURASIA_USE1_S0BANK_SHIFT) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
						 dwFlags |
						 EURASIA_USE1_SKIPINV;

	PVR_ASSERT(!aui32RegTypeToUSE1Src1BExt[eSrc1Type]);
	#if defined(SGX_FEATURE_USE_NEW_EFO_OPTIONS)
	if (aui32RegTypeToUSE1Src0BExt[eSrc0Type])
	{
		psUSEInst->ui32Word1 |= SGX545_USE1_EFO_S0BEXT;
	}
	if (aui32RegTypeToUSE1Src2BExt[eSrc2Type])
	{
		psUSEInst->ui32Word1 |= SGX545_USE1_EFO_S2BEXT;
	}
	#else /* defined(SGX_FEATURE_USE_NEW_EFO_OPTIONS) */
	PVR_ASSERT(!aui32RegTypeToUSE1Src0BExt[eSrc0Type]);
	PVR_ASSERT(!aui32RegTypeToUSE1Src2BExt[eSrc2Type]);
	#endif /* defined(SGX_FEATURE_USE_NEW_EFO_OPTIONS) */
}

/*
	Helper to construct a test (with alu op) instruction.
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildALUTST)
#endif
FORCE_INLINE void BuildALUTST(	PPVR_USE_INST	psUSEInst,
							IMG_UINT32		dwEPRED,
							IMG_UINT32		dwRMask,
							IMG_UINT32		dwFlags,
							USE_REGTYPE	eDestType,
							IMG_UINT32		dwDestIdx,
							IMG_UINT32		dwWBEnable,
							USE_REGTYPE	eSrc1Type,
							IMG_UINT32		dwSrc1Idx,
							USE_REGTYPE	eSrc2Type,
							IMG_UINT32		dwSrc2Idx,
							IMG_UINT32		dwPDST,
							IMG_UINT32		dwSTST,
							IMG_UINT32		dwZTST,
							IMG_UINT32		dwCHANCC,
							IMG_UINT32		dwALUSEL,
							IMG_UINT32		dwALUOP)
{
	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT) |
						 (dwALUSEL << EURASIA_USE0_TEST_ALUSEL_SHIFT) |
						 (dwALUOP << EURASIA_USE0_TEST_ALUOP_SHIFT) |
						 dwWBEnable;

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_TEST << EURASIA_USE1_OP_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (dwRMask << EURASIA_USE1_RMSKCNT_SHIFT) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
						 (aui32RegTypeToUSE1DestBExt[eDestType]) |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (aui32RegTypeToUSE1Src2BExt[eSrc2Type]) |
						 (dwPDST << EURASIA_USE1_TEST_PDST_SHIFT) |
						 (dwCHANCC << EURASIA_USE1_TEST_CHANCC_SHIFT) |
						 (dwSTST << EURASIA_USE1_TEST_STST_SHIFT) |
						 (dwZTST << EURASIA_USE1_TEST_ZTST_SHIFT) |
						 dwFlags |
						 EURASIA_USE1_SKIPINV;
}

/*
	Helper to construct a WOP instruction.
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildWOP)
#endif
FORCE_INLINE void BuildWOP(	PPVR_USE_INST		psUSEInst,
							IMG_UINT32			dwPTNB,
							IMG_UINT32			dwFlags)
{
	psUSEInst->ui32Word0 = 	(dwPTNB << EURASIA_USE0_WOP_PTNB_SHIFT);
	psUSEInst->ui32Word1 = 	(EURASIA_USE1_OP_SPECIAL << EURASIA_USE1_OP_SHIFT) |
							(EURASIA_USE1_OTHER_OP2_WOP << EURASIA_USE1_OTHER_OP2_SHIFT) | 
							(EURASIA_USE1_SPECIAL_OPCAT_OTHER << EURASIA_USE1_SPECIAL_OPCAT_SHIFT) |
							dwFlags;
}

/*
	Helper to construct a MUTEX instruction.
	bAction - (true=lock, false=release)
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildMUTEX)
#endif
FORCE_INLINE void BuildMUTEX(	PPVR_USE_INST		psUSEInst,
							IMG_BOOL			bAction,
							IMG_UINT32			dwFlags)
{
	psUSEInst->ui32Word0 = 	(bAction?EURASIA_USE0_LOCKRELEASE_ACTION_LOCK:EURASIA_USE0_LOCKRELEASE_ACTION_RELEASE);
	psUSEInst->ui32Word1 = 	(EURASIA_USE1_OP_SPECIAL << EURASIA_USE1_OP_SHIFT) |
							(EURASIA_USE1_OTHER_OP2_LOCKRELEASE << EURASIA_USE1_OTHER_OP2_SHIFT) | 
							(EURASIA_USE1_SPECIAL_OPCAT_OTHER << EURASIA_USE1_SPECIAL_OPCAT_SHIFT) |
							dwFlags;
}

/*
	Helper to construct a NOP instruction.
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildNOP)
#endif
FORCE_INLINE void BuildNOP(	PPVR_USE_INST		psUSEInst,
							IMG_UINT32			dwFlags,
							IMG_BOOL		bUnmatchableCodeToggle)
{
	psUSEInst->ui32Word0 = 	(bUnmatchableCodeToggle?1UL:0);
	psUSEInst->ui32Word1 = 	(EURASIA_USE1_FLOWCTRL_OP2_NOP << EURASIA_USE1_FLOWCTRL_OP2_SHIFT) |
							(EURASIA_USE1_OP_SPECIAL << EURASIA_USE1_OP_SHIFT) |
							dwFlags;
}

/*
	Helper to build an generalised EMIT instruction.
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildEMIT)
#endif
FORCE_INLINE void BuildEMIT(	PPVR_USE_INST	psUSEInst,
						 	IMG_UINT32		dwEPRED,
							IMG_UINT32		dwFlags,
							USE_REGTYPE	eSrc0Type,
							IMG_UINT32		dwSrc0Idx,
							USE_REGTYPE	eSrc1Type,
							IMG_UINT32		dwSrc1Idx,
							USE_REGTYPE	eSrc2Type,
							IMG_UINT32		dwSrc2Idx,
							IMG_UINT32		dwTarget,
							IMG_UINT32		dwINCP,
							IMG_BOOL		bFreep,
							IMG_UINT32		dwSide_109_108,
							IMG_UINT32		dwSide_107_102,
							IMG_UINT32		dwSide_101_96)
{							
	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwSrc0Idx << EURASIA_USE0_SRC0_SHIFT) |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT) |
						 (dwSide_101_96 << 22) |
						 (bFreep?EURASIA_USE0_EMIT_FREEP:0);

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_SPECIAL << EURASIA_USE1_OP_SHIFT) |
						 (EURASIA_USE1_OTHER_OP2_EMIT << EURASIA_USE1_OTHER_OP2_SHIFT) |
						 (EURASIA_USE1_SPECIAL_OPCAT_OTHER << EURASIA_USE1_SPECIAL_OPCAT_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (aui32RegTypeToUSE1Src0BExt_EMIT[eSrc0Type]) |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (aui32RegTypeToUSE1Src2BExt[eSrc2Type]) |
						 (aui32RegTypeToUSE1Src0Bank[eSrc0Type] << EURASIA_USE1_S0BANK_SHIFT) |
						 (dwTarget << EURASIA_USE1_EMIT_TARGET_SHIFT) |
						 (dwINCP << EURASIA_USE1_EMIT_INCP_SHIFT) |
						 (dwSide_109_108 << 10) |
						 (dwSide_107_102 >> 3) |
						 dwFlags;
}

/*
	Helper to build an EMITPIX instruction.
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildEMITPIX)
#endif
FORCE_INLINE void _BuildEMITPIX(PPVR_USE_INST	psUSEInst,
						 	IMG_UINT32				dwEPRED,
							IMG_UINT32				dwFlags,
							USE_REGTYPE			eSrc0Type,
							IMG_UINT32				dwSrc0Idx,
							USE_REGTYPE			eSrc1Type,
							IMG_UINT32				dwSrc1Idx,
							USE_REGTYPE			eSrc2Type,
							IMG_UINT32				dwSrc2Idx,
							IMG_UINT32				dwINCP,
							IMG_BOOL				bFreep,
							IMG_UINT32				dwSideBand)
{
	IMG_UINT32	dwSideBand109108;
	IMG_UINT32	dwSideBand107102;
	IMG_UINT32	dwSideBand10196;

	dwSideBand109108 = dwSideBand & (((~EURASIA_USE1_EMIT_SIDEBAND_109_108_CLRMSK) >> EURASIA_USE1_EMIT_SIDEBAND_109_108_SHIFT) << 12);
	dwSideBand107102 = dwSideBand & (((~EURASIA_USE1_EMIT_SIDEBAND_107_102_CLRMSK) >> EURASIA_USE1_EMIT_SIDEBAND_107_102_SHIFT) << 6);
	dwSideBand10196 = dwSideBand & (((~EURASIA_USE0_EMIT_SIDEBAND_101_96_CLRMSK) >> EURASIA_USE0_EMIT_SIDEBAND_101_96_SHIFT) << 0);

	BuildEMIT(	psUSEInst,
				dwEPRED,
				dwFlags,
				eSrc0Type,
				dwSrc0Idx,
				eSrc1Type,
				dwSrc1Idx,
				eSrc2Type,
				dwSrc2Idx,
				EURASIA_USE1_EMIT_TARGET_PIXELBE,
				dwINCP,
				bFreep,
				dwSideBand109108,
				dwSideBand107102,
				dwSideBand10196);
}

#if !defined(SGX545)
/*
	Helper to build an EMITPIX instruction.
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildEMITPIX)
#endif
FORCE_INLINE void BuildEMITPIX(PPVR_USE_INST	psUSEInst,
						 	   IMG_UINT32		dwEPRED,
							   IMG_UINT32		dwFlags,
							   USE_REGTYPE	eSrc0Type,
							   IMG_UINT32		dwSrc0Idx,
							   USE_REGTYPE	eSrc1Type,
							   IMG_UINT32		dwSrc1Idx,
							   USE_REGTYPE	eSrc2Type,
							   IMG_UINT32		dwSrc2Idx,
							   IMG_UINT32		dwINCP,
							   IMG_BOOL		bFreep,
							  IMG_UINT32		dwSrcSelDstOff,
							IMG_BOOL		bDither,
							IMG_BOOL		bTwoEmits,
							IMG_BOOL		bTileRelative,
							IMG_UINT32		dwScale)
{
	BuildEMIT(	psUSEInst,
				dwEPRED,
				dwFlags,
				eSrc0Type,
				dwSrc0Idx,
				eSrc1Type,
				dwSrc1Idx,
				eSrc2Type,
				dwSrc2Idx,
				EURASIA_USE1_EMIT_TARGET_PIXELBE,
				dwINCP,
				bFreep,
				0,
				dwSrcSelDstOff << EURASIA_PIXELBE2SB_SRCSEL_SHIFT,
				((bTileRelative?EURASIA_PIXELBE2SB_TILERELATIVE:0) |
				(bDither?EURASIA_PIXELBE2SB_DITHER:0) |
				(bTwoEmits?EURASIA_PIXELBE1SB_TWOEMITS:0) |
				(dwScale << EURASIA_PIXELBE2SB_SCALE_SHIFT)));
}

/*
	Helper to build an EMITPDS instruction.
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildEMITPDS)
#endif
FORCE_INLINE void BuildEMITPDS(PPVR_USE_INST	psUSEInst,
						 	IMG_UINT32		dwEPRED,
							IMG_UINT32		dwFlags,
							USE_REGTYPE	eSrc0Type,
							IMG_UINT32		dwSrc0Idx,
							USE_REGTYPE	eSrc1Type,
							IMG_UINT32		dwSrc1Idx,
							USE_REGTYPE	eSrc2Type,
							IMG_UINT32		dwSrc2Idx,
							IMG_UINT32		dwINCP,
							IMG_BOOL		bFreep,
							IMG_BOOL		bTaskS,
							IMG_BOOL		bTaskE,
							IMG_BOOL		bAttributeStatic,
							IMG_BOOL		bAttributeFree,
							IMG_BOOL		bSD,
							IMG_UINT32		dwInstanceCount,
							IMG_BOOL		bPartial,
							IMG_UINT32		dwOutputPartitions,
							IMG_UINT32		dwDataMaster)
{
	BuildEMIT(	psUSEInst,
				dwEPRED,
				dwFlags |
				(bTaskS?EURASIA_USE1_EMIT_PDSCTRL_TASKS:0) |
				(bTaskE?EURASIA_USE1_EMIT_PDSCTRL_TASKE:0),
				eSrc0Type,
				dwSrc0Idx,
				eSrc1Type,
				dwSrc1Idx,
				eSrc2Type,
				dwSrc2Idx,
				EURASIA_USE1_EMIT_TARGET_PDS,
				dwINCP,
				bFreep,
				(bAttributeStatic?EURASIA_PDSSB3_USEATTRIBUTESTATIC:0) |
				(bAttributeFree?EURASIA_PDSSB3_USEATTRIBUTEFREE:0),
				(bSD?EURASIA_PDSSB3_PDSSEQDEPENDENCY:0) |
				(dwInstanceCount << EURASIA_PDSSB3_USEINSTANCECOUNT_SHIFT),
				(bPartial?EURASIA_PDSSB3_USEATTRIBUTEPARITIAL:0) |
				(dwOutputPartitions << EURASIA_PDSSB3_PDSOUTPUTPARCOUNT_SHIFT) |
				(dwDataMaster << EURASIA_PDSSB3_USEDATAMASTER_SHIFT));
}

/*
	Helper to build an EMITMTE instruction.
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildEMITMTE)
#endif
FORCE_INLINE void BuildEMITMTE(PPVR_USE_INST	psUSEInst,
						 	IMG_UINT32		dwEPRED,
							IMG_UINT32		dwFlags,
							USE_REGTYPE	eSrc0Type,
							IMG_UINT32		dwSrc0Idx,
							USE_REGTYPE	eSrc1Type,
							IMG_UINT32		dwSrc1Idx,
							USE_REGTYPE	eSrc2Type,
							IMG_UINT32		dwSrc2Idx,
							IMG_UINT32		dwINCP,
							IMG_BOOL		bFreep,
							IMG_UINT32		dwAdvance,
							IMG_UINT32		dwID,
							IMG_UINT32		dwMTECTRL)
{
	BuildEMIT(	psUSEInst,
				dwEPRED,
				dwFlags | (dwMTECTRL << EURASIA_USE1_EMIT_MTECTRL_SHIFT),
				eSrc0Type,
				dwSrc0Idx,
				eSrc1Type,
				dwSrc1Idx,
				eSrc2Type,
				dwSrc2Idx,
				EURASIA_USE1_EMIT_TARGET_MTE,
				dwINCP,
				bFreep,
				0,
				0,
				((dwAdvance << EURASIA_MTEPRIM3_ADVCNT_SHIFT) |
				(dwID << EURASIA_MTEPRIM3_ID_SHIFT)) >> 22);
}
#else /* #if !defined(SGX545) */

/*
	Helper to build an EMITPIX instruction.
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildEMITPIX)
#endif
FORCE_INLINE void BuildEMITPIX(PPVR_USE_INST	psUSEInst,
						 	IMG_UINT32		dwEPRED,
							IMG_UINT32		dwFlags,
							USE_REGTYPE	eSrc0Type,
							IMG_UINT32		dwSrc0Idx,
							USE_REGTYPE	eSrc1Type,
							IMG_UINT32		dwSrc1Idx,
							USE_REGTYPE	eSrc2Type,
							IMG_UINT32		dwSrc2Idx,
							IMG_UINT32		dwINCP,
							IMG_BOOL		bFreep,
							IMG_UINT32		dwSrcSelDstOff,
							IMG_BOOL		bDither,
							IMG_BOOL		bTwoEmits,
							IMG_BOOL		bTileRelative,
							IMG_BOOL		bGammaCorrect,
							IMG_UINT32		dwMEML,
							IMG_UINT32		dwPMode)
{
	BuildEMIT(	psUSEInst,
				dwEPRED,
				dwFlags,
				eSrc0Type,
				dwSrc0Idx,
				eSrc1Type,
				dwSrc1Idx,
				eSrc2Type,
				dwSrc2Idx,
				EURASIA_USE1_EMIT_TARGET_PIXELBE,
				dwINCP,
				bFreep,
				(bGammaCorrect?EURASIA_PIXELBE2SB_GAMMACORRECT:0) |
				(dwMEML << EURASIA_PIXELBE2SB_MEMLAYOUT_SHIFT),
				(dwSrcSelDstOff << EURASIA_PIXELBE2SB_SRCSEL_SHIFT) | 
				(bTileRelative?EURASIA_PIXELBE2SB_TILERELATIVE:0) |
				(bDither?EURASIA_PIXELBE2SB_DITHER:0) |
				(bTwoEmits?EURASIA_PIXELBE1SB_TWOEMITS:0),
				(dwPMode << EURASIA_PIXELBE2SB_PACKMODE_SHIFT));
}

/*
	Helper to build an EMITPDS instruction.
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildEMITPDS)
#endif
FORCE_INLINE void BuildEMITPDS(PPVR_USE_INST	psUSEInst,
						 	IMG_UINT32		dwEPRED,
							IMG_UINT32		dwFlags,
							USE_REGTYPE	eSrc0Type,
							IMG_UINT32		dwSrc0Idx,
							USE_REGTYPE	eSrc1Type,
							IMG_UINT32		dwSrc1Idx,
							USE_REGTYPE	eSrc2Type,
							IMG_UINT32		dwSrc2Idx,
							IMG_UINT32		dwINCP,
							IMG_BOOL		bFreep,
							IMG_BOOL		bTaskS,
							IMG_BOOL		bTaskE,
							IMG_BOOL		bSD,
							IMG_UINT32		dwInstanceCount,
							IMG_UINT32		dwOutputPartitions,
							IMG_UINT32		dwDataMaster)
{
	BuildEMIT(	psUSEInst,
				dwEPRED,
				dwFlags |
				(bTaskS?EURASIA_USE1_EMIT_PDSCTRL_TASKS:0) |
				(bTaskE?EURASIA_USE1_EMIT_PDSCTRL_TASKE:0),
				eSrc0Type,
				dwSrc0Idx,
				eSrc1Type,
				dwSrc1Idx,
				eSrc2Type,
				dwSrc2Idx,
				EURASIA_USE1_EMIT_TARGET_PDS,
				dwINCP,
				bFreep,
				0,
				(bSD?EURASIA_PDSSB3_PDSSEQDEPENDENCY:0) |
				(dwInstanceCount << EURASIA_PDSSB3_USEINSTANCECOUNT_SHIFT),
				(dwOutputPartitions << EURASIA_PDSSB3_PDSOUTPUTPARCOUNT_SHIFT) |
				(dwDataMaster << EURASIA_PDSSB3_USEDATAMASTER_SHIFT));
}

/*
	Helper to build an EMITMTE instruction.
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildEMITMTE)
#endif
FORCE_INLINE void BuildEMITMTE(PPVR_USE_INST	psUSEInst,
						 	IMG_UINT32		dwEPRED,
							IMG_UINT32		dwFlags,
							USE_REGTYPE	eSrc0Type,
							IMG_UINT32		dwSrc0Idx,
							USE_REGTYPE	eSrc1Type,
							IMG_UINT32		dwSrc1Idx,
							USE_REGTYPE	eSrc2Type,
							IMG_UINT32		dwSrc2Idx,
							IMG_UINT32		dwINCP,
							IMG_BOOL		bFreep)
{
	BuildEMIT(	psUSEInst,
				dwEPRED,
				dwFlags,
				eSrc0Type,
				dwSrc0Idx,
				eSrc1Type,
				dwSrc1Idx,
				eSrc2Type,
				dwSrc2Idx,
				EURASIA_USE1_EMIT_TARGET_MTE,
				dwINCP,
				bFreep,
				0,
				0,
				0);
}

#if defined(SGX_FEATURE_VCB)
/*
	Helper to build an EMITVCB instruction.
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildEMITVCB)
#endif
FORCE_INLINE void BuildEMITVCB(PPVR_USE_INST	psUSEInst,
						 	IMG_UINT32		dwEPRED,
							IMG_UINT32		dwFlags,
							USE_REGTYPE	eSrc0Type,
							IMG_UINT32		dwSrc0Idx,
							USE_REGTYPE	eSrc1Type,
							IMG_UINT32		dwSrc1Idx,
							USE_REGTYPE	eSrc2Type,
							IMG_UINT32		dwSrc2Idx,
							IMG_UINT32		dwINCP,
							IMG_BOOL		bFreep)
{
	BuildEMIT(	psUSEInst,
				dwEPRED,
				dwFlags,
				eSrc0Type,
				dwSrc0Idx,
				eSrc1Type,
				dwSrc1Idx,
				eSrc2Type,
				dwSrc2Idx,
				SGX545_USE1_EMIT_TARGET_VCB,
				dwINCP,
				bFreep,
				0,
				0,
				0);
}
#endif
#endif /* #if !defined(SGX545) */

/*
	Helper to build a generalised Integer Arithmetic instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildIARITH)
#endif
FORCE_INLINE void BuildIARITH(	PPVR_USE_INST	psUSEInst,
							IMG_UINT32		dwOpCode,
						 	IMG_UINT32		dwEPRED,
							IMG_UINT32		dwRCount,
							IMG_UINT32		dwFlags,
							USE_REGTYPE	eDestType,
							IMG_UINT32		dwDestIdx,
							USE_REGTYPE	eSrc0Type,
							IMG_UINT32		dwSrc0Idx,
							IMG_UINT32		dwSrc0Mod,
							USE_REGTYPE	eSrc1Type,
							IMG_UINT32		dwSrc1Idx,
							IMG_UINT32		dwSrc1Mod,
							USE_REGTYPE	eSrc2Type,
							IMG_UINT32		dwSrc2Idx,
							IMG_UINT32		dwSrc2Mod)
{							
	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						 (dwSrc0Idx << EURASIA_USE0_SRC0_SHIFT) |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT);

	psUSEInst->ui32Word1 = (dwOpCode << EURASIA_USE1_OP_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (dwRCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						 (aui32RegTypeToUSE1DestBExt[eDestType]) |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (aui32RegTypeToUSE1Src2BExt[eSrc2Type]) |
						 (dwSrc0Mod << EURASIA_USE1_SRC0MOD_SHIFT) |
						 (dwSrc1Mod << EURASIA_USE1_SRC1MOD_SHIFT) |
						 (dwSrc2Mod << EURASIA_USE1_SRC2MOD_SHIFT) |
						 (aui32RegTypeToUSE1Src0Bank[eSrc0Type] << EURASIA_USE1_S0BANK_SHIFT) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
						 dwFlags |
						 EURASIA_USE1_SKIPINV;
}

/*
	Helper to build an IMA16 instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildIMA16)
#endif
FORCE_INLINE void BuildIMA16(	PPVR_USE_INST	psUSEInst,
						 	IMG_UINT32		dwEPRED,
							IMG_UINT32		dwRCount,
							IMG_UINT32		dwFlags,
							USE_REGTYPE	eDestType,
							IMG_UINT32		dwDestIdx,
							USE_REGTYPE	eSrc0Type,
							IMG_UINT32		dwSrc0Idx,
							IMG_UINT32		dwSrc0Mod,
							USE_REGTYPE	eSrc1Type,
							IMG_UINT32		dwSrc1Idx,
							IMG_UINT32		dwSrc1Mod,
							USE_REGTYPE	eSrc2Type,
							IMG_UINT32		dwSrc2Idx,
							IMG_UINT32		dwSrc2Mod)
{
	BuildIARITH(psUSEInst,
				EURASIA_USE1_OP_IMA16,
				dwEPRED,
				dwRCount,
				dwFlags,
				eDestType,
				dwDestIdx,
				eSrc0Type,
				dwSrc0Idx,
				dwSrc0Mod,
				eSrc1Type,
				dwSrc1Idx,
				dwSrc1Mod,
				eSrc2Type,
				dwSrc2Idx,
				dwSrc2Mod);
}

/*
	Helper to build an IMA8 instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildIMA8)
#endif
FORCE_INLINE void BuildIMA8(	PPVR_USE_INST	psUSEInst,
						 	IMG_UINT32		dwEPRED,
							IMG_UINT32		dwRCount,
							IMG_UINT32		dwFlags,
							USE_REGTYPE	eDestType,
							IMG_UINT32		dwDestIdx,
							USE_REGTYPE	eSrc0Type,
							IMG_UINT32		dwSrc0Idx,
							IMG_UINT32		dwSrc0Mod,
							USE_REGTYPE	eSrc1Type,
							IMG_UINT32		dwSrc1Idx,
							IMG_UINT32		dwSrc1Mod,
							USE_REGTYPE	eSrc2Type,
							IMG_UINT32		dwSrc2Idx,
							IMG_UINT32		dwSrc2Mod)
{
	BuildIARITH(psUSEInst,
				EURASIA_USE1_OP_IMA8,
				dwEPRED,
				dwRCount,
				dwFlags,
				eDestType,
				dwDestIdx,
				eSrc0Type,
				dwSrc0Idx,
				dwSrc0Mod,
				eSrc1Type,
				dwSrc1Idx,
				dwSrc1Mod,
				eSrc2Type,
				dwSrc2Idx,
				dwSrc2Mod);
}

/*
	Helper to build an IMAE instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildIMAE)
#endif
FORCE_INLINE void BuildIMAE(	PPVR_USE_INST	psUSEInst,
						 	IMG_UINT32		dwEPRED,
							IMG_UINT32		dwRCount,
							IMG_UINT32		dwFlags,
							USE_REGTYPE	eDestType,
							IMG_UINT32		dwDestIdx,
							USE_REGTYPE	eSrc0Type,
							IMG_UINT32		dwSrc0Idx,
							IMG_UINT32		dwSrc0Mod,
							USE_REGTYPE	eSrc1Type,
							IMG_UINT32		dwSrc1Idx,
							IMG_UINT32		dwSrc1Mod,
							USE_REGTYPE	eSrc2Type,
							IMG_UINT32		dwSrc2Idx,
							IMG_UINT32		dwSrc2Mod)
{
	BuildIARITH(psUSEInst,
				EURASIA_USE1_OP_IMAE,
				dwEPRED,
				dwRCount,
				dwFlags,
				eDestType,
				dwDestIdx,
				eSrc0Type,
				dwSrc0Idx,
				dwSrc0Mod,
				eSrc1Type,
				dwSrc1Idx,
				dwSrc1Mod,
				eSrc2Type,
				dwSrc2Idx,
				dwSrc2Mod);
}

/*
	Helper to build an LAPC instruction.
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildLAPC)
#endif
FORCE_INLINE void BuildLAPC(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwFlags)
{
	psUSEInst->ui32Word0 = 	0;
	psUSEInst->ui32Word1 = 	(dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
							(EURASIA_USE1_FLOWCTRL_OP2_LAPC << EURASIA_USE1_FLOWCTRL_OP2_SHIFT) |
							(EURASIA_USE1_OP_SPECIAL << EURASIA_USE1_OP_SHIFT) |
							dwFlags;
}

/*
	helper to build a BR instruction.
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildBR)
#endif
FORCE_INLINE void BuildBR(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwAddressOffset,
					   IMG_UINT32		dwFlags)
{
	psUSEInst->ui32Word0 = 	((dwAddressOffset << EURASIA_USE0_BRANCH_OFFSET_SHIFT) & ~EURASIA_USE0_BRANCH_OFFSET_CLRMSK);
	psUSEInst->ui32Word1 = 	(dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
							(EURASIA_USE1_FLOWCTRL_OP2_BR << EURASIA_USE1_FLOWCTRL_OP2_SHIFT) |
							(EURASIA_USE1_OP_SPECIAL << EURASIA_USE1_OP_SHIFT) |
							dwFlags;
}

/*
	Helper to construct a SETL USE-instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildSETL)
#endif
FORCE_INLINE void BuildSETL(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   IMG_UINT32		dwFlags)
{
	psUSEInst->ui32Word0 = 	(dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT);
	psUSEInst->ui32Word1 = 	(dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
							(EURASIA_USE1_FLOWCTRL_OP2_SETL << EURASIA_USE1_FLOWCTRL_OP2_SHIFT) |
							(EURASIA_USE1_OP_SPECIAL << EURASIA_USE1_OP_SHIFT) |
							(aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
							dwFlags;
}

/*
	Helper to construct a MOV USE-instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildMOV)
#endif
FORCE_INLINE void BuildMOV(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   IMG_UINT32		dwSrc1Mod)
{
	PVR_ASSERT((IMG_UINT32)eDestType < (sizeof(aui32RegTypeToUSE1DestBank) / sizeof(aui32RegTypeToUSE1DestBank[0])));
	PVR_ASSERT((IMG_UINT32)eSrc1Type < (sizeof(aui32RegTypeToUSE0Src1Bank) / sizeof(aui32RegTypeToUSE0Src1Bank[0])));

	PVR_ASSERT(dwDestIdx < EURASIA_USE_REGISTER_NUMBER_MAX);
	PVR_ASSERT(dwSrc1Idx < EURASIA_USE_REGISTER_NUMBER_MAX);

	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (EURASIA_USE0_S2EXTBANK_IMMEDIATE << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT);

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_MOVC << EURASIA_USE1_OP_SHIFT) |	
						 (EURASIA_USE1_MOVC_TSTDTYPE_UNCOND << EURASIA_USE1_MOVC_TSTDTYPE_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (aui32RegTypeToUSE1DestBExt[eDestType]) |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 EURASIA_USE1_S2BEXT |
						 (dwRCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						 (dwSrc1Mod << EURASIA_USE1_SRC1MOD_SHIFT) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
						 dwFlags |
						 EURASIA_USE1_SKIPINV;
}

/*
	Helper to construct a general FARITH USE-instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildFARITH)
#endif
FORCE_INLINE void BuildFARITH(PPVR_USE_INST		psUSEInst,
						  IMG_UINT32			ui32OP2,
						  IMG_UINT32			ui32EPRED,
						  IMG_UINT32			ui32RCount,
						  IMG_UINT32			ui32Flags,
						  USE_REGTYPE			eDestType,
						  IMG_UINT32			ui32DestIdx,
						  USE_REGTYPE			eSrc0Type,
						  IMG_UINT32			ui32Src0Idx,
						  IMG_UINT32			ui32Src0Mod,
						  USE_REGTYPE			eSrc1Type,
						  IMG_UINT32			ui32Src1Idx,
						  IMG_UINT32			ui32Src1Mod,
						  USE_REGTYPE			eSrc2Type,
						  IMG_UINT32			ui32Src2Idx,
						  IMG_UINT32			ui32Src2Mod)
{
	PVR_ASSERT(eSrc0Type == USE_REGTYPE_PRIMATTR || eSrc0Type == USE_REGTYPE_TEMP);

	PVR_ASSERT((IMG_UINT32)eDestType < (sizeof(aui32RegTypeToUSE1DestBank) / sizeof(aui32RegTypeToUSE1DestBank[0])));
	PVR_ASSERT((IMG_UINT32)eSrc0Type < (sizeof(aui32RegTypeToUSE1Src0Bank) / sizeof(aui32RegTypeToUSE1Src0Bank[0])));
	PVR_ASSERT((IMG_UINT32)eSrc1Type < (sizeof(aui32RegTypeToUSE0Src1Bank) / sizeof(aui32RegTypeToUSE0Src1Bank[0])));
	PVR_ASSERT((IMG_UINT32)eSrc2Type < (sizeof(aui32RegTypeToUSE0Src2Bank) / sizeof(aui32RegTypeToUSE0Src2Bank[0])));

	PVR_ASSERT(ui32DestIdx < EURASIA_USE_REGISTER_NUMBER_MAX);
	PVR_ASSERT(ui32Src0Idx < EURASIA_USE_REGISTER_NUMBER_MAX);
	PVR_ASSERT(ui32Src1Idx < EURASIA_USE_REGISTER_NUMBER_MAX);
	PVR_ASSERT(ui32Src2Idx < EURASIA_USE_REGISTER_NUMBER_MAX);

	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						 (ui32DestIdx << EURASIA_USE0_DST_SHIFT) |
						 (ui32Src0Idx << EURASIA_USE0_SRC0_SHIFT) |
						 (ui32Src1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (ui32Src2Idx << EURASIA_USE0_SRC2_SHIFT);

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_FARITH << EURASIA_USE1_OP_SHIFT) |
						 (ui32OP2 << EURASIA_USE1_FLOAT_OP2_SHIFT) |
						 (ui32EPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (ui32RCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						 (aui32RegTypeToUSE1DestBExt[eDestType]) |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (aui32RegTypeToUSE1Src2BExt[eSrc2Type]) |
						 (ui32Src0Mod << EURASIA_USE1_SRC0MOD_SHIFT) |
						 (ui32Src1Mod << EURASIA_USE1_SRC1MOD_SHIFT) |
						 (ui32Src2Mod << EURASIA_USE1_SRC2MOD_SHIFT) |
						 (aui32RegTypeToUSE1Src0Bank[eSrc0Type] << EURASIA_USE1_S0BANK_SHIFT) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
						 ui32Flags |
						 EURASIA_USE1_SKIPINV;
}

/*
	Helper to construct a DDPC USE-instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildDDPC)
#endif
FORCE_INLINE void BuildDDPC(PPVR_USE_INST	psUSEInst,
						IMG_UINT32		dwEPRED,
						IMG_UINT32		dwRCount,
						IMG_UINT32		dwFlags,
						IMG_UINT32		dwPlaneIdx0,
						IMG_UINT32		dwPlaneIdx1,
						IMG_UINT32		dwFPInternalUpdate,
						USE_REGTYPE	eDestType,
						IMG_UINT32		dwDestIdx,
						USE_REGTYPE	eSrc0Type,
						IMG_UINT32		dwSrc0Idx,
						USE_REGTYPE	eSrc1Type,
						IMG_UINT32		dwSrc1Idx,
						USE_REGTYPE	eSrc2Type,
						IMG_UINT32		dwSrc2Idx)
{
	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						 (dwSrc0Idx << EURASIA_USE0_SRC0_SHIFT) |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT);
						 
	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_FDOTPRODUCT << EURASIA_USE1_OP_SHIFT) |
						 (EURASIA_USE1_FLOAT_OP2_DDPC << EURASIA_USE1_FLOAT_OP2_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (dwRCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						 dwFlags |
						 EURASIA_USE1_SKIPINV |
						 dwFPInternalUpdate |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (aui32RegTypeToUSE1Src2BExt[eSrc2Type]) |
						 (dwPlaneIdx0 << (EURASIA_USE1_DDPC_CLIPPLANEUPDATE_SHIFT + 0)) |
						 (dwPlaneIdx1 << (EURASIA_USE1_DDPC_CLIPPLANEUPDATE_SHIFT + 3)) |
						 (aui32RegTypeToUSE1Src0Bank[eSrc0Type] << EURASIA_USE1_S0BANK_SHIFT) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT);
}

/*
	Helper to construct a DDP USE-instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildDDP)
#endif
FORCE_INLINE void BuildDDP(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   IMG_UINT32		dwFPInternalUpdate,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc0Type,
					   IMG_UINT32		dwSrc0Idx,
					   IMG_UINT32		dwSrc0Mod,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   IMG_UINT32		dwSrc1Mod,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx,
					   IMG_UINT32		dwSrc2Mod)
{
	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						 (dwSrc0Idx << EURASIA_USE0_SRC0_SHIFT) |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT);
						 
	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_FDOTPRODUCT << EURASIA_USE1_OP_SHIFT) |
						 (EURASIA_USE1_FLOAT_OP2_DDP << EURASIA_USE1_FLOAT_OP2_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (dwRCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						 dwFlags |
						 EURASIA_USE1_SKIPINV |
						 dwFPInternalUpdate |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (aui32RegTypeToUSE1Src2BExt[eSrc2Type]) |
						 (dwSrc0Mod << EURASIA_USE1_SRC0MOD_SHIFT) |
						 (dwSrc1Mod << EURASIA_USE1_SRC1MOD_SHIFT) |
						 (dwSrc2Mod << EURASIA_USE1_SRC2MOD_SHIFT) |
						 (aui32RegTypeToUSE1Src0Bank[eSrc0Type] << EURASIA_USE1_S0BANK_SHIFT) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT);
}

/*
	Helper to construct a DPC USE-instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildDPC)
#endif
FORCE_INLINE void BuildDPC(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   IMG_UINT32		dwPlaneIdx,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   IMG_UINT32		dwSrc1Mod,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx,
					   IMG_UINT32		dwSrc2Mod)
{
	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						 (dwPlaneIdx << EURASIA_USE0_DP_CLIPPLANEUPDATE_SHIFT) |
						 EURASIA_USE0_DP_CLIPENABLE |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT);
						 
	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_FDOTPRODUCT << EURASIA_USE1_OP_SHIFT) |
						 (EURASIA_USE1_FLOAT_OP2_DP << EURASIA_USE1_FLOAT_OP2_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (dwFlags & ~EURASIA_USE1_RCNTSEL) |
						 EURASIA_USE1_SKIPINV |
						 (aui32RegTypeToUSE1DestBExt[eDestType]) |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (aui32RegTypeToUSE1Src2BExt[eSrc2Type]) |
						 (dwSrc1Mod << EURASIA_USE1_SRC1MOD_SHIFT) |
						 (dwSrc2Mod << EURASIA_USE1_SRC2MOD_SHIFT) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT);
	#if defined(SGX_FEATURE_USE_PER_INST_MOE_INCREMENTS)
	PVR_ASSERT(dwRCount < SGX545_USE1_FLOAT_RCOUNT_MAXIMUM);
	PVR_ASSERT(dwFlags & EURASIA_USE1_RCNTSEL);
	psUSEInst->ui32Word1 |= SGX545_USE1_FLOAT_MOE | (dwRCount << SGX545_USE1_FLOAT_RCNT_SHIFT);
	#else /* defined(SGX_FEATURE_USE_PER_INST_MOE_INCREMENTS) */
	psUSEInst->ui32Word1 |= (dwRCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						  (dwFlags & EURASIA_USE1_RCNTSEL);
	#endif /* defined(SGX_FEATURE_USE_PER_INST_MOE_INCREMENTS) */
}

/*
	Helper to construct a DP USE-instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildDP)
#endif
FORCE_INLINE void BuildDP(PPVR_USE_INST		psUSEInst,
					  IMG_UINT32			dwEPRED,
					  IMG_UINT32			dwRCount,
					  IMG_UINT32			dwFlags,
					  USE_REGTYPE	eDestType,
					  IMG_UINT32			dwDestIdx,
					  USE_REGTYPE	eSrc1Type,
					  IMG_UINT32			dwSrc1Idx,
					  IMG_UINT32			dwSrc1Mod,
					  USE_REGTYPE	eSrc2Type,
					  IMG_UINT32			dwSrc2Idx,
					  IMG_UINT32			dwSrc2Mod)
{
	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT);
						 
	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_FDOTPRODUCT << EURASIA_USE1_OP_SHIFT) |
						 (EURASIA_USE1_FLOAT_OP2_DP << EURASIA_USE1_FLOAT_OP2_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (dwRCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						 dwFlags |
						 EURASIA_USE1_SKIPINV |
						 (aui32RegTypeToUSE1DestBExt[eDestType]) |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (aui32RegTypeToUSE1Src2BExt[eSrc2Type]) |
						 (dwSrc1Mod << EURASIA_USE1_SRC1MOD_SHIFT) |
						 (dwSrc2Mod << EURASIA_USE1_SRC2MOD_SHIFT) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT);
}

/*
	Helper to construct a general FSCALAR USE-instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildFSCALAR)
#endif
FORCE_INLINE void BuildFSCALAR(PPVR_USE_INST	psUSEInst,
						   IMG_UINT32		dwOP2,
						   IMG_UINT32		dwEPRED,
						   IMG_UINT32		dwRCount,
						   IMG_UINT32		dwFlags,
						   USE_REGTYPE	eDestType,
						   IMG_UINT32		dwDestIdx,
						   USE_REGTYPE	eSrc1Type,
						   IMG_UINT32		dwSrc1Idx,
						   IMG_UINT32		dwSrc1Mod)
{
	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT);

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_FSCALAR << EURASIA_USE1_OP_SHIFT) |
						 (dwOP2 << EURASIA_USE1_FLOAT_OP2_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (dwRCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						 (aui32RegTypeToUSE1DestBExt[eDestType]) |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (dwSrc1Mod << EURASIA_USE1_SRC1MOD_SHIFT) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
						 dwFlags |
						 EURASIA_USE1_SKIPINV; 
}

#if defined(SGX_FEATURE_USE_FCLAMP)
/*
	Helper to construct a general FCLAMP USE-instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildFCLAMP)
#endif
FORCE_INLINE void BuildFCLAMP(PPVR_USE_INST	psUSEInst,
						  IMG_UINT32			dwOP2,
						  IMG_UINT32			dwEPRED,
						  IMG_UINT32			dwRCount,
						  IMG_UINT32			dwFlags,
						  USE_REGTYPE	eDestType,
						  IMG_UINT32			dwDestIdx,
						  USE_REGTYPE	eSrc0Type,
						  IMG_UINT32			dwSrc0Idx,
						  IMG_UINT32			dwSrc0Mod,
						  USE_REGTYPE	eSrc1Type,
						  IMG_UINT32			dwSrc1Idx,
						  IMG_UINT32			dwSrc1Mod,
						  USE_REGTYPE	eSrc2Type,
						  IMG_UINT32			dwSrc2Idx,
						  IMG_UINT32			dwSrc2Mod)
{
	PVR_ASSERT(dwRCount < SGX545_USE1_FLOAT_RCOUNT_MAXIMUM);
	PVR_ASSERT(dwFlags & EURASIA_USE1_RCNTSEL);
	PVR_ASSERT(!aui32RegTypeToUSE1Src0BExt[eSrc0Type]);
	PVR_ASSERT(!(dwSrc0Mod & EURASIA_USE_SRCMOD_NEGATE));

	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						 (dwSrc0Idx << EURASIA_USE0_SRC0_SHIFT) |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT);

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_FMINMAX << EURASIA_USE1_OP_SHIFT) |
						 (dwOP2 << EURASIA_USE1_FLOAT_OP2_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (dwRCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						 (aui32RegTypeToUSE1DestBExt[eDestType]) |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (aui32RegTypeToUSE1Src2BExt[eSrc2Type]) |
						 (dwSrc1Mod << EURASIA_USE1_SRC1MOD_SHIFT) |
						 (dwSrc2Mod << EURASIA_USE1_SRC2MOD_SHIFT) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
						 (aui32RegTypeToUSE1Src0Bank[eSrc0Type] << EURASIA_USE1_S0BANK_SHIFT) |
						 dwFlags |
						 EURASIA_USE1_SKIPINV;
	if (dwSrc0Mod & EURASIA_USE_SRCMOD_ABSOLUTE)
	{
		psUSEInst->ui32Word1 |= SGX545_USE1_FLOAT_SRC0ABS;
	}
}
#else /* defined(SGX_FEATURE_USE_FCLAMP) */
/*
	Helper to construct a general FMINMAX USE-instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildFMINMAX)
#endif
FORCE_INLINE void BuildFMINMAX(PPVR_USE_INST	psUSEInst,
						   IMG_UINT32		dwOP2,
						   IMG_UINT32		dwEPRED,
						   IMG_UINT32		dwRCount,
						   IMG_UINT32		dwFlags,
						   USE_REGTYPE	eDestType,
						   IMG_UINT32		dwDestIdx,
						   USE_REGTYPE	eSrc1Type,
						   IMG_UINT32		dwSrc1Idx,
						   IMG_UINT32		dwSrc1Mod,
						   USE_REGTYPE	eSrc2Type,
						   IMG_UINT32		dwSrc2Idx,
						   IMG_UINT32		dwSrc2Mod)
{
	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT);

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_FMINMAX << EURASIA_USE1_OP_SHIFT) |
						 (dwOP2 << EURASIA_USE1_FLOAT_OP2_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (dwRCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						 (aui32RegTypeToUSE1DestBExt[eDestType]) |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (aui32RegTypeToUSE1Src2BExt[eSrc2Type]) |
						 (dwSrc1Mod << EURASIA_USE1_SRC1MOD_SHIFT) |
						 (dwSrc2Mod << EURASIA_USE1_SRC2MOD_SHIFT) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
						 dwFlags |
						 EURASIA_USE1_SKIPINV;
}
#endif /* defined(SGX_FEATURE_USE_FCLAMP) */

/*
	Helper to construct a general PCKUNPCK USE-instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildPCKUNPCK)
#endif
FORCE_INLINE void BuildPCKUNPCK(PPVR_USE_INST	psUSEInst,
						    IMG_UINT32		dwEPRED,
						    IMG_UINT32		dwRCount,
						    IMG_UINT32		dwFlags,
							IMG_UINT32		dwDestFormat,
							IMG_UINT32		dwSrcFormat,
							IMG_UINT32		dwScale,
						    USE_REGTYPE	eDestType,
						    IMG_UINT32		dwDestIdx,
							IMG_UINT32		dwDestCompMask,
						    USE_REGTYPE	eSrc1Type,
						    IMG_UINT32		dwSrc1Idx,
						    IMG_UINT32		dwSrc1CompSel,
						    USE_REGTYPE	eSrc2Type,
						    IMG_UINT32		dwSrc2Idx,
						    IMG_UINT32		dwSrc2CompSel)
{
	psUSEInst->ui32Word0	= (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						  (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						  (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						  (dwScale & EURASIA_USE0_PCK_SCALE) |
						  (dwSrc1CompSel << EURASIA_USE0_PCK_S1SCSEL_SHIFT) |
						  (dwSrc2CompSel << EURASIA_USE0_PCK_S2SCSEL_SHIFT) |
						  (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						  (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT);

	psUSEInst->ui32Word1	= (EURASIA_USE1_OP_PCKUNPCK << EURASIA_USE1_OP_SHIFT) |
						  (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						  (dwRCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						  (aui32RegTypeToUSE1DestBExt[eDestType]) |
						  (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						  (aui32RegTypeToUSE1Src2BExt[eSrc2Type]) |
						  (dwSrcFormat << EURASIA_USE1_PCK_SRCF_SHIFT) |
						  (dwDestFormat << EURASIA_USE1_PCK_DSTF_SHIFT) |
						  (dwDestCompMask << EURASIA_USE1_PCK_DMASK_SHIFT) |
						  (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
						  dwFlags |
						  EURASIA_USE1_SKIPINV;
}

/*
	Helper to construct a LIMM USE-instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildLIMM)
#endif
FORCE_INLINE void BuildLIMM(PPVR_USE_INST	psUSEInst,
					    IMG_UINT32		dwEPRED,
						IMG_UINT32		dwFlags,
						USE_REGTYPE	eDestType,
						IMG_UINT32		dwDestIdx,
						IMG_UINT32		dwValue)
{
	psUSEInst->ui32Word0 = (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						 (((dwValue >> 0) << EURASIA_USE0_LIMM_IMML21_SHIFT) & (~EURASIA_USE0_LIMM_IMML21_CLRMSK));

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_SPECIAL << EURASIA_USE1_OP_SHIFT) |
						 (EURASIA_USE1_SPECIAL_OPCAT_OTHER << EURASIA_USE1_SPECIAL_OPCAT_SHIFT) |
						 (EURASIA_USE1_OTHER_OP2_LIMM << EURASIA_USE1_OTHER_OP2_SHIFT) |
						 (dwEPRED << EURASIA_USE1_LIMM_EPRED_SHIFT) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
						 (aui32RegTypeToUSE1DestBExt[eDestType]) |
						 (((dwValue >> 21) << EURASIA_USE1_LIMM_IMM2521_SHIFT) & (~EURASIA_USE1_LIMM_IMM2521_CLRMSK)) |
						 (((dwValue >> 26) << EURASIA_USE1_LIMM_IMM3126_SHIFT) & (~EURASIA_USE1_LIMM_IMM3126_CLRMSK)) |
						 dwFlags |
						 EURASIA_USE1_SKIPINV;
}

/*
	Helper to construct BITWISE USE-instructions (except RLP) where SRC2 is not
	an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildBITWISE)
#endif
FORCE_INLINE void BuildBITWISE(PPVR_USE_INST	psUSEInst,
						   IMG_UINT32		dwOP,
						   IMG_UINT32		dwOP2,
						   IMG_UINT32		dwEPRED,
						   IMG_UINT32		dwRCount,
						   IMG_UINT32		dwFlags,
						   USE_REGTYPE	eDestType,
						   IMG_UINT32		dwDestIdx,
						   USE_REGTYPE	eSrc1Type,
						   IMG_UINT32		dwSrc1Idx,
						   USE_REGTYPE	eSrc2Type,
						   IMG_UINT32		dwSrc2Idx)
{
	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT);

	psUSEInst->ui32Word1 = (dwOP << EURASIA_USE1_OP_SHIFT) |
						 (dwOP2 << EURASIA_USE1_BITWISE_OP2_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (dwRCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						 (aui32RegTypeToUSE1DestBExt[eDestType]) |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (aui32RegTypeToUSE1Src2BExt[eSrc2Type]) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
						 dwFlags |
						 EURASIA_USE1_SKIPINV;
}

/*
	Helper to construct BITWISE USE-instructions (except RLP) where SRC2 is
	an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildBITWISEIMM)
#endif
FORCE_INLINE void BuildBITWISEIMM(PPVR_USE_INST		psUSEInst,
							  IMG_UINT32			dwOP,
							  IMG_UINT32			dwOP2,
							  IMG_UINT32			dwEPRED,
							  IMG_UINT32			dwRCount,
							  IMG_UINT32			dwFlags,
							  USE_REGTYPE	eDestType,
							  IMG_UINT32			dwDestIdx,
							  USE_REGTYPE	eSrc1Type,
							  IMG_UINT32			dwSrc1Idx,
							  IMG_UINT32			dwSrc2Imm,
							  IMG_UINT32			dwSrc2LShift)
{
	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[USE_REGTYPE_IMMEDIATE] << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwDestIdx << EURASIA_USE0_DST_SHIFT) |
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (((dwSrc2Imm >> 7) << EURASIA_USE0_BITWISE_SRC2IEXTLPSEL_SHIFT) & (~EURASIA_USE0_BITWISE_SRC2IEXTLPSEL_CLRMSK)) |
						 (((dwSrc2Imm >> 0) << EURASIA_USE0_SRC2_SHIFT) & (~EURASIA_USE0_SRC2_CLRMSK));

	psUSEInst->ui32Word1 = (dwOP << EURASIA_USE1_OP_SHIFT) |
						 (dwOP2 << EURASIA_USE1_BITWISE_OP2_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (dwRCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						 (aui32RegTypeToUSE1DestBExt[eDestType]) |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (aui32RegTypeToUSE1Src2BExt[USE_REGTYPE_IMMEDIATE]) |
						 (((dwSrc2Imm >> 14) << EURASIA_USE1_BITWISE_SRC2IEXTH_SHIFT) & (~EURASIA_USE1_BITWISE_SRC2IEXTH_CLRMSK)) |
						 (dwSrc2LShift << EURASIA_USE1_BITWISE_SRC2ROT_SHIFT) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
						 dwFlags |
						 EURASIA_USE1_SKIPINV;
}

/*
	Helper to construct RLP USE-instructions
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildRLP)
#endif
FORCE_INLINE void BuildRLP(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   IMG_UINT32		dwPredIdx,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx)
{
	psUSEInst->ui32Word0 = (aui32RegTypeToUSE0Src1Bank[eSrc1Type] << EURASIA_USE0_S1BANK_SHIFT) |
						 (aui32RegTypeToUSE0Src2Bank[eSrc2Type] << EURASIA_USE0_S2BANK_SHIFT) |
						 (dwDestIdx << EURASIA_USE0_DST_SHIFT) |				 
						 (dwSrc1Idx << EURASIA_USE0_SRC1_SHIFT) |
						 (dwSrc2Idx << EURASIA_USE0_SRC2_SHIFT) |
						 (dwPredIdx << EURASIA_USE0_BITWISE_SRC2IEXTLPSEL_SHIFT);

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_ANDOR << EURASIA_USE1_OP_SHIFT) |
						 (EURASIA_USE1_BITWISE_OP2_RLP << EURASIA_USE1_BITWISE_OP2_SHIFT) |
						 (dwEPRED << EURASIA_USE1_EPRED_SHIFT) |
						 (dwRCount << EURASIA_USE1_RMSKCNT_SHIFT) |
						 (aui32RegTypeToUSE1DestBExt[eDestType]) |
						 (aui32RegTypeToUSE1Src1BExt[eSrc1Type]) |
						 (aui32RegTypeToUSE1Src2BExt[eSrc2Type]) |
						 (aui32RegTypeToUSE1DestBank[eDestType] << EURASIA_USE1_D1BANK_SHIFT) |
						 dwFlags |
						 EURASIA_USE1_SKIPINV;
}

/*
	Helper to construct SMLSI USE-instructions
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildSMBO)
#endif
FORCE_INLINE void BuildSMBO(PPVR_USE_INST		psUSEInst,
						 IMG_UINT32			dwDestBOFF,
						 IMG_UINT32			dwSrc0BOFF,
						 IMG_UINT32			dwSrc1BOFF,
						 IMG_UINT32			dwSrc2BOFF)
{
	psUSEInst->ui32Word0 = 	((dwSrc0BOFF << EURASIA_USE0_MOECTRL_SMR_S0RANGE_SHIFT) & (~EURASIA_USE0_MOECTRL_SMR_S0RANGE_CLRMSK)) |
							(dwSrc1BOFF << EURASIA_USE0_MOECTRL_SMR_S1RANGE_SHIFT) |
							(dwSrc2BOFF << EURASIA_USE0_MOECTRL_SMR_S2RANGE_SHIFT);

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_SPECIAL << EURASIA_USE1_OP_SHIFT) |
						 (EURASIA_USE1_MOECTRL_OP2_SMBO << EURASIA_USE1_MOECTRL_OP2_SHIFT) |
						 (EURASIA_USE1_SPECIAL_OPCAT_MOECTRL << EURASIA_USE1_SPECIAL_OPCAT_SHIFT) |
						 (dwDestBOFF << EURASIA_USE1_MOECTRL_SMR_DRANGE_SHIFT) |
						 ((dwSrc0BOFF << EURASIA_USE1_MOECTRL_SMR_S0RANGE_SHIFT) & (~EURASIA_USE1_MOECTRL_SMR_S0RANGE_CLRMSK)) |
						 EURASIA_USE1_SKIPINV;
}

/*
	Helper to construct SMLSI USE-instructions
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildSMLSI)
#endif
FORCE_INLINE void BuildSMLSI(PPVR_USE_INST		psUSEInst,
						 IMG_UINT32			dwTempLim,
						 IMG_UINT32			dwPrimAttrLim,
						 IMG_UINT32			dwSecAttrLim,
						 IMG_UINT32			dwSwizEnableFlags,
						 IMG_UINT32			dwDestIncSwiz,
						 IMG_UINT32			dwSrc0IncSwiz,
						 IMG_UINT32			dwSrc1IncSwiz,
						 IMG_UINT32			dwSrc2IncSwiz)
{
	psUSEInst->ui32Word0 = (dwSrc2IncSwiz << EURASIA_USE0_MOECTRL_SMLSI_S2INC_SHIFT) |
						 (dwSrc1IncSwiz << EURASIA_USE0_MOECTRL_SMLSI_S1INC_SHIFT) |
						 (dwSrc0IncSwiz << EURASIA_USE0_MOECTRL_SMLSI_S0INC_SHIFT) |
						 (dwDestIncSwiz << EURASIA_USE0_MOECTRL_SMLSI_DINC_SHIFT);

	psUSEInst->ui32Word1 = (EURASIA_USE1_OP_SPECIAL << EURASIA_USE1_OP_SHIFT) |
						 (EURASIA_USE1_MOECTRL_OP2_SMLSI << EURASIA_USE1_MOECTRL_OP2_SHIFT) |
						 (EURASIA_USE1_SPECIAL_OPCAT_MOECTRL << EURASIA_USE1_SPECIAL_OPCAT_SHIFT) |
						 (dwSecAttrLim << EURASIA_USE1_MOECTRL_SMLSI_SLIMIT_SHIFT) |
						 (dwPrimAttrLim << EURASIA_USE1_MOECTRL_SMLSI_PLIMIT_SHIFT) |
						 (dwTempLim << EURASIA_USE1_MOECTRL_SMLSI_TLIMIT_SHIFT) |
						 dwSwizEnableFlags |
						 EURASIA_USE1_SKIPINV;
}

/*
	Helper to construct an AND USE-instruction where SRC2 is an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildANDIMM)
#endif
FORCE_INLINE void BuildANDIMM(PPVR_USE_INST		psUSEInst,
						  IMG_UINT32			dwEPRED,
						  IMG_UINT32			dwRCount,
						  IMG_UINT32			dwFlags,
						  USE_REGTYPE	eDestType,
						  IMG_UINT32			dwDestIdx,
						  USE_REGTYPE	eSrc1Type,
						  IMG_UINT32			dwSrc1Idx,
						  IMG_UINT32			dwSrc2Imm,
						  IMG_UINT32			dwSrc2LShift)
{
	BuildBITWISEIMM(psUSEInst,
					EURASIA_USE1_OP_ANDOR,
					EURASIA_USE1_BITWISE_OP2_AND,
					dwEPRED, dwRCount,
					dwFlags,
					eDestType, dwDestIdx,
					eSrc1Type, dwSrc1Idx,
					dwSrc2Imm, dwSrc2LShift);
}

/*
	Helper to construct an AND USE-instruction where SRC2 is not an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildAND)
#endif
FORCE_INLINE void BuildAND(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx)
{
	BuildBITWISE(psUSEInst,
				 EURASIA_USE1_OP_ANDOR,
				 EURASIA_USE1_BITWISE_OP2_AND,
				 dwEPRED, dwRCount,
				 dwFlags,
				 eDestType, dwDestIdx,
				 eSrc1Type, dwSrc1Idx,
				 eSrc2Type, dwSrc2Idx);
}

/*
	Helper to construct an OR USE-instruction where SRC2 is an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildORIMM)
#endif
FORCE_INLINE void BuildORIMM(PPVR_USE_INST		psUSEInst,
						 IMG_UINT32			dwEPRED,
						 IMG_UINT32			dwRCount,
						 IMG_UINT32			dwFlags,
						 USE_REGTYPE	eDestType,
						 IMG_UINT32			dwDestIdx,
						 USE_REGTYPE	eSrc1Type,
						 IMG_UINT32			dwSrc1Idx,
						 IMG_UINT32			dwSrc2Imm,
						 IMG_UINT32			dwSrc2LShift)
{
	BuildBITWISEIMM(psUSEInst,
					EURASIA_USE1_OP_ANDOR,
					EURASIA_USE1_BITWISE_OP2_OR,
					dwEPRED, dwRCount,
					dwFlags,
					eDestType, dwDestIdx,
					eSrc1Type, dwSrc1Idx,
					dwSrc2Imm, dwSrc2LShift);
}

/*
	Helper to construct an OR USE-instruction where SRC2 is not an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildOR)
#endif
FORCE_INLINE void BuildOR(PPVR_USE_INST		psUSEInst,
					  IMG_UINT32			dwEPRED,
					  IMG_UINT32			dwRCount,
					  IMG_UINT32			dwFlags,
					  USE_REGTYPE	eDestType,
					  IMG_UINT32			dwDestIdx,
					  USE_REGTYPE	eSrc1Type,
					  IMG_UINT32			dwSrc1Idx,
					  USE_REGTYPE	eSrc2Type,
					  IMG_UINT32			dwSrc2Idx)
{
	BuildBITWISE(psUSEInst,
				 EURASIA_USE1_OP_ANDOR,
				 EURASIA_USE1_BITWISE_OP2_OR,
				 dwEPRED, dwRCount,
				 dwFlags,
			     eDestType, dwDestIdx,
			     eSrc1Type, dwSrc1Idx,
			     eSrc2Type, dwSrc2Idx);
}

/*
	Helper to construct a SHR USE-instruction where SRC2 is an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildSHRIMM)
#endif
FORCE_INLINE void BuildSHRIMM(PPVR_USE_INST		psUSEInst,
						  IMG_UINT32			dwEPRED,
						  IMG_UINT32			dwRCount,
						  IMG_UINT32			dwFlags,
						  USE_REGTYPE	eDestType,
						  IMG_UINT32			dwDestIdx,
						  USE_REGTYPE	eSrc1Type,
						  IMG_UINT32			dwSrc1Idx,
						  IMG_UINT32			dwSrc2Imm,
						  IMG_UINT32			dwSrc2LShift)
{
	BuildBITWISEIMM(psUSEInst,
					EURASIA_USE1_OP_SHRASR,
					EURASIA_USE1_BITWISE_OP2_SHR,
					dwEPRED, dwRCount,
					dwFlags,
					eDestType, dwDestIdx,
					eSrc1Type, dwSrc1Idx,
					dwSrc2Imm, dwSrc2LShift);
}

/*
	Helper to construct a SHR USE-instruction where SRC2 is not an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildSHR)
#endif
FORCE_INLINE void BuildSHR(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx)
{
	BuildBITWISE(psUSEInst,
				 EURASIA_USE1_OP_SHRASR,
				 EURASIA_USE1_BITWISE_OP2_SHR,
				 dwEPRED, dwRCount,
				 dwFlags,
				 eDestType, dwDestIdx,
				 eSrc1Type, dwSrc1Idx,
				 eSrc2Type, dwSrc2Idx);
}

/*
	Helper to construct a ASR USE-instruction where SRC2 is an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildASRIMM)
#endif
FORCE_INLINE void BuildASRIMM(PPVR_USE_INST		psUSEInst,
						  IMG_UINT32			dwEPRED,
						  IMG_UINT32			dwRCount,
						  IMG_UINT32			dwFlags,
						  USE_REGTYPE	eDestType,
						  IMG_UINT32			dwDestIdx,
						  USE_REGTYPE	eSrc1Type,
						  IMG_UINT32			dwSrc1Idx,
						  IMG_UINT32			dwSrc2Imm,
						  IMG_UINT32			dwSrc2LShift)
{
	BuildBITWISEIMM(psUSEInst,
					EURASIA_USE1_OP_SHRASR,
					EURASIA_USE1_BITWISE_OP2_ASR,
					dwEPRED, dwRCount,
					dwFlags,
					eDestType, dwDestIdx,
					eSrc1Type, dwSrc1Idx,
					dwSrc2Imm, dwSrc2LShift);
}

/*
	Helper to construct a ASR USE-instruction where SRC2 is not an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildASR)
#endif
FORCE_INLINE void BuildASR(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx)
{
	BuildBITWISE(psUSEInst,
				 EURASIA_USE1_OP_SHRASR,
				 EURASIA_USE1_BITWISE_OP2_ASR,
				 dwEPRED, dwRCount,
				 dwFlags,
				 eDestType, dwDestIdx,
				 eSrc1Type, dwSrc1Idx,
				 eSrc2Type, dwSrc2Idx);
}

/*
	Helper to construct a XOR USE-instruction where SRC2 is an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildXORIMM)
#endif
FORCE_INLINE void BuildXORIMM(PPVR_USE_INST		psUSEInst,
						  IMG_UINT32			dwEPRED,
						  IMG_UINT32			dwRCount,
						  IMG_UINT32			dwFlags,
						  USE_REGTYPE	eDestType,
						  IMG_UINT32			dwDestIdx,
						  USE_REGTYPE	eSrc1Type,
						  IMG_UINT32			dwSrc1Idx,
						  IMG_UINT32			dwSrc2Imm,
						  IMG_UINT32			dwSrc2LShift)
{
	BuildBITWISEIMM(psUSEInst,
					EURASIA_USE1_OP_XOR,
					EURASIA_USE1_BITWISE_OP2_XOR,
					dwEPRED, dwRCount,
					dwFlags,
					eDestType, dwDestIdx,
					eSrc1Type, dwSrc1Idx,
					dwSrc2Imm, dwSrc2LShift);
}

/*
	Helper to construct a XOR USE-instruction where SRC2 is not an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildXOR)
#endif
FORCE_INLINE void BuildXOR(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx)
{
	BuildBITWISE(psUSEInst,
				 EURASIA_USE1_OP_XOR,
				 EURASIA_USE1_BITWISE_OP2_XOR,
				 dwEPRED, dwRCount,
				 dwFlags,
				 eDestType, dwDestIdx,
				 eSrc1Type, dwSrc1Idx,
				 eSrc2Type, dwSrc2Idx);
}

/*
	Helper to construct a SHL USE-instruction where SRC2 is an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildSHLIMM)
#endif
FORCE_INLINE void BuildSHLIMM(PPVR_USE_INST		psUSEInst,
						  IMG_UINT32			dwEPRED,
						  IMG_UINT32			dwRCount,
						  IMG_UINT32			dwFlags,
						  USE_REGTYPE	eDestType,
						  IMG_UINT32			dwDestIdx,
						  USE_REGTYPE	eSrc1Type,
						  IMG_UINT32			dwSrc1Idx,
						  IMG_UINT32			dwSrc2Imm,
						  IMG_UINT32			dwSrc2LShift)
{
	BuildBITWISEIMM(psUSEInst,
					EURASIA_USE1_OP_SHLROL,
					EURASIA_USE1_BITWISE_OP2_SHL,
					dwEPRED, dwRCount,
					dwFlags,
					eDestType, dwDestIdx,
					eSrc1Type, dwSrc1Idx,
					dwSrc2Imm, dwSrc2LShift);
}

/*
	Helper to construct a SHL USE-instruction where SRC2 is not an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildSHL)
#endif
FORCE_INLINE void BuildSHL(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx)
{
	BuildBITWISE(psUSEInst,
				 EURASIA_USE1_OP_SHLROL,
				 EURASIA_USE1_BITWISE_OP2_SHL,
				 dwEPRED, dwRCount,
				 dwFlags,
				 eDestType, dwDestIdx,
				 eSrc1Type, dwSrc1Idx,
				 eSrc2Type, dwSrc2Idx);
}

/*
	Helper to construct a ROL USE-instruction where SRC2 is an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildROLIM)
#endif
FORCE_INLINE void BuildROLIMM(PPVR_USE_INST		psUSEInst,
						  IMG_UINT32			dwEPRED,
						  IMG_UINT32			dwRCount,
						  IMG_UINT32			dwFlags,
						  USE_REGTYPE	eDestType,
						  IMG_UINT32			dwDestIdx,
						  USE_REGTYPE	eSrc1Type,
						  IMG_UINT32			dwSrc1Idx,
						  IMG_UINT32			dwSrc2Imm,
						  IMG_UINT32			dwSrc2LShift)
{
	BuildBITWISEIMM(psUSEInst,
					EURASIA_USE1_OP_SHLROL,
					EURASIA_USE1_BITWISE_OP2_ROL,
					dwEPRED, dwRCount,
					dwFlags,
					eDestType, dwDestIdx,
					eSrc1Type, dwSrc1Idx,
					dwSrc2Imm, dwSrc2LShift);
}

/*
	Helper to construct a ROL USE-instruction where SRC2 is not an immediate value
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildROL)
#endif
FORCE_INLINE void BuildROL(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx)
{
	BuildBITWISE(psUSEInst,
				 EURASIA_USE1_OP_SHLROL,
				 EURASIA_USE1_BITWISE_OP2_ROL,
				 dwEPRED, dwRCount,
				 dwFlags,
				 eDestType, dwDestIdx,
				 eSrc1Type, dwSrc1Idx,
				 eSrc2Type, dwSrc2Idx);
}

/*
	Helper to build an UNPCKF32 instruction to unpack data to a 32-bit float
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildUNPCKF32)
#endif
FORCE_INLINE void BuildUNPCKF32(PPVR_USE_INST	psUSEInst,
						    IMG_UINT32		dwEPRED,
						    IMG_UINT32		dwRCount,
						    IMG_UINT32		dwFlags,
							IMG_UINT32		dwSrcFormat,
							IMG_UINT32		dwScale,
						    USE_REGTYPE	eDestType,
						    IMG_UINT32		dwDestIdx,
						    USE_REGTYPE	eSrcType,
						    IMG_UINT32		dwSrcIdx,
						    IMG_UINT32		dwSrcCompSel)
{
	BuildPCKUNPCK(psUSEInst,
				  dwEPRED, dwRCount,
				  dwFlags,
				  EURASIA_USE1_PCK_FMT_F32, dwSrcFormat, dwScale,
				  eDestType, dwDestIdx, 0xF,
				  eSrcType, dwSrcIdx, dwSrcCompSel,
				  eSrcType, dwSrcIdx, dwSrcCompSel);
}

/*
	Helper to build an F32PCK instruction to pack 2 32-bit float values
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildF32PCK)
#endif
FORCE_INLINE void BuildF32PCK(PPVR_USE_INST		psUSEInst,
						  IMG_UINT32			dwEPRED,
						  IMG_UINT32			dwRCount,
						  IMG_UINT32			dwFlags,
						  IMG_UINT32			dwDestFormat,
						  IMG_UINT32			dwScale,
						  USE_REGTYPE	eDestType,
						  IMG_UINT32			dwDestIdx,
						  IMG_UINT32			dwDestCompMask,
						  USE_REGTYPE	eSrc1Type,
						  IMG_UINT32			dwSrc1Idx,
						  USE_REGTYPE	eSrc2Type,
						  IMG_UINT32			dwSrc2Idx)
{
	BuildPCKUNPCK(psUSEInst,
				  dwEPRED, dwRCount,
				  dwFlags,
				  dwDestFormat, EURASIA_USE1_PCK_FMT_F32, dwScale,
				  eDestType, dwDestIdx, dwDestCompMask,
				  eSrc1Type, dwSrc1Idx, 0,
				  eSrc2Type, dwSrc2Idx, 0);
}

/*
	Helper to build a MAD USE-instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildMAD)
#endif
FORCE_INLINE void BuildMAD(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc0Type,
					   IMG_UINT32		dwSrc0Idx,
					   IMG_UINT32		dwSrc0Mod,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   IMG_UINT32		dwSrc1Mod,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx,
					   IMG_UINT32		dwSrc2Mod)
{
	BuildFARITH(psUSEInst,
				EURASIA_USE1_FLOAT_OP2_MAD,
				dwEPRED, dwRCount,
				dwFlags,
				eDestType, dwDestIdx,
				eSrc0Type, dwSrc0Idx, dwSrc0Mod, 
				eSrc1Type, dwSrc1Idx, dwSrc1Mod,
				eSrc2Type, dwSrc2Idx, dwSrc2Mod);
}

/*
	Helper to build a ADM USE-instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildADM)
#endif
FORCE_INLINE void BuildADM(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc0Type,
					   IMG_UINT32		dwSrc0Idx,
					   IMG_UINT32		dwSrc0Mod,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   IMG_UINT32		dwSrc1Mod,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx,
					   IMG_UINT32		dwSrc2Mod)
{
	BuildFARITH(psUSEInst,
				EURASIA_USE1_FLOAT_OP2_ADM,
				dwEPRED, dwRCount,
				dwFlags,
				eDestType, dwDestIdx,
				eSrc0Type, dwSrc0Idx, dwSrc0Mod,
				eSrc1Type, dwSrc1Idx, dwSrc1Mod,
				eSrc2Type, dwSrc2Idx, dwSrc2Mod);
}

/*
	Helper to build a RCP USE-instruction
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildRCP)
#endif
FORCE_INLINE void BuildRCP(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   IMG_UINT32		dwSrc1Mod)
{
	BuildFSCALAR(psUSEInst,
				 EURASIA_USE1_FLOAT_OP2_RCP,
				 dwEPRED, dwRCount,
				 dwFlags,
				 eDestType, dwDestIdx,
				 eSrc1Type, dwSrc1Idx, dwSrc1Mod);
}

/*
	Helper to build a MIN USE-instruction
*/
#if defined(SGX_FEATURE_USE_FCLAMP)
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildMIN)
#endif
FORCE_INLINE void BuildMIN(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   IMG_UINT32		dwSrc1Mod,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx,
					   IMG_UINT32		dwSrc2Mod)
{
	BuildFCLAMP(psUSEInst,
				SGX545_USE1_FLOAT_OP2_MAXMIN,
				dwEPRED,
				dwRCount,
				dwFlags,
				eDestType,
				dwDestIdx,
				eSrc1Type,
				dwSrc1Idx,
				dwSrc1Mod,
				eSrc1Type,
				dwSrc1Idx,
				dwSrc1Mod,
				eSrc2Type,
				dwSrc2Idx,
				dwSrc2Mod);
}
#else /* defined(SGX_FEATURE_USE_FCLAMP) */
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildMIN)
#endif
FORCE_INLINE void BuildMIN(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   IMG_UINT32		dwSrc1Mod,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx,
					   IMG_UINT32		dwSrc2Mod)
{
	BuildFMINMAX(psUSEInst,
				 EURASIA_USE1_FLOAT_OP2_MIN,
				 dwEPRED, dwRCount,
				 dwFlags,
				 eDestType, dwDestIdx,
				 eSrc1Type, dwSrc1Idx, dwSrc1Mod,
				 eSrc2Type, dwSrc2Idx, dwSrc2Mod);
}
#endif /* defined(SGX_FEATURE_USE_FCLAMP) */

/*
	Helper to build a MAX USE-instruction
*/
#if defined(SGX_FEATURE_USE_FCLAMP)
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildMAX)
#endif
FORCE_INLINE void BuildMAX(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   IMG_UINT32		dwSrc1Mod,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx,
					   IMG_UINT32		dwSrc2Mod)
{
	BuildFCLAMP(psUSEInst,
				SGX545_USE1_FLOAT_OP2_MINMAX,
				dwEPRED,
				dwRCount,
				dwFlags,
				eDestType,
				dwDestIdx,
				eSrc1Type,
				dwSrc1Idx,
				dwSrc1Mod,
				eSrc2Type,
				dwSrc2Idx,
				dwSrc2Mod,
				eSrc1Type,
				dwSrc1Idx,
				dwSrc1Mod);
}
#else /* defined(SGX_FEATURE_USE_FCLAMP) */
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildMAX)
#endif
FORCE_INLINE void BuildMAX(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   IMG_UINT32		dwSrc1Mod,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx,
					   IMG_UINT32		dwSrc2Mod)
{
	BuildFMINMAX(psUSEInst,
				 EURASIA_USE1_FLOAT_OP2_MAX,
				 dwEPRED, dwRCount,
				 dwFlags,
				 eDestType, dwDestIdx,
				 eSrc1Type, dwSrc1Idx, dwSrc1Mod,
				 eSrc2Type, dwSrc2Idx, dwSrc2Mod);
}
#endif /* defined(SGX_FEATURE_USE_FCLAMP) */

/*
	Helper to build a SDM USE-instruciton to perform:

	dest = DSRC;
	i0 = src0*src1;
	i1 = src0*src2;
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildSDM)
#endif
FORCE_INLINE void BuildSDM(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   IMG_UINT32		dwDSRC,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc0Type,
					   IMG_UINT32		dwSrc0Idx,
					   IMG_UINT32		dwSrc0Mod,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   IMG_UINT32		dwSrc1Mod,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx,
					   IMG_UINT32		dwSrc2Mod)
{
	#if defined(SGX_FEATURE_USE_NEW_EFO_OPTIONS)
	BuildEFO(psUSEInst,
			 dwEPRED, dwRCount,
			 dwFlags | EURASIA_USE1_EFO_WI0EN | EURASIA_USE1_EFO_WI1EN,
			 SGX545_USE1_EFO_MSRC_SRC0SRC2_SRC1SRC2,
			 SGX545_USE1_EFO_ASRC_SRC0SRC2_SRC1SRC2,
			 EURASIA_USE1_EFO_ISRC_I0M0_I1M1,
			 dwDSRC,
			 eDestType, dwDestIdx,
			 eSrc1Type, dwSrc1Idx, dwSrc1Mod,
			 eSrc2Type, dwSrc2Idx, dwSrc2Mod,
			 eSrc0Type, dwSrc0Idx, dwSrc0Mod);
	#else /* defined(SGX_FEATURE_USE_NEW_EFO_OPTIONS) */
	BuildEFO(psUSEInst,
			 dwEPRED, dwRCount,
			 dwFlags | EURASIA_USE1_EFO_WI0EN | EURASIA_USE1_EFO_WI1EN,
			 EURASIA_USE1_EFO_MSRC_SRC0SRC1_SRC0SRC2,
			 EURASIA_USE1_EFO_ASRC_SRC0SRC1_SRC2SRC0,
			 EURASIA_USE1_EFO_ISRC_I0M0_I1M1,
			 dwDSRC,
			 eDestType, dwDestIdx,
			 eSrc0Type, dwSrc0Idx, dwSrc0Mod,
			 eSrc1Type, dwSrc1Idx, dwSrc1Mod,
			 eSrc2Type, dwSrc2Idx, dwSrc2Mod);
	#endif /* defined(SGX_FEATURE_USE_NEW_EFO_OPTIONS) */
}

/*
	Macro to build a DMA USE-instruciton to perform:

	dest = DSRC;
	i0 = src0*src1 + i0;
	i1 = src0*src2 + i1;
*/
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildDMA)
#endif
FORCE_INLINE void BuildDMA(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32		dwEPRED,
					   IMG_UINT32		dwRCount,
					   IMG_UINT32		dwFlags,
					   IMG_UINT32		dwDSRC,
					   USE_REGTYPE	eDestType,
					   IMG_UINT32		dwDestIdx,
					   USE_REGTYPE	eSrc0Type,
					   IMG_UINT32		dwSrc0Idx,
					   IMG_UINT32		dwSrc0Mod,
					   USE_REGTYPE	eSrc1Type,
					   IMG_UINT32		dwSrc1Idx,
					   IMG_UINT32		dwSrc1Mod,
					   USE_REGTYPE	eSrc2Type,
					   IMG_UINT32		dwSrc2Idx,
					   IMG_UINT32		dwSrc2Mod)
{
	#if defined(SGX_FEATURE_USE_NEW_EFO_OPTIONS)
	BuildEFO(psUSEInst,
			 dwEPRED, dwRCount,
			 dwFlags | EURASIA_USE1_EFO_WI0EN | EURASIA_USE1_EFO_WI1EN,
			 SGX545_USE1_EFO_MSRC_SRC0SRC2_SRC1SRC2,
			 SGX545_USE1_EFO_ASRC_M0I0_I1M1,
			 EURASIA_USE1_EFO_ISRC_I0A0_I1A1,
			 dwDSRC,
			 eDestType, dwDestIdx,
			 eSrc1Type, dwSrc1Idx, dwSrc1Mod,
			 eSrc2Type, dwSrc2Idx, dwSrc2Mod,
			 eSrc0Type, dwSrc0Idx, dwSrc0Mod);
	#else /* defined(SGX_FEATURE_USE_NEW_EFO_OPTIONS) */
	BuildEFO(psUSEInst,
			 dwEPRED, dwRCount,
			 dwFlags | EURASIA_USE1_EFO_WI0EN | EURASIA_USE1_EFO_WI1EN,
			 EURASIA_USE1_EFO_MSRC_SRC0SRC1_SRC0SRC2,
			 EURASIA_USE1_EFO_ASRC_M0I0_I1M1,
			 EURASIA_USE1_EFO_ISRC_I0A0_I1A1,
			 dwDSRC,
			 eDestType, dwDestIdx,
			 eSrc0Type, dwSrc0Idx, dwSrc0Mod,
			 eSrc1Type, dwSrc1Idx, dwSrc1Mod,
			 eSrc2Type, dwSrc2Idx, dwSrc2Mod);
	#endif /* defined(SGX_FEATURE_USE_NEW_EFO_OPTIONS) */
}

#if defined(SGX_FEATURE_USE_UNLIMITED_PHASES)
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildPHASImmediate)
#endif
FORCE_INLINE void BuildPHASImmediate(PPVR_USE_INST	psUSEInst,
									 IMG_UINT32		ui32End,
									 IMG_UINT32		ui32Mode,
									 IMG_UINT32		ui32Rate,
									 IMG_UINT32		ui32WaitCond,
									 IMG_UINT32		ui32TempCount,
									 IMG_UINT32		ui32ExeAddr)
{
	psUSEInst->ui32Word0	=	(ui32ExeAddr						<<	EURASIA_USE0_OTHER2_PHAS_IMM_EXEADDR_SHIFT);
	psUSEInst->ui32Word1	=	(EURASIA_USE1_OP_SPECIAL			<<	EURASIA_USE1_OP_SHIFT)						|	
								(EURASIA_USE1_OTHER2_OP2_PHAS		<<	EURASIA_USE1_OTHER2_OP2_SHIFT)				|
								EURASIA_USE1_SPECIAL_OPCAT_EXTRA													|
								(EURASIA_USE1_SPECIAL_OPCAT_OTHER2	<<	EURASIA_USE1_SPECIAL_OPCAT_SHIFT)			|
								ui32End																				|
								EURASIA_USE1_OTHER2_PHAS_IMM														|
								(ui32Mode							<<	EURASIA_USE1_OTHER2_PHAS_IMM_MODE_SHIFT)	|
								(ui32Rate							<<	EURASIA_USE1_OTHER2_PHAS_IMM_RATE_SHIFT)	|
								(ui32WaitCond						<<	EURASIA_USE1_OTHER2_PHAS_IMM_WAITCOND_SHIFT) |
								(ui32TempCount						<<	EURASIA_USE1_OTHER2_PHAS_IMM_TCOUNT_SHIFT);
}

#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildPHASNonImmediate)
#endif
FORCE_INLINE void BuildPHASNonImmediate(PPVR_USE_INST	psUSEInst,
										IMG_UINT32		ui32End,
										IMG_UINT32		ui32NoSched,
										USE_REGTYPE		eSrc1Type,
										IMG_UINT32		ui32Src1Idx,
										USE_REGTYPE		eSrc2Type,
										IMG_UINT32		ui32Src2Idx)
{
	psUSEInst->ui32Word0	=	(aui32RegTypeToUSE0Src1Bank[eSrc1Type]	<< EURASIA_USE0_S1BANK_SHIFT)				|
								(aui32RegTypeToUSE0Src2Bank[eSrc2Type]	<< EURASIA_USE0_S2BANK_SHIFT)				|			 
								(ui32Src1Idx							<< EURASIA_USE0_SRC1_SHIFT)					|
								(ui32Src2Idx							<< EURASIA_USE0_SRC2_SHIFT);
	psUSEInst->ui32Word1	=	(EURASIA_USE1_OP_SPECIAL				<< EURASIA_USE1_OP_SHIFT)					|
								(EURASIA_USE1_OTHER2_OP2_PHAS			<< EURASIA_USE1_OTHER2_OP2_SHIFT)			|
								EURASIA_USE1_SPECIAL_OPCAT_EXTRA													|
								(EURASIA_USE1_SPECIAL_OPCAT_OTHER2		<< EURASIA_USE1_SPECIAL_OPCAT_SHIFT)		|
								ui32End																				|
								ui32NoSched																			|
								(aui32RegTypeToUSE1Src1BExt[eSrc1Type])												|
								(aui32RegTypeToUSE1Src2BExt[eSrc2Type]);
}

#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildPHASNonImmediate2)
#endif
FORCE_INLINE void BuildPHASNonImmediate2(PPVR_USE_INST	psUSEInst,
										 IMG_UINT32		ui32End,
										 IMG_UINT32		ui32NoSched,
										 IMG_UINT32		ui32Mode,
										 IMG_UINT32		ui32WaitCond,
										 IMG_UINT32		ui32Rate,
										 USE_REGTYPE	eSrc2Type,
										 IMG_UINT32		ui32Src2Idx)
{
	USE_REGTYPE		eSrc1Type;
	IMG_UINT32		ui32Src1Idx;

	eSrc1Type = USE_REGTYPE_IMMEDIATE;
	ui32Src1Idx = (ui32Mode		<< EURASIA_USE_OTHER2_PHAS_SRC1_MODE_SHIFT) |
				  (ui32WaitCond	<< EURASIA_USE_OTHER2_PHAS_SRC1_WAITCOND_SHIFT) |
				  (ui32Rate		<< EURASIA_USE_OTHER2_PHAS_SRC1_RATE_SHIFT);

	BuildPHASNonImmediate(psUSEInst,
						  ui32End,
						  ui32NoSched,
						  eSrc1Type,
						  ui32Src1Idx,
						  eSrc2Type,
						  ui32Src2Idx);
}

#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildPHASLastPhase)
#endif
FORCE_INLINE void BuildPHASLastPhase(PPVR_USE_INST		psUSEInst,
									 IMG_UINT32			ui32End)
{
	BuildPHASImmediate(psUSEInst,
					   ui32End,
					   EURASIA_USE_OTHER2_PHAS_MODE_PARALLEL,
					   EURASIA_USE_OTHER2_PHAS_RATE_PIXEL,
					   EURASIA_USE_OTHER2_PHAS_WAITCOND_END,
					   0,
					   0);
}

#endif /* SGX_FEATURE_USE_UNLIMITED_PHASES */

#if defined(SGX545)
#ifdef INLINE_IS_PRAGMA
#pragma inline(BuildCFI)
#endif
FORCE_INLINE void BuildCFI(PPVR_USE_INST	psUSEInst,
					   IMG_UINT32			ui32Flags,
					   IMG_UINT32			ui32Mode,
					   USE_REGTYPE			eSrc1Type,
					   IMG_UINT32			ui32Src1Idx,
					   USE_REGTYPE			eSrc2Type,
					   IMG_UINT32			ui32Src2Idx,
					   IMG_UINT32			ui32Levels)
{
	psUSEInst->ui32Word0	=	(aui32RegTypeToUSE0Src1Bank[eSrc1Type]	<< EURASIA_USE0_S1BANK_SHIFT)			|
								(aui32RegTypeToUSE0Src2Bank[eSrc2Type]	<< EURASIA_USE0_S2BANK_SHIFT)			|			 
								(ui32Src1Idx							<< EURASIA_USE0_SRC1_SHIFT)				|
								(ui32Src2Idx							<< EURASIA_USE0_SRC2_SHIFT);
	psUSEInst->ui32Word1	=	(EURASIA_USE1_OP_SPECIAL				<< EURASIA_USE1_OP_SHIFT)				|
								(SGX545_USE1_OTHER2_OP2_CFI				<< EURASIA_USE1_OTHER2_OP2_SHIFT)		|
								EURASIA_USE1_SPECIAL_OPCAT_EXTRA												|
								(EURASIA_USE1_SPECIAL_OPCAT_OTHER2		<< EURASIA_USE1_SPECIAL_OPCAT_SHIFT)	|
								ui32Flags																		|
								ui32Mode																		|
								(ui32Levels								<< SGX545_USE1_OTHER2_CFI_LEVEL_SHIFT)	|
								(aui32RegTypeToUSE1Src1BExt[eSrc1Type])											|
								(aui32RegTypeToUSE1Src2BExt[eSrc2Type]);
}
#endif /* defined(SGX545) */

#endif	/* #ifndef _usecodegen_h_ */

/*****************************************************************************
 End of file (usecodegen.h)
*****************************************************************************/
