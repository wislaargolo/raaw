<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "functions.h"
#include "aux_functions.h"

int yyerror(char *msg);

hash_table* functions_table;

void initial_functions() {
    insert_function("print", "void", NULL);
    insert_function("printLine", "void", NULL);
    insert_function("readInt", "int", NULL);
    insert_function("readFloat", "float", NULL);
    insert_function("readChar", "char", NULL);
    insert_function("readString", "string", NULL);
    insert_function("readBoolean", "boolean", NULL);
}

void init_function_table() {
    functions_table = create_hash_table();
    initial_functions();
}

int insert_function(char* name, char* return_type, function_data** current) {

    if(has_function(name)) { 
        if(current != NULL) *current = hash_get(functions_table, name);
        return 1;
    }
     
    
    function_data* data = malloc(sizeof(function_data));
    data->return_type = strdup(return_type);
    data->params = NULL;
    data->last_param = NULL; 
    data->num_params = 0;

    if (current) *current = data;
    

    hash_insert(functions_table, name, data);

    return 0;
}

int new_param(function_data* function, char* type) {

    if (function == NULL || type == NULL) return -1;

    function_param* param = malloc(sizeof(function_param));
    param->type = strdup(type);
    function->num_params++;

    if (function->params == NULL) {
        function->params = param;
        function->last_param = param;
    } else {
        function->last_param->next = param;
        function->last_param = param;
    }
    param->next = NULL;

    return 0;
}

int has_function(char* name) {
    return hash_has(functions_table, name);
}

function_data get_function(char* name) {
    return hash_get_t(functions_table, name, function_data);
}

char* get_function_return_type(char* name) {
    function_data data = get_function(name);
    return data.return_type;
}

void free_params(function_param* params) {
    while (params != NULL) {
        function_param* next = params->next;
        free(params->type); 
        free(params);
        params = next;
    }
}

void free_function_table() {
    if (functions_table == NULL) return;

    for (int i = 0; i < functions_table->capacity; i++) {
        hash_node* node = functions_table->nodes[i];
        while (node != NULL) {
            function_data* data = (function_data*) node->value;
            if (data) {
                free(data->return_type);
                free_params(data->params);
            }
            node = node->next;
        }
    }

    free_hash(functions_table);
}

void print_function_table() {
    printf("\n[ESTADO ATUAL DA TABELA DE FUNÇÕES]\n");
    printf("Capacidade: %d | Elementos: %d\n", functions_table->capacity, functions_table->num_elements);

    for (int i = 0; i < functions_table->capacity; i++) {
        printf("Bucket %d: ", i);
        hash_node *node = functions_table->nodes[i];
        if (node == NULL) {
            printf("(vazio)\n");
            continue;
        }

        while (node != NULL) {
            
            function_data fd = *(function_data *)node->value;
            printf("['%s' -> ret:%s, n=%d", node->key, fd.return_type, fd.num_params);
            if(fd.num_params > 0) printf(", params: ");

            function_param* param = fd.params;
            while(param != NULL) {
                    printf("%s", param->type);
                    if (param->next != NULL) {
                        printf(", ");
                    }
                
                param = param->next;
            }
            printf("] -> ");
            
            node = node->next;
        }
        printf("NULL\n");
    }
    printf("\n");
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "functions.h"
#include "aux_functions.h"

int yyerror(char *msg);

hash_table* functions_table;

void init_function_table() {
    functions_table = create_hash_table();
    insert_function("print", "void", NULL);
    insert_function("printLine", "void", NULL);
    insert_function("strCopy", "void", NULL);
    insert_function("strConcat", "void", NULL);
    insert_function("strCompSize", "void", NULL);
    insert_function("strNCopy", "void", NULL);
    insert_function("strDup", "void", NULL);
    insert_function("toUpper", "void", NULL);
    insert_function("toLower", "void", NULL);
    insert_function("freeString", "void", NULL);
    insert_function("isEquals", "void", NULL);
}

int insert_function(char* name, char* return_type, function_data** current) {

    if(has_function(name)) {
        if(current != NULL) *current = hash_get(functions_table, name);
        return 1;
    }


    function_data* data = malloc(sizeof(function_data));
    data->return_type = strdup(return_type);
    data->params = NULL;
    data->last_param = NULL;
    data->num_params = 0;

    if (current) *current = data;


    hash_insert(functions_table, name, data);

    return 0;
}

int new_param(function_data* function, char* type) {

    if (function == NULL) return -1;

    function_param* param = malloc(sizeof(function_param));
    param->type = strdup(type);
    function->num_params++;

    if (function->params == NULL) {
        function->params = param;
        function->last_param = param;
    } else {
        function->last_param->next = param;
        function->last_param = param;
    }
    param->next = NULL;

    return 0;
}

int has_function(char* name) {
    return hash_has(functions_table, name);
}

function_data get_function(char* name) {
    return hash_get_t(functions_table, name, function_data);
}

void free_params(function_param* params) {
    while (params != NULL) {
        function_param* next = params->next;
        free(params->type);
        free(params);
        params = next;
    }
}

void free_function_table() {
    if (functions_table == NULL) return;

    for (int i = 0; i < functions_table->capacity; i++) {
        hash_node* node = functions_table->nodes[i];
        while (node != NULL) {
            function_data* data = (function_data*) node->value;
            if (data) {
                free(data->return_type);
                free_params(data->params);
            }
            node = node->next;
        }
    }

    free_hash(functions_table);
}

void print_function_table() {
    printf("\n[ESTADO ATUAL DA TABELA DE FUNÇÕES]\n");
    printf("Capacidade: %d | Elementos: %d\n", functions_table->capacity, functions_table->num_elements);

    for (int i = 0; i < functions_table->capacity; i++) {
        printf("Bucket %d: ", i);
        hash_node *node = functions_table->nodes[i];
        if (node == NULL) {
            printf("(vazio)\n");
            continue;
        }

        while (node != NULL) {

            function_data fd = *(function_data *)node->value;
            printf("['%s' -> ret:%s, n=%d", node->key, fd.return_type, fd.num_params);
            if(fd.num_params > 0) printf(", params: ");

            function_param* param = fd.params;
            while(param != NULL) {
                param = param->next;
                if (param != NULL) {
                    printf(", ");
                }
            }
            printf("] -> ");

            node = node->next;
        }
        printf("NULL\n");
    }
    printf("\n");
}
>>>>>>> origin/ana
