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

memcached -d -m 128 -u wanga -p 11111 -P `pwd`/ma.pid		#-P后必须是绝对路径，相对路径不可以
if [ $? -eq 0 ];then
	echo "start ma succeed,port:[11111]"
fi

memcached -d -m 128 -u wanga -p 11112 -P `pwd`/ba.pid
if [ $? -eq 0 ];then
	echo "start ba succeed,port:[11112]"
fi
