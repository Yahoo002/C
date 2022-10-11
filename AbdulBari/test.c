#include <stdio.h>

int main()
{
  int *p;
  int *q;
  int a = 10, b = 20;
  p = &a;
  q = &b;
  printf("%d \n%d", *p, *q);
  p = q;
  printf("\n%d \n%d", *p, *q);
}