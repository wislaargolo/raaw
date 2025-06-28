#ifndef TYPES
#define TYPES

struct struct_tuple {
  char* name;
  char* type;
  struct struct_tuple* next;
};

typedef struct struct_tuple struct_tuple;

union type_info {
  struct_tuple* struct_tuples;
  char* list_type;
  char* alias_type;
};

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
int insert_struct_type(char* name, struct_tuple* tuples);
int has_type(char* name);
type_data get_type_data(char* name);

#endif
