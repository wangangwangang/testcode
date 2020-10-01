#!/bin/bash
#added by wangang 20191030
#function:test select_case

PS3="please input a number:"
list()
{
	clear
	echo "-----------菜单栏-----------"
	echo "1)apache"
	echo "2)mysql"
	echo "3)php"
	echo "4)back"
}

back_reminder()
{
	echo "press anykey to continue"
	read time
	unset time
}

select i in "apache" "mysql" "php" "back"
do 
	case $i in
		apache)
			echo "apache..."
			back_reminder
			list
			;;
		mysql)
			echo "apache..."
			back_reminder
			list
			;;
		php)
			echo "php..."
			back_reminder
			list
			;;
		back)
			exit
			;;
		*)
			echo "Usage:[1 2 3 4]"
			back_reminder
			list
			;;
	esac
done