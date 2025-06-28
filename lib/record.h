#ifndef RECORD
#define RECORD

struct var_declaration {
	char* name;
	char* type;
	int dimension;
	struct var_declaration* next;
};

typedef struct var_declaration var_declaration;

struct var_declaration_list {
	int size;
	var_declaration* top;
};

typedef struct var_declaration_list var_declaration_list;

struct record {
	char * code;
	char * type;
	var_declaration_list var_declarations;
};

typedef struct record record;

void free_record(record *);
record * create_record(char *, char *);

#endif
