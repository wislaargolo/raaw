#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "variables.h"

Stack* create_stack() {
  Stack* stack = (Stack*) malloc(sizeof(Stack));
  ScopeNode* node = (ScopeNode*) malloc(sizeof(ScopeNode));
  if (stack == NULL || node == NULL) {
    printf("NO MEMORY!!!\n");
    return NULL;
  }
  node->name = strdup("");
  node->is_loop = 0;
  node->is_switch = 0;
  node->parent = NULL;
  node->count = 0;
  node->break_label = NULL;
  node->continue_label = NULL;
  node->if_end_label = NULL;
  stack->top = node;
  return stack;
}

void push_subprogram(Stack* stack, char* name) {
  ScopeNode* node = (ScopeNode*) malloc(sizeof(ScopeNode));

  if (node == NULL) {
    printf("NO NODE!!! >.<\n");
    return;
  }

  node->name = strdup(name);
  node->count = 0;
  node->is_loop = 0;
  node->is_switch = 0;
  node->parent = stack->top;
  node->break_label = NULL;
  node->continue_label = NULL;
  node->if_end_label = NULL;
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

  if (node == NULL) {
    printf("NO NODE!!! >.<\n");
    return;
  }

  if (is_loop || is_switch) {
        node->break_label = NULL;
        node->continue_label = NULL;
    } else {
        node->break_label = parent->break_label ? strdup(parent->break_label) : NULL;
        node->continue_label = parent->continue_label ? strdup(parent->continue_label) : NULL;
  }


  node->if_end_label = parent->if_end_label ? strdup(parent->if_end_label) : NULL;

  node->name = name;
  node->count = 0;
  node->is_loop = parent->is_loop || is_loop;
  node->is_switch = parent->is_switch || is_switch;
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

  remove_scope_variables(stack);

  if (top->name) free(top->name);
  if (top->break_label) free(top->break_label);
  if (top->continue_label) free(top->continue_label);
  if (top->if_end_label) free(top->if_end_label);

  stack->top = top->parent;
  free(top);
}

void free_stack(Stack *stack) {
  while (stack->top != NULL) {
    pop(stack);
  }

  free(stack);
}
