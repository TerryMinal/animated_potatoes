struct node;

// Add song node
struct node * add_song_node(struct node *lib[], char artist[], char song[]);

// search for a song given song and artist name
struct node * search(struct node *lib[], char artist[], char song[]);

// print out all entries under a certain letter
void print_under_letter(struct node *lib[], char letter);

// print out all songs of a specific artist
void print_artist_song(struct node *lib[], char artist[]);

// prints out the whole library
void print_library(struct node *lib[]);

// print out a series of randomly chosen songs
void shuffle(struct node *lib[]);

// delete a song
void delete_song(struct node *lib[], char artist[], char song[]);

// delete all nodes
void delete_nodes(struct node *lib[]);
