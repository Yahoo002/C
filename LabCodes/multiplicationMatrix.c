#include <stdio.h>
#include <stdlib.h>

int main()
{
  int arr[10][10], arr2[10][10], multiply[10][10], row1, column1, row2, column2;

  printf("Enter dimesions of a m x n matrix\n");
  scanf("%d %d", &row1, &column1);

  printf("Enter dimesions of a 2nd m x n matrix\n");
  scanf("%d %d", &row2, &column2);

  if (column1 != row2)
  {
    printf("The column of 1st matrix and row of 2nd matrix should be equal\n");
    exit(0);
  }

  printf("Enter elements of the 1st %d x %d matrix\n", row1, column1);
  for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < column1; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  printf("Enter elements of the 2nd %d x %d matrix\n", row2, column2);
  for (int i = 0; i < row2; i++)
  {
    for (int j = 0; j < column2; j++)
    {
      scanf("%d", &arr2[i][j]);
    }
  }

  for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < column2; j++)
    {
      multiply[i][j] = 0;
      for (int k = 0; k < column1; k++)
      {
        multiply[i][j] = multiply[i][j] + arr[i][k] * arr2[k][j];
      }
    }
  }
  printf("The product of matrix is: \n");
  for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < column2; j++)
    {
      printf("%d ", multiply[i][j]);
    }
    printf("\n");
  }
  return 0;
}