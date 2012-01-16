#ifndef _SPLAY_TREE
#define _SPLAY_TREE
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

    new_node = node_search(d->root, key);

    if (new_node == NULL) {
        new_node = (struct node *)malloc(sizeof(struct node));

        new_node->left = new_node->right = new_node->parent = NULL;
        new_node->key = key;
        new_node->value = value;
        p->root = node_insert(d->root, new_node);
    } else {
        new_node->value = value;
    }
    splay(new_node);
    d->root = new_node;
    d->root->parent = NULL;
}

int dict_delete(struct dictionary *d, unsigned int key) {
    struct node *deleted_node, *left, *right;
    unsigned int ret;
 
    deleted_node = node_search(d->root, key);

    if (deleted_node != NULL) {
        splay(deleted_node);
        d->root = deleted_node;
        d->root->parent = NULL;

        left = d->root->left;
        right = d->root->right;

        if (left != NULL) left->parent = NULL;
        if (right != NULL) right->parent = NULL;
        
        if (right != NULL) {
            new_root = node_min(right);
            splay(new_root);
            new_root->parent = NULL;
            
            new_root->left = left;
            if (left != NULL) left->parent = new_root;        

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
        splay(le_node);
        d->root = le_node;
        d->root->parent = NULL;
        return d->root->value; 
    } else {
        return -1;
    }
}
void dict_free(struct dictionary *d) {
    node_free(d->root);
    free(d);
}

void splay(struct node *n) {
    struct node *dad, *grandpa;
    dad = n->parent;
    if (dad == NULL) return;

    grandpa = dad->parent;

    if (grandpa == NULL) {
        /* We're root's childrens */
        if (n == dad->left) {
            zig(n, dad);
        } else { 
            zag(n, dad);
        }
        return;
    }

    if (n == dad->left && dad == grandpa->left) {
        zigzig(n, dad, grandpa);
    } else if (n == dad->right && dad == grandpa->left) {
        zag(n, dad);
        zig(n, grandpa);
    } else if (n == dad->left && dad == grandpa->right) {
        zig(n, dad);
        zag(n, grandpa);
    } else if (n == dad->right && dad == grandpa->right) {
        zagzag(n, dad, grandpa);
    }

    splay(n);

}

void zig(struct node *son, struct node *dad) {
    
    dad->left = son->right;
    if (dad->left != NULL) dad->left->parent = dad;

    son->right = dad;

    if (dad->parent != NULL) {
        if (dad->parent->left == dad) dad->parent->left = son;
        else dad->parent->right = son;
    }

    son->parent = dad->parent;
    dad->parent = son;
}

void zag(struct node *son, struct node *dad) {
    
    dad->right = son->left;
    if (dad->right != NULL) dad->right->parent = dad;

    son->left = dad;

    if (dad->parent != NULL) {
        if (dad->parent->left == dad) dad->parent->left = son;
        else dad->parent->right = son;
    }

    son->parent = dad->parent;
    dad->parent = son;
}

void zigzig(struct node *son, struct node *dad, struct node *grandpa) {
    
    son->parent = grandpa->parent;

    grandpa->left = dad->right;
    if (grandpa->left != NULL) grandpa->left->parent = grandpa;

    dad->left = son->right;
    if (dad->left != NULL) dad->left->parent = dad;

    son->right = dad;
    dad->parent = son;

    if (grandpa->parent != NULL) {
        if (grandpa->parent->left == grandpa) grandpa->parent->left = son;
        else grandpa->parent->right = son;
    }

    dad->right = grandpa;
    grandpa->parent = dad;
}

void zagzag(struct node *son, struct node *dad, struct node *grandpa) {
   
    son->parent = grandpa->parent;

    grandpa->right = dad->left;
    if (grandpa->right != NULL) grandpa->right->parent = grandpa;

    dad->right = son->left;
    if (dad->right != NULL) dad->right->parent = dad;

    son->left = dad;
    dad->parent = son;

    if (grandpa->parent != NULL) {
        if (grandpa->parent->left == grandpa) grandpa->parent->left = son;
        else grandpa->parent->right = son;
    }

    dad->left = grandpa;
    grandpa->parent = dad;
}

struct node *node_insert(struct node *root, struct node *new_node) {
    
    if (root == NULL) return new_node;
    
    new_node->parent = root;

    if (new_node->value > root->value) {
        root->right = node_insert(root->right, new_node);
    } else if (new_node->value <= root->value) {
        root->left = node_insert(root->left, new_node);
    }

    return root;
}

struct node *node_search(struct node *root, unsigned int key) {

    if (root == NULL) return NULL;

    if (root->key == key) return root;

    return (root->key < key) ? node_search(root->left, key) : node_search(root->right, key);

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

