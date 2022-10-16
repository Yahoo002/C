#include <stdio.h>
#include <stdlib.h>

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
  p->next = t;
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

void checkSort(struct Node *p)
{
  int x = -65536;
  while (p != NULL)
  {
    if (p->data < x)
    {
      printf("The list is not sorted");
      return;
    }
    x = p->data;
    p = p->next;
  }
  printf("The list is sorted");
}

int removeDuplicate(struct Node *p)
{
  int x = INT32_MIN;
  struct Node *q = NULL;
  while (p != NULL)
  {
    if (p->data < x)
    {
      printf("It is not sorted");
      return 0;
    }
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
  checkSort(first);
  // display(first);
}