#!/bin/sh

create()
{
    echo "Enter filename:"
		read fname
		if [ -e $fname ] ; then	# -e to check if file exists, if exits remove the file
			echo "File Already Exists!!"
		else
            cont=1
            echo  "NAME   |   NUMBER   |    ADDRESS\n===============================" | cat >> $fname
            while [ "$cont" -gt 0 ]
            do
                echo "\nEnter Name"
                read name
                echo "Enter Phone Number of $name"
                read number
                echo "Enter Address of $name"
                read address
                echo "$name   |   $number   |   $address" | cat >> $fname
                echo "Enter 0 to Stop, 1 to Enter next"
                read cont
            done
        fi    
}

display()
{
    echo "Enter Address Book name: "
    read fname
    if [ -e $fname ] ; then
        cat $fname
    else
        echo "File does not Exist!!"
    fi
}

insert()
{
    echo "Enter Address Book name: "
    read fname
    if [ -e $fname ] ; then
        echo "\nEnter Name"
        read name
        echo "Enter Phone Number of $name"
        read number
        echo "Enter Address of $name"
        read address
        echo "$name   |   $number   |   $address" | cat >> $fname
        echo "Record Inserted!!"
    else
        echo "File does not Exist!!"
    fi
}

delete()
{
    echo "Enter Address Book name: "
    read fname
    if [ -e $fname ] ; then
        echo "Enter Name or Phn number:"
		read del
		temp="temp"
		grep -v "$del" $fname | cat >> $temp 
		rm $fname
		cat $temp | cat >> $fname
		rm $temp
        echo "Record Deleted!!"
    else
        echo "File does not Exist!!"
    fi
}
search()
{
    echo "Enter Address Book name: "
    read fname
    if [ -e $fname ] ; then
        echo "Enter the name or Phn number:"
        read srch
        echo  "NAME       NUMBER       ADDRESS\n==============================="
        grep -i "$srch" $fname
    else
        echo "File does not Exist!!"
    fi
}

modify()
{
    echo "Enter Address Book name: "
    read fname
    if [ -e $fname ] ; then
        echo "Enter name Or Phn number:"
        read mod
        temp="temp"
        grep -v "$mod" $fname | cat >> $temp
        rm $fname
        cat $temp | cat >> $fname
        echo "\nEnter Name"
        read name
        echo "Enter Phone Number of $name"
        read number
        echo "Enter Address of $name"
        read address
        echo "$name   |   $number   |   $address" | cat >> $fname
        echo "Record Modified!!"
    else
        echo "File does not Exist!!"
    fi
}

#main

while [ true ]
do
    echo "Write shell script for address book manipulation"
    echo "1.Create Address Book"
    echo "2.Display Address Book"
    echo "3.Insert Record"
    echo "4.Delete Record"
    echo "5.Modify Record"
    echo "6.Search Record"
    echo "7.Exit"
    echo "Enter the choice:"
    read ch

    case $ch in
    1) create ;;
    2) display ;;
    3) insert ;;
    4) delete ;;
    5) modify ;;
    6) search ;;
    7) exit ;;

    esac
done