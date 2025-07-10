#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "types.h"
#include "stack.h"
#include "variables.h"
#include "aux_functions.h"

hash_table* variables_table;

void init_variables_table() {
    variables_table = create_hash_table();
}

int insert_variable(Stack* stack, char* name, char* type, int is_const) {

    if (stack == NULL || stack->top == NULL) {
        fprintf(stderr, "Stack is empty or not initialized\n");
        return -1;
    }

    if(exists_in_scope(stack, name)) return 1;

    char* scope = stack->top->name;
    char* key = make_key(name, scope);

    variable_data* data = malloc(sizeof(variable_data));
    data->type = strdup(type);
    data->is_const = is_const;

    hash_insert(variables_table, key, data);
    if(key) free(key);

    //printf("\nVariable '%s' of type '%s' inserted successfully in scope '%s'\n", name, type, scope);
    //print_variable_table();


    return 0;
}

char* make_key(char* name, char* scope) {
    char* key = (char*) malloc(strlen(name) + strlen(scope) + 2);

    if(strcmp(scope, "") == 0) sprintf(key, "%s", name);
    else sprintf(key, "%s#%s", scope, name);
    return key;
}

int exists_in_scope(Stack* stack, char* name) {
    if (stack == NULL || stack->top == NULL) return -1;

    char* scope = stack->top->name;
    char* key = make_key(name, scope);

    int exists = hash_has(variables_table, key);
    free(key);

    return exists;
}

int exists_scope_parent(Stack* stack, char* name) {
    if (stack == NULL || stack->top == NULL) return -1;

    ScopeNode* node = stack->top;
    while (node != NULL) {
        char* key = make_key(name, node->name);
        if (hash_has(variables_table, key)) {
            free(key);
            return 1;
        }
        free(key);
        node = node->parent;
    }

    return 0;
}


variable_data get_variable(Stack* stack, char* name) {
    if (!stack || !stack->top || name == NULL) {
        fprintf(stderr, "Invalid stack or variable name\n");
        return (variable_data){NULL, 0};
    }

    ScopeNode *node = stack->top;
    while (node != NULL) {
        char *key = make_key(name, node->name);

        if (hash_has(variables_table, key)) {
            variable_data data = hash_get_t(variables_table, key, variable_data);

            free(key);
            return data;
        }

        free(key);
        node = node->parent;
    }

    return (variable_data){NULL, 0};
}

char* get_variable_type(Stack* stack, char* name) {
    variable_data data = get_variable(stack, name);
    if (data.type == NULL) return NULL;
    return strdup(data.type);
}


void print_variable_table() {

    printf("\n[ESTADO ATUAL DA TABELA DE VARIÁVEIS]\n");
    printf("Capacidade: %d | Elementos: %d\n", variables_table->capacity, variables_table->num_elements);

    for (int i = 0; i < variables_table->capacity; i++) {
        hash_node* node = variables_table->nodes[i];
        printf("Bucket %d: ", i);
        if (node == NULL) {
            printf("(vazio)\n");
            continue;
        }
        while (node != NULL) {
            variable_data vd = *(variable_data *)node->value;
            printf("['%s' -> type: %s, const: %d] -> ", node->key, vd.type, vd.is_const);
            node = node->next;
        }
    }
}

void free_variables_table() {
    if (variables_table == NULL) return;

    for (int i = 0; i < variables_table->capacity; i++) {
        hash_node* node = variables_table->nodes[i];
        while (node != NULL) {
            variable_data* data = (variable_data*) node->value;

            if (data) free(data->type);
            hash_delete(variables_table, node->key);

            node = node->next;
        }
    }

    free_hash(variables_table);
}

int remove_scope_variables(Stack* stack) {
    if (stack == NULL || stack->top == NULL) return -1;

    char* scope = stack->top->name;
    for (int i = 0; i < variables_table->capacity; i++) {
        hash_node* node = variables_table->nodes[i];

        while(node != NULL) {
            hash_node* next = node->next;
            if (strncmp(node->key, scope, strlen(scope)) == 0 && node->key[strlen(scope)] == '#') {
                variable_data* data = (variable_data*) node->value;
                if (data) free(data->type);

                hash_delete(variables_table, node->key);

            }
            node = next;
        }
    }

    return 0;
}

int is_const_variable(Stack* stack, char* name) {
    variable_data data = get_variable(stack, name);

    return data.is_const;
}
