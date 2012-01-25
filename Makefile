default: all
	
all: run_once_binary run_once_randomized run_once_avl run_once_van_emde run_once_splay run_once_hash run_global
	rm bin/*.o

# ================== Scripts ================== 

# ======== Insertions / Deletions ======== 
run_global: src/scripts/run_global.sh make_instance
	cp src/scripts/run_global.sh bin/run_global.sh

run_once_binary: binary_tree src/scripts/run_once.c src/structures/dictionary.h
	gcc -g bin/binary_tree.o src/scripts/run_once.c -lrt -o bin/run_once_binary

run_once_randomized: randomized_tree src/scripts/run_once.c src/structures/dictionary.h
	gcc -g bin/randomized_tree.o src/scripts/run_once.c -lrt -o bin/run_once_randomized

run_once_avl: avl_tree src/scripts/run_once.c src/structures/dictionary.h
	gcc -g bin/avl_tree.o src/scripts/run_once.c -lrt -o bin/run_once_avl

run_once_van_emde: van_emde src/scripts/run_once.c src/structures/dictionary.h
	gcc -g bin/van_emde.o src/scripts/run_once.c -lm -lrt -o bin/run_once_van_emde

run_once_splay: splay_tree src/scripts/run_once.c src/structures/dictionary.h
	gcc -g bin/splay_tree.o src/scripts/run_once.c  -lrt -o bin/run_once_splay

run_once_hash: hash_table src/scripts/run_once.c src/structures/dictionary.h
	gcc -g bin/hash_table.o src/scripts/run_once.c  -lrt -lm -o bin/run_once_hash

# ================== Utils ================== 

make_instance: src/scripts/make_instance.c
	gcc -g src/scripts/make_instance.c -o bin/make_instance

# ================== Structures ================== 

binary_tree:  src/structures/dictionary.h src/structures/binary_tree.c
	gcc -g -c src/structures/binary_tree.c -o bin/binary_tree.o

randomized_tree:  src/structures/dictionary.h src/structures/randomized_binary_tree.c
	gcc -g -c src/structures/randomized_binary_tree.c -o bin/randomized_tree.o

avl_tree:  src/structures/dictionary.h src/structures/avl.c
	gcc -g -c src/structures/avl.c -o bin/avl_tree.o

van_emde:  src/structures/dictionary.h src/structures/van_emde_boas.c
	gcc -g -c src/structures/van_emde_boas.c -o bin/van_emde.o

splay_tree:  src/structures/dictionary.h src/structures/splay_tree.c
	gcc -g -c src/structures/splay_tree.c -o bin/splay_tree.o

hash_table:  src/structures/dictionary.h src/structures/hash_table.c
	gcc -g -c src/structures/hash_table.c -o bin/hash_table.o

# ================== Cleaning, etc ================== 

clean:
	rm -f `ls -1 bin/* | grep -v 'bin_README\|results'`
