#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LL.h"
#include "LL.c"

//insert in order
// struct node * insert(struct node * node);

//returns node based on artist and song song
// struct node * return_node(char artist[], char song_song[]);

//returns first song based on artist
// struct node * return_first_song(char artist[]);

struct node * insert(struct node *front, char artist[], char song[]) {
  struct node *node = make_node(artist, song);
  struct node *current_node = front;
  struct node *previous;
  while (current_node != NULL && strcmp(node->artist, current_node->artist) >= 0) {
    previous = current_node;
    current_node = current_node->next;
  }
  previous->next = node;
  node->next = current_node;
  return node;
}


int main() {
  struct node *front = malloc(sizeof(struct node));
  front = make_node("d", "e");
  // insert(front, "a", "b");
  print_list(front);
  front = free_list(front);
  // printf("printing after list has been freed:\n");
  // print_list(front);
  return 0;
}
