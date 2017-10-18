#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LL.c"

// struct node * insert(struct node *front, struct node *node) {
//   struct node * current_node = front;
//   struct node * previous;
//   while (current_node != NULL) {
//     if (strcmp(node->artist, current_node->artist) <= 0) {
//       node->next = current_node;
//       previous->next = node;
//     }
//     previous = current_node;
//     current_node = current_node->next;
//   }
// }

int main() {
  struct node *front = malloc(sizeof(struct node));
  front->next = NULL;
  // int i;
  // for (i = 100; i > 0; i--) {
  //   front = insert_front(front, "a", "b");
  // }
  // print_list(front);
  // free_list(front);
  // printf("printing after list has been freed:\n");
  // print_list(front);
  return 0;
}
