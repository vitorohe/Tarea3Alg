#ifndef _DICTIONARY_
#define _DICTIONARY_

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

/* ===================== Binary Tree ===================== */
#ifdef _BINARY_TREE
struct node{
    struct node *left, *right;
		unsigned int key;
    unsigned int value;
};

struct dictionary {
    struct node *root;
		int size;
		int universe;
};

struct node *insert(struct node *r, unsigned int key, unsigned int value);
int get(struct node *r, unsigned int key);
struct node *delete(struct node **r, unsigned int key);
struct node *find_min(struct node *r);
void node_free(struct node *r);
void tree_print(struct node *r, int floor);
#endif
/* ===================== AVL Tree ===================== */
#ifdef _RANDOMIZED_BINARY_TREE
#endif
/* ===================== AVL Tree ===================== */
#ifdef _AVL_TREE

struct node{
    struct node *left, *right;
    int height;
    unsigned int key;
    unsigned int value;
};

struct dictionary {
    struct node *root;
};

struct node *insert_rec(struct node *root, struct node *new_node);
struct node *search_rec(struct node *root, unsigned int key);
void delete_rec(struct node *root, unsigned int key);
struct node *delete_node(struct node *root);

struct node *swap_with_left(struct node *dad, struct node *child);
struct node *rebalance(struct node *root);

struct node *rot_LL(struct node *old);
struct node *rot_LR(struct node *old);
struct node *rot_RL(struct node *old);
struct node *rot_RR(struct node *old);


void set_height(struct node *n);
void free_rec(struct node *n);
/*struct node *node_insert(struct node *root, unsigned int key, unsigned int value);
struct node *node_search(struct node *root, unsigned int key);
void node_free(struct node *n);*/

/* AVL Tree rotations */
/*struct node *left_single(struct node *n); 
struct node *right_single(struct node *n); 
struct node *left_double(struct node *n); 
struct node *right_double(struct node *n); 
struct node *node_min(struct node *root);
*/


#endif

/* ===================== Van Emde Boas Tree ===================== */

#ifdef _VAN_EMDE_BOAS

#ifndef _UNIVERSE
#define _UNIVERSE 100
#endif

struct array_trees {
	
	struct dictionary *dict_child;
	int non_empty;
	
};
 
 
struct dictionary {
	
	int min;
	int max;
	int amin;
	int amax;
	int key_min;
	int key_max;
	int n_elems;	
	int universo;
	int nhijos;
	struct array_trees *atrees;
		
};
void update_amin_amax(struct dictionary *d, int i);
void del_amin_amax(struct dictionary *d, int i);
int higher(int x, int universo);
int lower(int x, int universo);

#endif

/* ===================== Splay Tree ===================== */

#ifdef _SPLAY_TREE

struct node{
    struct node *parent;
    struct node *left, *right;
    unsigned int key;
    unsigned int value;
};

struct dictionary {
    struct node *root;
};
/* Tree operations */
struct node *node_insert(struct node *root, struct node *new_node);
void node_free(struct node *n);

/* Splay Tree rotations */
void splay(struct node *n);
void zag(struct node *son, struct node *dad); 
void zig(struct node *son, struct node *dad); 
void zigzig(struct node *son, struct node *dad, struct node *grandpa);
void zagzag(struct node *son, struct node *dad, struct node *grandpa); 

#endif

/* ===================== Hash Table  ===================== */

#ifdef _HASH_TABLE

#define Bprime 16777289
#define Sprime 65537

struct node{
    struct node *left, *right;
    unsigned int key;
    unsigned int value;
};

struct slot{
	struct node *first;	
};

struct dictionary{
	struct slot *slots;
	int size;
	int a, b, prime;
};

/* List operations */
void node_free(struct node *n);

#endif

/* 
   Creates a new dictionary structure, which should be
   deallocated through dict_free().

Params:
    size(IN) - the number of elements the dictionary will
    be able to hold.

	universe(IN) - the size of the universe (range of numbers
	that we can have in a dictionary).
Returns:
    the newly created dictionary structure.
*/
struct dictionary *dict_new(unsigned int size, unsigned int universe);

/*
   Tests a dictionary for emptiness

Params:
    d(IN) - the dictionary to test for emptiness.

Returns:
    TRUE if the dictionary was empty, FALSE if it
    wasn't.
*/
int dict_empty(struct dictionary *d);

/*
    Inserts an element in the dictionary, or updates its value if it
    was already in the structure.

Params:
    d(IN/OUT) - the dictionary where the element will be inserted.
    key(IN) - the key for the new element.
    value(OUT) - the value for the new element.

*/
void dict_set(struct dictionary *d, unsigned int key, unsigned int value);

/*
    Retrieves the value of an element in the dictionary using its key.

Params:
    d(IN) - the dictionary where the element will be inserted.
    key(IN) - the element to insert.

Returns:
    the value of the element with the specified key, or -1 if there was 
    no element with such a key.
*/
int dict_get(struct dictionary *d, unsigned int key);

/*
   Deletes an entry from a dictionary given its key. Does nothing 
   if there isn't an element with such a key.

Params: 
    d(IN/OUT) - the dictionary from which to delete the element.
    key (IN) - the key for the search and deletion.
 */
void dict_delete(struct dictionary *d, unsigned int key);

/*
   Deallocates a dictionary created through dict_new(). Unspecified
   behavior will happen if a null dictionary, an already freed
   dictionary or a dictionary that wasn't allocated through
   dict_new() is freed with this function.

Params:
    d(IN/OUT) - the dictionary to be freed.
*/
void dict_free(struct dictionary *d);

#endif
