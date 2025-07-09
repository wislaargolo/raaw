#include "file_raaw.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *openFile(const char *filename, const char *mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return NULL;
    }
    return file;
}

int closeFile(FILE *stream) {
    if (stream == NULL) {
        fprintf(stderr, "closeFile: provided stream is NULL\n");
        return EOF; 
    }
    int res = fclose(stream);
    if (res == EOF) {
        fprintf(stderr, "Error closing file\n");
        return EOF; 
    }
    return res;
}

int readCharFile(FILE *stream) {
    if (stream == NULL) {
        fprintf(stderr, "readCharFile: provided stream is NULL\n");
        return EOF;
    }
    int c = fgetc(stream);
    if (c == EOF) {
        return EOF;
    }
    return c;
}

char *readStringFile(char *str, int n, FILE *stream) {
    if (str == NULL) {
        fprintf(stderr, "readStringFile: provided buffer is NULL\n");
        return NULL;
    }
    if (stream == NULL) {
        fprintf(stderr, "readStringFile: provided stream is NULL\n");
        return NULL;
    }
    char *res = fgets(str, n, stream);
    if (res == NULL) {
        fprintf(stderr, "readStringFile: Error read string to file\n");
    }
    return res;
}

int writeCharFile(char c, FILE *stream) {
    if (stream == NULL) {
        fprintf(stderr, "writeCharFile: provided stream is NULL\n");
        return EOF;
    }
    int res = fputc(c, stream);
    if (res == EOF) {
        fprintf(stderr, "Error writing char to file\n");
        return EOF;
    }
    return res;
}

int writeStringFile(const char *str, FILE *stream) {
    if (str == NULL) {
        fprintf(stderr, "writeStringFile: provided string is NULL\n");
        return EOF;
    }
    if (stream == NULL) {
        fprintf(stderr, "writeStringFile: provided stream is NULL\n");
        return EOF;
    }
    int res = fputs(str, stream);
    if (res == EOF) {
        fprintf(stderr, "Error writing string to file\n");
        return EOF;
    }
    return res;
}

int isEof(char value) {
    if(value == EOF) {
        return 0;
    }else {
        return 1;
    }
}
