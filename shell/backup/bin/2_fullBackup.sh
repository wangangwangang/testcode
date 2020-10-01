#!/bin/bash
#added by wanga 20191226
#function:全量备份（去除某些文件）

path="/home/yisheng/wanga/test/testcode/shell/bachup"
DATE=`date +%Y%m%d%s` 
TAR="$path/tar"
FULLBACK="$path/fullBackup"
EXCLUDE="--exclude $TAR/tar2  --exclude $TAR/tar3"
LOG="$path/log/$DATE.log"


#定义日志打印函数
echo_log()
{

	echo "$DATE[info]:$@" | tee -a $LOG
} 

echo_log "-------------------------tar begin-------------------------------"

tar -zvcf $FULLBACK/fullback_$DATE.tar.gz $TAR $EXCLUDE | tee -a $LOG 2>&1

if [ $? -eq 0 ];then
	echo_log "---------------tar end---------------------"
	echo 0
else
	echo_log "---------------tar failed------------------"
	echo 1
fi
