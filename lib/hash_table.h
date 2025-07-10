#ifndef HASH_TABLE
#define HASH_TABLE

#define hash_insert_t(ht, key, value, type) do { \
  type* tmp = (type*) malloc(sizeof(tmp));     \
  *tmp = value;                                \
  hash_insert(ht, key, (void*) tmp);           \
} while(0)

#define hash_get_t(ht, key, type) (*((type*) hash_get(ht, key)))

struct hash_node {
  char* key;
  void* value;
  struct hash_node* next;
};

typedef struct hash_node hash_node;

struct hash_table {
  int num_elements, capacity;
  hash_node** nodes;
};

typedef struct hash_table hash_table;

hash_table* create_hash_table();
void hash_insert(hash_table* ht, char* key, void* value);
void hash_delete(hash_table* ht, char* key);
int hash_has(hash_table* ht, char* key);
void* hash_get(hash_table* ht, char* key);
void hash_resize(hash_table* ht, int new_capacity);
void free_hash(hash_table* ht);

#endif
