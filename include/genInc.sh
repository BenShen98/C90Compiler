#!/bin/bash

rm -f inc.temp
for file in ast/*.hpp; do
    printf "#include \"%s\"\n" ${file} >> inc.temp
done