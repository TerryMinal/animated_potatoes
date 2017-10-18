struct node;
// Should take a pointer to a node struct
// and print out all of the data in the list
void print_list(struct node *front);

// Should take a pointer to the existing list and the data to be added,
// create a new node and put it at the beginning of the list.
// The second argument should match whatever data you contain in your nodes.
// Returns a pointer to the beginning of the list.

struct node * make_node(char new_artist[], char new_song[]);

struct node * insert_front(struct node *front, char new_artist[], char new_song[]);

// Should take a pointer to a list as a parameter and then go through
// the entire list freeing each node and return a pointer to the beginning of the
// list (which should be NULL by then).
struct node * free_list(struct node *front);

//insert in order
struct node * insert(struct node * node);

//returns node based on artist and song song
struct node * return_node(char artist[], char song_song[]);

//returns first song based on artist
struct node * return_first_song(char artist[]);

//returns random element
struct node * return_random();

//removes a single specified node
struct node * remove_node(struct node * node);
