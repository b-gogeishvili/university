#include <stdlib.h>

struct ListItem {
  void* data; //Can point to any data type
  struct ListItem* next;
};

// Function to insert data. Ssize of the data type is also required
struct ListItem* Insert(struct ListItem*, void*, size_t);

// Function that access and prints the linked list. This function needs
// to know how many bytes of memory is to be read to print the data
// So a function pointer is required for printing different data type
void PrintAll(struct ListItem*, void (*)(void*));

// Helper function to print an integer
void PrintInt(void*);

// Helper function to print a float
void PrintFloat(void*);
