#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LL.c"

int main() {
  struct node *front = malloc(sizeof(struct node));
  front = make_node("a", "b");
  int i;
  for (i = 100; i > 0; i--) {
    front = insert_front(front, "b", "c");
  }
  print_list(front);
  front = free_list(front);
  printf("printing after list has been freed:\n");
  print_list(front);
  return 0;
}
