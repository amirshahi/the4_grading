#!/bin/bash
filename="IDs.txt"
> out.txt
while read -r line
do
	ID="$line"
	echo $ID
	FILE=../ap$ID/the4/msort_pth.c
	if [ ! -f "$FILE" ]
	then
		echo -e "$ID The file doesn't exist\r\n" >> out.txt
	else
		echo -e "\r\n$ID :">> out.txt
		cp $FILE .
		gcc -O2 msort_pth.c msort_pth_test.c -pthread -lm
		echo -e "M20 K1 :" >> out.txt
		./a.out 20 1  >> out.txt

		echo -e "M20 K5 :" >> out.txt
		./a.out 20 5 >> out.txt

		echo -e "M27 K2 :" >> out.txt
		/usr/bin/time -v ./a.out 27 2  2>&1 | grep -e 'OK' -e 'ERROR' -e 'Maximum' -e 'Runtime' >> out.txt
	
		echo -e "M28 K2 :" >> out.txt
		/usr/bin/time -v ./a.out 28 2  2>&1 | grep -e 'OK' -e 'ERROR' -e 'Maximum' -e 'Runtime' >> out.txt
		rm a.out	

		rm msort_pth.c
	fi

done < "$filename"

