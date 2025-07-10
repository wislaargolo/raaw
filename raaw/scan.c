#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define INIT_CAP  64

int readInt() {
    int v;
    scanf("%d", &v);
    return v;
}


float readFloat() {
    float v;
    scanf("%f", &v);
    return v;
}

char readChar() {
    int c;
    do {
        c = getchar();
    } while (isspace(c) && c != EOF);

    if (c == EOF)
        fprintf(stderr, "Unexpected end of input in readChar");

    return (char) c;
}

char* readString() {
    size_t cap = INIT_CAP;
    char *buffer = malloc(cap);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed in readString");
        return strdup("");
    }

    size_t len = 0;
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (len + 1 >= cap) {
            cap *= 2;
            char *new_buffer = realloc(buffer, cap);
            if (!new_buffer) {
                free(buffer);
                fprintf(stderr, "Memory allocation failed in readString");
                return strdup("");
            }
            buffer = new_buffer;
        }
        buffer[len++] = (char) ch;
    }

    if(ch == EOF && len == 0) {
        free(buffer);
        fprintf(stderr, "Unexpected end of input in readString");
        return strdup("");
    }

    buffer[len] = '\0';
    return buffer; /*vão ter que dar free*/
}


bool readBoolean() {
    char *input = readString();
    if (!input) return false;

    if (strcmp(input, "true") == 0) {
        free(input);
        return true;
    } else if (strcmp(input, "false") == 0) {
        free(input);
        return false;
    }

    free(input);
    return false;
}

