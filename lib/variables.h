#ifndef VARIABLES
#define VARIABLES   

struct variable_data {
    char* type;     
    int is_const;  
};

typedef struct variable_data variable_data;

void init_variables_table();
void insert_variable(Stack* stack, char* name, char* type, int is_const);
static char* make_key(char* name, char* scope);
int exists_in_scope(Stack* stack, char* name);
variable_data* get_variable(Stack* stack, char* name);
void print_variable_table();
void free_variables_tables();
void remove_scope_variables(Stack* stack);

//void remove_scope_variables(char* scope_id);
//void insert_const_variable(Stack* stack, char* name, char* type);
//bool is_const_variable(Stack* stack, char* name);
//bool is_global_variable(char* name);
#endif
