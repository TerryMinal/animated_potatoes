#include <stdio.h>
#include <stdlib.h>
#include "music_library.h"
#include "LL.c"
// Add song node
struct node * add_song_node(struct node *song);

// search for a song given song and artist name
struct node * search(char artist[], char song[]);

// print out all entries under a certain letter
void print_under_letter(char letter);

// print out all songs of a specific artist
void print_artist_song(char artist[]);

// prints out the whole library
void print_library();

// print out a series of randomly chosen songs
void shuffle();

// delete a song
void delete_song(char song[]);

// delete all nodes
void delete_nodes();

int main() {
  return 0; 
}
