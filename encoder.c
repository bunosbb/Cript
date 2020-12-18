#include <stdio.h>
#include <stdlib.h>
#include "cript.h"
#include "str_util.h"

int main(int argc, char** argv) {
    int key;
    char* type;
    char* text;
    char* strKey;
    if (argc == 4) {
        if (isEqualStr(argv[1], "--caesar")) {
            if (!strToInt(argv[3], &key)) {
                printf("ERROR: key must be number for caesar encode\n");
                return 0;
            }
        }else if (isEqualStr(argv[1], "--xor")) {
            strCopy(&strKey, argv[3]);
        } else {
            printf("ERROR: encode type maust be --caesar or --xor\n");
            return 0;
        }
        strCopy(&type, argv[1]);
        mutableFilter(type);
        strCopy(&text, argv[2]);
    } else if (argc == 1) {
        printf("Please enter type: ");
        type = (char*)malloc(100 * sizeof(char));
        scanf("%s", type);
        printf("28 %c\n", type[0]);
        mutableFilter(type);
        printf("30\n");
        printf("Enter text: ");
        text = (char*)malloc(1000 * sizeof(char));
        scanf("%s", text);
        printf("Enter key: ");
        strKey = (char*)malloc(1000 * sizeof(char));
        scanf("%s", strKey);
        if (isEqualStr(type, "caesar")) {
            if (!strToInt(strKey, &key)) {
                printf("ERROR: key must be number for caesar encode\n");
                return 0;
            }
        }else if (!isEqualStr(type, "xor")) {
            printf("ERROR: encode type maust be caesar or xor\n");
            return 0;
        }
    } else {
        printf("Invalid input.\n");
        printf("Valid input is \"./encoder --caesar text key\" or \"./encoder --xor text key\"\n");
        return 0;
    }
    mutableToLower(text);
    mutableStrip(text);
    mutableFilter(type);
    if (isEqualStr(type, "caesar")) {
        mutableCaesarEncode(text, key);
    } else {
        mutableXOREncode(text, strKey);
    }
    printf("Encoded string: ");
    unsigned int size = len(text);
    for (int i = 0; i < size; ++i) {
        printf("%c", text[i]);
    }
    printf("\n");
}