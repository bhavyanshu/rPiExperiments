#!/usr/bin/env python

# Copyright 2014 - Bhavyanshu Parasher
# No restriction on distribution/modification of the source
# Info - This program is for PIR sensor. Contionusly checks for state, 
#        set LED if movement detected and plays wav file on detection.

import RPi.GPIO as GPIO
import time
import pygame

pygame.mixer.init()
pygame.mixer.music.load("beep.wav")

PIR = 7		# On-board pin number 7 (GPIO04)
LED = 11	# On-board pin number 11 (GPIO17)

state = False
val = False

GPIO.setmode(GPIO.BOARD)	# Change this if using GPIO numbering
GPIO.setup(PIR, GPIO.IN)	# Set PIR as input
GPIO.setup(LED, GPIO.OUT)	# Set LED as output
 
try:
	while True:
		val = GPIO.input(PIR)            # read input value
		if (val == True):                # check if the input is HIGH
			GPIO.output(LED, True)          # turn LED ON
			if (state == False):
				# ON
				pygame.mixer.music.play()
				state = True
		else:
			GPIO.output(LED, False)         # turn LED OFF
			if (state == True):
				# OFF
				time.sleep(2)
				state = False;
except KeyboardInterrupt:
	GPIO.cleanup()