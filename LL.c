#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LL.h"

struct node {
  char song[256];
  char artist[256];
  struct node *next;
};

void print_node(struct node *node) {
  printf(" artist: %s | song: %s \n" , node->artist, node->song);
  return;
}

void print_list(struct node *node) {
  struct node *current_node = node;
  while (current_node != NULL) {
    print_node(current_node);
    current_node = current_node->next;
  }
  return;
}

// default sets the node next to NULL
struct node * make_node(char new_artist[], char new_song[]) {
  struct node *node = (struct node *) malloc(sizeof(struct node));
  strcpy(node->song, new_song);
  strcpy(node->artist , new_artist);
  node->next = NULL;
  return node;
}
struct node * insert_front(struct node *front, char new_artist[], char new_song[]) {
  struct node *new_front = make_node(new_artist, new_song);
  new_front->next = front;
  return new_front;
}

struct node * free_list(struct node *node) {
  struct node *current_node = node;
  struct node *temp;
  while (current_node != NULL) {
    temp = current_node->next;
    free(current_node);
    current_node = temp;
  }
  return NULL;
}

// int main() {
//   struct node *front = malloc(sizeof(*front));
//   front->value = 0;
//   front->next = NULL;
//   int i;
//   for (i = 100; i > 0; i--) {
//     front = insert_front(front, i);
//   }
//   print_list(front);
//   free_list(front);
//   printf("printing after list has been freed:\n");
//   print_list(front);
//   return 0;
// }
