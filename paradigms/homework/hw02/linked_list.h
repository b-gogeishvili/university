#include <stdbool.h>

struct ListItem {
  void* data; // Can point to any data type
  struct ListItem* next;
};

struct ListItem* Insert(struct ListItem*, void*, size_t);

void PrintLinkedList(struct ListItem*, void (*)(void*));
struct Student* Find(struct ListItem*, void*, struct Student* (*)(struct ListItem*, void*));
