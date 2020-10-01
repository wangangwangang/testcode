#!/bin/bash
#added by wangang 201941030
#function:test while_case

list()
{
	clear
	echo "-----------菜单栏-----------"
	echo "1)apache"
	echo "2)mysql"
	echo "3)php"
	echo "4)back"
	read -p "please input num:" num
}

back_reminder()
{
	echo "press anykey to continue"
	read time
	unset time
}

list

while [ true ]
do
	case $num in
		1)
			echo "apache..."
			back_reminder
			list
			;;
		2)
			echo "mysql..."
			back_reminder
			list
			;;
		3)
			echo "php..."
			back_reminder
			list
			;;
		4)
			exit
			;;
		*)
			echo "input word error..."
			back_reminder
			list
			;;
	esac
done
	