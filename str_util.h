#ifndef _STR_UTIL_H_
#define _STR_UTIL_H_

#include <stdbool.h>

unsigned int len (const char* str);

void strCopy (char* dest, const char* src);

void mutableToLower (char* str);
char* immutableToLower (const char* str);

void mutableToUpper (char* str);
char* immutableToUpper (const char* str);

void mutableStrip (char* str);
char* immutableStrip (const char* str);

void mutableRemoveSpaces (char* str);
char* immutableRemoveSpaces (const char* str);

void mutableFilter (char* str);
char* immutableFilter (const char* str);

bool isNumber (const char* str);

bool strToInt (const char* str, int* result);

bool isWord (const char* str);

bool isEqualStr (const char* str1, const char* str2);

#endif