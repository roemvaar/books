#!/bin/bash

# Write a script with two arguments <file name> and <max_count>
# The script should create a file with <file_name> with each line
# containing count, date and random number, until <max_count> passed
# as argument.
#
# If the arguments are not passed, we have to show and error message
# with usage with the file name
# 
# Usage example: 
# ./random.sh test.txt 3
# 1) 2020-05-08 10:56:54 -> <random_number>
# 2) 2020-05-08 10:56:54 -> <random_number>
# 3) 2020-05-08 10:56:54 -> <random_number>
#
# Linux has a environment variable called RANDOM which gives random
# number between 0 and 32767

COUNT=0

if [ "$#" != 2 ]; then
    echo "Error: Wrong number of arguments"
    echo "Usage example:"
    echo "./random <file_name> <max_count>"
    exit 1
fi

while [ "$COUNT" -le "$2" ]; do
    echo ""$COUNT") "$(date '+%Y-%m-%d %H:%M:%S')" -> $RANDOM"
    COUNT=$((COUNT+1))
done

exit 0

