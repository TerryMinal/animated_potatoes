#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//insert in order
// struct node * insert(struct node * node);

//returns node based on artist and song
// struct node * return_node(char artist[], char song[]);

//returns first song based on artist
// struct node * return_first_song(char artist[]);

struct node {
  char song[256];
  char artist[256];
  struct node *next;
};

void print_node(struct node *node) {
  if (node == NULL)
  printf("The node is null\n");
  else
  printf(" artist: %s | song: %s \n" , node->artist, node->song);
}

void print_list(struct node *current_node) {
  while (current_node != NULL) {
    print_node(current_node);
    current_node = current_node->next;
  }
}


struct node * make_node(char new_artist[], char new_song[]) {
  struct node *node = (struct node *) malloc(sizeof(struct node));
  strcpy(node->song, new_song);
  strcpy(node->artist , new_artist);
  node->next = NULL;
  return node;
}

struct node * insert_front(struct node *front, char new_artist[], char new_song[]) {
  struct node *new_front = make_node(new_artist, new_song);
  new_front->next = front;
  return new_front;
}

struct node * insert(struct node *current_node, char artist[], char song[]) {
  //case where there exists no node in the linked list
  if (current_node == NULL) {
    current_node = make_node(artist, song);
    return current_node;
  }
  //case where the node belongs in the front
  else if (strcmp(artist, current_node->artist) <= 0) {
    return insert_front(current_node, artist, song);
  }
  //case where the node belongs after the front
  else {
    struct node *previous = current_node;
    while(current_node != NULL && strcmp(artist, current_node->artist) >= 0) {
      previous = current_node;
      current_node = current_node->next;
    }
    struct node *node = make_node(artist, song);
    previous->next = node;
    node->next = current_node;
  }
}

struct node * add_song_node(struct node *lib[], char artist[], char song[]) {

  int index = (int)((artist[0] - 'a')); //taking advantage of every character being an int... set index through subtraction of different ascii values
  //if there is no linked list present in this index, make a new node
  // printf("%d\n", index);
  // lib[i] = insert(lib[i], art, son);
  lib[index] = insert(lib[index], artist, song);
  return lib[index];
}


//returns node based on artist and song
struct node * return_node(struct node *current_node, char artist[], char song[]) {
  struct node *ret_node = NULL;
  while (current_node != NULL) {
    if (strcmp(current_node->artist, artist) == 0 && strcmp(current_node->song, song) == 0)
      ret_node = current_node;
    current_node = current_node->next;
  }
  return ret_node;
}

//returns first song based on artist
struct node * return_first_song(struct node *current_node, char artist[]) {
  struct node *ret_node = NULL;
  while (current_node != NULL) {
    if (strcmp(current_node->artist, artist) == 0)
    ret_node = current_node;
    current_node = current_node->next;
  }
  return ret_node;
}

struct node * return_random(struct node * front) {
  //Seed the random number picker with the time
  srand(time(NULL));
  //Pick a random number in the range of 0-10
  int rand_num;
  printf("Random number: %d\n", rand_num);
  struct node * temp_node = front;
  //Iterate through the linked list for a rand_num amount of times.
  //Return the node that rand_num stopped at.
  rand_num = rand()%10;
  while (rand_num) {
    if (temp_node == NULL) //if it reached the end of the linked list go back to the front
      temp_node = front;
    temp_node = temp_node->next;
    rand_num--;
  }
  //if the rand temp_node is NULL cycle through till you find the next node
  while (temp_node != NULL) {
    if (temp_node == NULL)
      temp_node = front;
    else
      temp_node = temp_node->next;
  }
  return temp_node;
}

struct node * free_list(struct node *node) {
  struct node *temp;
  while ( node != NULL) {
    temp = node->next;
    free(node);
    node = temp;
  }
  return NULL;
}

//terry
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

//terry
// print out all entries under a certain letter
void print_under_letter(struct node *lib[], char letter) {
  int index = (int) (letter - 'a'); //set index through subtraction of ascii values
  printf("linked list of %c:\n");
  print_list(lib[index]);
}

//terry
// prints out the whole library
void print_library(struct node *lib[]) {
  char alphabet[] = "abcedfghijklmnopqrstuvwxyz";
  int i;
  for (i = 0; i < 26; i++) {
    print_under_letter(lib, alphabet[i]);
  }
}

//terry
// print out a series of randomly chosen songs
void shuffle(struct node *lib[]) {
  srand(time(NULL));
  int n;
  int i;
  int rand_num;
  for (n = 0; n < 3; n++) {
    i = 0;
    rand_num = rand()%26;
    //makes sure to find a part in the array that has nodes
    while (lib[rand_num] != NULL) {
      if (i >= 25) //if it traversed the whole list and it didn't find anything
        printf("there are no nodes in this library");
      i++;
      rand_num = (rand_num + 1)%26;
      printf("%d\n", rand_num);
    }
    printf("node: ");
    print_node(return_random(lib[rand_num]));
  }
}


int main() {
  printf("\n"); //space between output of makefile and output of this file

  struct node *front;
  // front = insert(front, "a", "b");
  struct node *lib[27];
  // struct node *front;// = add_song_node(lib, "b", "oh yeah baby");
  srand(time(NULL));
  int i;
  char alphabet[] = "abcedfghijklmnopqrstuvwxyz";
  char *artist[26];
  char *songs[26];
  for (i = 0; i < 26; i++) {
    lib[i] = NULL;
  }
  for (i = 0; i < 26; i++) {
    char *art = &(alphabet[ (int) (rand()%26) ]);
    char *son = &(alphabet[ (int) (rand()%26) ]);
    artist[i] = art;
    songs[i] = son;
    // printf("inserting artist: %s, inserting song: %s, for the %d time\n", art, son, i);
    add_song_node(lib, art , son);
  }
  // printf("\n=================debgugging search=============\n");
  // for (i = 0; i < 26; i++) {
  //   print_node(search(lib, artist[i], songs[i]));
  // }
  printf("\n=================debgugging shuffle=============\n");
  shuffle(lib);
  // printf("\n=================debgugging print_under_letter=============\n");
  // for (i = 0; i < 26; i++) {
  //   print_under_letter(lib, alphabet[i]);
  // }
  // printf("\n=================debgugging print_library=============\n");
  // print_library(lib);

  // print_list(front);
  // printf("debugging return_node...\n");
  // struct node *d = return_node(front, "a", "b");
  // print_node(d);
  // printf("debugging return_first_song...\n");
  // d = return_first_song(front, "d");
  // print_node(d);
  for (i = 0; i < 26; i++) {
    free_list(lib[i]);
    // printf("%s\n", str);
    // add_song_node(lib, "i hate seg faults", "i hate seg faults");
  }
  // printf("printing after list has been freed:\n");
  // print_list(front);
  return 0;
}
