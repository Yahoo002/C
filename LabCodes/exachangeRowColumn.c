#include <stdio.h>

int main()
{
  int arr[10][10], arr2[10][10], row, column, temp = 0;
  printf("Enter dimesions of a m x n matrix\n");
  scanf("%d %d", &row, &column);

  printf("Enter elements of the %d x %d matrix\n", row, column);
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      scanf("%d", &arr[i][j]);
      arr2[i][j] = arr[i][j];
    }
  }

  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      temp = arr[i][j];
      arr[i][j] = arr2[j][i];
      arr2[j][i] = temp;
    }
  }
  printf("The exchanged row and column matrix is: \n");
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      printf("%d ", arr2[i][j]);
    }
    printf("\n");
  }
  return 0;
}