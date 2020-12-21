#================================================================
#
#
#   文件名称：stop.sh
#   创 建 者：Ang Wang
#   创建日期：2020年12月17日
#   描    述：
#
#================================================================


#!/bin/sh

#无.pid文件时停掉进程的方法
if false;then
kill -9 `lsof -i :11111 | grep "memcached" | awk '{print $2}'`
if [ $? -eq 0 ];then
	echo "stop ma succeed,port[11111]"
fi

kill -9 `lsof -i :11112 | grep "memcached" | awk '{print $2}'`
if [ $? -eq 0 ];then
	echo "stop ba succeed,port[11112]"
fi
fi

kill -9 `cat /work/test1/wa/ma.pid`
if [ $? -eq 0 ];then
	echo "stop ma succeed,port[11111]"
fi

kill -9 `cat /work/test1/wa/ba.pid`
if [ $? -eq 0 ];then
	echo "stop ba succeed,port[11112]"
fi
