#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
