#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 512

unsigned int buf[BUF_SIZE];

void create_random_array(unsigned int *arr, int universe, off_t n_elems);
void save_array_to_file(unsigned int *array, const char *filename, off_t size);
void swap(unsigned int *array, int i1, int i2);

int int_cmp(const void *a, const void *b) {

    const unsigned int *ia = (const unsigned int *)a; // casting pointer types 
    const unsigned int *ib = (const unsigned int *)b;
    if (*ia == *ib) {
        return 0;
    } else if (*ia < *ib) {
        return -1;
    } else {
        return 1;
    }
}

void semisort(unsigned int *elems, unsigned int size) {
    int i1, i2, i, n_swaps;
    unsigned int aux;
    
    n_swaps = size/4;

    srandom(time(NULL));

    for (i = 0; i < n_swaps; i++) {
        i1 = random() % size;
        i2 = random() % size;

        aux = elems[i1];
        elems[i1] = elems[i2];
        elems[i2] = aux;
    }

}

int main(int argc, char **argv) {
    unsigned int *insertions, *deletions, *finds;

    int exp_n, k, universe;
    int i, j;
    int ins_idx, del_idx, find_idx;

    int sorted, chosen;
    off_t n, ins_size, find_size;

    exp_n = atoi(argv[1]);
    k = atoi(argv[2]);
    universe = atoi(argv[3]);

    n = 1 << exp_n;

    ins_size = 3 * k * n;

    find_size =  k * n;

    insertions = (unsigned int *)malloc(sizeof(unsigned int) * ins_size);
    deletions = (unsigned int *)malloc(sizeof(unsigned int) * ins_size);
    finds = (unsigned int *)malloc(sizeof(unsigned int) * find_size);

    //Create 2*3*k*n elements for insertion
    create_random_array(insertions, universe, ins_size);

    sorted = atoi(argv[4]);

    if (sorted == 2 || sorted == 3) {
        qsort(insertions, ins_size, sizeof(unsigned int), int_cmp); 
        semisort(insertions, ins_size);
    }

    save_array_to_file(insertions, "insertions", ins_size);

    ins_idx = del_idx = find_idx = 0;

    for (i = 0; i < n; i++) {
        ins_idx += k;

        for (j = 0; j < k; j++) {
            chosen = (random() % (ins_idx - del_idx)) + del_idx;
            deletions[del_idx] = insertions[chosen];
            swap(insertions, del_idx, chosen);
            del_idx++;
        }

        if (sorted == 2 || sorted == 4) {
            qsort(deletions + del_idx - k, k, sizeof(unsigned int), int_cmp);
            semisort(deletions + del_idx - k, k);
        }

        ins_idx += k;
    }

    create_random_array(finds, universe, find_size / 2);

    for (find_idx = (find_size / 2) + 1; find_idx < find_size; find_idx++) {

        chosen = (random() % (ins_idx - del_idx)) + del_idx;
        finds[find_idx] = insertions[chosen];
        
    }

    save_array_to_file(finds, "finds", find_size);

    for (i = 0; i < n; i++) {

        for (j = 0; j < k; j++) {
            chosen = (random() % (ins_idx - del_idx)) + del_idx;
            deletions[del_idx] = insertions[chosen];
            swap(insertions, del_idx, chosen);
            del_idx++;
        }

        if (sorted == 2 || sorted == 4) {
            qsort(deletions + del_idx - k, k, sizeof(unsigned int), int_cmp);
            semisort(deletions + del_idx - k, k);
        }

        ins_idx += k;

        for (j = 0; j < k; j++) {
            chosen = (random() % (ins_idx - del_idx)) + del_idx;
            deletions[del_idx] = insertions[chosen];
            swap(insertions, del_idx, chosen);
            del_idx++;
        }
 
        if (sorted == 2 || sorted == 4) {
            qsort(deletions + del_idx - k, k, sizeof(unsigned int), int_cmp);
            semisort(deletions + del_idx - k, k);
        }

    }

    save_array_to_file(deletions, "deletions", ins_size);

}

void create_random_array(unsigned int *arr, int universe, off_t n_elems) {
    
    off_t i;
    unsigned int mask;

    mask = ~((~0) << universe);
    
    srandom(time(NULL));

    for (i = 0; i < n_elems; i++) {
        arr[i] = random() & mask;
    }
}

void save_array_to_file(unsigned int *array, const char *filename, off_t size) {
    
    off_t ret, idx;
    int fd;
    char *foo;

    size *= 4;
    fd = open(filename, O_RDWR | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);

    idx = 0;

    foo = (char *) array;

    while ((ret = write(fd, &(foo[idx]), size - idx)) > 0 && (size - idx) > 0) idx += ret;

    close(fd);

}

void swap(unsigned int *array, int i1, int i2) {
    unsigned int aux;

    aux = array[i1];
    array[i1] = array[i2];
    array[i2] = aux;

}
