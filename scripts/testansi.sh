#!/bin/bash

source scripts/config.sh

rm -rf ${ANSI_BIN}
mkdir ${ANSI_BIN}

FAIL=0;

for i in ${TESTDIRECTORY}/*.c; do
  CASE=${i##*/}
  ${GCC_ANSI} -c ${TESTDRIVER}/${CASE} -o ${ANSI_BIN}/driver.${CASE%.c}.o
  FAIL=$((${FAIL}+$?))
  ${GCC_ANSI} -pedantic-errors -pedantic -c ${TESTDIRECTORY}/${CASE} -o ${ANSI_BIN}/${CASE%.c}.o
  FAIL=$((${FAIL}+$?))

done

exit ${FAIL}
