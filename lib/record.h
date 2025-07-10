#ifndef RECORD
#define RECORD

struct parameter_record {
    char* code;
    char* type;
    struct parameter_record* next;
};

typedef struct parameter_record parameter_record;

struct declaration_term_record {
	char* code;
	char* name;
	char* init_type;
	int dimension;
	struct declaration_term_record* next;
};

typedef struct declaration_term_record declaration_term_record;

struct type_record {
	char* code;
	char* name;
};

typedef struct type_record type_record;

struct record {
	char * code;
	char * type;
};

typedef struct record record;

struct dimensional_record {
  char* code;
  char* type;
  int dimension;
};

typedef struct dimensional_record dimensional_record;

struct identifier_ref_record {
  char* code;
  char* type;
	char* setter_code;
	char* ref_code;
};

typedef struct identifier_ref_record identifier_ref_record;

void free_record(record *);
record * create_record(char *, char *);
void free_param(parameter_record *);
parameter_record * create_param(char *, char *);
parameter_record * add_param(parameter_record *, parameter_record *);
int num_params(parameter_record*);

#endif
