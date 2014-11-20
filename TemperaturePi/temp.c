/**
 * Copyright (c) 2014 Bhavyanshu Parasher - No restriction on the distribution/modification of this file.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>
#include <errno.h>
#include <math.h>
#include <time.h>

double readTemp(const char*);

int main(int argc, char *argv[])
{
	const char *devicepath;
	double t;
	if(argc==1)
	{
		printf("You cannot directly run this. Please run tem.sh. Example, chmod +x tem.sh | ./tem.sh\n");
		exit(0);
	}
	else
	{
		devicepath = argv[1]; //Get device file path from argument passed by bash script
	}
	t = readTemp(devicepath);
	printf("{ 'Temperature' : %.3lf , 'Time' : %d }\n",t,(int)time(NULL));
	return 0;
}

double readTemp(const char *path)
{
	FILE *device = fopen(path, "r");
	double temperature = -1;
	char crcVar[5];
	if (device == NULL)
	{
		printf("Check connections %s\n", path);
		perror("\n");
	}
	if (device != NULL)
	{
		if (!ferror(device))
		{
			fscanf(device, "%*x %*x %*x %*x %*x %*x %*x %*x %*x : crc=%*x %s", crcVar);
			if (strncmp(crcVar, "YES", 3) == 0)
			{
				fscanf(device, "%*x %*x %*x %*x %*x %*x %*x %*x %*x t=%lf", &temperature);
				//printf("%.3lf\n",temperature);
				temperature /= 1000.0;
			}
		}
	}
	fclose(device);
	return temperature;
}