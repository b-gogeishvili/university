#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListItem {
  void* data;
  struct ListItem* next;
};

struct ListItem*
Insert(struct ListItem* item, void* data, size_t data_size) {
  struct ListItem* newListItem =
    (struct ListItem*)malloc(sizeof(struct ListItem));
  newListItem->data = malloc(data_size);
  newListItem->next = item;
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

int main() {
  
  // Create an int linked list
  // 10 -> 20 -> 30 -> 40
  struct ListItem* lst1 = NULL;
  unsigned i_size = sizeof(int);
  int i_arr[] = {40, 30, 20, 10};
  lst1 = Insert(lst1, i_arr, i_size);
  lst1 = Insert(lst1, i_arr + 1, i_size);
  lst1 = Insert(lst1, i_arr + 2, i_size);
  lst1 = Insert(lst1, i_arr + 3, i_size);
  
  
  // Printing the Integer list
  printf("Created integer linked list is: \n");
  PrintAll(lst1, PrintInt);
  
  // Create an float linked list
  // 10.1 -> 20.2 -> 30.3 -> 40.4
  struct ListItem* lst2 = NULL;
  unsigned f_size = sizeof(float);
  float f_arr[] = {40.4, 30.3, 20.2, 10.1};
  lst2 = Insert(lst2, f_arr, f_size);
  lst2 = Insert(lst2, f_arr + 1, f_size);
  lst2 = Insert(lst2, f_arr + 2, f_size);
  lst2 = Insert(lst2, f_arr + 3, f_size);
  
  // Printing the Float list
  printf("\nCreated float linked list is: \n");
  PrintAll(lst2, PrintFloat);
    
  return 0;
}
