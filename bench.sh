#!/bin/bash
${1} 2> ${2}
for i in {2..100}
do
   ${1} 2>> ${2}
done