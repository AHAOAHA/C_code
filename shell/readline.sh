#/bin/bash

count=0
cat test.txt | while read line
do
	echo $count
	result=`echo $line | grep localhost`
	if [ "$result" != "" ]
	then
		count=`expr $count + 1`
	fi
done

echo $count
