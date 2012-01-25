#!/bin/bash

set -e
set -u

rm -f ./insertions ./deletions ./finds

exp_universe=16
exp_n=11
file=results/small_universe

echo "Small universe..."

for sorted in 1 2 3 4
do
    for k in 1 3 7
    do
        for m in {1..10}
        do
            echo "Testing big universe, k=$k, run $m, sorted=$sorted" 
            echo "Testing big universe, k=$k, run $m, sorted=$sorted" >> $file
            ./make_instance $exp_n $k $exp_universe $sorted

            echo "Binary Tree:" >> $file
            ./run_once_binary $exp_n $k $exp_universe 5 >> $file
            echo >> $file

            echo "Randomized Binary Tree:" >> $file
            ./run_once_randomized $exp_n $k $exp_universe 5 >> $file
            echo >> $file

            echo "AVL Tree:" >> $file
            ./run_once_avl $exp_n $k $exp_universe 5 >> $file
            echo >> $file

            echo "Van Emde Boas Tree:" >> $file
            ./run_once_van_emde $exp_n $k $exp_universe 5 >> $file
            echo >> $file

            echo "Splay Tree:" >> $file
            ./run_once_splay $exp_n $k $exp_universe 5 >> $file
            echo >> $file

            echo "Hash Table:" >> $file
            ./run_once_hash $exp_n $k $exp_universe 5 >> $file
            echo >> $file

            rm ./insertions ./deletions ./finds
        done
    done
done

exp_universe=24
exp_n=19
file=results/big_universe

echo "Big universe"

for sorted in 1 2 3 4
do
    for k in 1 3 7
    do
        for m in {1..5}
        do
            echo "Testing small universe, k=$k, run $m, sorted=$sorted" >> $file
            ./make_instance $exp_n $k $exp_universe $sorted

            echo "Binary Tree:" >> $file
            ./run_once_binary $exp_n $k $exp_universe 5 >> $file
            echo >> $file

            echo "Randomized Binary Tree:" >> $file
            ./run_once_randomized $exp_n $k $exp_universe 5 >> $file
            echo >> $file

            echo "AVL Tree:" >> $file
            ./run_once_avl $exp_n $k $exp_universe 5 >> $file
            echo >> $file

            echo "Van Emde Boas Tree:" >> $file
            ./run_once_van_emde $exp_n $k $exp_universe 5 >> $file
            echo >> $file

            echo "Splay Tree:" >> $file
            ./run_once_splay $exp_n $k $exp_universe 5 >> $file
            echo >> $file

            echo "Hash Table:" >> $file
            ./run_once_hash $exp_n $k $exp_universe 5 >> $file
            echo >> $file

            rm ./insertions ./deletions ./finds

        done
    done
done
