#ifndef __DEBUG_LOG_H__
#define __DEBUG_LOG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdarg.h>
#include "stTime.h"

// show info on the screen
extern int g_ST_INFO_OPEN;
// debug log Output to the local file
extern int g_DEBUG_LOG_FILE_OPEN;

// ---------- 20190110 ---------- ////
void st_Log_T(const char *format, ...);
void st_print_T(const char *format, ...);
void st_info_T(const char *format, ...);
void st_debug_T(const char *format, ...);
//// ---------------------------- ////
void st_print(const char *format, ...);
void st_info(const char *format, ...);
void st_debug(const char *format, ...);

#ifdef __cplusplus
}
#endif
#endif	// __DEBUG_LOG_H__
