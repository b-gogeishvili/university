#include <stdio.h>
#include <string.h>

typedef int (*PF) (const char*, const char*);

int main()
{
  PF mycmp = strcmp;
  printf("Output = %i\n", mycmp("MyStr1","MyStr2"));
}
