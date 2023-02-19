#!/bin/bash
while :
do
	echo  -e "\nDroPDown Menu\n"
	echo "1.Create Address Book"
	echo "2.Display Address Book"
	echo "3.Insert Record in the Address Book"
	echo "4.Modify a Record in Address Book"
	echo "5.Delete a Record in Address Book"
	echo "6.Exit "
	echo  -e "\nEnter Choice\n" 
	read choice
	case $choice in
		1)
			echo "Enter filename"
			read filename
			touch $filename
			echo "Address Book Created !"
	
	;;
		2)
			echo -e  "\nName\tAddress\tPhone_Number\n"
			cat  $filename
	;;
		3)
		
			echo "Enter Name"
			read name
			echo "Enter Address"
			read address
			echo "Enter Phone Number"
			read phone_number
			
			echo   -e  "$name\t$address\t$phone_number\n"  >> $filename
	;;
	
		
	
		4)
			echo  -e "\nEnter the name to modify a record : \n"
			read name
		        number=`grep -n $name $filename | cut -f1 -d ':' `
		        echo $number
		        echo "What do you want to modify ? "
		    	read modified
			echo "Enter the updated value"
			read value
			sed -i "$number s/$modified/$value/" $filename
			echo Record Modified		
		
	;;
		
		5)
			echo  -e "\nEnter the Name  to delete a record : \n"
			read name
			sed -i "/$name/d" $filename
			echo -e "\nRecord Deleted\n"
	;;
		6)
		exit
	;;
		*)echo "Wrong Choice" 
	;;
	esac


done


