#ifndef _VAN_EMDE_BOAS
#define _VAN_EMDE_BOAS
#endif
#include "dictionary.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
  
  
struct dictionary *dict_new(unsigned int size,unsigned int universe) {
    struct dictionary *p;
	int i,new_universe;
	
    p = (struct dictionary *)malloc(sizeof(struct dictionary));
    p->n_elems = 0;
    p->min = INT_MIN;
    p->max = INT_MAX;
    p->key_min = -1;
    p->key_max = -1;
    p->universo = (int)pow(2,universe);
    p->nhijos = 0;
    
    if(universe > 1){
   
		p->nhijos = (int)pow(2,ceil((double)universe/2));

		p->atrees = (struct array_trees *)malloc(sizeof(struct array_trees)*p->nhijos);
		
		for (i = 0; i < p->nhijos; i++)
			p->atrees[i].dict_child = dict_new(0,universe/2);
	}
	else{
		p->atrees = NULL;
	}
    
    return p;
}

int dict_empty(struct dictionary *d) {
    int i;
    
    for(i = 0; d->nhijos; i++)
		if(d->atrees[i].non_empty == 1)
			return 0;
			
	return 1;
}

void dict_set(struct dictionary *d, unsigned int key, unsigned int value){
    int i, tmp, tmpv, h, l;

    d->n_elems++;
    if (d->n_elems == 1) {
			d->max = value;
			d->key_max = key;
			d->min = value;
			d->key_min = key;
			return;
		}
		
	else if (d->n_elems == 2) {
		if (key < d->key_min) {
			d->key_min = key;
			d->min = value;
			return;
		}
		else if(key > d->key_max){
			d->key_max = key;
			d->max = value;
			return;
		}
		else{
			if(value != d->max){
				d->max = value;
				d->min = value;
				d->n_elems--;
			}			
		}
	}
	else {
		if (key < d->key_min) {
			tmp = d->key_min;
			tmpv = d->min;
			d->key_min = key;
			d->min = value;
			key = tmp;
			value = tmpv;
		}
		
		else if (key > d->key_max) {
			tmp = d->key_max;
			tmpv = d->max;
			d->key_max = key;
			d->max = value;
			key = tmp;
			value = tmpv;
		}
		else if(key == d->key_max){
			if(value != d->max){
				d->max = value;
				return;
			}
		}
		else if(key == d->key_min){
			if(value != d->min){
				d->min = value;
				return;
			}
		}
	}
	
		
	if(d->atrees != NULL){	
		
		h = higher(key,d->universo);
		l = lower(key,d->universo);
		
		dict_set(d->atrees[h].dict_child,l,value);
	
	
		if (d->atrees[h].dict_child->n_elems == 1){
			d->atrees[h].non_empty = 1;
			update_amin_amax(d,h);
		}
		
	}
}

int dict_get(struct dictionary *d, unsigned int key){

    if (d->n_elems == 1)
		if(key == d->key_max)
			return d->max;
		
	else if (d->n_elems == 2)
		if (key == d->key_min)
			return d->min;

		else if(key == d->key_max)
			return d->max;
			
	if(d->atrees != NULL){	
		
		h = higher(key,d->universo);
		l = lower(key,d->universo);
		
		return dict_get(d->atrees[h].dict_child,l);
		
	}
}

void dict_delete(struct dictionary *d, unsigned int key){
    int i=-1;

#ifdef DEBUG
    if (d->n_elems == 0) {
        printf("No elements to delete from dictionary.\n");
        exit(1);
    }
#endif
	
	d->n_elems--;
	
	if(d->n_elems == 0){
		d->min = INT_MIN;
		d->max = INT_MAX;
		return;
	}
	
	if (d->n_elems == 1) {
		if(del_elem == d>min)
			d->min = d->max;
		else
			d->max = d->min;
			
		return;
	}
	
	
	else {
		
		if(del_elem == d->min){
			d->min=d->amin*d->atrees[amin].dict_child->universo + d->atrees[d->amin].dict_child->min;
			del_elem = d->min;
			i = d->amin;
		}			
		
		else if(del_elem == d->max){
			d->max=d->amax*d->atrees[amax].dict_child->universo + d->atrees[d->amax].dict_child->max;
			del_elem = d->max;
			i = d->amax;
		}
		
	}
	
	if(i != -1){
		
		d_delete(d->atrees[i].dict_child);
	
		if (d->atrees[i].dict_child->n_elems == 0){
			d->atrees[i].non_empty = 0;
			del_amin_amax(d,i);
		}
				
				
	}

}

void update_amin_amax(struct dictionary *d, int i){
	
	if(d->amin == -1){
		d->amin = i;
		d->amax = i;
	}
	else{
		if(d->amin > i)
			d->amin = i;
		else if(d->amax < i)
			d->amax = i;
	}
	
}

void del_amin_amax(struct dictionary *d, int i){
	
	int j;
	
	if(d->amin == i && d->max == i){
		d->amin = d->amax = -1;
		return;
	}
	if(d->amin == i){
		d->amin = -1
		for(j = i+1; j < d->nhijos; j++)
			if(d->atrees[j].non_empty){
				d->amin = j;
				break;
			}
		
	}
	else if(d->max == i){
		d->amax = -1
		for(j = i-1; j > 0; j++)
			if(d->atrees[j].non_empty){
				d->amax = j;
				break;
			}
	}
	
}

void dict_free(struct dictionary *p) {
    
    int i;
    
    if(p->nhijos != 0){
		for(i = 0; i < p->nhijos; i++){
			dict_free(p->atrees[i].dict_child);
		}
		
		free(p->atrees);
	}
    
    free(p);
}

int higher(int x, int universo) {	
	return (x >> (int)floor((log(universo)/log(2))/2));
}

int lower(int x, int universo) {
	return (x & (0xffffffff >> (32-(int)ceil(log(universo)/log(2)) + ((int)ceil((log(universo)/log(2)))-(int)floor((log(universo)/log(2))/2)))));
}
