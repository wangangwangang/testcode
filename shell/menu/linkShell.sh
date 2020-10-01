#!/bin/bash
#add by wanga 20191030
#function:功能脚本执行控制

path="/home/yisheng/wanga/test/testcode/shell"
#脚本列表配置文件
LIST="$path/menu/shell.list"

#定义功能函数----------------------------------------begin-----------------------------------------------

#列表打印函数
list()
{
	clear
		listNum=0
	echo "----------------------菜单信息提示栏----------------------"
	grep "^\[" $LIST | while read line
	do
		shell_Name=`echo $line | awk -F [ '{print $2}'`
		listNum=`expr $listNum + 1`
		printf "%3d)%s\n" $listNum "$shell_Name"
	done
	echo "000)退出"
	read -p "please input num:" num
}

#执行完选项后提示返回菜单并做停顿
back_reminder()
{
	echo "press anykey to continue"
	read time
	unset time
}

#定义功能函数---------------------------------------end----------------------------------------------

#脚本核心部分------------------------------------begin----------------------------

list

while [ true ]
do
	case $num in
		000)
			exit;;
		*)
			listNum=0
			grep '^\[' $LIST | while read line
			do
				listNum=`expr $listNum + 1`
				if [ $listNum -ge $num ];then
					shell=`echo $line | awk '{print $NF}'`
					echo $shell
					/bin/bash $shell
					exit
				fi
			done
			back_reminder
			list
			;;
	esac
done

#脚本核心部分-----------------end----------------------------------



































