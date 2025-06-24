#ifndef RECORD
#define RECORD

struct record {
	   char * code; 
	   char * type; 
};

typedef struct record record;
 
void free_record(record *);
record * create_record(char *, char *);

#endif