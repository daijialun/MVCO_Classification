#!/usr/bin/env sh

rm -rf val.txt

echo "Create val.txt"
SRC=/deep/DataSet/MVCO_30/all
DST=/deep/DataSet/MVCO_30/val


j=0
for dirname in `ls -F | grep /$`
do
   if [ -d "${DST}/${dirname}" ]; then
	    rm -r ${DST}/${dirname}
	fi
   mkdir ${DST}/${dirname}
   for filename in `find ${dirname} -type f -name '*.png' | tail -n 200`
   do
	
        cp ${SRC}/${filename} ${DST}/${dirname}
#	echo "`pwd`/${filename}  ${j}" >> train.txt
   done
#   j=`expr $j + 1`
done

