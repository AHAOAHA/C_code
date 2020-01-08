#!/bin/bash
##################################################
# Copyright(C) 2016-2019. All right reserved.
# 
# Filename: fire.sh
# Author: ahaoozhang
# Date: 2019-08-07 21:02:25 (星期三)
# Describe: 火焰图
##################################################

# 第一个参数代表进程pid
pid=${1}

# 第二个表示采样频率
fre=${2}

# 第三个表示监控时长
dur=${3}

sudo perf record -F ${fre} -p ${pid} -g -o ~/tmp/fire/in-fb.data -- sleep ${dur}

sudo perf script -i ~/tmp/fire/in-fb.data > ~/tmp/fire/in-fb.perf

stackcollapse-perf.pl ~/tmp/fire/in-fb.perf > ~/tmp/fire/in-fb.folded

flamegraph.pl ~/tmp/fire/in-fb.folded > ~/tmp/fire/in-fb-cpu.svg

rm -f ~/tmp/fire/in-fb.data

rm -f ~/tmp/fire/in-fb.perf

rm -f ~/tmp/fire/in-fb.folded

