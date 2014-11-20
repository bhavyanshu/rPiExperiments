#What does the above do?

* temp.sh - Bash script to just display output of temp.c to stdout. Does not generate any log file. 
* temp_log.sh - Bash script to generate a log file containing data returned from temp.c. 
* temp.c - Gets the temperature and timestamp. Generates a log file which contains data to be converted by log2json.py into a valid JSON format.
* log2json.py - Converts log file data to a valid JSON output and dumps it to log.json file.

#Usage

Connect your DS18B20 to your raspberry pi. Next download this repository and unzip it. Then,

	cd ./TemperaturePi
	chmod +x *.sh
	
Now run `./temp.sh` or `./temp_log.sh` as per your requirement.

#Purpose?

This program can be used to generate graph from final json data. 

#How? 

Just tie ./temp_log.sh as a cron job and you can specify when you want to run this script. 
You can modify the temp_log.sh and add ftp commands to push latest json file to your hosting service. On your hosting service, use JQuery or anything to generate graph from this json data.

#Limitations?

Currently not suitable for frequent temperature monitoring. You can use temp.sh file for live monitoring as it does not involve any file operation. 
