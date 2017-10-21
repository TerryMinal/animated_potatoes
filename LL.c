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
  return new_front;
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


//Inserts a node in the current order 
struct node * insert(struct node *current_node, char artist[], char song[]) {
  struct node *ret_node = current_node; 
 //case where there exists no node in the linked list
  if ( (!current_node) || (strcmp(artist, current_node->artist) <= 0) ) {
    return insert_front(current_node, artist, song);
  }
  //case where the node belongs after the front
  else {
    struct node *previous = current_node;
    while(current_node != NULL && strcmp(artist, current_node->artist) >= 0) {
      previous = current_node;
      current_node = current_node->next;
    }

    //printf("linking\n");
    struct node *node = make_node(artist, song);
    //print_node(node);
    
    previous->next = node;
    // printf("previous next: %s, %s\n", previous->next->song, previous->next->artist);
    
    node->next = current_node;
    //printf("current next: %s, %s\n", node->next->song, node->next->artist);
  }
  //printf("insert completed\n");
  return ret_node;
}

//Returns a randomly selected node
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
  while (rand_num > 0) {
    //case where the temp_node reaches the end of the linked list
    if (temp_node == NULL) {
      temp_node = front;
      break;
    }
    
    temp_node = temp_node->next;
    rand_num--;
  }
  print_node(temp_node);
  return temp_node;
}


// returns a pointer to the front
//Removes a selected node
struct node * remove_node(char artist[], char song[], struct node *front) {
  struct node * current = front;
  struct node * previous = front;

  //If the node that needs to be removed is the first node in the list:
  if ( strcmp(front->song, song) == 0 && strcmp (front->artist, artist) == 0) {
    //printf("1\n");
    struct node * temp = front;
    // printf("front: %s, %s\n", front->song, front->artist);
    front = front->next;
    //printf("front: %s, %s\n", front->song, front->artist);
    free(temp);
    return front;
  }

  //Else traverse through the list while the values of the current node is not the same as the values in the node that needs to be removed
  while (current->next) {
    //If current is at the node that needs to be removed: 
    if ( strcmp(current->song, song) == 0 && strcmp (current->artist, artist) == 0) {
      struct node * temp = current; 
      previous->next = current->next;
      free(temp);
      return front;
    }
    
    //printf("Value inside previous node: \nArtist: %s \nSong: %s \n\n", previous->artist, previous->song);
    //Update the previous node
    previous = current;
    
    current = current->next;
    //printf("Value inside temp_node node: \nArtist: %s \nSong: %s \n\n", current->artist, current->song); 
  }
  previous->next = NULL;
  free(current);
  return front;  
}
      
  


 



