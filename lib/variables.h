#ifndef VARIABLES
#define VARIABLES

struct variable_data {
    char* type;
    int is_const;
};

typedef struct variable_data variable_data;

void init_variables_table();
int insert_variable(Stack* stack, char* name, char* type, int is_const);
char* make_key(char* name, char* scope);
int exists_in_scope(Stack* stack, char* name);
int exists_scope_parent(Stack* stack, char* name);
variable_data get_variable(Stack* stack, char* name);
char* get_variable_type(Stack* stack, char* name);
void free_variables_table();
int remove_scope_variables(Stack* stack);
int is_const_variable(Stack* stack, char* name);

//void insert_const_variable(Stack* stack, char* name, char* type);
//bool is_const_variable(Stack* stack, char* name);
//bool is_global_variable(char* name);
#endif
