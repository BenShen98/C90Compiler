#!/bin/bash

rm -f inc_hpp.temp
rm -f inc_make.temp
for file in ast/*.hpp; do
    printf "#include \"%s\"\n" ${file} >> inc_hpp.temp
    printf "%s " ${file} >> inc_make.temp
done