#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "functions.h"
#include "aux_functions.h"

int yyerror(char *msg);

hash_table* functions_table;

void initial_functions() {
    function_data* fdata;

    insert_function("print", "void", NULL);
    insert_function("printLine", "void", NULL);
    insert_function("readInt", "int", NULL);
    insert_function("readFloat", "float", NULL);
    insert_function("readChar", "char", NULL);
    insert_function("readString", "string", NULL);
    insert_function("readBoolean", "boolean", NULL);

    insert_function("strLen", "int", &fdata);
    new_param(fdata, "string");

    insert_function("strCopy", "string", &fdata);
    new_param(fdata, "string");
    new_param(fdata, "string");

    insert_function("strConcat", "string", &fdata);
    new_param(fdata, "string");
    new_param(fdata, "string");

    insert_function("strNCopy", "string", &fdata);
    new_param(fdata, "string");
    new_param(fdata, "string");
    new_param(fdata, "int");

    insert_function("strDup", "string", &fdata);
    new_param(fdata, "string");

    insert_function("toUpper", "char", &fdata);
    new_param(fdata, "char");

    insert_function("toLower", "char", &fdata);
    new_param(fdata, "char");

    insert_function("freeString", "void", &fdata);
    new_param(fdata, "string");

    insert_function("isEquals", "boolean", &fdata);
    new_param(fdata, "string");
    new_param(fdata, "string");

    insert_function("listPush", "void", &fdata);
    new_param(fdata, "list<_>");
    new_param(fdata, "_");

    insert_function("listPop", "void", &fdata);
    new_param(fdata, "list<_>");

    insert_function("listInsert", "void", &fdata);
    new_param(fdata, "list<_>");
    new_param(fdata, "int");
    new_param(fdata, "_");

    insert_function("listRemove", "void", &fdata);
    new_param(fdata, "list<_>");
    new_param(fdata, "int");

    insert_function("freeList", "void", &fdata);
    new_param(fdata, "list<_>");

    insert_function("listSize", "int", &fdata);
    new_param(fdata, "list<_>");

    insert_function("listInit", "void", &fdata);
    new_param(fdata, "list<_>");
    new_param(fdata, "int");

    insert_function("openFile",         "file",  &fdata);
    new_param(fdata, "string");
    new_param(fdata, "string");

    insert_function("closeFile",        "int",   &fdata);
    new_param(fdata, "file");

    insert_function("readCharFile",     "char",  &fdata);
    new_param(fdata, "file");

    insert_function("readStringFile",  "string", &fdata);
    new_param(fdata, "string");
    new_param(fdata, "int");
    new_param(fdata, "file");

    insert_function("writeCharFile",    "int",   &fdata);
    new_param(fdata, "char");
    new_param(fdata, "file");

    insert_function("writeStringFile",  "int",   &fdata);
    new_param(fdata, "string");
    new_param(fdata, "file");

    insert_function("isEof",        "boolean",   &fdata);
    new_param(fdata, "char");

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
    if(has_function(name)) {
        return hash_get_t(functions_table, name, function_data);
    }
    return (function_data){NULL, 0, NULL, NULL};
}

char* get_function_return_type(char* name) {
    function_data data = get_function(name);
    return strdup(data.return_type);
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

