#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "types.h"

#define insert_type(name, data) hash_insert_t(types_table, name, data, type_data)

hash_table* types_table;

void init_types_table() {
  types_table = create_hash_table();
}

int has_type(char* name) {
  return hash_has(types_table, name);
}

type_data get_type_data(char* name) {
  return hash_get_t(types_table, name, type_data);
}

void insert_struct_type(char* name) {
  type_data data;
  type_info info;

  info.struct_attrs = create_hash_table();

  data.discriminator = STRUCT_TYPE;
  data.info = info;

  insert_type(name, data);
}

int is_struct(char* name) {
  type_data data = get_type_data(name);

  if (data.discriminator == ALIAS_TYPE) {
    return is_struct(data.info.alias_type);
  }

  return data.discriminator == STRUCT_TYPE;
}

void insert_struct_attr(char* struct_name, char* name, char* type) {
  type_data data = get_type_data(struct_name);

  if (data.discriminator == ALIAS_TYPE) {
    return insert_struct_attr(data.info.alias_type, name, type);
  }

  hash_insert_t(data.info.struct_attrs, name, strdup(type), char*);
}

int struct_has_attr(char* struct_name, char* name) {
  type_data data = get_type_data(struct_name);

  if (data.discriminator == ALIAS_TYPE) {
    return struct_has_attr(data.info.alias_type, name);
  }

  return hash_has(data.info.struct_attrs, name);
}

char* get_struct_attr_type(char* struct_name, char* name) {
  type_data data = get_type_data(struct_name);

  if (data.discriminator == ALIAS_TYPE) {
    return get_struct_attr_type(data.info.alias_type, name);
  }

  return hash_get_t(data.info.struct_attrs, name, char*);
}

void insert_alias_type(char* name, char* type) {
  type_data data;
  type_info info;

  info.alias_type = type;

  data.discriminator = ALIAS_TYPE;
  data.info = info;

  insert_type(name, data);
}

int is_of_type(char* name, char* type) {
  if (has_type(name)) {
    type_data data = get_type_data(name);

    if (data.discriminator == ALIAS_TYPE) {
      return is_of_type(data.info.alias_type, type);
    }
  }

  size_t len = strlen(name);

  if (len < strlen(type) + 2) {
    return 0;
  }

  return (
    strncmp(name, type, strlen(type)) == 0 &&
    name[strlen(type)] == '<' &&
    name[len - 1] == '>'
  );
}

char* get_inner_type(char* name, char* type) {
  if (has_type(name)) {
    type_data data = get_type_data(name);

    if (data.discriminator == ALIAS_TYPE) {
      return get_inner_type(data.info.alias_type, type);
    }
  }

  size_t len = strlen(name);
  size_t inner_len = len - strlen(type) - 2;
  char* result = malloc(inner_len + 1);

  strncpy(result, name + strlen(type) + 1, inner_len);
  result[inner_len] = '\0';
  return result;
}

int is_list(char* name) {
  return is_of_type(name, "list");
}

char* get_list_type(char* name) {
  return get_inner_type(name, "list");
}

int is_ptr(char* name) {
  return is_of_type(name, "ptr");
}

char* get_ptr_type(char* name) {
  return get_inner_type(name, "ptr");
}