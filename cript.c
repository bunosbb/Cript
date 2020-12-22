#include "cript.h"

void mutableCaesarEncode (char* str, int key) {
    unsigned int size = len(str);

    for (int i = 0; i < size; ++i) {
        str[i] = (str[i] + key + ALP_SIZE) % ALP_SIZE;
    }
}
char* immutableCaesarEncode (const char* str, int key) {
    char* result;
    strCopy(result, str);
    mutableCaesarEncode(result, key);
    return result;
}

void mutableCaesarDecode (char* str, int key) {
    mutableCaesarEncode(str, -key);
}
char* immutableCaesarDecode (const char* str, int key) {
    return immutableCaesarEncode(str, key);
}

void mutableXOREncode (char* str, const char* key) {
    unsigned int size = len(str);
    unsigned int keySize = len(key);
    for (int i = 0; i < size; ++i) {
        str[i] = (((int)str[i]) ^ ((int)key[i % keySize]));
    }
}
char* immutableXOREncode (const char* str, const char* key) {
    char* result;
    strCopy(result, str);
    mutableXOREncode(result, key);
    return result;
}

void mutableXORDecode (char* str, const char* key) {
    mutableXOREncode(str, key);
}
char* immutableXORDecode (const char* str, const char* key) {
    return immutableXOREncode(str, key);
}