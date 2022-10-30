#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
} *first = NULL, *t, *last;

void create(int arr[], int n)
{
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = arr[0];
  first->next = NULL;
  last = first;
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
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = first;
  first = t;
}

void insertAtEnd(struct Node *p, int x)
{
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

void deleteAtAnyPos(struct Node *p, int pos)
{
  struct Node *q = NULL;
  for (int i = 0; i < pos - 1; i++)
  {
    q = p;
    p = p->next;
  }
  q->next = p->next;
  free(p);
}

int main()
{
  int n;
  printf("Enter size of linked list\n");
  scanf("%d", &n);
  int arr[n];
  printf("Eneter data in %d nodes\n", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  create(arr, n);
  display(first);
  insertAtBeginning(first, 20);
  insertAtEnd(first, 15);
  insertAtAnyPos(first, 12, 4);
  display(first);
  return 0;
}