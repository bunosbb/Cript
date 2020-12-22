#include "str_util.h"
#include <stdlib.h>

unsigned int len (const char* str) {
    unsigned int size = 0;
    while (str[size] != '\0') {
        ++size;
    }
    return size;
}

void strCopy (char* dest, const char* src) {
    unsigned int size = len(src);
    for (int i = 0; i < size; ++i) {
        dest[i] = src[i];
    }
    dest[size] = '\0';
}

void mutableToLower (char* str) {
    int size = len(str);
    for (int i = 0; i < size; ++i) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] = 'a' + (str[i] - 'A');
        }
    }
}
char* immutableToLower (const char* str) {
    char* result;
    strCopy(result, str);
    mutableToLower(result);
}

void mutableToUpper (char* str) {
    int size = len(str);
    for (int i = 0; i < size; ++i) {
        if ('a' <= str[i] && str[i] <= 'z') {
            str[i] -= 'a' + 'A';
        }
    }
}
char* immutableToUpper (const char* str) {
    char* result;
    strCopy(result, str);
    mutableToUpper(result);
}

void mutableStrip (char* str) {
    unsigned int size = len(str);
    int l = 0;
    while (l < size && str[l] == ' ') {
        ++l;
    }
    int r = size - 1;
    while (r >= 0 && str[r] == ' ') {
        --r;
    }
    if (r < l) {
        str[0] = '\0';
        return;
    }
    for (int i = l; i <= r; ++i) {
        str[i - l] = str[i];
    }
    str[r - l + 1] = '\0';
}
char* immutableStrip (const char* str) {
    char* result;
    strCopy(result, str);
    mutableStrip(result);
    return result;
}

void mutableRemoveSpaces (char* str) {
    unsigned int size = len(str);
    unsigned int spaceCnt = 0;
    for (int i = 0; i < size; ++i) {
        if (str[i] != ' ') {
            str[i - spaceCnt] = str[i];
        } else {
            ++spaceCnt;
        }
    }
    str[size - spaceCnt] = '\0';
}
char* immutableRemoveSpaces (const char* str) {
    char* result;
    strCopy(result, str);
    mutableRemoveSpaces(result);
    return result;
}

void mutableFilter (char* str) {
    unsigned int size = len(str);
    int badSymbolsCnt = 0;
    for (int i = 0; i < size; ++i) {
        if (('a' <= str[i] && str[i] <= 'z')
        || ('A' <= str[i] && str[i] <= 'Z')
        || ('0' <= str[i] && str[i] <= '9')
        || str[i] == ' ')
        {
            str[i - badSymbolsCnt] = str[i];
        } else {
            ++badSymbolsCnt;
        }
    }
    str[size - badSymbolsCnt] = '\0';
}
char* immutableFilter (const char* str) {
    char* result;
    strCopy(result, str);
    mutableFilter(result);
    return result;
}

bool isNumber (const char* str) {
    unsigned int size = len(str);
    for (int i = 0; i < size; ++i) {
        if ((str[i] == '-' && i != 0)
        || ((str[i] < '0' || '9' < str[i]) && str[i] != '-')) {
            return false;
        }
    }
    return true;
}

bool strToInt (const char* str, int* result) {
    if (!isNumber(str)) {
        return false;
    }
    int i = 0;
    int isNegative = 0;
    if (str[i] == '-') {
        isNegative = 1;
        ++i;
    }
    unsigned int size = len(str);
    *result = 0;
    for (;i < size; ++i) {
        (*result) *= 10;
        (*result) += (int)(str[i] - '0');
    }
    if (isNegative) {
        (*result) *= -1;
    }
    return true;
}

bool isWord (const char* str) {
    unsigned int size = len(str);
    for (int i = 0; i < size; ++i) {
        if ((str[i] < 'a' || 'z' < str[i])
        && (str[i] < 'A' || 'Z' < str[i])) {
            return false;
        }
    }
    return true;
}

bool isEqualStr (const char* str1, const char* str2) {
    unsigned int size1 = len(str1);
    unsigned int size2 = len(str2);
    if (size1 != size2) {
        return false;
    }
    for (int i = 0; i < size1; ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}