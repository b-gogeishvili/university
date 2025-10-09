#include <stdio.h>
#include <string.h>
#include "my_linked_list.h"

// Function to insert data. Ssize of the data type is also required
struct ListItem* Insert(struct ListItem* item, void* data, size_t data_size) {
  
  // Allocate memory for a new item
  struct ListItem* newListItem = (struct ListItem*)malloc(sizeof(struct ListItem));
  
  newListItem->data = malloc(data_size);
  newListItem->next = item;
  
  // Copy contents of data to newly allocated memory.
  memcpy(newListItem->data, data, data_size);
  
  return newListItem;
}

// Function that access and prints the linked list. This function needs
// to know how many bytes of memory is to be read to print the data
// So a function pointer is required for printing different data type
void PrintAll(struct ListItem *lst, void (*f)(void *)) {
  while (lst != NULL) {
    f(lst->data);
    lst = lst->next;
  }
  printf("\n");
}

// Helper function to print an integer
void PrintInt(void* n) {
  printf(" %d", *(int*)n);
}

// Helper function to print a float
void PrintFloat(void *f) {
  printf(" %.3f", *(float*)f);
}
