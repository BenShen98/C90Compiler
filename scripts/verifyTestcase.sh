#!/bin/bash

source scripts/config.sh

rm -rf ${ANSI_BIN}
mkdir ${ANSI_BIN}

FAIL=0;

for i in ${TESTDIRECTORY}/*.c; do
  CASE=${i##*/}
  ${GCC_ANSI} -c ${TESTDRIVER}/${CASE} -o ${ANSI_BIN}/driver.${CASE%.c}.o
  ${GCC_ANSI} -pedantic-errors -pedantic -c ${TESTDIRECTORY}/${CASE} -o ${ANSI_BIN}/${CASE%.c}.o
  ${GCC_ANSI}  ${ANSI_BIN}/${CASE%.c}.o ${ANSI_BIN}/driver.${CASE%.c}.o ${ABI_COMPLIANCE_C} -o ${ANSI_BIN}/${CASE}
  ${ANSI_BIN}/${CASE}
  RETURNCODE=$?
  if [[ ${RETURNCODE} -ne "0" ]]; then
     FAIL=$(( ${FAIL} + 1 ))
     echo "${CASE} failed, get exit code ${RETURNCODE}"
  fi

done

echo "total ${FAIL} failed"

exit ${FAIL}
