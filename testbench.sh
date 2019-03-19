#!/bin/bash

chmod u+x c_translator_formative.sh
chmod u+x testmips.sh
fail=0

./c_translator_formative.sh
fail=$?
echo "*************TESTING STATS************"
echo " Failed ${fail} C2Python tests"
echo "*************END of PYTHON**************"

./testmips.sh
fail=$?
echo "*************TESTING STATS************"
echo " Failed ${fail} MIPS tests"
echo "*************END of MIPS**************"
