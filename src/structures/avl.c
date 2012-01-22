#ifndef _AVL_TREE
#define _AVL_TREE
#endif
#include <stdlib.h>
#include "dictionary.h"
#ifdef DEBUG
#include <stdio.h>
#endif

struct dictionary *dict_new(unsigned int size, unsigned int universe) {
    struct dictionary *dict;

    dict = (struct dictionary *)malloc(sizeof(struct dictionary));

    dict->root = NULL;

    return dict;
}

int dict_empty(struct dictionary *d) {
    
    return (d->root == NULL)? TRUE : FALSE;
}

void dict_set(struct dictionary *d, unsigned int key, unsigned int value) {
    struct node *new_node;

    d->root = node_insert(d->root, key, value);
}

//FIXME
void dict_delete(struct dictionary *d, unsigned int key) {
    struct node *deleted_node, *left, *right, *new_root;
    unsigned int ret;
 
    deleted_node = node_search(d->root, key);

    if (deleted_node != NULL) {
        d->root = deleted_node;
        left = d->root->left;
        right = d->root->right;
        
        if (right != NULL) {
            new_root = node_min(right);
            new_root->left = left;
            d->root = new_root;
        } else {
            d->root = left;
        }
    }
}
int dict_get(struct dictionary *d, unsigned int key) {
    struct node *le_node;
    unsigned int ret;
 
    le_node = node_search(d->root, key);

    if (le_node != NULL) {
        return le_node->value; 
    } else {
        return -1;
    }
}

void dict_free(struct dictionary *d) {
    node_free(d->root);
    free(d);
}

struct node *left_single(struct node *n) {
    struct node *aux;
    if (n == NULL || n->left == NULL) return n;

    aux = n->left;

    n->left = aux->right;

    aux->right = n;

    n->height = ((height(n->left) > height(n->right))? height(n->left) : height(n->right)) + 1;

    aux->height = ((height(aux->left) > height(n->right))? height(n->left) : height(n->right)) + 1;

    return aux;
}


struct node *right_single(struct node *n) {
    struct node *aux;
    if (n == NULL || n->right == NULL) return n;

    aux = n->right;

    n->right = aux->left;

    aux->left = n;

    n->height = ((height(n->left) > height(n->right))? height(n->left) : height(n->right)) + 1;

    aux->height = ((height(aux->left) > height(n->right))? height(n->left) : height(n->right)) + 1;

    return aux;
}

struct node *left_double(struct node *n) {
    n->left = right_single(n->left);
    n = left_single(n);
    return n;
}

struct node *right_double(struct node *n) {
    n->right = left_single(n->right);
    n = right_single(n);
    return n;
}

int height(struct node *n) {
    return (n != NULL)? n->height : -1; 
}


struct node *node_insert(struct node *root, unsigned int key, unsigned int value) {
    struct node *n;

    if (root == NULL) {
        n = (struct node *)malloc(sizeof(struct node));
        n->height = 0;
        n->left = n->right = NULL;
        n->key = key;
        n->value = value; 

        return n;
    }

    if (root->key == key) {
        root->value = value;
        return root;
    }
    
    if (key > root->key) {

        root->right = node_insert(root->right, key, value);

        if (height(root->left) - height(root->right) == -2) {
            if (key > root->right->key) {
                root = right_single(root);
            } else {
                root = right_double(root);
            }
        }
    } else  {

        root->left = node_insert(root->left, key, value);

        if (height(root->left) - height(root->right) == 2) {
            if (key < root->left->key) {
                root = left_single(root);
            } else {
                root = left_double(root);
            }
        }
    }

    root->height = ((height(root->left) > height(root->right))? height(root->left) : height(root->right)) +1;
    return root;
}

struct node *node_search(struct node *root, unsigned int key) {

    if (root == NULL) return NULL;

    if (root->key == key) return root;

    return (root->key > key) ? node_search(root->left, key) : node_search(root->right, key);

}

void node_free(struct node *n) {
    
    if (n == NULL) return;

    node_free(n->left);
    node_free(n->right);

    free(n);

}

struct node *node_min(struct node *root) {
        return (root->left == NULL)? root : node_min(root->left);
}

