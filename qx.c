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
    temp_node = temp_node->next;
    rand_num--;
  }

  return temp_node;
}


struct node * remove_node(struct node * node, struct node * front) {
  struct node * current = front;
  struct node * previous = front; 

  //If the node that needs to be removed is the first node in the list: 
  if ( ( strcmp (current->song, node->song) == 0 ) && ( strcmp (current->artist,node->artist) ) == 0) {
    front  = current->next;
    free(current);
    
    //print_list(front);
    return front; 
  }

  //Else traverse through the list while the values of the current node is not the same as the values in the node that needs to be removed 
  while ( (strcmp(current->song, node->song) != 0) && (strcmp(current->artist,node->artist)) != 0 ) {
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
  previous->next = current->next;
  return front;
}


int main() {
  struct node *front = malloc(sizeof(struct node));
  struct node *temporary;

  /* -----------------------MAKING A LINKED LIST-------------------------*/
  //Make a front node 
  front = make_node("a", "b");

  int i;

  //Creating a linked list of nodes 
  for (i = 10; i > 0; i--) {
    front = insert_front(front, "b", "c");
  }

  //struct node * test_node = make_node("e", "f");
  front = insert_front(front, "e", "f"); 
  

  /* -----------------------RETURNING A RANDOM NODE-------------------------*/
  temporary = front;
  printf("===============================\n");
  temporary = return_random(front);
  printf("Printing the randomly selected node: \nArtist: %s \nSong: %s \n", temporary->artist, temporary->song);
  

  /* ----------------------REMOVING A RANDOM NODE-------------------------*/  
  struct node * node_tb_removed = make_node("a", "b");
  printf("\n===============================\n");
  printf("Removing a node: \n");
  printf("Node to be removed: \nArtist: %s \nSong: %s \n\n", node_tb_removed->artist, node_tb_removed->song);
  front = remove_node(node_tb_removed, front);
  printf("Updated list: \n"); 
  print_list(front);

  node_tb_removed = make_node("e", "f");
  printf("\n===============================\n");
  printf("Removing a node: \n");
  printf("Node to be removed: \nArtist: %s \nSong: %s \n\n", node_tb_removed->artist, node_tb_removed->song);
  front = remove_node(node_tb_removed, front);
  printf("Updated list: \n"); 
  print_list(front);

  node_tb_removed = make_node("b", "c");
  printf("\n===============================\n");
  printf("Removing a node: \n");
  printf("Node to be removed: \nArtist: %s \nSong: %s \n\n", node_tb_removed->artist, node_tb_removed->song);
  front = remove_node(node_tb_removed, front);
  printf("Updated list: \n"); 
  print_list(front);
  
  node_tb_removed = make_node("b", "c");
  printf("\n===============================\n");
  printf("Removing a node: \n");
  printf("Node to be removed: \nArtist: %s \nSong: %s \n\n", node_tb_removed->artist, node_tb_removed->song);
  front = remove_node(node_tb_removed, front);
  printf("Updated list: \n"); 
  print_list(front);
  
  node_tb_removed = make_node("b", "c");
  printf("\n===============================\n");
  printf("Removing a node: \n");
  printf("Node to be removed: \nArtist: %s \nSong: %s \n\n", node_tb_removed->artist, node_tb_removed->song);
  front = remove_node(node_tb_removed, front);
  printf("Updated list: \n"); 
  print_list(front);
  printf("\n===============================\n");


  /* ----------------------FREEING THE NODES OF THE LINKED LIST-------------------------*/  
  front = free_list(front);
  free(temporary); 
  printf("printing after list has been freed:\n");
  print_list(front);


  
  return 0;
}


