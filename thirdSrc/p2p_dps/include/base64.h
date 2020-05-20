/*
//  CS2 Network LIMITED All right reserved.
//
//  base64.h: The base Encode/Decode include file
//  Author: Charlie Chang (sengfu@gmail.com)
*/

#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

void Base64_Decode(const char *b64src, char *dststr);
void Base64_Encode(const char *scrstr, char *b64dst);

#ifdef __cplusplus
}
#endif
