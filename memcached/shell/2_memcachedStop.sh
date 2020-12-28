#!/bin/bash
#added by wangang 20191227
#function:stop memcached

kill -9 `cat <mypath>/memcached/memcached.ma.pid`
if [ $? -ne 0 ];then
	echo "stop main memcached failed!"
else 
	echo "stop main memcached succeed!"
fi

kill -9 `cat <mypath>/memcached/memcached.ba.pid`
if [ $? -ne 0 ];then
	echo "stop ba memcached failed!"
else 
	echo "stop ba memcached succeed!"
fi

