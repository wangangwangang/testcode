#!/bin/bash
#added by wangang 20191226
#function:增量备份（去除某些文件）

DATE=`date +%Y%m%d`
TAR=`<mypath>/backup/tar`
ADDBACK="<mypath>/backup/addBackup"
FILE="<mypath>/backup/diffFile/diffFile"
EXCLUDE="--exclude $TAR/tar2 --exclude $TAR/tar3"
LOG="<mypath>/backup/log/$DATE.log"

echo "$DATE[info]:-----------------tar begin-----------------------" | tee -a $LOG
tar -g $FILE -zvcf $ADDBACK/addback_$DATE.tar.gz $TAR $EXCLUDE | tee -a $LOG 2>&1

if [ $? -eq 0 ];then
	echo "$DATE[info]:-------------------tar end-------------------------" | tee -a $LOG
	exit 0
else
	echo "$DATE[info]:-------------------tar failed----------------------" | tee -a $LOG
	exit 1
fi
