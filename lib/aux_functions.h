#ifndef AUX_FUNCTIONS
#define AUX_FUNCTIONS

#include <stdio.h>
#include <stdarg.h>
#include "./record.h"

char* cat(int, ...);
char* print_type(char* t);
char* boolean_to_string(int b);
record* build_printf(parameter_record* params, int is_line);
record* build_function_call(char* name, parameter_record* params);

#endif
