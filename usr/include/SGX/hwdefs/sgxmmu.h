/*!****************************************************************************
@File			sgxmmu.h

@Title			SGX MMU defines

@Author			Imagination Technologies

@date   		11/10/2005
 
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

@Platform		

@Description	Provides SGX MMU declarations and macros

@DoxygenVer		

******************************************************************************/

/******************************************************************************
Modifications :-

$Log: sgxmmu.h $
*****************************************************************************/

#if !defined(__SGXMMU_H__)
#define __SGXMMU_H__

/* to be implemented */

/* SGX MMU maps 4Kb pages */
#define SGX_MMU_PAGE_SHIFT				(12)
#define SGX_MMU_PAGE_SIZE				(1UL<<SGX_MMU_PAGE_SHIFT)
#define SGX_MMU_PAGE_MASK				(SGX_MMU_PAGE_SIZE - 1UL)

/* PD details */
#define SGX_MMU_PD_SHIFT				(10)
#define SGX_MMU_PD_SIZE					(1<<SGX_MMU_PD_SHIFT)
#define SGX_MMU_PD_MASK					(0xFFC00000UL)

/* PD Entry details */
#define SGX_MMU_PDE_ADDR_MASK			(0xFFFFF000UL)
#define SGX_MMU_PDE_VALID				(0x00000001UL)
/* variable page size control field */
#define SGX_MMU_PDE_PAGE_SIZE_4K		(0x00000000UL)
#if defined(SGX_FEATURE_VARIABLE_MMU_PAGE_SIZE)
#define SGX_MMU_PDE_PAGE_SIZE_16K		(0x00000002UL)
#define SGX_MMU_PDE_PAGE_SIZE_64K		(0x00000004UL)
#define SGX_MMU_PDE_PAGE_SIZE_256K		(0x00000006UL)
#define SGX_MMU_PDE_PAGE_SIZE_1M		(0x00000008UL)
#define SGX_MMU_PDE_PAGE_SIZE_4M		(0x0000000AUL)
#define SGX_MMU_PDE_PAGE_SIZE_MASK		(0x0000000EUL)
#else
#define SGX_MMU_PDE_WRITEONLY			(0x00000002UL)
#define SGX_MMU_PDE_READONLY			(0x00000004UL)
#define SGX_MMU_PDE_CACHECONSISTENT		(0x00000008UL)
#define SGX_MMU_PDE_EDMPROTECT			(0x00000010UL)
#endif

/* PT details */
#define SGX_MMU_PT_SHIFT				(10)
#define SGX_MMU_PT_SIZE					(1UL<<SGX_MMU_PT_SHIFT)
#define SGX_MMU_PT_MASK					(0x003FF000UL)

/* PT Entry details */
#define SGX_MMU_PTE_ADDR_MASK			(0xFFFFF000UL)
#define SGX_MMU_PTE_VALID				(0x00000001UL)
#define SGX_MMU_PTE_WRITEONLY			(0x00000002UL)
#define SGX_MMU_PTE_READONLY			(0x00000004UL)
#define SGX_MMU_PTE_CACHECONSISTENT		(0x00000008UL)
#define SGX_MMU_PTE_EDMPROTECT			(0x00000010UL)

#endif	/* __SGXMMU_H__ */

/*****************************************************************************
 End of file (sgxmmu.h)
*****************************************************************************/
