#include <stdio.h>
#include <math.h>
int main()
{
  int arr[20][20], norm = 0, sum = 0, trace = 0;
  int m = 3, n = 3;
  printf("Enter elements of a 3x3 matrix\n");

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  for (int i = 0; i < m; i++)
  {
    trace = trace + arr[i][i];
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      sum = sum + arr[i][j] * arr[i][j];
    }
  }

  norm = sqrt(sum);

  printf("The trace is: %d\n", trace);
  printf("The norm is: %d\n", norm);
  return 0;
}