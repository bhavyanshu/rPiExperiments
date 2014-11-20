# Copyright (c) 2014 Bhavyanshu Parasher - No restriction on the distribution/modification of this file.
#!/bin/bash
sudo modprobe w1-gpio
sudo modprobe w1-therm

base_dir="/sys/bus/w1/devices/28-*/"
temp_dev="w1_slave"
dev=$base_dir$temp_dev

gcc -O3 -fPIC -g -Wall -Werror temp.c -o temp

echo `./temp $dev` >> log;

if [ $? -eq 0 ]; then
    echo `python log2json.py`;
else
    echo FAIL
fi