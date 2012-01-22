#include <stdlib.h>
#include <stdio.h>
#include "../structures/dictionary.h"
#define DEFAULT_N 20

int main(int argc, char **argv) {
    int n_elems, aux, i;
    struct dictionary *dict;
    int *elems;
    if (argc < 2) {
        n_elems = DEFAULT_N;
    } else {
        n_elems = atoi(argv[1]);
    } 

    elems = (int *)malloc(sizeof(int) * n_elems);
    dict = dict_new(n_elems, 7);

    for (i = 0; i < n_elems; i++) {
        aux = random() % 100;
        elems[i] = aux;
        printf("Inserting %d -> %d...\n", aux, i);
        dict_set(dict, aux, i);   
    }

    for (i = 0; i < n_elems; i++) {
        aux = dict_get(dict, elems[i]);
        printf("Extracted: %d -> %d \n", elems[i], aux);
    }

    for (i = n_elems - 1; i >= 0; i--) {
        aux = dict_get(dict, elems[i]);
        printf("Extracted: %d -> %d \n", elems[i], aux);
    }

    dict_free(dict);
}

