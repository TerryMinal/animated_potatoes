#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
// #include "music_library.h"
//#include "LL.c"

struct node * add_song_node(struct node *lib[], char artist[], char song[]) {
  
  int index = (int)((artist[0] - 'a')); //taking advantage of every character being an int... set index through subtraction of different ascii values
  //if there is no linked list present in this index, make a new node
  if (lib[index] == NULL) { 
    printf("%d\n", index); 
    lib[index] = make_node(artist, song);
  }
  //else: add a node by order of artist
  else
    lib[index] = insert(lib[index], artist, song);
  // front = insert(lib[index], artist, song);
  // print_node(front); */
  return lib[index]; 
}

//terry
// search for a song given song and artist name
struct node * search(struct node *lib[], char artist[], char song[]) {
  int index = (int) ((artist[0]) - 'a'); //taking advantage of every character being an int... set index through subtraction of different ascii values
  struct node *current_node = lib[index];
  while (current_node != NULL) {
    if (strcmp(current_node->song, song) == 0)
      free(current_node);
      return current_node;
    current_node = current_node->next;
  }
  free(current_node);
  return NULL; //if there is no node with given parameters, return NULL
}

//terry
// print out all entries under a certain letter
void print_under_letter(struct node *lib[], char letter) {
  int index = (int) ('z' - letter); //set index through subtraction of ascii values
  print_list(lib[index]);
  return;
}

//terry
// prints out the whole library
void print_library(struct node *lib[]) {
  int i = 0;
  for (; i < 27; i++) {
    struct node * current_node = lib[i];
    printf("artist: %s", current_node->artist);
    print_list(current_node);
  }
}

//terry
// print out a series of randomly chosen songs
void shuffle(struct node *lib[]) {
  srand(time(NULL));
  int i;
  int rand_num = rand()%26;
  struct node *rand_node = return_random(lib[rand_num]);
  for (i = 0; i < 3; i++) {
    rand_num = rand()%26;
    rand_node = return_random(lib[rand_num]);
    printf("artist: %s, song: %s\n", rand_node->artist, rand_node->song);
  }
  free(rand_node);
  // printf("%d\n", rand_num);
}

/* 
int main() {
  struct node *lib[26];
  struct node *front = add_song_node(lib, "b", "oh yeah baby");
  srand(time(NULL)); 
  int i;
  char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; 
  for (i = 0; i < 30; i++) {
    char *art = &(alphabet[(int) (rand()%26) ]);
    char *son = &(alphabet[(int) (rand()%26) ]);
    printf("adding artist: %s, adding song: %s, for the %d time", art, son, i);
    front = add_song_node(lib, art, son);
  }
  print_library(lib); 
  //shuffle(lib);
  // print_library(lib);
  // search(lib, "b", "oh yeahbaby");
  // print_node(search(lib, "b", "oh yeahbaby"));
  return 0;
}
*/
