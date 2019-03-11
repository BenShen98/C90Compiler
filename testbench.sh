#!/bin/bash

chmod u+x c_translator_formative.sh
fail=0

./c_translator_formative.sh
fail=$?

echo "*************TESTING STATS************"
echo " Failed ${fail} C2Python tests"
echo "*************END of test**************"

exit ${fail}
