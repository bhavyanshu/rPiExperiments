# Copyright (c) 2014 Bhavyanshu Parasher - No restriction on the distribution/modification of this file.
#!/usr/bin/python

import json
from ast import literal_eval
with open('log') as f:
    sale = [literal_eval(line) for line in f]
    data = {'Gurgaon': sale}		#Change Gurgaon to your locality name
    #print(data)

with open('log.json', 'w') as outfile:
        json.dump(data, outfile)