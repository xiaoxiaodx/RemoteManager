/*
//  CS2 Network LIMITED All right reserved.
//
//  StringEncDec.h: The Web iPN String Enc / Dec include file
//  Author: Charlie Chang (sengfu@gmail.com)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#ifdef __cplusplus
extern "C" {
#endif

int iPN_StringEnc(const char *keystr, const char *src, char *dest, unsigned int maxsize);
int iPN_StringDnc(const char *keystr, const char *src, char *dest, unsigned int maxsize);

#ifdef __cplusplus
}
#endif