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


struct node * return_random(struct node * front) {
  //Seed the random number picker with the time
  srand(time(NULL));
  //Pick a random number in the range of 0-10
  int rand_num;
  struct node * temp_node = front;
  //Iterate through the linked list for a rand_num amount of times.
  //Return the node that rand_num stopped at.
  rand_num = rand()%10;
  while (rand_num) {
    if (temp_node == NULL) //if it reached the end of the linked list go back to the front
    temp_node = front;
    if (temp_node->next != NULL) //only counts the times we get an existing node
    rand_num--;
    temp_node = temp_node->next;
  }

  return temp_node;
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

struct node * free_list(struct node *node) {
  struct node *temp;
  while ( node != NULL) {
    temp = node->next;
    free(node);
    node = temp;
  }
  return NULL;
}

struct node * remove_node(struct node *front, char artist[], char song[]) {
  struct node * current = front;
  struct node * previous = front;
  //given the case where front is NULL
  if (front == NULL) {
    printf("given node is NULL, cannot perform any operations\n");
    return front;
  }
  //If the node that needs to be removed is the first node in the list:
  if ( ( strcmp(front->song, song) == 0 ) && ( strcmp(front->artist, artist) == 0)) {
    // printf("removing first node\n");
    front  = front->next;
    free(current);
    return front;
  }

  //Else traverse through the list while the values of the current node is not the same as the values in the node that needs to be removed
  while ( current != NULL && (strcmp(current->song, song) != 0) && (strcmp(current->artist, artist) != 0) ) {
    previous = current;
    current = current->next;
  }

  //When loop is done:
  //Set the next node of the node before the target to the node after the target.
  //EX: A->B->C, Want to remove B, Set A's next node to C and remove B : A->C
  // case in which the node was not found and therefore not removed
  if (current == NULL) {
    printf("node does not exist in this Linked List\n");
    return front;
  }
  else {
    previous->next = current->next;
    free(current);
    current = NULL;
    return front;
  }
}

// delete a song
void delete_song(struct node *lib[], char artist[], char song[]) {
  int index =  (int)(artist[0] - 'a');
  // sets pointer to the front... this ensures that the front pointer always reflects a malloced node
  lib[index] = remove_node(lib[index], artist, song);
}

//queenie
// delete all nodes
void delete_nodes(struct node *lib[]) {
  int index = 0;
  while (index < 26) {
    free_list(lib[index]);
    index++;
  }
}

int main() {
  printf("\n"); //space between output of makefile and output of this file

  // front = insert(front, "a", "b");
  struct node *lib[26];
  // struct node *front;// = add_song_node(lib, "b", "oh yeah baby");
  srand(time(NULL));
  int i;
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
  // printf("\n=================debgugging search=============\n");
  // for (i = 0; i < 26; i++) {
  //   print_node(search(lib, artist[i], songs[i]));
  // }
  // printf("\n=================debgugging print_under_letter=============\n");
  // for (i = 0; i < 26; i++) {
  //   print_under_letter(lib, alphabet[i]);
  // }
  // printf("\n=================debgugging print_library=============\n");
  // print_library(lib);
  // printf("\n=================debgugging shuffle=============\n");
  // shuffle(lib);
  // printf("\n=================debgugging print_artist_song=============\n");
  // for (i = 0; i < 26; i++) {
  //   print_artist_song(lib, artists[i]);
  // }
  // printf("\n=================debgugging remove_node=============\n");
  // struct node *front = make_node("a", "b");
  // for (i = 0; i < 26; i++) {
  //   insert(front, alphabet + i, alphabet + (26 - i));
  // }
  // printf("linked list before any removals\n");
  // print_list(front);
  // //removing artist z's song (last song)
  // printf("removing artist %s, song %s\n", alphabet + 25, alphabet + 1);
  // remove_node(front, alphabet + 25, alphabet + 1); //removing the artist z
  //
  // printf("list after removing z\n");
  // print_list(front);
  // //removing first song
  // printf("removing first node\n");
  // front = remove_node(front, "a", "b"); //removing the artist z
  //
  // printf("list after removing first node\n");
  // print_list(front);
  // //removing random nodes
  // int rands;
  // for (i = 0; i < 26; i++) {
  //   rands = rand()%26;
  //   printf("removing artist %s, song %s\n", alphabet + rands, alphabet + 26 - rands);
  //   front = remove_node(front, alphabet + rands, alphabet + 26 - rands); //removing the artist
  // }
  // printf("list after removing random nodes\n");
  // print_list(front);
  printf("\n=================debgugging delete_song=============\n");
  printf("library before deleting any songs\n");
  print_library(lib);
  printf("\n" );
  // int rand_num;
  for (i = 0; i < 26; i++) {
    // rand_num = rand()%26;
    printf("\ndeleting artist %s, song %s\n", artists[i], songs[i]);
    delete_song(lib, artists[i], songs[i]);
    printf("\nlibrary after deleting node for %dth time\n", i);
    print_library(lib);
  }
  printf("library after deleting random nodes\n");
  //end of debuggin
  // for (i = 0; i < 26; i++) {
  //   free_list(lib[i]);
    // printf("%s\n", str);
    // add_song_node(lib, "i hate seg faults", "i hate seg faults");
  // }
  // printf("printing after list has been freed:\n");
  // print_list(front);
  return 0;
}
