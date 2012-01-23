#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structures/dictionary.h"

struct dictionary *dict_new(unsigned int size, unsigned int universe){
	struct dictionary *t;
	t= (struct dictionary *) malloc(sizeof(struct dictionary));
	t->size = 0;
	return t;
}

int dict_empty(struct dictionary *d){
	return d->size == 0;
}

void dict_set(struct dictionary *d, unsigned int key, unsigned int value){
	if(dict_empty(d)){
		struct node *new;
		new = (struct node *)malloc(sizeof(struct node));
		new->key = key;
		new->value = value;
		new->size = 1;
		d->root = new;
	}
	else
		insert(&d->root,key,value);
	d->size++;
}

int dict_get(struct dictionary *d, unsigned int key){
	return get(d->root,key);
}

void dict_delete(struct dictionary *d, unsigned int key){
	struct node **aux;
	aux = &(d->root);
	if(delete(aux,key) == 1)
		d->size--;
	if(d->size == 0)
		d->root = NULL;
	recalculate_sizes(d->root);
}

void dict_free(struct dictionary *d){
	node_free(d->root);
	free(d);
}

struct node *insert(struct node **r, unsigned int key, unsigned int value){
	int ra;
	struct node *aux;
	aux = *r;
	if(aux == NULL){
		struct node *new;
		new = (struct node *)malloc(sizeof(struct node));
		new->key = key;
		new->value = value;
		new->size = 1;
		aux = new;
		return aux;
	}
	srand(time (0));
	ra = rand()%(aux->size) + 1;
	if(ra == 1){
		struct node *left;
		struct node *right;
		left = NULL;
		right = NULL;
		cut(aux,&left,&right,key,value);
		struct node *new;
		new = (struct node *)malloc(sizeof(struct node));
		new->key = key;
		new->value = value;
		new->size = aux->size;
		new->left = left;
		new->right = right;
		*r = new;
		recalculate_sizes(*r);
		left = NULL;
		right = NULL;
		return *r;
	}
	else{
		if(aux->key == key);
		if(key < aux->key){
			aux->left = insert(&aux->left,key,value);
			aux->size++;
		}
		else{
			aux->right = insert(&aux->right,key,value);
			aux->size++;
		}
		return aux;
	}
}
void cut(struct node *r,struct node **t1, struct node **t2, unsigned int key, unsigned int value){
	struct node *left;
	struct node *right;
	left = NULL;
	right = NULL;
	if(r == NULL) return;
	if(key < r->key){
		cut(r->left,&left,&right,key,value);
		if(left != NULL)
			*t1 = left;
		if(right != NULL)
			r->left = right;
		else
			r->left = NULL;
		*t2 = r;
		left = NULL;
		right = NULL;
	}
	else{
		cut(r->right,&left,&right,key,value);
		if(left != NULL)
			r->right = left;
		else
			r->right = NULL;
		*t1 = r;
		if(right != NULL)
			*t2 = right;
		left = NULL;
		right = NULL;
	}	
}

int recalculate_sizes(struct node *r){
	if(r == NULL) return 0;
	r->size = 0;
	r->size = 1 + recalculate_sizes(r->left) + recalculate_sizes(r->right);
	return r->size;
}
	
int get(struct node *r, unsigned int key){
	if(r == NULL)
		return -1;
	if(r->key == key)
		return r->value;
	if(key < r->key)
		return get(r->left,key);
	if(key > r->key)
		return get(r->right,key);
	else
		return -1;
}

int delete(struct node **r, unsigned int key){
	struct node *aux;
	aux = *r;
	if(aux == NULL){
		return -1;
	}
	if(aux->key == key){
		 prom(r);
		 return 1;
	}
	if(key < aux->key)
		return delete(&((*r)->left),key);
	if(key > aux->key)
		return delete(&((*r)->right),key);
}

void prom(struct node **r){
	int ra;
	struct node *aux;
	aux = *r;
	if(aux->size == 1){
		node_free(aux);
		*r = NULL;
	}	
	else if(aux->left == NULL){
		aux->key = aux->right->key;
		aux->value = aux->right->value;
		prom(&aux->right);

	}
	else if(aux->right == NULL){
		aux->key = aux->left->key;
		aux->value = aux->left->value;
		prom(&aux->left);
	}
	else{
		srand (time (0));
		ra = rand()%(aux->size) + 1;
		if(ra <= aux->left->size){
			aux->key = aux->left->key;
			aux->value = aux->left->value;
			prom(&aux->left);
		}
		else{
			aux->key = aux->right->key;
			aux->value = aux->right->value;
			prom(&aux->right);
		}
	}
}

void node_free(struct node *r){
	if(r == NULL) return;
	node_free(r->left);
	node_free(r->right);
	memset(r,0,sizeof(struct node));
	free(r);
}

void tree_print(struct node *r, int floor){
	int i;
	for(i = 0; i < floor;i++)
		printf("\t");
	if(r == NULL)
		printf("null\n");
	else{
		printf("key: %d value: %d size: %d\n",r->key,r->value,r->size);
		tree_print(r->left,floor+1);
		tree_print(r->right,floor+1);
	}
}

