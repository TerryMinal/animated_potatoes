#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

struct node {
  char name[256];
  char artist[256];
  struct node *next;
};

void print_list(struct node *node) {
  struct node *current_node = node;
  while (current_node != NULL) {
    printf("artist: %s | song: %s" , current_node->artist, current_node->name);
    current_node = current_node->next;
  }
  return;
}

struct node * insert_front(struct node *front, char[] new_name, char[] new_artist) {
  struct node *new_front = (struct node *) malloc(sizeof(new_front));
  new_front->name = new_name;
  new_front->artist = new_artist;
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

struct node * insert(struct node *front, struct node *node) {
  struct node * current_node = front;
  struct node * previous;
  while (current_node != NULL) {
    if (strcmp(current_node->artist, node->artist) <= 0) {
      node->next = current_node;
      previous->next = node;
    }
    previous = current_node;
    current_node = current_node->next;
  }
}

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
