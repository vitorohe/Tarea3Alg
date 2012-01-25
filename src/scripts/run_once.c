#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "../structures/dictionary.h"

#define timespec_diff_ns(timeA_p, timeB_p) ((timeA_p.tv_sec - timeB_p.tv_sec)*1000000000 + (timeA_p.tv_nsec - timeB_p.tv_nsec))

#define timespec_diff_ms(timeA_p, timeB_p) ((timeA_p.tv_sec - timeB_p.tv_sec)*1000 + (timeA_p.tv_nsec - timeB_p.tv_nsec)/1000000)

unsigned int *load_file_into_array(char *filename, off_t n_elems) {
    unsigned int *elems;
    int idx, ret;
    FILE *file;

    elems = (unsigned int *)malloc(n_elems * sizeof(unsigned int));
    
    file = fopen(filename, "rb");

    idx = 0;

    while ((ret = fread(elems + idx, sizeof(unsigned int), n_elems - idx, file)) > 0 && (n_elems - idx) > 0) idx += ret;
   
    fclose(file);

    return elems;
}

int main(int argc, char **argv) {
    unsigned int exp_universe, exp_n, n, k, i, j, m, repeats, sorted;
    struct dictionary *dict;
    unsigned int *inserts, *deletes, *finds;
    struct timespec before, after;

    int ins_idx, del_idx, find_idx;

    if (argc < 5) {
        printf("Usage : run_once exp_n k exp_universe repetitions\n");
        exit(1);
    }

    exp_universe = atoi(argv[3]); 
    k = atoi(argv[2]); 
    exp_n = atoi(argv[1]); 
    repeats = atoi(argv[4]);
    n = 1 << exp_n;

    inserts = load_file_into_array("insertions", 3 * k * n);
    deletes = load_file_into_array("deletions", 3 * k * n);
    finds = load_file_into_array("finds", k * n);

    dict = dict_new(k * n, exp_universe);

    for (m = 0; m < repeats; m++) {
    ins_idx = del_idx = find_idx = 0;

    clock_gettime(CLOCK_MONOTONIC, &before);
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) dict_set(dict, inserts[ins_idx++], i);
        for (j = 0; j < k; j++) dict_delete(dict, deletes[del_idx++]);
        for (j = 0; j < k; j++) dict_set(dict, inserts[ins_idx++], i);
    }
    clock_gettime(CLOCK_MONOTONIC, &after);

    if (exp_universe > 20) {
        printf("idi: %lldms\t", timespec_diff_ms(after, before));
    } else {
        printf("idi: %lldns\t", timespec_diff_ns(after, before));
    }

    clock_gettime(CLOCK_MONOTONIC, &before);
    for (find_idx = 0; find_idx < k * n; find_idx++) {
        dict_get(dict, finds[find_idx]);
    }
    clock_gettime(CLOCK_MONOTONIC, &after);

    if (exp_universe > 20) {
        printf("f: %lldms\t", timespec_diff_ms(after, before));
    } else {
        printf("f: %lldns\t", timespec_diff_ns(after, before));
    }

    clock_gettime(CLOCK_MONOTONIC, &before);
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) dict_delete(dict, deletes[del_idx++]);
        for (j = 0; j < k; j++) dict_set(dict, inserts[ins_idx++], i);
        for (j = 0; j < k; j++) dict_delete(dict, deletes[del_idx++]);
    }
    clock_gettime(CLOCK_MONOTONIC, &after);
 
    if (exp_universe > 20) {
        printf("did: %lldms\t\n", timespec_diff_ms(after, before));
    } else {
        printf("did: %lldns\t\n", timespec_diff_ns(after, before));
    }

    }
    free(inserts);
    free(deletes);
    free(finds);
    dict_free(dict);
    exit(0);
}



