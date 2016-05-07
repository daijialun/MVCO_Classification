#!/usr/bin/env sh


echo "Create val.txt"
rm -rf val.txt
#rm -rf list.txt

j=0
for dirname in `ls -F | grep /$`
do
   for filename in `find ${dirname} -type f -name '*.png'`
   do
       echo "/${filename}  ${j}" >> val.txt
   done
   j=`expr $j + 1`
done

