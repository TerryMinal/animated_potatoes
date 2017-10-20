#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LL.h"
#include "LL.c"
//insert in order
// struct node * insert(struct node * node);

//returns node based on artist and song
// struct node * return_node(char artist[], char song[]);

//returns first song based on artist
// struct node * return_first_song(char artist[]);

struct node * insert(struct node *current_node, char artist[], char song[]) {
  struct node *node = make_node(artist, song);
  struct node *previous = current_node;
  while (current_node != NULL && strcmp(node->artist, current_node->artist) >= 0) {
    previous = current_node;
    current_node = current_node->next;
  }
  if (previous == current_node) {
    if (strcmp(node->artist, current_node->artist) >= 0) {
      previous->next = node;
      node->next = NULL;
    }
    else {
      node->next = current_node;
    }
  }
  else {
    previous->next = node;
    node->next = current_node;
  }
  return node;
}

//returns node based on artist and song
struct node * return_node(struct node *current_node, char artist[], char song[]) {
  struct node *ret_node = NULL;
  while (current_node != NULL) {
    if (strcmp(current_node->artist, artist) == 0 && strcmp(current_node->song, song) == 0)
       ret_node = current_node;
    current_node = current_node->next;
  }
  return ret_node;
}

//returns first song based on artist
struct node * return_first_song(struct node *current_node, char artist[]) {
  struct node *ret_node = NULL;
  while (current_node != NULL) {
    if (strcmp(current_node->artist, artist) == 0)
       ret_node = current_node;
    current_node = current_node->next;
  }
  return ret_node;
}

int main() {
  printf("\n"); //space between output of makefile and output of this file
  struct node *front = make_node("d", "e");
  front = insert(front, "a", "b");
  // print_list(front);
  printf("debugging return_node...\n");
  struct node *d = return_node(front, "a", "b");
  print_node(d);
  printf("debugging return_first_song...\n");
  d = return_first_song(front, "d");
  print_node(d);
  front = free_list(front);
  // printf("printing after list has been freed:\n");
  // print_list(front);
  return 0;
}
