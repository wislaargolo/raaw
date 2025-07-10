#ifndef LIST_H
#define LIST_H

typedef struct list {
  int size;
  int capacity;
  void** data;
} list;

void listInit(list* l, int size);
void _listPush_void(list* l, void* el);
void listPop(list* l);
void _listInsert_void(list* l, int index, void* el);
void listRemove(list* l, int index);
void freeList(list* l);
int listSize(list* l);
void* _listGet_void(list* l, int index);
void _listSet_void(list* l, int index, void* el);

#define listPush(l, el, type) do { \
  type* tmp = (type*) malloc(sizeof(type)); \
  *tmp = el; \
  _listPush_void(l, (void*) tmp); \
} while(0)

#define listInsert(l, index, el, type) do { \
  type* tmp = (type*) malloc(sizeof(type)); \
  *tmp = el; \
  _listInsert_void(l, index, (void*) tmp); \
} while(0)

#define _listGet(l, index, type) (*((type*) _listGet_void(l, index)))

#define _listSet(l, index, el, type) do { \
  type* tmp = (type*) malloc(sizeof(type)); \
  *tmp = el; \
  _listSet_void(l, index, (void*) tmp); \
} while(0)

#endif
