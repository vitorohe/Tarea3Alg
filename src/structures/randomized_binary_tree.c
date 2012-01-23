#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structures/dictionary.h"

struct dictionary *dict_new(unsigned int size, unsigned int universe){
	struct dictionary *t;
	t= (struct dictionary *) malloc(sizeof(struct dictionary));
	t->size = 0;
	srand (time (0));
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
		new->left = NULL;
		new->right = NULL;
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
	if(delete(&(d->root),key) != NULL)
		d->size--;
	if(d->root == NULL)
		d->size--;
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
		new->left = NULL;
		new->right = NULL;
		aux = new;
		return aux;
	}
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

struct node *delete(struct node **r, unsigned int key){
	int ra;
	struct node *t;
	struct node *aux;
	t = *r;
	if(t == NULL)
		return NULL;
	if(key < t->key)
		t->left = delete(&(t->left),key);
	else if(key > t->key)
		t->right = delete(&(t->right),key);
	else{
		if(t->left != NULL && t->right != NULL){
			ra = rand()%(t->size) + 1;
			if(ra <= t->left->size){
				aux = find_min(t->right);
				t->key = aux->key;
				t->value = aux->value;
				t->right = delete(&(t->right),t->key);
			}
			else{
				aux = find_max(t->left);
				t->key = aux->key;
				t->value = aux->value;
				t->left = delete(&(t->left),t->key);
			}
		}
		else{
			aux = *r;
			if((*r)->left == NULL)
				*r = (*r)->right;
			else if((*r)->right == NULL)
				*r = (*r)->left;
			free(aux);
		}
	}
	return *r;
}

struct node *find_min(struct node *r){
	if(r == NULL)
		return NULL;
	else
		if(r->left == NULL)
			return r;
		else
			return find_min(r->left);
}

struct node *find_max(struct node *r){
	if(r == NULL)
		return NULL;
	else
		if(r->right == NULL)
			return r;
		else
			return find_max(r->right);
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

