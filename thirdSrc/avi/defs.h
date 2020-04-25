/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : defs.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2005/4/23
  Last Modified :
  Description   : ���ö���
  Function List :
  History       :
  1.Date        : 2005/4/20
    Author      : T41030
    Modification: Created file

******************************************************************************/


#ifndef __HI_DEFS_H__
#define __HI_DEFS_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#ifndef __GNUC__
#define __asm__    asm
#define __inline__ inline
#endif

#define DO_NOTHING

#if HI_OS_TYPE == HI_OS_WIN32
	#ifndef INLINE
		#define INLINE __inline
	#endif
#elif HI_OS_TYPE == HI_OS_LINUX
#define INLINE inline
#endif

/*use for parameter INPUT, *DO NOT Modify the value* */
#define IN
/* use for parameter OUTPUT, the value maybe change when return from the function 
 * the init value is ingore in the function.*/
#define OUT
/*use for parameter INPUT and OUTPUT*/
#define IO

/* --------------------------------  */
#define EXTERN extern
#define STATIC static

#define LOCALVAR static
#define GLOBALVAR extern


/*����ȫ�ֱ���ʱ*/
#define DECLARE_GLOBALVAR 

/*ʹ��ȫ�ֱ���ʱ, �ô�����*/
#define USE_GLOBALVAR extern


#define LOCALFUNC    static
#define EXTERNFUNC   extern



/*�Ͳ�ε�LOW API*/
#define LAPI  
/*�߲��API*/
#define HAPI  
/*Multimedia Frame API*/
#define MMFAPI

/* -------- Standard input/output/err *****/
#define STDIN  stdin
#define STDOUT stdout
#define STDERR stderr

#ifndef MIN
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#endif
#ifndef MAX
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#endif

/*
 * ���ݸ�����ֵv, �Ͷ���λ��a, �����������ʼ��ַ
 * ��4byte����, 0x80001232 ALIGN_START(0x80001232,4) = 0x80001230
 */
#define ALIGN_START(v,a) (((v)) & (~((a)-1)))

/*
 * ���ݸ�����ֵv, �Ͷ���λ��a, ��������Ľ�����ַ��ַ
 * ��4byte����, 0x80001232 ALIGN_END(0x80001232,4) = 0x80001233
 */
#define ALIGN_END(v,a) (((v) & ~((a)-1)) + ((a)-1) ) 
/*
 * ���ݸ�����ֵv, �Ͷ���λ��a, ����������һ��ַ�Ŀ�ʼ��ַ
 * ��4byte����, 0x80001232 ALIGN_NEXT(0x80001232,4) = 0x80001234
 */

#define ALIGN_NEXT(v,a) ((((v) + ((a)-1)) & (~((a)-1))))

#define ALIGN_LENGTH(l, a) ALIGN_NEXT(l, a)

#define ALIGNTYPE_1BYTE  1
/*zsp*/
#define ALIGNTYPE_2BYTE  2
/*x86... default*/
#define ALIGNTYPE_4BYTE  4

#define ALIGNTYPE_8BYTE  8
/*1 Page*/
#define ALIGNTYPE_4K     4096

#define ALIGNTYPE_ZSP    ALIGNTYPE_2BYTE

#define ALIGNTYPE_VIDEO  ALIGNTYPE_8BYTE

#if HI_OS_TYPE == HI_OS_LINUX
#define PRINT_OUT(args...) printf(##args)
#endif

#define PACK_ONE_BYTE  __attribute__((__packed__))


typedef long                    HI_LONG;

#ifndef _M_IX86
typedef unsigned long long      HI_PTS_TIME;
#else
typedef __int64                 HI_PTS_TIME;
#endif




#define  HI_LITTLE_ENDIAN   1234       /* �ֽ���С��ģʽ */
#define  HI_BIG_ENDIAN      4321       /* �ֽ��򣬴��ģʽ */



#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __HI_DEFS_H__ */
