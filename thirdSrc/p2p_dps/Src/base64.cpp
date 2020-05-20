/*
//  CS2 Network LIMITED All right reserved.
//
//  base64.cpp: The base Encode/Decode include file
//  Author: Charlie Chang (sengfu@gmail.com)
//
*/

#include "base64.h"

/* ---- Base64 Encoding/Decoding Table --- */
char __b64_Array[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/* __b64_DecodeBlock - decode 4 '6-bit' characters into 3 8-bit binary bytes */
void __b64_DecodeBlock(unsigned char in[], char *clrstr)
{
	char out[4];
	out[0] = in[0] << 2 | in[1] >> 4;
	out[1] = in[1] << 4 | in[2] >> 2;
	out[2] = in[2] << 6 | in[3] >> 0;
	out[3] = '\0';
	strncat(clrstr, out, sizeof(out));
}

/* __b64_EncodeBlock - encode 3 8-bit binary bytes as 4 '6-bit' characters */
void __b64_EncodeBlock( unsigned char in[], char b64str[], int len )
{
	char out[5];
	out[0] = __b64_Array[ in[0] >> 2 ];
	out[1] = __b64_Array[ ((in[0] & 0x03) << 4) | ((in[1] & 0xf0) >> 4) ];
	out[2] = (unsigned char) (len > 1 ? __b64_Array[ ((in[1] & 0x0f) << 2) |
			 ((in[2] & 0xc0) >> 6) ] : '=');
	out[3] = (unsigned char) (len > 2 ? __b64_Array[ in[2] & 0x3f ] : '=');
	out[4] = '\0';
	strncat(b64str, out, sizeof(out));
}

void Base64_Decode(const char *b64src, char *dststr)
{
	int c, phase, i;
	unsigned char in[4];
	char *p = NULL;

	dststr[0] = '\0';
	phase = 0; i=0;
	while (b64src[i])
	{
		c = (int) b64src[i];
		if (c == '=')
		{
			__b64_DecodeBlock(in, dststr);
			break;
		}
		p = strchr(__b64_Array, c);
		if (p)
		{
			in[phase] = p - __b64_Array;
			phase = (phase + 1) % 4;
			if (phase == 0)
			{
				__b64_DecodeBlock(in, dststr);
				in[0]=in[1]=in[2]=in[3]=0;
			}
		}
		i++;
	}
}

/* Base64_Encode - base64 encode a stream, adding padding if needed */
void Base64_Encode(const char *scrstr, char *b64dst)
{
	unsigned char in[3];
	int i, len = 0;
	int j = 0;

	b64dst[0] = '\0';
	while (scrstr[j])
	{
		len = 0;
		for ( i = 0; i < 3; i++)
		{
			in[i] = (unsigned char) scrstr[j];
			if (scrstr[j])
			{
				len++;
				j++;
			}
			else
			{
				in[i] = 0;
			}
		}
		if ( len )
		{
			__b64_EncodeBlock( in, b64dst, len );
		}
	}
}
