#include <stdlib.h>
#include <stdio.h>

int main()
{
  int n, arr[5][5], temp;

  printf("Enter dimensions of the N square matrix\n");
  scanf("%d", &n);
  printf("Enter elements of a %d x %d matrix\n", n, n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
      {
        temp = arr[i][j];
        arr[i][j] = arr[i][n - i - 1];
        arr[i][n - i - 1] = temp;
      }
    }
  }

  printf("The changed matrix is: \n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}