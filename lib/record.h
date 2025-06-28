#ifndef RECORD
#define RECORD

struct declaration_term_record {
	char* code;
	char* name;
	int dimension;
	struct declaration_term_record* next;
};

typedef struct declaration_term_record declaration_term_record;

struct record {
	char * code;
	char * type;
};

typedef struct record record;

void free_record(record *);
record * create_record(char *, char *);

#endif
