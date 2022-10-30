#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
  int data;
  struct Node *next;
} *first = NULL;

void create(int arr[], int n)
{
  struct Node *t, *last;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = arr[0];
  first->next = NULL;
  last = first; // assigning the address of "first" pointer to 'last" pointer. SO that we can use "last" pointer to assign values for "first" as well.

  for (int i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = arr[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

void display(struct Node *p)
{
  while (p != NULL)
  {
    printf("%d  ", p->data);
    p = p->next;
  }
  printf("\n");
}

void insertAtBeginning(struct Node *p, int x)
{
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = first;
  first = t;
}

void insertAtEnd(struct Node *p, int x)
{
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  while (p->next != NULL)
  {
    p = p->next;
  }
  t->next = p->next;
  p->next = t; // linking the node t to the already present linked list of nodes p
}

void insertAtAnyPos(struct Node *p, int x, int pos)
{
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  if (pos == 0)
  {
    t->next = first;
    first = t;
  }
  else
  {
    for (int i = 1; i < pos - 1; i++)
    {
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
}

void deleteFirst(struct Node *p)
{
  first = first->next;
  free(p);
}

void deleteAtEnd(struct Node *p)
{
  struct Node *q = NULL;
  while (p->next != NULL)
  {
    q = p;
    p = p->next;
  }
  q->next = p->next;
  free(p);
}

void deleteAnyPos(struct Node *p, int pos)
{
  struct Node *q = NULL;
  for (int i = 0; i < pos - 1 && p; i++)
  {
    q = p;
    p = p->next;
  }
  q->next = p->next;
  int x = p->data;
  free(p);
}

bool checkSort(struct Node *p, int n)
{
  int x = -65536;
  while (p != NULL)
  {
    if (p->data < x)
    {
      return false;
    }
    x = p->data;
    p = p->next;
  }
  return true;
}

void sort(struct Node *p, int n)
{
  struct Node *q;
  int t;
  for (int i = 0; i < n - 1; i++)
  {
    q = p;
    p = p->next;
    if (q->data > p->data)
    {
      t = q->data;
      q->data = p->data;
      p->data = t;
    }
  }
}

void reverse(struct Node *p, int n)
{
  int arr[n];
  p = first;
  int i = 0;
  while (p != NULL)
  {
    arr[i++] = p->data;
    p = p->next;
  }
  p = first;
  while (p != NULL)
  {
    p->data = arr[--i];
    p = p->next;
  }
}

int main()
{
  int n;
  printf("Enter size of linked list\n");
  scanf("%d", &n);
  int arr[n];
  printf("Enter data in %d nodes\n", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  create(arr, n);
  // display(first);
  // insertAtBeginning(first, 10);
  // display(first);
  // insertAtEnd(first, 20, n);
  // display(first);
  // insertAtAnyPos(first, 30, 3);
  // display(first);
  // deleteAnyPos(first, 4);
  // deleteFirst(first);
  // deleteAtEnd(first);
  // Delete(first, 3);
  // for (int i = 0; i < n; i++)
  // {
  //   if (checkSort(first, n))
  //   {
  //     printf("The sorted list is\n");
  //     display(first);
  //     break;
  //   }
  //   else
  //   {
  //     sort(first, n);
  //   }
  // }
  reverse(first, n);
  display(first);
}