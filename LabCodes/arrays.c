#include <stdio.h>

void arrayInsertion();
void arrayDeletion();
void arrayReverse();
void arrayInsertSort();

int main()
{
  int n = 10;
  int arr[20] = {0};
  int pos = 2;
  int num = 3;
  printf("Enter 10 numbers\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  // arrayInsertion(pos, arr, sum, n);
  // arrayDeletion(pos, arr, n);
  // arrayReverse(arr, n);
  // arrayInsertSort(arr, n, num);

  return 0;
}

void arrayInsertion(int pos, int arr[], int num, int n)
{
  // int arrLength = sizeof(arr) / sizeof(arr[0]) + 1;
  if (pos <= n)
  {
    for (int i = n + 1; i >= pos; i--)
    {
      arr[i] = arr[i - 1];
    }
  }
  else
  {
    printf("Error. Please enter position within 0-10\n");
  }
  arr[pos - 1] = num;
  printf("When %d is added to %d position\n", num, pos);
  for (int i = 0; i < n + 1; i++)
  {
    printf("%d ", arr[i]);
  }
}

void arrayDeletion(int pos, int arr[], int n)
{
  if (pos <= n)
  {
    for (int i = pos - 1; i <= n - 1; i++)
    {
      arr[i] = arr[i + 1];
    }
  }
  else
  {
    printf("Enter position within 0-10\n");
  }

  printf("\nWhen number on %d position is removed:\n", pos);
  for (int i = 0; i < n - 1; i++)
  {
    printf("%d ", arr[i]);
  }
}

void arrayReverse(int arr[], int n)
{
  for (int i = 0; i < n / 2; i++)
  {
    int temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
  }
  printf("\nThe reversed array is:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}

void arrayInsertSort(int arr[], int n, int num)
{
  int i;
  for (i = n - 1; num < arr[i] && i >= 0; i--)
  {
    arr[i + 1] = arr[i];
  }
  arr[i + 1] = num;
  n++;
  printf("The element %d added in sorted array is:\n", num);
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}