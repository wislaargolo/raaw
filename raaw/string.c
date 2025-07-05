#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

size_t strLeght(const char* s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

char* strCopy(char* dest, const char* src) {
    char* original_dest = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return original_dest;
}

char* strConcat(char* dest, const char* src) {
    char* original_dest = dest;

    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return original_dest;
}

int strCompSize(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

char* strNCopy(char* dest, const char* src, size_t n) {
    char* original_dest = dest;
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return original_dest;
}

char* strDup(const char* s) {
    if (s == NULL) {
        return NULL;
    }
    size_t len = strlen(s);
    char* new_s = (char*) malloc(len + 1);
    if (new_s == NULL) {
        fprintf(stderr, "Falha na alocação de memória para strdup.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_s, s);
    return new_s;
}

int toUpper(int c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

int toLower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

void freeString(char * str) {
    free(str);
}

int isEquals(const char* s1, const char* s2) {
    if (s1 == NULL && s2 == NULL) return 1;
    if (s1 == NULL || s2 == NULL) return 0;
    return strcmp(s1, s2) == 0;
}
