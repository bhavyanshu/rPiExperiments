#!/bin/bash
sudo modprobe w1-gpio
sudo modprobe w1-therm

base_dir="/sys/bus/w1/devices/28-*/"
temp_dev="w1_slave"
dev=$base_dir$temp_dev

gcc -O3 -fPIC -g -Wall -Werror temp.c -o temp

while true; do echo `./temp $dev` >> log ; sleep 1; done