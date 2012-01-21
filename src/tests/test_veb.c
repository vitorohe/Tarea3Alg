#include <stdlib.h>
#include <stdio.h>
#include "../structures/dictionary.h"

//~ gcc -o tveb test_veb.c ../structures/van_emde_boas.c -D_VAN_EMDE_BOAS -lm


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


int main(){

	struct dictionary *d;
	int i;
	d = dict_new(0,4);
	int min;
	int nums[7];
	int keys[7];
	
	keys[0] = 9;
	nums[0] = 14; 
	
	keys[1] = 4;
	nums[1] = 7; 
	
	keys[2] = 12;
	nums[2] = 5; 
	
	keys[3] = 0;
	nums[3] = 15; 
	
	keys[4] = 2;
	nums[4] = 3; 
	
	keys[5] = 14;
	nums[5] = 4; 
	
	keys[6] = 5;
	nums[6] = 2; 
	
	//~ printvEB(d,0);
		
	for(i = 0; i < 7; i++){
		//~ printf("Inserting %d...\n",nums[i]);
		dict_set(d,keys[i],nums[i]);
		//~ printvEB(d,0);
	}
	
	printvEB(d,0);
	
	dict_set(d,9,8);
	printf("set key 9 con 8\n");
	printf("get key 9 = %d\n",dict_get(d,9));
	
	dict_delete(d,9);
	printvEB(d,0);
	
	dict_delete(d,0);
	printvEB(d,0);
	
	dict_free(d);


}
