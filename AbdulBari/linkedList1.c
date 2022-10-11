// #include <stdlib.h>
// #include <stdio.h>

// struct Node
// {
//   int data;
//   struct Node *next;
// } *first = NULL;

// void create(int arr[], int n)
// {
//   int i;
//   struct Node *t, *last;
//   first = (struct Node *)malloc(sizeof(struct Node));
//   first->data = arr[0];
//   first->next = NULL;
//   last = first;

//   for (i = 1; i < n; i++)
//   {
//     t = (struct Node *)malloc(sizeof(struct Node));
//     t->data = arr[i];
//     t->next = NULL;
//     last->next = t;
//     last = t;
//   }
// }

// void display(struct Node *p)
// {
//   while (p != NULL)
//   {
//     printf("%d ", p->data);
//     p = p->next;
//   }
// }

// int main()
// {
//   int arr[] = {3, 5, 7, 9, 11};
//   create(arr, 5);
//   display(first);
//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
} *first = NULL;

void create(int arr[], int n)
{
  int i;
  struct Node *t, *last;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = arr[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = arr[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

void display(struct Node *p)
{ // printing using recursion
  if (p != NULL)
  {
    printf("%d ", p->data);
    display(p->next);
  }
  if (p == NULL)
  {
    printf("\n");
  }
  // printf("%d", p);
}

int count(struct Node *p)
{
  if (p == 0)
  {
    return 0;
  }
  else
  {
    return count(p->next) + 1;
  }
}

// int add(struct Node *p)
// {
//   int sum = 0;
//   while (p)
//   {
//     sum = sum + p->data;
//     p = p->next;
//   }
//   return sum;

// using recursion
// if (p == 0)
// {
//   return 0;
// }
// else
// {
//   return add(p->next) + p->data;
// }
//}

// int max(struct Node *p)
// {
//   int max = INT32_MIN;
//   while (p)
//   {
//     if (p->data > max)
//     {
//       max = p->data;
//     }
//     p = p->next;
//   }
//   return max;
// }

// struct Node *Rsearch(struct Node *p, int key)
// {
//   // using recursion
//   if (p == NULL)
//     return 0;
//   if (key == p->data)
//     return p;
//   return Lsearch(p->next, key);
// }

// struct Node *Lsearch(struct Node *p, int key)
// {
//   struct Node *q = NULL;
//   while (p != NULL)
//   {
//     if (key == p->data)
//     {
//       q->next = p->next;
//       p->next = first;
//       first = p;
//       return p;
//     }
//     else
//     {
//       q = p;
//       p = p->next;
//     }
//   }
//   return NULL;
// }

void Insert(struct Node *p, int index, int x)
{
  struct Node *t;
  if (index < 0 || index > count(p))
  {
    printf("Enter a position between 0 and %d.\n", count(p));
    exit(0);
  }
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;

  if (index == 0)
  {
    t->next = first;
    first = t;
  }
  else
  {
    for (int i = 0; i < index - 1; i++)
    {
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
}

int main()
{
  int n;
  int insertElement;
  int insertPosition;
  printf("Enter number of array elements: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter %d elements: ", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  create(arr, n);
  printf("The linked list formed is: \n");
  display(first);
  printf("Enter an element to be inserted ");
  scanf("%d", &insertElement);
  printf("Enter the position of %d between 0 and %d ", insertElement, n);
  scanf("%d", &insertPosition);
  Insert(first, insertPosition, insertElement);
  printf("The new linked list is: \n");
  display(first);

  // int arr[] = {1, 2, 3, 4, 5};
  // int n = 5;
  // create(arr, n);
  // display(first);
  // Insert(first, 0, 10);

  // printf("\nCount is %d \n", count(first));

  // printf("Sum is %d\n", add(first));

  // printf("Max is %d\n", max(first));

  // int key = 0;
  // printf("Enter number to be found\n");
  // scanf("%d", &key);
  // struct Node *temp;
  // temp = Lsearch(first, key);
  // if (temp)
  // {
  //   printf("The address of %d is %p\n", key, temp);
  // }
  // else
  // {
  //   printf("%d is not found\n", key);
  // }
  free(first);
  return 0;
}