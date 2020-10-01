#!/bin/bash
#added by wangang 20191226
#function:删除多余文件

FULLBACK="<mypath>/backup/fullBackup"
ADDBACK="<mypath>/backup/addBackup"
FILE="<mypath>/backup/diffFile/diffFile"
LOG="<mypath>/backup/log"

rm -rf $FULLBACK/* $ADDBACK/* $FILE $LOG/*
