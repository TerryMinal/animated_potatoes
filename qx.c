#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "music_library.h"
#include "LL.c"
#include "tg.c"


//queenie
// print out all songs of a specific artist
void print_artist_song(struct node *lib[], char artist[]) {
  int index = (int)(artist[0] - 'a');
  printf("Index: %d", index);

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

// delete a song
void delete_song(struct node *lib[], char artist[], char song[]) {
  int index =  (int)(artist[0] - 'a');
  struct node * current_node = lib[index];
  remove_node(artist, song, current_node); 


  /*
  while (index < 27) {
   
    while ( current_node != NULL) {
      struct node * previous = current_node;
      
      if ( strcmp(current_node->song, song) == 0 ) {
	previous->next = current_node->next;
	free(current_node);
	free(previous);
	break;
      }
      
      current_node = current_node->next;
    }
    index++; 
    } */
}

//queenie
// delete all nodes
void delete_nodes(struct node *lib[]) {
  int index = 0;
  while (index < 27) {
    free_list(lib[index]);
    index++;
  }
}


  

int main() {
  struct node *lib[26];
  int i = 0;
  char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  
  for (; i < 27; i++) {
    lib[i] = NULL;
  }
  
  struct node * front;
  
  front = add_song_node(lib, "ed Sheeran", "Afire Love");
  print_library(lib); 
  // = add_song_node(lib, "luis Fonsi", "Despacito ft. Justin Bieber");

  /*
  front = add_song_node(lib, "high School Musical", "Breaking Free");
  
  front = add_song_node(lib, "Hairspray", "You Can't Stop the Beat");
  front = add_song_node(lib, "DJ Khaled", "I'm the One");
  front = add_song_node(lib, "Drake", "Fake Love");
  
  front = add_song_node(lib, "Sam Smith", "Too Good for Goodbyes");
  
  front = add_song_node(lib, "Sam Smith", "I Know I'm Not the Only One");
  front = add_song_node(lib, "The Chainsmokers", "Closer");
  front = add_song_node(lib, "The Chainsmokers", "Paris");
  front = add_song_node(lib, "The Chainsmokers", "Don't Let Me Down");
  front = add_song_node(lib, "The Chainsmokers", "Roses");
  front = add_song_node(lib, "Khalid", "Location");
  */
  
  
 
  front = add_song_node(lib, "b", "breaking free");
  //print_artist_song(lib, "a");
  print_library(lib); 
  return 0;
}
