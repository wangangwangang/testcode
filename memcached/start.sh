#================================================================
#
#
#   文件名称：start.sh
#   创 建 者：Ang Wang
#   创建日期：2020年12月17日
#   描    述：
#
#================================================================


#!/bin/sh

memcached -d -m 128 -u wanga -p 11111 -P ./ma.pid
if [ $? -eq 0 ];then
	echo "start ma succeed,port:[11111]"
fi

memcached -d -m 128 -u wanga -p 11112 -P ./ba.pid
if [ $? -eq 0 ];then
	echo "start ba succeed,port[11112]"
fi
