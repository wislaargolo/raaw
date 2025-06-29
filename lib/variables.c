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
    free(key);

    return 0;
}

static char* make_key(char* name, char* scope) {
    char* key = (char*) malloc(strlen(name) + strlen(scope) + 2);

    sprintf(key, "%s#%s", scope, name);
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

variable_data get_variable(Stack* stack, char* name) {
    char* key = make_key(name, stack->top->name);
    variable_data data = hash_get_t(variables_table, key, variable_data);
    free(key);
    return data;
}

void print_variable_table() {
    print_hash_table(variables_table);
}

void free_variables_tables() {
    if (variables_table == NULL) return;

    for (int i = 0; i < variables_table->capacity; i++) {
        hash_node* node = variables_table->nodes[i];
        while (node != NULL) {
            variable_data* data = (variable_data*) node->value;

            if (data) {
                free(data->type); 
                free(data);        
            }

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
        hash_node* prev = NULL;

        while (node != NULL) {
            hash_node* next = node->next; 

            if (strncmp(node->key, scope, strlen(scope)) == 0 && node->key[strlen(scope)] == '#') {
                if (prev == NULL) {
                    variables_table->nodes[i] = next;
                } else {
                    prev->next = next;
                }
                free(node->key);
                variable_data* data = (variable_data*) node->value;
                if(data){
                  free(data->type);
                  free(data);
                }
                free(node);
            } else {
                prev = node;
            }
            node = next;
        }
    }

    return 0;
}
