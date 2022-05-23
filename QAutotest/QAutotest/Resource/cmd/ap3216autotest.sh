#!/bin/sh
PATH="/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin"
while [ 1 ]
do
als=$(cat /sys/class/misc/ap3216c/als)
ir=$(cat /sys/class/misc/ap3216c/ir)
ps=$(cat /sys/class/misc/ap3216c/ps)
echo " ap3216 测试"

echo "光强:      $als"
echo "红外:      $ir"
echo "接近:      $ps"
sleep 1
done
