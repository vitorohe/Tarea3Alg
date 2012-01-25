#ifndef _HASH_TABLE
#define _HASH_TABLE
#endif
#include "dictionary.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


struct dictionary *dict_new(unsigned int size, unsigned int universe){
	
	int i;
	struct dictionary *d;
	
	d = (struct dictionary *)malloc(sizeof(struct dictionary));
	
	d->size = size;

	if(size == 2048)
		d->prime = Sprime;
	else
		d->prime = Bprime;
		
	d->a = 1+rand()%(d->prime-2);
	d->b = rand()%(d->prime-1);
	d->slots = (struct slot *)malloc(sizeof(struct slot)*d->size);
	
	for(i = 0; i < d->size; i++)
		d->slots[i].first = NULL;

	return d;
}

int dict_empty(struct dictionary *d){
	int i;
	
	for(i = 0; i < d->size; i++)
		if(d->slots[i].first != NULL)
			return 1;
		
	return 0;
	
}

int hash(struct dictionary *d, unsigned int key){
	
	return ((d->a*key+d->b)%d->prime)%d->size;
	
}

void dict_set(struct dictionary *d, unsigned int key, unsigned int value){
	
	int i;
	struct node *nodo;
	
	i = hash(d,key);
		
	if(d->slots[i].first == NULL){
		d->slots[i].first = (struct node *)malloc(sizeof(struct node));
		d->slots[i].first->key = key;
		d->slots[i].first->value = value;
		d->slots[i].first->left = NULL;
		d->slots[i].first->right = NULL;
	}
	
	nodo = d->slots[i].first;
	
	while(1){
		if(nodo->key == key){
			if(nodo->value != value)
				nodo->value = value;
		
			return;
		}
		
		if(nodo->right != NULL)
			nodo = nodo->right;
		else
			break;
			
	}
	
	nodo->right = (struct node *)malloc(sizeof(struct node));
	nodo->right->key = key;
	nodo->right->value = value;
	nodo->right->left = nodo;
	nodo->right->right = NULL;
	
}

int dict_get(struct dictionary *d, unsigned int key){
	
	int i;
	struct node *nodo;
	
	i = hash(d,key);
	
	for(nodo = d->slots[i].first; nodo != NULL; nodo = nodo->right){
		if(nodo->key == key)
			return nodo->value;
	}
	
	return -1;
	
}

void dict_delete(struct dictionary *d, unsigned int key){
	
	int i;
	struct node *nodo;
	
	i = hash(d,key);
	
	if(d->slots[i].first == NULL)
		return;
	
	if(d->slots[i].first->key == key){
		if(d->slots[i].first->right != NULL){
			d->slots[i].first = d->slots[i].first->right;
			d->slots[i].first->left->right = NULL;
			d->slots[i].first->left->left = NULL;
			node_free(d->slots[i].first->left);
			d->slots[i].first->left = NULL;
		}
		else{
			node_free(d->slots[i].first);
			d->slots[i].first = NULL;
		}
		return;
	}

	for(nodo = d->slots[i].first->right; nodo != NULL; nodo = nodo->right){
		if(nodo->key == key){
			if(nodo->left !=NULL)
				nodo->left->right = nodo->right;

			if(nodo->right !=NULL)
				nodo->right->left = nodo->left;
			
			nodo->left = NULL;
			nodo->right = NULL;
			node_free(nodo);
			
			return;
		}
	}
	
}

void node_free(struct node *n) {
    
    if (n == NULL) return;
    
    node_free(n->right);

    free(n);

}

void dict_free(struct dictionary *d){
	
	int i;
	
	for(i = 0; i < d->size; i++)
		node_free(d->slots[i].first);
		
	free(d->slots);
	
	free(d);
}
