#!/usr/bin/env sh

rm -rf train.txt

echo "Create train.txt"
SRC=/deep/DataSet/MVCO_30/all
DST=/deep/DataSet/MVCO_30/train


j=0
for dirname in `ls -F | grep /$`
do
   if [ -d "${DST}/${dirname}" ]; then
	    rm -r ${DST}/${dirname}
	fi
   mkdir ${DST}/${dirname}
   for filename in `find ${dirname} -type f -name '*.png' | head -n 800`
   do
	
        cp ${SRC}/${filename} ${DST}/${dirname}
#	echo "`pwd`/${filename}  ${j}" >> train.txt
   done
#   j=`expr $j + 1`
done

