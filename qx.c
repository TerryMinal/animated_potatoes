#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "LL.c"

int main() {
  struct node *front = malloc(sizeof(*front));
  front->value = 0;
  front->next = NULL;
  int i;
  for (i = 100; i > 0; i--) {
    front = insert_front(front, i);
  }
  print_list(front);
  free_list(front);
  printf("printing after list has been freed:\n");
  print_list(front);
  return 0;
}
