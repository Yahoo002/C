#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
  int length;
  int breadth;
  char x;
} r2;

int main()
{
  struct Rectangle r1 = {10, 5};

  r2 = r1;
  printf("%lu\n", sizeof(r1));
  printf("%d\n", r2.breadth);
  return 0;
}