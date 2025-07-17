#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

typedef struct node {
  int value;
  struct node *next;
} node;

typedef struct stack {
  node *head;
} stack;

stack* create_stack() {
  stack *s = malloc(sizeof(stack));
  s->head = NULL;
  return s;
}

bool push(stack *s, int value) {
  node *newnode = malloc(sizeof(node));
  if (newnode == NULL) return false;

  newnode->value = value;
  newnode->next = s->head;
  s->head = newnode;
  return true;
}

int pop(stack *s) {
  if (s->head == NULL) return STACK_EMPTY;

  int result = s->head->value;
  node *tmp = s->head;
  s->head = s->head->next;
  free(tmp);
  return result;
}

void stack_free(stack *s) {
  while(s->head != NULL) {
    node *tmp = s->head;
    s->head = s->head->next;
    free (tmp);
  }
}

int main() {
  stack *s = create_stack();
  push(s, 14);
  push(s, 35);
  push(s, 50);
  push(s, 3);

  int t;
  while((t = pop(s)) != STACK_EMPTY) {
    printf("t = %d\n", t);
  }

  stack_free(s);
  return 0;
}
