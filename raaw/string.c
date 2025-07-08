#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

size_t strLength(const char* s) {
    return strlen(s);
}

char* strCopy(char* dest, const char* src) {
    return strcpy(dest, src);
}

char* strConcat(const char* s1, const char* s2) {
    if (s1 == NULL || s2 == NULL) return NULL;

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    
    char* result = (char*)malloc(len1 + len2 + 1);
    if (result == NULL) return NULL;

    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int strCompSize(const char* s1, const char* s2) {
    return strcmp(s1, s2);
}

char* strNCopy(char* dest, const char* src, size_t n) {
    return strncpy(dest, src, n);
}

char* strDup(const char* s) {
    return strdup(s);
}

int toUpper(int c) {
    return toupper(c);
}

int toLower(int c) {
    return tolower(c);
}

void freeString(char* str) {
    free(str);
}

int isEquals(const char* s1, const char* s2) {
    if (s1 == NULL && s2 == NULL) return 1;
    if (s1 == NULL || s2 == NULL) return 0;
    return strcmp(s1, s2) == 0;
}
