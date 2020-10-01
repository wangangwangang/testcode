#!/bin/bash
#作用：使用重定向方式实现非交互式ftp获取、推送文件

#设置远程服务器信息
ftpSvrIp=""
ftpUsr="wanga"
ftpPwd="1qaz2wsx"

#设置文件目录
localOutDir="<mypath>/ftp/2"
localInDir="<mypath>/ftp/1"
targetOutDir="<mypath>/ftp/2"
targetInDir="<mypath>/ftp/1"

#设置日志文件
LOG="<mypath>/ftp/ftp/log"

DATE=`date +%Y%m%d %H%M%S`

#ftp获取、推送文件
echo "" | tee -a $LOG
echo "$DATE[info] in $0 [$LINENO],ftp  begin !" | tee -a $LOG
echo "" | tee -a $LOG

ftp -n <<!
open $ftpSvrIp
user $ftpUsr $ftpPwd
binary
lcd  $localInDir
cd $targetOutDir
get file_target
lcd $localOutDir
cd $targetInDir
put file_local
bye
!

echo "" | tee -a $LOG

#判断文件获取是否成功
if [ -e $localGetDir/file1 ];then
	echo "$DATE[info] in $0 [$LINENO],ftp end !" | tee -a $LOG
else
	{
		echo "$DATE[info] in $0 [$LINENO],ftp failed !" | tee -a $LOG
		echo "[FAILED]"
		exit 1
	}
fi






