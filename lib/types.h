#ifndef TYPES
#define TYPES

#include "hash_table.h"

union type_info {
  hash_table* struct_attrs;
  hash_table* enum_attrs;
};

typedef union type_info type_info;

enum type_discriminator {
  STRUCT_TYPE,
  ENUM_TYPE,
};

typedef enum type_discriminator type_discriminator;

struct type_data {
  type_discriminator discriminator;
  type_info info;
};

typedef struct type_data type_data;

void init_types_table();
int has_type(char* name);
type_data get_type_data(char* name);
void insert_struct_type(char* name);
int is_struct(char* name);
void insert_struct_attr(char* struct_name, char* name, char* type);
int struct_has_attr(char* struct_name, char* name);
char* get_struct_attr_type(char* struct_name, char* name);
int is_numeric(char* name);
int is_list(char* name);
char* get_list_type(char* name);
int is_array(char* name);
char* get_array_type(char* name);
int is_ptr(char* name);
int is_string(char* name);
char* get_ptr_type(char* name);
void insert_enum_type(char* name);
int is_enum(char* name);
void insert_enum_attr(char* enum_name, char* name);
int enum_has_attr(char* enum_name, char* name);
int is_enum_group(char* name);
char* get_enum_group_name(char* name);
int type_check(char* t1, char* t2);

#endif
