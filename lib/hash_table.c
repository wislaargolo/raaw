#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

hash_table* create_hash_table() {
  hash_table* ht = (hash_table*) malloc(sizeof(hash_table));

  ht->capacity = 100;
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
  int index = hash_function(ht, key);
  hash_node* node = (hash_node*) malloc(sizeof(node));

  node->key = strdup(key);
  node->value = value;
  node->next = NULL;

  if (ht->nodes[index] == NULL) {
    ht->nodes[index] = node;
  }

  else {
    node->next = ht->nodes[index];
    ht->nodes[index] = node;
  }
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
      free(curr_node);
      break;
    }
    prev_node = curr_node;
    curr_node = curr_node->next;
  }
  return;
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
