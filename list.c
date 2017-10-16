#include <stdio.h>
#include <stdlib.h>
#include "headers.h"


void print_list(struct node * x) {

  printf("%d\n", x->val);

  if ( x->next ) {
    print_list(x->next);
  }
}

struct node * insert_front(struct node * n, int i) {
  struct node * front = (struct node *) malloc(sizeof(struct node));
  front->val = i;
  front->next = n;
  return front;
}

struct node * free_list(struct node * n) {
  if (n->next) {
    free_list(n->next);
  }
  free(n);
  return n;
}

int main() {
  struct node first;
  struct node second;
  struct node third;
  struct node * head;

  printf("--------------start print_list testing-------------------------\n");

  first.val = 1;
  first.next = &second;

  second.val = 2;
  second.next = &third;

  third.val = 3;
  third.next = NULL;

  head = &first;

  print_list(head);
  printf("\n");
  print_list(&first);
  printf("--------------end print_list testing-------------------------\n");

  printf("--------------start insert testing-------------------------\n");
  head = insert_front(head, 0);
  print_list(head);
  printf("--------------end insert testing-------------------------\n");

  printf("--------------start free testing-------------------------\n");
  free(head);
  print_list(head);
  printf("--------------end free testing-------------------------\n");
}
