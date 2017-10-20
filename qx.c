#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "music_library.h"
#include "LL.c"

//queenie
// Add song node
struct node * add_song_node(char lib[], struct node *song);

//queenie
// print out all songs of a specific artist
void print_artist_song(char lib[], char artist[]);

//queenie
// delete a song
void delete_song(char lib[], char song[]);

//queenie
// delete all nodes
void delete_nodes(char lib[]);
