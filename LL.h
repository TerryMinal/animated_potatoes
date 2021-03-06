struct node;

//prints out one node
void print_node(struct node *node);

// Should take a pointer to a node struct
// and print out all of the data in the list
void print_list(struct node *current_node);

// Should take a pointer to the existing list and the data to be added,
// create a new node and put it at the beginning of the list.
// The second argument should match whatever data you contain in your nodes.
// Returns a pointer to the beginning of the list.

struct node * make_node(char new_artist[], char new_song[]);

struct node * insert_front(struct node *current_node, char new_artist[], char new_song[]);

//insert in order
struct node * insert(struct node *current_node, char artist[], char song[]);

//returns node based on artist and song song
struct node * return_node(struct node *current_node, char artist[], char song_song[]);

//returns first song based on artist
struct node * return_first_song(struct node *current_node, char artist[]);

//returns random element
struct node * return_random(struct node * front);

//removes a single specified node
struct node * remove_node( struct node * front, char artist[], char song[]);

// Should take a pointer to a list as a parameter and then go through
// the entire list freeing each node and return a pointer to the beginning of the
// list (which should be NULL by then).
struct node * free_list(struct node *current_node);
