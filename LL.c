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

void print_node(struct node *node) {
  if (!node)
    printf("The node is null\n");
  else
    printf(" artist: %s | song: %s \n" , node->artist, node->song);
}

void print_list(struct node *current_node) {
  while (current_node) {
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
struct node * insert_front(struct node *front, char new_artist[], char new_song[]) {
  struct node *new_front = make_node(new_artist, new_song);
  new_front->next = front;
  return new_front;
}

struct node * free_list(struct node *node) {
  struct node *temp;
  while ( node != NULL) {
    temp = node->next;
    free(node);
    node = temp;
  }
  return NULL;
}

// in the case that the node is inserted at the beginning, return the node. Else, return the front
// this is to guarantee that there will always be a pointer to the front
struct node * insert(struct node *current_node, char artist[], char song[]) {
  struct node *node = make_node(artist, song);
  struct node *previous = NULL;
  struct node *front = current_node;
  while (current_node != NULL && strcmp(node->artist, current_node->artist) >= 0) {
    previous = current_node;
    current_node = current_node->next;
  }
  // this checks whether its the first node
  if (previous == NULL) {
    // if the node should go after the first node
    if (strcmp(node->artist, current_node->artist) >= 0) {
      node->next = current_node->next;
      current_node->next = node;
      return front;
    }
    else {
      node->next = current_node;
      return node;
    }
  }
  // in the case where youre not entering at the front
  else {
    previous->next = node;
    node->next = current_node;
    return front;
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
// if there is a node returns a pointer to it
// else returns null
struct node * return_first_song(struct node *current_node, char artist[]) {
  struct node *ret_node = NULL;
  while (current_node != NULL) {
    if (strcmp(current_node->artist, artist) == 0)
    ret_node = current_node;
    current_node = current_node->next;
  }
  return ret_node;
}


// to be done:
//returns random element
// struct node * return_random();

//removes a single specified node
// struct node * remove_node(struct node * node);

struct node * return_random(struct node * front) {
  //printf("Running return_random\n");

  //Seed the random number picker with the time
  srand(time(NULL));

  //Pick a random number in the range of 0-10
  int rand_num = rand()%10;
  printf("Random number: %d\n", rand_num);

  struct node * temp_node = front;

  //Iterate through the linked list for a rand_num amount of times.
  //Return the node that rand_num stopped at.
  while (rand_num) {
    if (temp_node == NULL)
      temp_node = front;
    temp_node = temp_node->next;
    rand_num--;
  }

  return temp_node;
}

// returns a pointer to the front
struct node * remove_node(char artist[], char song[], struct node *front) {
  struct node * current = front;
  struct node * previous = front;

  //If the node that needs to be removed is the first node in the list:
  if ( ( strcmp (front->song, song) == 0 ) && ( strcmp (front->artist, artist) ) == 0) {
    front  = front->next;
    free(current); //freeing current b/c its a temp var holding front

    //print_list(front);
    return front;
  }

  //Else traverse through the list while the values of the current node is not the same as the values in the node that needs to be removed
  while ( current != NULL && (!strcmp(current->song, song)) && (!strcmp(current->artist, artist)) ) {
    //printf("Value inside previous node: \nArtist: %s \nSong: %s \n\n", previous->artist, previous->song);

    //Update the previous node
    previous = current;

    //Move the current one node forward
    current = current->next;
    //printf("Value inside temp_node node: \nArtist: %s \nSong: %s \n\n", current->artist, current->song);
  }

  //When loop is done:
  //Set the next node of the node before the target to the node after the target.
  //EX: A->B->C, Want to remove B, Set A's next node to C and remove B : A->C
  // case in which the node was not found and therefore not removed
  if (current == NULL)
    return front;
  previous->next = current->next;
  free(current);
  return front;
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
