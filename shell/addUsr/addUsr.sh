#------------------------
#added by wangang 20200102
#function:本脚本用于批量添加用户
#------------------------

#!/bin/bash

while read line
do 
	username=`echo $line | awk '{print $2}'`
	userpwd=`echo $line | awk '{print $4}'`
	sudo useradd $username
	echo "$userpwd" | passwd --stdin $username
done < userInfo.txt

if [ $? -ne 0 ];then
	echo "add user failed!!!"
	exit 1
else
	echo "add user succeed!!!"
	exit 0
fi
