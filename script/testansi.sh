#!/bin/bash

source script/config.sh

rm -rf ${ANSI_BIN}
mkdir ${ANSI_BIN}


for i in ${TESTDIRECTORY}/*.c; do
  CASE=${i##*/}
  ${GCC_ANSI} -c ${TESTDRIVER}/${CASE} -o ${ANSI_BIN}/driver.${CASE%.c}.o
  ${GCC_ANSI} -pedantic-errors -c ${TESTDIRECTORY}/${CASE} -o ${ANSI_BIN}/${CASE%.c}.o
  ${GCC_ANSI} ${ANSI_BIN}/driver.${CASE%.c}.o ${ANSI_BIN}/${CASE%.c}.o -o ${ANSI_BIN}/${CASE%.c}

done
