#ifndef FUNCTIONS
#define FUNCTIONS

typedef struct function_param {
    char* type;                    
    struct function_param* next;   
} function_param;


typedef struct {
    char* return_type;
    int num_params;   
    function_param* params; 
    function_param* last_param; 
} function_data;

void init_function_table(); 
int insert_function(char* name, char* return_type, function_data** current);
int has_function(char* name);
function_data get_function(char* name);
int new_param(function_data* function, char* type);

void free_function_table();
void free_params(function_param* params);
void print_function_table();

#endif
