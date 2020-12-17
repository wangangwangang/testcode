#================================================================
#
#
#   文件名称：stop.sh
#   创 建 者：Ang Wang
#   创建日期：2020年12月17日
#   描    述：如果-P参数启动memcached时无法创建.pid文件时，可以用这种办法结束进程
#
#================================================================


#!/bin/sh

kill -9 `lsof -i :11111 | grep "memcached" | awk '{print $2}'`
if [ $? -eq 0 ];then
	echo "stop ma succeed,port[11111]"
fi

kill -9 `lsof -i :11112 | grep "memcached" | awk '{print $2}'`
if [ $? -eq 0 ];then
	echo "stop ba succeed,port[11112]"
fi
