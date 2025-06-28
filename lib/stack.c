#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

Stack* create_stack() {
  Stack* stack = (Stack*) malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}

void push_subprogram(Stack* stack, char* name, char* return_type) {
  ScopeNode* node = (ScopeNode*) malloc(sizeof(ScopeNode));

  if (node == NULL)
  {
    printf("NO NODE!!! >.<\n");
    return;
  }

  node->name = strdup(name);
  node->count = 0;
  node->is_loop = 0;
  node->is_switch = 0;
  node->return_type = strdup(return_type);
  node->parent = NULL;
  stack->top = node;
}

void push(Stack* stack, int is_loop, int is_switch) {
  ScopeNode* parent = stack->top;

  char* parent_name = parent->name;

  char count_str[20];

  sprintf(count_str, "%d", parent->count);

  int name_size = strlen(parent_name) + strlen(count_str) + 2;
  char* name = (char*) malloc(name_size);

  if (name == NULL) {
    printf("NO MEMORY!!!\n");
    return;
  }

  snprintf(name, name_size, "%s_%s", parent_name, count_str);

  ScopeNode* node = (ScopeNode*) malloc(sizeof(ScopeNode));

  if (node == NULL)
  {
    printf("NO NODE!!! >.<\n");
    return;
  }

  node->name = name;
  node->count = 0;
  node->is_loop = parent->is_loop || is_loop;
  node->is_switch = parent->is_switch || is_switch;
  node->return_type = strdup(parent->return_type);
  node->parent = parent;
  parent->count++;
  stack->top = node;
}

void pop(Stack* stack) {
  ScopeNode* top = stack->top;

  if (top == NULL) {
    printf("STACK IS EMPTY!!! >.< \n");
    return;
  }

  free(top->name);
  free(top->return_type);

  stack->top = top->parent;
  free(top);
}

void free_stack(Stack *stack) {
  while (stack->top != NULL) {
    pop(stack);
  }

  free(stack);
}
