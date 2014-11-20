##Overview

These are C and Python implementation for PIR sensor. It polls the sensor and if any movement is detected, it turns the LED on and plays a .wav file.

##How to run it?

**For Python implementation**          

* Just run `sudo python pir.py` in terminal. Ctrl+C to gracefully exit.

**For C implementation**

* The C implementation depends on [bcm2835 library](http://www.airspayce.com/mikem/bcm2835/).

You will have to install the library manually using

	wget http://www.open.com.au/mikem/bcm2835/bcm2835-1.5.tar.gz
	tar zxvf bcm2835-1.5.tar.gz
	cd bcm2835-1.5
	./configure
	make
	sudo make check
	sudo make install

and then compile the pir.c using      

	gcc pir.c -o pir -l bcm2835
