#ifndef TYPES
#define TYPES

struct struct_attr {
  int dimension;
  char* type;
};

typedef struct struct_attr struct_attr;

union type_info {
  hash_table* struct_attrs;
  char* list_type;
  char* alias_type;
};

#define get_struct_attr(st, name) hash_get_t(st, name, struct_attr)
#define insert_struct_attr(st, name, attr) hash_insert_t(st, name, attr, struct_attr)
#define has_struct_attr(st, name) hash_has(st, name)

typedef union type_info type_info;

enum type_discriminator {
  PRIM,
  LIST,
  STRUCT,
};

typedef enum type_discriminator type_discriminator;

struct type_data {
  type_discriminator discriminator;
  type_info info;
};

typedef struct type_data type_data;

int insert_list_type(char* name, char* type);
int insert_struct_type(char* name, hash_table* struct_attrs);
int has_type(char* name);
type_data get_type_data(char* name);
void init_types_table();
void insert_prim_type(char* name);

#endif
