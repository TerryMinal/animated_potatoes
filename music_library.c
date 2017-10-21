#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "music_library.h"
#include "LL.c"


struct node * add_song_node(struct node *lib[], char artist[], char song[]) {

  int index = (int)((artist[0] - 'a')); //taking advantage of every character being an int... set index through subtraction of different ascii values
  lib[index] = insert(lib[index], artist, song);
  return lib[index];
}

// search for a song given song and artist name
struct node * search(struct node *lib[], char artist[], char song[]) {
  int index = (int) ((artist[0]) - 'a'); //taking advantage of every character being an int... set index through subtraction of different ascii values
  struct node *current_node = lib[index];
  while (current_node != NULL) {
    if (strcmp(current_node->song, song) == 0)
      return current_node;
    current_node = current_node->next;
  }
  return NULL; //if there is no node with given parameters, return NULL
}


// print out all entries under a certain letter
void print_under_letter(struct node *lib[], char letter) {
  int index = (int) ('z' - letter); //set index through subtraction of ascii values
  //printf("%d", index);
  print_list(lib[index]); 
}

// prints out the whole library
void print_library(struct node *lib[]) {
  int i;
  for (i = 0; i < 26; i++) {
    // printf("artist: %s", current_node->artist);
    print_list(lib[i]);
  }
}

// print out a series of randomly chosen songs
void shuffle(struct node *lib[]) {
  srand(time(NULL));
  int i;
  int rand_num = rand()%26;

  while (lib[rand_num]) {
    rand_num = rand()%26; 
    if (!lib[rand_num]) {
      print_node(return_random(lib[rand_num]));
      break;
    }
  }
  /* 
  printf("randnum: %d\n",rand_num);
  }
  
  struct node *rand_node = return_random(lib[rand_num]);
  /* for (i = 0; i < 3; i++) {
    rand_num = rand()%26;
    rand_node = return_random(lib[rand_num]);
    printf("artist: %s, song: %s\n", rand_node->artist, rand_node->song);
    }
  // printf("%d\n", rand_num);
  */ 
  
  //free(rand_node);
}

void print_artist_song(struct node *lib[], char artist[]) {
  int index = (int)(artist[0] - 'a');
  //printf("Index: %d", index);

  struct node * current_node = lib[index];

  while (current_node != NULL) {
    if ( strcmp(current_node->artist, artist) == 0) {
      printf("\n=========================\n");
      printf("Songs by %s: \n", artist);
      printf("%s : %s\n", artist, current_node->song);
    }
    current_node = current_node->next;
  }
}

// delete a song by utilizing the remove_node method
void delete_song(struct node *lib[], char artist[], char song[]) {
  int index =  (int)(artist[0] - 'a');
  struct node * current_node = lib[index];
  remove_node(artist, song, current_node);
}


// delete all nodes
void delete_nodes(struct node *lib[]) {
  int index = 0;
  while (index < 27) {
    free_list(lib[index]);
    index++;
  }
}

int main() {
  printf("\n"); //space between output of makefile and output of this file

  struct node *front;
  struct node *search_node; 
 
  struct node *lib[27];

  srand(time(NULL));
  int i;
  
  char alphabet[] = "abcedfghijklmnopqrstuvwxyz";
  
  for (i = 0; i < 27; i++) {
    lib[i] = NULL;
  }


  printf("\n==============TESTING LINKED LIST=================\n");
  printf("Testing insert_front\n"); 
  front = insert_front(front, "a", "abcd");
  print_list(front);
  printf("================================================\n");
  printf("Testing insert: \n"); 
  front = insert(front, "c", "cats");
  front = insert(front, "ed sheeran", "Afire Love");
  front = insert(front, "b", "bananar");
  front = insert(front, "d", "dogs");
  front = insert(front, "e", "elephants");
  front = insert(front, "f", "ferrets");
  front = insert(front, "g", "giraffe");
  front = insert(front, "h", "hihi");
  front = insert(front, "i", "igloo");
  front = insert(front, "j", "jelly beans");
  print_list(front);
  
  printf("================================================\n");
  printf("Testing return_random\n");
  struct node * temporary = return_random(front);
  free(temporary);
  printf("================================================\n");
  printf("Testing remove_node: \n");
  printf("Node to be removed: \nArtist: c \nSong: cats \n\n");
  front = remove_node("c", "cats", front);
  printf("Updated list: \n");
  print_list(front);

  printf("\nNode to be removed: \nArtist: f \nSong: ferrets \n\n");
  front = remove_node("f", "ferrets", front);
  printf("Updated list: \n");
  print_list(front);

  printf("\nNode to be removed: \nArtist: j \nSong: jelly beans \n\n");
  front = remove_node("j", "jelly beans", front);
  printf("Updated list: \n");
  print_list(front);

  /*printf("================================================\n");
  printf("Testing free_list: \n");
  front = free_list(front);
  print_list(front);
  */
  printf("\n==============TESTING MUSIC LIBRARY=================\n");
  
  printf("\nAdding more songs:\n");
 
  front = add_song_node(lib, "high school musical", "Breaking Free");
  front = add_song_node(lib, "hairspray", "You Can't Stop the Beat");
  front = add_song_node(lib, "dJ hhaled", "I'm the One");
  front = add_song_node(lib, "drake", "Fake Love");
  front = add_song_node(lib, "sam smith", "Too Good for Goodbyes");
  front = add_song_node(lib, "sam smith", "I Know I'm Not the Only One");
  front = add_song_node(lib, "the chainsmokers", "Closer");
  front = add_song_node(lib, "the chainsmokers", "Paris");
  front = add_song_node(lib, "the chainsmokers", "Don't Let Me Down");
  front = add_song_node(lib, "the chainsmokers", "Roses");
  front = add_song_node(lib, "khalid", "Location");
  printf("Current library: \n");
  print_library(lib);

  printf("\n==============================\n");
  printf("Testing search: searching for sam smith's too good for goodbyes \n");
  search_node = search(lib, "sam smith", "Too Good for Goodbyes");
  printf("Artist in search: %s, Song in search: %s\n", search_node->artist, search_node->song);

  printf("\n==============================\n");
  printf("Testing print_under_letter: printing all artists under t\n");
  print_under_letter(lib, 't');

  /*printf("\n==============================\n");
  printf("Testing shuffle \n");
  shuffle(lib); */

  printf("\n=============================\n");
  printf("Testing print_artist_song: printing all songs under khalid \n");
  print_artist_song(lib, "khalid");


  printf("\n=============================\n");
  printf("Testing delete_song: deleting Paris by the chainsmokers\n"); 
  delete_song(lib, "the chainsmokers", "Paris");
  printf("Updated library: \n");
  print_library(lib);

  printf("\nTesting delete_song: Don't Let Me Down by the chainsmokers\n"); 
  delete_song(lib, "the chainsmokers", "Don't Let Me Down");
  printf("Updated library: \n");
  print_library(lib);

  printf("\n=============================\n");
  printf("Testing delete_nodes: removing all from library\n"); 
  delete_nodes(lib);
  printf("Updated library: \n");
  return 0;
   /* 
  printf("Testing delete_song:  \n");
  delete_song(lib, "the chainsmokers", "Paris");
  print_library(lib); */

}
