#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "music_library.h"
#include "LL.c"



struct node * add_song_node(struct node *lib[], char artist[], char song[]) {

  int index = (int)((artist[0] - 'a')); //taking advantage of every character being an int... set index through subtraction of different ascii values
  //if there is no linked list present in this index, make a new node
  // printf("%d\n", index);
  // lib[i] = insert(lib[i], art, son);
  lib[index] = insert(lib[index], artist, song);
  return lib[index];
}

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

void print_under_letter(struct node *lib[], char letter) {
  int index = letter -'a';
  print_list(lib[index]);
}

void print_library(struct node *lib[]) {
  int i;
  for (i = 0; i < 26; i++) {
    print_list(lib[i]);
  }
}

void print_artist_song(struct node *lib[], char artist[]) {
  int index = (int)(artist[0] - 'a');
  struct node * current_node = lib[index];
  if (current_node == NULL) { //in the case there are no nodes in the library with this artist
    printf("this artist is not in the library");
    return;
  }
  printf("Songs by %s: \n", artist);
  while (current_node != NULL) {
    if ( strcmp(current_node->artist, artist) == 0) {
      printf("%s\n", current_node->song);
    }
    current_node = current_node->next;
  }
}

void shuffle(struct node *lib[]) {
  srand(time(NULL));
  //Pick a random number in the range of 0-10
  int rand_num = rand()%26;
  int i = 0;
  while (lib[rand_num] == NULL) {
    if (i > 25) {
      printf("there exists no node in the library");
      return;
    }
    printf("%s\n", lib[rand_num]->artist);
    rand_num = (rand_num + 1)%26;
    i++;
  }
  struct node *node = return_random(lib[rand_num]);
  print_node(node);
}

// delete a song
void delete_song(struct node *lib[], char artist[], char song[]) {
  int index =  (int)(artist[0] - 'a');
  // sets pointer to the front... this ensures that the front pointer always reflects a malloced node
  *(lib + index) = remove_node(*(lib + index), artist, song);
}

//queenie
// delete all nodes
void delete_nodes(struct node *lib[]) {
  int index = 0;
  while (index < 26) {
    lib[index] = free_list(lib[index]);
    index++;
  }
}

int main() {
  printf("\n"); //space between output of makefile and output of this file
  int i;
  srand(time(NULL));

  struct node *lib[26];
  char alphabet[] = "abcedfghijklmnopqrstuvwxyz";
  char *artists[26];
  char *songs[26];
  //initializing the library
  for (i = 0; i < 26; i++) {
    lib[i] = NULL;
  }
  for (i = 0; i < 26; i++) {
    char *art = alphabet + rand()%26;
    char *son = alphabet + 26 -rand()%26;
    artists[i] = art;
    songs[i] = son;
    // printf("inserting artist: %s, inserting song: %s, for the %d time\n", art, son, i);
    add_song_node(lib, art , son);
  }
  printf("\n=================debgugging free_list=============\n");
  printf("\n==============TESTING LINKED LIST=================\n");
  struct node *front;// = add_song_node(lib, "b", "oh yeah baby");
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
  front = remove_node(front, "c", "cats");
  printf("Updated list: \n");
  print_list(front);

  printf("\nNode to be removed: \nArtist: f \nSong: ferrets \n\n");
  front = remove_node(front, "f", "ferrets");
  printf("Updated list: \n");
  print_list(front);

  printf("\nNode to be removed: \nArtist: j \nSong: jelly beans \n\n");
  front = remove_node( front, "j", "jelly beans");
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
  printf("Testing search:\n");
  printf("Searching for sam smith's too good for goodbyes \n");
  struct node *search_node;
  search_node = search(lib, "sam smith", "Too Good for Goodbyes");
  printf("Found! Artist in search: %s, Song in search: %s\n", search_node->artist, search_node->song);

  printf("\nSearching for khalid's Location \n");
  search_node = search(lib, "khalid", "Location");
  printf("Found! Artist in search: %s, Song in search: %s\n", search_node->artist, search_node->song);

  printf("\nSearching for hairspray's You Can't Stop the Beat\n");
  search_node = search(lib, "hairspray", "You Can't Stop the Beat");
  printf("Found! Artist in search: %s, Song in search: %s\n", search_node->artist, search_node->song);

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

  printf("\n==============TESTING MUSIC LIBRARY=================\n");

  printf("\nAdding more songs:\n");
  front = add_song_node(lib, "bear", "paws");
  front = add_song_node(lib, "blue", "skies");
  front = add_song_node(lib, "hi", "bye");
  print_library(lib);

  return 0;
}
