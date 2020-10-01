#!/bin/bash
#added by wangang 20191105
#auto test 实现指定目录下文件一周一次全量备份，一天一次增量备份时

path="/home/yisheng/wanga/test/testcode/shell/backup"
week=`date +%u`
DATE=`date +%Y%m%d`
TAR="$path/tar" 
FULLBACK="$path/fullBackup" 
ADDBACK="$path/addBackup"
FILE="$path/diffFile/diffFile"

#判断是否有参数传入
if [ ! -z $1 ];then
	DATE=$1
fi

if [ $week -eq 7 ];then
	rm -rf $FILE
	tar -g $FILE -zvcf $FULLBACK/fullBack_$DATE.tar.gz $TAR
else
	if [ -e $FILE ];then
		tar -g $FILE -zvcf $ADDBACK/addBack_$DATE.tar.gz $TAR
	else
		tar -g $FILE -zvcf $FULLBACK/fullBack_$DATE.tar.gz $TAR
	fi
fi

