#!/bin/bash
if [ -e temp.s ]
then
	rm temp.s
fi
if [ -e pa1-3-main.s ]
then
	cat pa1-3-main.s >> temp.s
	if [ -e pa1-3-function.s ]
	then
		cat pa1-3-function.s >> temp.s
		if [ s$1 == sqtspim ]
		then
			qtspim temp.s
		else
			spim -f temp.s
		fi
		rm temp.s
	else
		echo There is no "pa1-3-function.s" file
	fi
else
	echo There is no "pa1-3-main.s" file
fi

