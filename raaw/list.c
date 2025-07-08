#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

#define INITIAL_CAPACITY 4

void ensureCapacity(list* l) {
  if (l->size >= l->capacity) {
    int newCapacity = l->capacity == 0 ? INITIAL_CAPACITY : l->capacity * 2;
    void** newData = (void**) realloc(l->data, newCapacity * sizeof(void*));
    if (!newData) return;
    l->data = newData;
    l->capacity = newCapacity;
  }
}

void listInit(list* l, int size) {
  l->size = size;
  l->capacity = size;
  l->data = (void**) malloc(size * sizeof(void*));
}

void _listPush_void(list* l, void* el) {
  ensureCapacity(l);
  l->data[l->size++] = el;
}

void listPop(list* l) {
  if (l->size == 0) return;
  l->size--;
  if (l->data[l->size]) {
    free(l->data[l->size]);
  }
}

void _listInsert_void(list* l, int index, void* el) {
  if (index < 0) index = 0;
  if (index > l->size) index = l->size;
  ensureCapacity(l);
  memmove(&l->data[index + 1], &l->data[index], (l->size - index) * sizeof(void*));
  l->data[index] = el;
  l->size++;
}

void listRemove(list* l, int index) {
  if (index < 0 || index >= l->size) return;
  if (l->data[index]) {
    free(l->data[index]);
  }
  memmove(&l->data[index], &l->data[index + 1], (l->size - index - 1) * sizeof(void*));
  l->size--;
}

void listClear(list* l) {
  for (int i = 0; i < l->size; i++) {
    if (l->data[i] != NULL) {
      free(l->data[i]);
    }
  }

  if (l->data != NULL) {
    free(l->data);
  }
  printf("%d\n", l->size);
  l->data = NULL;
  l->size = 0;
  printf("%d\n", l->size);
  l->capacity = 0;
}

int listSize(list* l) {
  return l->size;
}

void* _listGet_void(list* l, int index) {
  if (index < 0 || index >= l->size) {
    printf("List index out of bounds\n");
    listClear(l);
    exit(1);
  };
  return l->data[index];
}

void _listSet_void(list* l, int index, void* el) {
  if (index < 0 || index >= l->size) {
    printf("List index out of bounds\n");
    listClear(l);
    exit(1);
  };
  if (l->data[index]) {
      free(l->data[index]);
  }
  l->data[index] = el;
}
