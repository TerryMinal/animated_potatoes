#include <stdio.h>
#include <stdlib.h>
#include "music_library.h"
#include "LL.c"

//queenie
// Add song node
struct node * add_song_node(struct node *song);

//queenie
// print out all songs of a specific artist
void print_artist_song(char artist[]);

//queenie
// delete a song
void delete_song(char song[]);

//queenie
// delete all nodes
void delete_nodes();

//terry
// search for a song given song and artist name
struct node * search(char artist[], char song[]);

//terry
// print out all entries under a certain letter
void print_under_letter(char letter);

//terry
// prints out the whole library
void print_library();

//terry
// print out a series of randomly chosen songs
void shuffle();

int main() {
  return 0;
}
