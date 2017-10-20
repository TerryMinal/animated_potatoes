#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LL.c"
#include <time.h>

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
    //case where the temp_node reaches the end of the linked list
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
  while ( current != NULL && (strcmp(current->song, song) != 0) && (strcmp(current->artist, artist)) != 0 ) {
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


int main() {
  struct node *front = make_node("a", "b");
  struct node *temporary;

  /* -----------------------MAKING A LINKED LIST-------------------------*/

  int i;

  //Creating a linked list of nodes
  for (i = 10; i > 0; i--) {
    front = insert(front, "blank", "blank");
  }

  front = insert(front, "e", "f");

  /* -----------------------RETURNING A RANDOM NODE-------------------------*/
  temporary = front;
  printf("===============================\n");
  temporary = return_random(front);
  printf("Printing the randomly selected node: \nArtist: %s \nSong: %s \n", temporary->artist, temporary->song);
  free(temporary);

  /* ----------------------REMOVING A RANDOM NODE-------------------------*/

  front = insert(front, "a", "b");
  printf("List before removal: \n");
  print_list(front);
  printf("\n===============================\n");
  printf("Removing a node: \n");
  printf("Node to be removed: \nArtist: a \nSong: b \n\n");
  front = remove_node("a", "b", front);
  printf("Updated list: \n");
  print_list(front);

  printf("\n===============================\n");
  front = insert(front, "e", "f");
  printf("List before removal: \n");
  print_list(front);
  printf("Removing a node: \n");
  printf("Node to be removed: \nArtist: e \nSong: f \n\n");
  front = remove_node("e", "f", front);
  printf("Updated list: \n");
  print_list(front);

  printf("\n===============================\n");
  printf("Removing a node: \n");
  printf("Node to be removed: \nArtist: b \nSong: c \n\n");
  front = remove_node("b", "c", front);
  printf("Updated list: \n");
  print_list(front);

  /* ----------------------FREEING THE NODES OF THE LINKED LIST-------------------------*/
  front = free_list(front);
  // free(temporary);
  printf("printing after list has been freed:\n");
  print_list(front);



  return 0;
}
