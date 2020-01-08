#!/bin/bash

str="ahaoozhang"

ret=`echo $str | grep oo`
echo "exit ret: "${ret}

ret=`echo $str | grep ood`
echo "not exit ret: "${ret}
