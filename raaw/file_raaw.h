#ifndef FILE_RAAW
#define FILE_RAAW

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

FILE *openFile(const char *filename, const char *mode);
int closeFile(FILE *stream);
int readCharFile(FILE *stream);
char *readStringFile(char *str, int n, FILE *stream);
int writeCharFile(char c, FILE *stream);
int writeStringFile(const char *str, FILE *stream);
int isEof(char value);

#endif
