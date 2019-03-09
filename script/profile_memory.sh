#!/bin/bash

echo $1
printf "\n\n######profile for max memory usage #########\n\n"
valgrind --tool=massif --stacks=yes --massif-out-file=./output/mem_profile $1
printf "\n\n######check memory leak#########\n\n"
valgrind --leak-check=full --show-leak-kinds=all $1
grep 'mem_heap' output/mem_profile | sort -t= -nr -k2 | head -1
grep 'mem_stack' output/mem_profile | sort -t= -nr -k2 | head -1


