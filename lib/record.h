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

void free_record(record *);
record * create_record(char *, char *);
void free_param(parameter_record *);
parameter_record * create_param(char *, char *);
parameter_record * add_param(parameter_record *, parameter_record *);
int num_params(parameter_record*);

#endif
