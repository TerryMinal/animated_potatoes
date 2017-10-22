#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LL.h"

struct node {
  char song[256];
  char artist[256];
  struct node *next;
};

//Prints one node:
void print_node(struct node *node) {
  if (node == NULL)
    printf("The node is null\n");
  else
    printf(" artist: %s | song: %s \n" , node->artist, node->song);
}

//Prints a list:
void print_list(struct node *current_node) {
  while (current_node != NULL) {
    print_node(current_node);
    current_node = current_node->next;
  }
}

// default sets the node next to NULL
struct node * make_node(char new_artist[], char new_song[]) {
  struct node *node = (struct node *) malloc(sizeof(struct node));
  strcpy(node->song, new_song);
  strcpy(node->artist , new_artist);
  node->next = NULL;
  return node;
}

//Inserts a node to the front of the list:
struct node * insert_front(struct node *front, char new_artist[], char new_song[]) {
  struct node *new_front = make_node(new_artist, new_song);
  new_front->next = front;
  front = new_front; 
  return new_front;
}

struct node * insert(struct node *current_node, char artist[], char song[]) {
  //case where there exists no node in the linked list
  if (current_node == NULL) {
    current_node = make_node(artist, song);
    return current_node;
  }
  //case where the node belongs in the front
  else if (strcmp(artist, current_node->artist) <= 0) {
    return insert_front(current_node, artist, song);
  }
  //case where the node belongs after the front
  else {
    struct node *previous = current_node;
    while(current_node != NULL && strcmp(artist, current_node->artist) >= 0) {
      previous = current_node;
      current_node = current_node->next;
    }
    struct node *node = make_node(artist, song);
    previous->next = node;
    node->next = current_node;
  }
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

struct node * return_random(struct node * front) {
  //Seed the random number picker with the time
  srand(time(NULL));
  //Pick a random number in the range of 0-10
  int rand_num;
  struct node * temp_node = front;
  //Iterate through the linked list for a rand_num amount of times.
  //Return the node that rand_num stopped at.
  rand_num = rand()%10;
  while (rand_num) {
    if (temp_node == NULL) //if it reached the end of the linked list go back to the front
    temp_node = front;
    if (temp_node->next != NULL) //only counts the times we get an existing node
      rand_num--;
    temp_node = temp_node->next;
  }

  return temp_node;
}

struct node * remove_node(struct node *front, char artist[], char song[]) {
  struct node * current = front;
  struct node * previous = front;
  //given the case where front is NULL
  if (front == NULL) {
    printf("given node is NULL, cannot perform any operations\n");
    return front;
  }
  //If the node that needs to be removed is the first node in the list:
  if ( ( strcmp(front->song, song) == 0 ) && ( strcmp(front->artist, artist) == 0)) {
    // printf("removing first node\n");
    front  = front->next;
    free(current);
    return front;
  }

  //Else traverse through the list while the values of the current node is not the same as the values in the node that needs to be removed
  while ( current != NULL ) {
    if (strcmp(current->artist, artist) == 0) {
      if (strcmp(current->song, song) == 0)
        break;
    }
    previous = current;
    current = current->next;
  }

  //When loop is done:
  //Set the next node of the node before the target to the node after the target.
  //EX: A->B->C, Want to remove B, Set A's next node to C and remove B : A->C
  // case in which the node was not found and therefore not removed
  if (current == NULL) {
    printf("node does not exist in this Linked List\n");
    return front;
  }
  else {
    previous->next = current->next;
    // printf("printing current_node... \n");
    print_node(current);
    free(current);
    current = NULL;
    return front;
  }
}

//Frees a list:
struct node * free_list(struct node *node) {
  while ( node ) {
    printf("Freeing node: %s by %s\n", node->song, node->artist);
    struct node * temp = node->next;
    free(node);
    node = temp;
  }
  return NULL;
}
//
// int main() {
//   return 0;
// }
