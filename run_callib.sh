#!/bin/bash

N_INSTANCES=$1
COUNT=0

if [ ! $N_INSTANCES ]; then
    printf "The number of instances must be provided!\n"
    printf "Try: ./run_p2 <number-of-instances>\n"
    exit 1
fi

if [ ! -f cpu_burn ]; then
    printf "Exec not found! Compiling from source...\n"
    ./compile.sh
fi

>&2 printf "Launching ${N_INSTANCES} instance(s)...\n\n"

while [ ${N_INSTANCES} -ne $COUNT ]
do
    ./cpu_burn
    COUNT=$((COUNT+1))
done

wait # Wait for child process ending.
