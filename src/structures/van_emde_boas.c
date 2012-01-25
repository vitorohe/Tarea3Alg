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
    struct dictionary *d;
	int i,new_universe;
	
    d = (struct dictionary *)malloc(sizeof(struct dictionary));
    d->n_elems = 0;
    d->min = INT_MIN;
    d->max = INT_MAX;
    d->key_min = -1;
    d->key_max = -1;
    d->universo = (int)pow(2,universe);
    d->nhijos = 0;
    
    if(universe > 1){
   
		d->nhijos = (int)pow(2,ceil((double)universe/2));

		d->atrees = (struct array_trees *)malloc(sizeof(struct array_trees)*d->nhijos);
		
		for (i = 0; i < d->nhijos; i++)
			d->atrees[i].dict_child = dict_new(0,universe/2);
	}
	else{
		d->atrees = NULL;
	}
    
    return d;
}

int dict_empty(struct dictionary *d) {
    int i;
    
    for(i = 0; d->nhijos; i++)
		if(d->atrees[i].non_empty == 1)
			return 0;
			
	return 1;
}

void dict_set(struct dictionary *d, unsigned int key, unsigned int value){
    int i, tmp, tmpv, h, l, cant;

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
			return;			
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
		
		cant = d->atrees[h].dict_child->n_elems;
		
		dict_set(d->atrees[h].dict_child,l,value);
	
		if(d->atrees[h].dict_child->n_elems != cant){
			if (d->atrees[h].dict_child->n_elems == 1){
				d->atrees[h].non_empty = 1;
				update_amin_amax(d,h);
			}
		}
		else
			d->n_elems--;
		
	}
}

int dict_get(struct dictionary *d, unsigned int key){

	int h,l;

    if (d->n_elems == 1){
		if(key == d->key_max)
			return d->max;
		else
			return -1;
	}
		
	else {
		if (key == d->key_min)
			return d->min;

		else if(key == d->key_max)
			return d->max;
	
		else if(d->atrees != NULL){	
		
			h = higher(key,d->universo);
			l = lower(key,d->universo);
		
			return dict_get(d->atrees[h].dict_child,l);
		}
		else
			return -1;
	}

}

void dict_delete(struct dictionary *d, unsigned int key){
    int i=-1;
    int h, l;

#ifdef DEBUG
    if (d->n_elems == 0) {
        printf("No elements to delete from dictionary.\n");
        exit(1);
    }
#endif
	
	d->n_elems--;
	
	if(d->n_elems < 0){
		d->n_elems = 0;
		return;
	}
	
	if(d->n_elems == 0){
		d->key_min = -1;
		d->key_max = -1;
		d->min = INT_MIN;
		d->max = INT_MAX;
		return;
	}
	
	if (d->n_elems == 1) {
		if(key == d->key_min){
			d->min = d->max;
			d->key_min = d->key_max;
		}
		else{
			d->key_max = d->key_min;
			d->max = d->min;
		}
			
		return;
	}
	
	
	else {
		if(key == d->key_min){
			d->key_min=d->amin*d->atrees[d->amin].dict_child->universo + d->atrees[d->amin].dict_child->key_min;
			d->min=d->amin*d->atrees[d->amin].dict_child->universo + d->atrees[d->amin].dict_child->min;
			key = d->atrees[d->amin].dict_child->key_min;
			i = d->amin;
		}			
		
		else if(key == d->key_max){
			d->key_max=d->amax*d->atrees[d->amax].dict_child->universo + d->atrees[d->amax].dict_child->key_max;
			d->max=d->amax*d->atrees[d->amax].dict_child->universo + d->atrees[d->amax].dict_child->max;
			key = d->atrees[d->amax].dict_child->key_max;
			i = d->amax;
		}
		
	}
	
	if(i != -1 && d->atrees != NULL){
		
		dict_delete(d->atrees[i].dict_child,key);

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
		d->amin = -1;
		for(j = i+1; j < d->amax; j++)
			if(d->atrees[j].non_empty){
				d->amin = j;
				break;
			}
		
	}
	else if(d->max == i){
		d->amax = -1;
		for(j = i-1; j > d->amin; j++)
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

void printvEB(struct dictionary *d,int tabs){
	int i;	
		
	for(i = 0; i < tabs; i++)
		printf("\t");
	printf("min: %d, key_min %d\n",d->min,d->key_min);
	
	for(i = 0; i < tabs; i++)
		printf("\t");
	printf("max: %d, key_max: %d\n",d->max,d->key_max);
	
	for(i = 0; i < tabs; i++)
		printf("\t");
	printf("n_elems %d\n",d->n_elems);
	
	for(i = 0; i < d->nhijos; i++)
		printvEB(d->atrees[i].dict_child,tabs+1);
	
}
