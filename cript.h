#ifndef _CRIPT_H_
#define _CRIPT_H_

#define ALP_SIZE 256

#include "str_util.h"

void mutableCaesarEncode (char* str, int key);
char* immutableCaesarEncode (const char* str, int key);

void mutableCaesarDecode (char* str, int key);
char* immutableCaesarDecode (const char* str, int key);

void mutableXOREncode (char* str, const char* key);
char* immutableXOREncode (const char* str, const char* key);

void mutableXORDecode (char* str, const char* key);
char* immutableXORDecode (const char* str, const char* key);

#endif