#include <stdio.h>
int main()
{

  int a[5] = {5, 2, 3, 4, 7};
  int i = ++a[2];
  int j = a[2]++;
  int k = a[i++];
  printf("%d \t%d \t%d", i, j, k);
}