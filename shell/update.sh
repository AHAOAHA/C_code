#!/bin/bash
##################################################
# Copyright(C) 2016-2019. All right reserved.
# 
# Filename: x.sh
# Author: ahaoozhang
# Date: 2019-08-29 22:25:10 (星期四)
# Describe: 
##################################################

# 备份原文
cd $PWD/source/_posts
git add -A
git commit -m "`date`"
git push -u origin master

# 备份主题文件，配置文件
cp -rf $PWD/themes/next $PWD/../Tmp/next_theme_config_bak/next.`date "+%Y/%m/%d-%H:%M:%S"`
cp -f $PWD/_config.yml $PWD/../Tmp/next_theme_config_bak/_config.yml.`date "+%Y/%m/%d-%H:%M:%S"`
git add -A
git commit -m "`date`"
git push -u origin master

# 生成页面,部署
hexo clean
hexo g
#hexo s
hexo d