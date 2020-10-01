#!/bin/bash
#added by wangang 20191227
#function:start memcached 

memcached -d -m 1024 -p 11211 <mypath>/memcached/memcached.ma.pid
if [ $? -ne 0 ];then
	echo "start main memcached failed!"
else
	echo "start main memcached succeed!"
fi

memcached -d -m 1024 -p 11210 <mypath>/memcached/memcached.ba.pid
if [ $? -ne 0 ];then
	echo "start ba memcached failed!"
else
	echo "start ba memcached succeed!"
fi