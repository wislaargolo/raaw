#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "types.h"

#define insert_type(name, data) hash_insert_t(types_table, name, data, type_data)

hash_table* types_table;

void insert_prim_type(char* name) {
  type_data data;

  data.discriminator = PRIM;

  insert_type(name, data);
}

void init_types_table() {
  types_table = create_hash_table();

  insert_prim_type("int");
  insert_prim_type("float");
  insert_prim_type("boolean");
  insert_prim_type("string");
}

int insert_list_type(char* name, char* type) {
  type_data data;
  type_info info;

  info.list_type = strdup(type);

  data.discriminator = LIST;
  data.info = info;

  insert_type(name, data);

  return 0;
}

int insert_struct_type(char* name, hash_table* struct_attrs) {
  type_data data;
  type_info info;

  info.struct_attrs = struct_attrs;

  data.discriminator = STRUCT;
  data.info = info;

  insert_type(name, data);

  return 0;
}

int has_type(char* name) {
  return hash_has(types_table, name);
}

type_data get_type_data(char* name) {
  return hash_get_t(types_table, name, type_data);
}
