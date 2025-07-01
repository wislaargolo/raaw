#ifndef STACK
#define STACK

typedef struct ScopeNode {
  char* name;
  struct ScopeNode* parent;
  int is_loop;
  int is_switch;
  char* return_type;
  int count;
  char* break_label;
  char* continue_label;
  char* if_end_label;
} ScopeNode;

typedef struct Stack {
  ScopeNode* top;
} Stack;

Stack* create_stack();

void push_subprogram(Stack* stack, char* name, char* return_type);

void push(Stack* stack, int is_loop, int is_switch);

void pop(Stack* stack);

void free_stack(Stack *stack);

#endif
