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
  r->var_declarations.size = 0;
  r->var_declarations.top = NULL;

  return r;
}
