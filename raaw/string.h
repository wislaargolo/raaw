#ifndef LIB_STRING
#define LIB_STRING

#include <stddef.h>

size_t strLeght(const char* s);
char* strCopy(char* dest, const char* src);
char* strConcat(char* dest, const char* src);
int strCompSize(const char* s1, const char* s2);
char* strNCopy(char* dest, const char* src, size_t n);
char* strDup(const char* s);

int toUpper(int c);
int toLower(int c);
void freeString(char * str);
int isEquals(const char* s1, const char* s2);

#endif
