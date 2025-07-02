#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

hash_table* create_hash_table() {
  hash_table* ht = (hash_table*) malloc(sizeof(hash_table));

  ht->capacity = 5;
  ht->num_elements = 0;
  ht->nodes = (hash_node**) malloc(sizeof(hash_node*) * ht->capacity);

  return ht;
}

int hash_function(hash_table* ht, char* key) {
  int index;
  int sum = 0, factor = 31;

  for (int i = 0; i < strlen(key); i++) {
    sum = ((sum % ht->capacity)
            + (((int)key[i]) * factor) % ht->capacity)
          % ht->capacity;

    factor = ((factor % __INT16_MAX__)
              * (31 % __INT16_MAX__))
              % __INT16_MAX__;
  }

  index = sum;
  return index;
}

void hash_insert(hash_table* ht, char* key, void* value) {
  if (ht->num_elements >= 0.75 * ht->capacity) {
      hash_resize(ht, ht->capacity * 2);
  }

  int index = hash_function(ht, key);
  hash_node* node = ht->nodes[index];

  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      free(node->value);  
      node->value = value;
      return;
    }
    node = node->next;
  }

  hash_node* new_node = (hash_node*) malloc(sizeof(hash_node));
  new_node->key = strdup(key);
  new_node->value = value;
  new_node->next = ht->nodes[index];
  ht->nodes[index] = new_node;
  ht->num_elements++;

}

void hash_delete(hash_table* ht, char* key) {
  int index = hash_function(ht, key);

  hash_node* prev_node = NULL;
  hash_node* curr_node = ht->nodes[index];

  while (curr_node != NULL) {
    if (strcmp(key, curr_node->key) == 0) {
      if (curr_node == ht->nodes[index]) {
        ht->nodes[index] = curr_node->next;
      } else {
        prev_node->next = curr_node->next;
      }
      free(curr_node->value);
      free(curr_node->key);
      free(curr_node);
      ht->num_elements--;
      break;
  }
    prev_node = curr_node;
    curr_node = curr_node->next;
  }

}

int hash_has(hash_table* ht, char* key) {
  int index = hash_function(ht, key);

  hash_node* node = ht->nodes[index];
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      return 1;
    }
    node = node->next;
  }

  return 0;
}

void* hash_get(hash_table* ht, char* key) {
  int index = hash_function(ht, key);

  hash_node* node = ht->nodes[index];
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      return node->value;
    }
    node = node->next;
  }

  return NULL;

}

void hash_resize(hash_table* ht, int new_capacity) {
  if(ht == NULL || new_capacity <= ht->capacity) {
    return;
  }
  hash_node** new_nodes = (hash_node**) calloc(new_capacity, sizeof(hash_node*));
  int old_capacity = ht->capacity;
  ht->capacity = new_capacity;

  for (int i = 0; i < old_capacity; i++) {
    hash_node* node = ht->nodes[i];
    while (node) {
      hash_node* next = node->next;

      int index = hash_function(ht, node->key);
      node->next = new_nodes[index];
      new_nodes[index] = node;

      node = next;
    }
  }

  free(ht->nodes);
  ht->nodes = new_nodes;
  ht->capacity = new_capacity;
}

void free_hash(hash_table* ht) {
  if (ht == NULL) return;

  for (int i = 0; i < ht->capacity; i++) {
    hash_node* node = ht->nodes[i];
    while (node) {
      hash_node* next = node->next;

      free(node->key);     
      free(node->value);   
      free(node);          

      node = next;
    }
  }

  free(ht->nodes);   
  free(ht);          
}



void print_hash_table(hash_table* ht) {
  printf("\n[ESTADO ATUAL DA HASH TABLE]\n");
  printf("Capacidade: %d | Elementos: %d\n", ht->capacity, ht->num_elements);

  for (int i = 0; i < ht->capacity; i++) {
    printf("Bucket %d: ", i);
    hash_node* node = ht->nodes[i];
    if (node == NULL) {
        printf("(vazio)\n");
        continue;
    }

    while (node != NULL) {
        printf("['%s' -> %p] -> ", node->key, node->value);
        node = node->next;
    }
    printf("NULL\n");
  }

  printf("\n");
}

