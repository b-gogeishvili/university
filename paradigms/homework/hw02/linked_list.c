#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct ListItem* LinkedList;
typedef struct ListItem {
  void* data;
  LinkedList next;
} Item;


LinkedList
Insert(LinkedList item, void* data, size_t data_size) {
  LinkedList newItem = (LinkedList)malloc(sizeof(Item));
  newItem->data = malloc(data_size);
  newItem->next = item;
  memcpy(newItem->data, data, data_size);
  
  return newItem;
}

struct Student* Find(LinkedList list, void* match, struct Student* (*f)(LinkedList, void*)) {
    return f(list, match);
}

// Function that access and prints the linked list. This function needs
// to know how many bytes of memory is to be read to print the data
// So a function pointer is required for printing different data type
void PrintLinkedList(LinkedList lst, void (*f)(void *)) {
  while (lst != NULL) {
    f(lst->data);
    lst = lst->next;
  }
  printf("\n");
}

// void PrintIntLinked(void* n) {
//   printf(" %d", *(int*)n);
// }

// void PrintFloatLinked(void *f) {
//   printf(" %.3f", *(float*)f);
// }
