// Used to access HEAP memory
// & - Address of variable
// * - Value at variable or declaring a pointer
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *p;
  p = (int *)malloc(5 * sizeof(int)); // assigns memory in heap
  p[0] = 1;
  p[1] = 2;
  for (int i = 0; i < 5; i++)
  {
    printf("%d\n", p[i]);
  }
}