#ifndef TYPES
#define TYPES

#include "hash_table.h"

union type_info {
  hash_table* struct_attrs;
  char* alias_type;
};

typedef union type_info type_info;

enum type_discriminator {
  ALIAS_TYPE,
  STRUCT_TYPE,
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
void insert_alias_type(char* name, char* type);
int is_list(char* name);
char* get_list_type(char* name);
int is_ptr(char* name);
char* get_ptr_type(char* name);

#endif
