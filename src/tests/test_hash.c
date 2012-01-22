#include <stdlib.h>
#include <stdio.h>
#include "../structures/dictionary.h"

//~ gcc -o thash test_hash.c ../structures/hash_table.c -D_HASH_TABLE -lm

void printList(struct node *n){
	
	if(n == NULL)
		printf("NULL\n");
	else{	
		printf("key %d, value %d ->", n->key, n->value);
		printList(n->right);
	}
	
	
}

void printHash(struct dictionary *d){
	int i;	
		
	for(i = 0; i < d->size; i++)
		if(d->slots[i].first != NULL)
			printList(d->slots[i].first);
	
}


int main(){

	struct dictionary *d;
	int i;
	d = dict_new(1,0);
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
	
	printf("new\n");
	
	//~ printHash(d);
		
	for(i = 0; i < 7; i++){
		//~ printf("Inserting %d...\n",nums[i]);
		dict_set(d,keys[i],nums[i]);
		//~ printHash(d);
	}
	
	printHash(d);
	
	dict_set(d,2,8);
	printf("set key 2 con 8\n");
	printf("get key 2 = %d\n",dict_get(d,2));
	
	printf("delete key 2\n");
	dict_delete(d,2);
	printHash(d);
	
	printf("delete key 9\n");
	dict_delete(d,9);
	printHash(d);
	
	dict_free(d);


}
