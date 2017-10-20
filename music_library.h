struct node;

// Add song node
struct node * add_song_node(char lib[], struct node *song);

// search for a song given song and artist name
struct node * search(char lib[], char artist[], char song[]);

// print out all entries under a certain letter
void print_under_letter(char lib[], char letter);

// print out all songs of a specific artist
void print_artist_song(char lib[], char artist[]);

// prints out the whole library
void print_library(char lib[]);

// print out a series of randomly chosen songs
void shuffle(char lib[]);

// delete a song
void delete_song(char lib[], char song[]);

// delete all nodes
void delete_nodes(char lib[]);
