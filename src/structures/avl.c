#ifndef _AVL_TREE
#define _AVL_TREE
#endif
#include <stdlib.h>
#include "dictionary.h"


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

    new_node = search_rec(d->root, key);

    if (new_node != NULL) {
        new_node->value = value;
        return;
    }

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->height = 1;
    new_node->left = new_node->right = NULL;
    new_node->key = key;
    new_node->value = value; 

    d->root = insert_rec(d->root, new_node);
    d->root = rebalance(d->root);

    set_height(d->root);

}

int dict_get(struct dictionary *d, unsigned int key) {
    struct node *le_node;
    unsigned int ret;
 
    le_node = search_rec(d->root, key);

    if (le_node != NULL) {
        return le_node->value; 
    } else {
        return -1;
    }
}

void dict_delete(struct dictionary *d, unsigned int key) {
    if (d->root == NULL) return;

    if (d->root->key == key) {
        d->root = delete_node(d->root);
    } else {
        delete_rec(d->root, key);
    }

    set_height(d->root);

    d->root = rebalance(d->root);
}

void dict_free(struct dictionary *d) {
    free_rec(d->root);
    free(d);
}

struct node *insert_rec(struct node *root, struct node *new_node) {
    struct node *aux;

    if (root == NULL) return new_node;

    if (root-> key > new_node->key) {
        root->left = insert_rec(root->left, new_node);
    } else {
        root->right = insert_rec(root->right, new_node);
    }

    aux = rebalance(root);
    set_height(aux);
    return aux;
}

struct node *search_rec(struct node *root, unsigned int key) {

    if (root == NULL) return NULL;

    if (root->key == key) return root;

    return (root->key > key) ? search_rec(root->left, key) : search_rec(root->right, key);

}

void delete_rec(struct node *root, unsigned int key) {
    if (root->key > key) {

        if (root->left == NULL) return;
        
        if (root->left->key == key) {
            root->left = delete_node(root->left);
        } else {
            delete_rec(root->left, key);
            set_height(root->left);
            root->left = rebalance(root->left);
        }

    } else {

        if (root->right == NULL) return;
        
        if (root->right->key == key) {
            root->right = delete_node(root->right);
        } else {
            delete_rec(root->right, key);
            set_height(root->right);
            root->right = rebalance(root->right);
        }
    }

    return;
}

struct node *node_min(struct node *root) {
    return (root->left == NULL)? root : node_min(root->left);
}


struct node *delete_node(struct node *root) {
    struct node *child, *aux;
    unsigned int key;
    if (root->left == NULL) {
        aux = root->right;
        free(root);
        return aux;
    } else if (root->right == NULL) {
        aux = root->left;
        free(root);
        return aux;
    } else {

        if (root->right->left == NULL) {
            child = root->right;
            root->value = child->value;
            root->key = child->key;
            root->right = child->right;
            free(child);
        } else {
            key = root->key;
            child = node_min(root->right);
            root->value = child->value;
            root->key = child->key;
            child->key = key;
            delete_rec(root, key);
        }
        
        set_height(root);
        return rebalance(root);
    }
}

struct node *swap_with_left(struct node *dad, struct node *child) {
    struct node *aux;
    if (child->right->right != NULL) {
        child->right = swap_with_left(dad, child->right);
    } else {
        dad->key = child->right->key;
        dad->value = child->right->value;
        aux = child->right;
        child->right = child->right->left;
        free(aux);
    }

    set_height(dad);
    rebalance(dad);
    return child;
}


struct node *rebalance(struct node *root) { 

    int AL, BL, CL, AR, BR, CR;

    if (height(root) < 3) return root;

    if (root->left != NULL) {
        AL = height(root->left->left);
        BL = height(root->left->right);
        CR = height(root->left);
    } else {
        AL = BL = CR = 0;
    }

    if (root->right != NULL) {
        BR = height(root->right->left);
        CL = height(root->right);
        AR = height(root->right->right);
    } else {
        BR = CL = AR = 0;
    }

    if (root->left != NULL) {
        if (AL >= BL && BL >= CL ) {
            return rot_LL(root);
        } else if (BL >= AL && AL >= CL) {
            return rot_LR(root);
        }
    }

    if (root->right != NULL) {
        if (AR >= BR && BR >= CR) {
            return rot_RR(root);
        } else if (BR >= AR && AR >= CR) {
            return rot_RL(root);
        }
    }
    
    return root;
}

struct node *rot_LL(struct node *old) {
    struct node *ret;
    ret = old->left;

    old->left = ret->right;
    ret->right = old;

    set_height(old);
    set_height(old->left);
    set_height(ret);

    return ret;
}

struct node *rot_RR(struct node *old) {
    struct node *ret;
    ret = old->right;

    old->right = ret->left;
    ret->left = old;

    set_height(old);
    set_height(old->right);
    set_height(ret);

    return ret;
}

struct node *rot_RL(struct node *old) {
    struct node *right, *ret;

    right = old->right;
    ret = right->left;
    old->right = ret->left;
    right->left = ret->right;
    ret->left = old;
    ret->right = right;

    set_height(old);
    set_height(right);
    set_height(ret);

    return ret;
}

struct node *rot_LR(struct node *old) {
    struct node *left, *ret;

    left = old->left;
    ret = left->right;
    old->left = ret->right;
    left->right = ret->left;
    ret->right = old;
    ret->left = left;

    set_height(old);
    set_height(left);
    set_height(ret);

    return ret;
}


void set_height(struct node *n) {
    if (n == NULL) return;

    n->height = ((height(n->left) > height(n->right))? height(n->left) : height(n->right)) + 1;
}

int height(struct node *n) {
    return (n != NULL)? n->height : 0;
}

void free_rec(struct node *n) {
    
    if (n == NULL) return;

    free_rec(n->left);
    free_rec(n->right);

    free(n);

}
