#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./types.h"
#include "./aux_functions.h"

char *cat(int count, ...) {
     va_list args;
     int tam_total = 0;

     va_start(args, count);

     for (int i = 0; i < count; i++) {
          char *str = va_arg(args, char *);
          if(str == NULL) continue;
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

char* print_type(char* t) {
    if (!strcmp(t,"int"))      return "%d";
    if (!strcmp(t,"float"))    return "%f";
    if (!strcmp(t,"string"))   return "%s";
    if (!strcmp(t,"char"))     return "%c";
    if (!strcmp(t,"boolean"))  return "%s";
    return "%p";
}

char* translate_type(char* t) {
     if (is_list(t)) {
          return strdup("list");
     } else if (is_ptr(t)) {
          return cat(2, translate_type(get_ptr_type(t)), "*");
     } else if (strcmp(t, "string") == 0) {
          return strdup("char*");
     } else if (strcmp(t, "file") == 0) {
          return strdup("FILE*");
     } else {
          return strdup(t);
     }
}

record* build_printf(parameter_record* params, int is_line) {

     char* format_type = strdup("\"");
     int first = 1;
     char *args = strdup("");


     for(parameter_record* param = params; param != NULL; param = param->next) {

          char* type = print_type(param->type);
          char* temp = cat(2, format_type, type);

          free(format_type);
          format_type = temp;

          char* args_txt;
          if (!strcmp(param->type, "boolean")) {
               args_txt = cat(4, "(", param->code, " ? \"true\" : \"false\"", ")");
          } else {
               args_txt = strdup(param->code);
          }


          if (first) {
               if(args) free(args);
               args = args_txt;
               first = 0;
          } else {
               temp = cat(3, args, ", ", args_txt);
               if(args) free(args);
               if(args_txt) free(args_txt);
               args = temp;
        }
     }

     format_type = realloc(format_type, strlen(format_type) + (is_line ? 4 : 2));
     strcat(format_type, is_line ? "\\n\"" : "\"");

     char* printf_code;

     if(first) {
          printf_code = cat(3, "printf(", format_type, ")");
     } else {
          printf_code = cat(5, "printf(", format_type, ", ", args, ")");
     }

     record *r = create_record(printf_code, "void");

     if(format_type) free(format_type);
     if(args) free(args);
     if(printf_code) free(printf_code);

    return r;
}

int is_list_function(char* name, parameter_record* params) {
     return (
          !strcmp(name, "listPush") ||
          !strcmp(name, "listPop") ||
          !strcmp(name, "listInsert") ||
          !strcmp(name, "listRemove") ||
          !strcmp(name, "freeList") ||
          !strcmp(name, "listInit") ||
          !strcmp(name, "listSize")
     ) && params != NULL && is_list(params->type);
}

int is_generic_list_function(char* name, parameter_record* params) {
     return (
          !strcmp(name, "listInsert") ||
          !strcmp(name, "listPush")
     ) && params != NULL && is_list(params->type);
}

record* build_function_call(char* name, parameter_record* params) {
    char* args = NULL;

    if (is_list_function(name, params)) {
        char* newCode = cat(2, "&", params->code);
        free(params->code);
        params->code = newCode;
    }

    for(parameter_record* param = params; param != NULL; param = param->next) {
          char *arg_code = strdup(param->code);
          char *tmp = args ? cat(3, args, ", ", arg_code) : strdup(arg_code);

          free(args);
          free(arg_code);
          args = tmp;

    }

    if (is_generic_list_function(name, params)) {
         char* list_type = get_list_type(params->type);
         char* translated_type = translate_type(list_type);
         free(list_type);
         char *tmp = args ? cat(3, args, ", ", translated_type) : strdup(translated_type);

         free(args);
         free(translated_type);
         args = tmp;
    }

    char* call_code;

    if (params == NULL) {
        call_code = cat(2, name, "()");
    } else {
        call_code = cat(4, name, "(", args, ")");
    }

    record *r = create_record(call_code, "");

    if(args) free(args);
    if(call_code) free(call_code);

    return r;
}

