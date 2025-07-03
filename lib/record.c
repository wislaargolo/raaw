#include "record.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_record(record * r){
  if (r) {
    if (r->code != NULL) free(r->code);
	  if (r->type != NULL) free(r->type);
    free(r);
  }
}

record * create_record(char * c1, char * c2){
  record * r = (record *) malloc(sizeof(record));

  if (!r) {
    printf("Allocation problem. Closing application...\n");
    exit(0);
  }

  r->code = strdup(c1);
  r->type = strdup(c2);

  return r;
}

parameter_record * create_param(char * c1, char * c2){
  parameter_record * r = (parameter_record *) malloc(sizeof(parameter_record));

  if (!r) {
    printf("Allocation problem. Closing application...\n");
    exit(0);
  }

  r->code = strdup(c1);
  r->type = strdup(c2);
  r->next = NULL;

  return r;
}

parameter_record * add_param(parameter_record * head, parameter_record * new_param) {
  if(head == NULL) {
    return new_param; 
  }
  parameter_record * current = head;
  while(current->next != NULL) {
    current = current->next;
  }
  current->next = new_param;
  return head;
}

void free_param(parameter_record * r) {
  if (r) {
    if (r->code != NULL) free(r->code);
    if (r->type != NULL) free(r->type);
    while(r->next != NULL) {
      parameter_record * next = r->next;
      free(r);
      r = next;
    }
  }
}

