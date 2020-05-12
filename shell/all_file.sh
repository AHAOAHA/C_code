#!/bin/bash
##################################################################
# Copyright(C) 2020-2020. All right reserved.
# 
# Filename: all_file.sh
# Author: ahaoozhang
# Date: 2020-05-12 23:33:50 (Tuesday)
# Describe: 
##################################################################
count=0
files=`find $1 -type f`
for file in ${files[@]}
do
    file_count=`cat ${file} | wc -l`
    let count=$count+$file_count
done

echo "count: $count"
