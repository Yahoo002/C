#include <stdio.h>
#include <stdlib.h>
int main()
{
  int m = 3, n = 3, p = 3, q = 3;
  int arr[10][10], arr2[10][10];

  printf("Enter elements of a 3x3 matrix\n");

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  printf("Enter elements of a 2nd 3x3 matrix\n");

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &arr2[i][j]);
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (arr[i][j] != arr2[j][i])
      {
        printf("Matrix is not symmetric.");
        exit(0);
      }
    }
  }

  printf("Matrix is symmetric");
  return 0;
}