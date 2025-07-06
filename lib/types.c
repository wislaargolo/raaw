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
  if(!has_type(name)) return 0;

  type_data data = get_type_data(name);

  return data.discriminator == STRUCT_TYPE;
}

void insert_struct_attr(char* struct_name, char* name, char* type) {
  if(has_type(struct_name)) {
    type_data data = get_type_data(struct_name);

    hash_insert_t(data.info.struct_attrs, name, strdup(type), char*);
  }
}

int struct_has_attr(char* struct_name, char* name) {

  if(!has_type(struct_name)) return 0;

  type_data data = get_type_data(struct_name);

  return hash_has(data.info.struct_attrs, name);
}

char* get_struct_attr_type(char* struct_name, char* name) {
  if(!has_type(struct_name)) return strdup("");

  type_data data = get_type_data(struct_name);

  return hash_get_t(data.info.struct_attrs, name, char*);
}

int is_of_type(char* name, char* type) {
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

void insert_enum_type(char* name) {
  type_data data;
  type_info info;

  info.struct_attrs = create_hash_table();

  data.discriminator = ENUM_TYPE;
  data.info = info;

  insert_type(name, data);
}

int is_enum(char* name) {
  if(!has_type(name)) return 0;

  type_data data = get_type_data(name);

  return data.discriminator == ENUM_TYPE;
}

void insert_enum_attr(char* enum_name, char* name) {
  if(has_type(enum_name)) {
    type_data data = get_type_data(enum_name);

    hash_insert_t(data.info.struct_attrs, name, 1, int);
  }
}

int enum_has_attr(char* enum_name, char* name) {
  if(!has_type(enum_name)) return 0;

  type_data data = get_type_data(enum_name);

  return hash_has(data.info.struct_attrs, name);
}

int is_enum_group(char* name) {
  return is_of_type(name, "enum_group");
}

char* get_enum_group_name(char* name) {
  return get_inner_type(name, "enum_group");
}

int type_check(char* t1, char* t2) {
  if (strcmp(t1, "_") == 0 || strcmp(t2, "_") == 0) {
    return 1;
  }

  if (is_ptr(t1) && is_ptr(t2)) {
    return type_check(get_ptr_type(t1), get_ptr_type(t2));
  }

  if (is_list(t1) && is_list(t2)) {
    return type_check(get_list_type(t1), get_list_type(t2));
  }

  return strcmp(t1, t2) == 0;
}

void print_types_table() {
    printf("=== TABELA DE TIPOS ===\n");

    for (int i = 0; i < types_table->capacity; i++) {
        hash_node* node = types_table->nodes[i];

        while (node != NULL) {
            char* name = node->key;
            type_data* data = (type_data*) node->value;

            printf("Tipo: %s\n", name);

            switch (data->discriminator) {
                case STRUCT_TYPE:
                    printf("  Categoria: struct\n");
                    printf("  Atributos:\n");
                    for (int j = 0; j < data->info.struct_attrs->capacity; j++) {
                        hash_node* attr_node = data->info.struct_attrs->nodes[j];
                        while (attr_node != NULL) {
                            char* attr_name = attr_node->key;
                            char* attr_type = (char*) attr_node->value;
                            printf("    %s: %s\n", attr_name, attr_type);
                            attr_node = attr_node->next;
                        }
                    }
                    break;

                case ENUM_TYPE:
                    printf("  Categoria: enum\n");
                    printf("  Valores:\n");
                    for (int j = 0; j < data->info.enum_attrs->capacity; j++) {
                        hash_node* enum_node = data->info.enum_attrs->nodes[j];
                        while (enum_node != NULL) {
                            printf("    %s\n", enum_node->key);
                            enum_node = enum_node->next;
                        }
                    }
                    break;

                default:
                    printf("  Categoria: desconhecida\n");
                    break;
            }

            printf("\n");
            node = node->next;
        }
    }
}
