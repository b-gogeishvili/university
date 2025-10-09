#include <stdio.h>
#include <my_linked_list.h>

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
