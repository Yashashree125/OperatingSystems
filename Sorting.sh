#!/bin/bash

while [[ $opt -lt 3 ]]
do
        echo enter the option
        echo "1 Ascending"
        echo "2 Decending"
        echo "3 for exit"
        echo "enter u r choice"
        read opt
ch="$opt"
case "$ch" in

"1")
        if [ "$opt" == "1" ]
                then
                gcc asc.c -o asc222 && ./asc222
                
        fi
;;

"2")
        if [ "$opt" == "2" ]
                then
                gcc desc.c -o desc222 && ./desc222

        fi
;;

"7") exit
;;
*) echo invalid input

esac
done