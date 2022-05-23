#!/bin/sh
PATH="/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin"
while [ 1 ]
do
accel_x=$(cat /sys/class/i2c-dev/i2c-0/device/0-0068/iio\:device2/in_accel_x_raw)
accel_y=$(cat /sys/class/i2c-dev/i2c-0/device/0-0068/iio\:device2/in_accel_y_raw)
accel_z=$(cat /sys/class/i2c-dev/i2c-0/device/0-0068/iio\:device2/in_accel_z_raw)

anglvel_x=$(cat /sys/class/i2c-dev/i2c-0/device/0-0068/iio\:device2/in_anglvel_x_raw)
anglvel_y=$(cat /sys/class/i2c-dev/i2c-0/device/0-0068/iio\:device2/in_anglvel_y_raw)
anglvel_z=$(cat /sys/class/i2c-dev/i2c-0/device/0-0068/iio\:device2/in_anglvel_z_raw)
echo " mpu6050 test"

echo "accel_x = $accel_x"
echo "accel_y = $accel_y"
echo "accel_z = $accel_z"
echo "anglvel_x = $anglvel_x"
echo "anglvel_y = $anglvel_y"
echo "anglvel_z = $anglvel_z"
sleep 1
done

