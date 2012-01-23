#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	struct dictionary *dict;
	int i;
	int keys[10] = {5 ,3, 6, 2, 1, 7, 4, 8, 10, 9};
	int values[10] = {5 ,3, 6, 2, 1, 7, 4, 8, 10, 9};
	dict = dict_new(10,10);

	for(i = 0; i < 10; i++){
		dict_set(dict,keys[i],values[i]);
	}
	tree_print(dict->root,0); 
	for(i = 0; i < 10; i++){
		tree_print(dict->root,0);
		printf("deleting %d\n",keys[i]);  
		dict_delete(dict,keys[i]);
	}
	tree_print(dict->root,0);
	dict_free(dict);
}
