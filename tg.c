#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "music_library.h"
#include "LL.c"

//terry
// search for a song given song and artist name
struct node * search(char lib[], char artist[], char song[]);

//terry
// print out all entries under a certain letter
void print_under_letter(char lib[], char letter);

//terry
// prints out the whole library
void print_library(char lib[]);

//terry
// print out a series of randomly chosen songs
void shuffle(char lib[]);
