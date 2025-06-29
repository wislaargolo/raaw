#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

char *cat(int count, ...) {
     va_list args;
     int tam_total = 0;

     va_start(args, count);

     for (int i = 0; i < count; i++) {
          char *str = va_arg(args, char *);
          tam_total += strlen(str);
     }

     va_end(args);

     char *result = malloc(tam_total + 1);
     if (!result) {
          printf("Allocation problem. Closing application...\n");
          exit(0);
     }

     char *current = result;
     va_start(args, count);

     for (int i = 0; i < count; i++) {
          char *str = va_arg(args, char *);
          if (str) {
               int len = strlen(str);
               memcpy(current, str, len);
               current += len;
          }
     }

     va_end(args);

     *current = '\0';

     return result;
}
