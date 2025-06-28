#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "types.h"
#include "stack.h"
#include "variables.h"

hash_table* variables_table;

void init_variables_table() {  
    variables_table = create_hash_table();
    if (variables_table == NULL) {
        fprintf(stderr, "Failed to create variables hash table\n");
        exit(EXIT_FAILURE);
    }

}

void insert_variable(Stack* stack, char* name, char* type, int is_const) {
    if (stack == NULL || stack->top == NULL) {
        fprintf(stderr, "Stack is empty or not initialized\n");
        return; 
    }

    if(!has_type(type)) {
        fprintf(stderr, "Type '%s' does not exist\n", type);
        return; 
    }

    char* scope = stack->top->name;
    char* key = make_key(name, scope);
    
    if (hash_has(variables_table, key)) {
        fprintf(stderr, "Variable '%s' already exists in scope '%s'\n", name, scope);
        free(key);
        return;
    }

    variable_data* data = malloc(sizeof(variable_data));
    data->type = strdup(type);
    data->is_const = is_const;

    hash_insert(variables_table, key, data);
    free(key);
}

static char* make_key(char* name, char* scope) {
    char* key = (char*) malloc(strlen(name) + strlen(scope) + 2);
    if (key == NULL) {
        fprintf(stderr, "Memory allocation failed for variable key\n");
        exit(EXIT_FAILURE);
    }
    sprintf(key, "%s#%s", scope, name);
    return key;
}

int exists_in_scope(Stack* stack, char* name) {
    if (stack == NULL || stack->top == NULL) {
        return 0; 
    }

    char* scope = stack->top->name;
    char* key = make_key(name, scope);
    
    int exists = hash_has(variables_table, key);
    free(key);
    
    return exists;
}

variable_data* get_variable(Stack* stack, char* name) {
    if (stack == NULL || stack->top == NULL) return NULL;

    char* key = make_key(name, stack->top->name);
    variable_data* data = (variable_data*) hash_get(variables_table, key);
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

void remove_scope_variables(Stack* stack) {
    if (stack == NULL || stack->top == NULL) return;

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
}

int main() {
    printf("=== Inicializando tabelas ===\n");

    // Inicializa tabela de tipos e de variáveis
    init_types_table();
    init_variables_table();

    // Adiciona tipos primitivos
    insert_prim_type("int");
    insert_prim_type("float");

    // Cria a pilha de escopos
    Stack* stack = create_stack();  // escopo "global"

    // Escopo global
    printf("\n--- Escopo: global ---\n");
    insert_variable(stack, "x", "int", 0);       // int x
    insert_variable(stack, "pi", "float", 1);    // const float pi

    printf("Variáveis no escopo global:\n");
    print_variable_table();

    // Novo escopo: bloco 1 (global_0)
    printf("%s ---\n", stack->top == NULL ? "Pilha vazia" : stack->top->name);
    printf("\n--- Escopo 1: %s ---\n", stack->top->name);
    push_subprogram(stack, "function_1" , "int");
    printf("\n--- Escopo: %s ---\n", stack->top->name);

    insert_variable(stack, "y", "float", 0);     // float y
    insert_variable(stack, "x", "int", 1);       // const int x (shadowing)

    printf("Variáveis após entrar em novo escopo:\n");
    print_variable_table();

    // Checa variáveis
    variable_data* var = get_variable(stack, "x");
    printf("\n[x] no escopo atual: tipo = %s, const = %s\n",
           var->type, var->is_const ? "sim" : "nao");

    // Remoção das variáveis do escopo atual
    printf("\nRemovendo variáveis do escopo: %s\n", stack->top->name);
    remove_scope_variables(stack);

    printf("Tabela após remoção do escopo atual:\n");
    print_variable_table();

    // Sair do escopo
    pop(stack);

    // Confirma que 'x' voltou a ser o do global
    var = get_variable(stack, "x");
    printf("\n[x] no escopo global novamente: tipo = %s, const = %s\n",
           var->type, var->is_const ? "sim" : "nao");

    // Finaliza
    free_variables_tables();
    free_stack(stack);

    printf("\n=== Testes concluídos ===\n");
    return 0;
}