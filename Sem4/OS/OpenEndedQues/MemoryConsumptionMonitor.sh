#!/bin/bash

while true; do
    # Get current memory usage
    mem_used=$(free | awk '/Mem/{printf("%.2f"), $3/$2 * 100}')
    
    # Get current CPU activity
    cpu_activity=$(top -bn1 | grep load | awk '{printf "%.2f%%", $(NF-2)}')
    
    # Get list of top memory-consuming processes
    mem_consumers=$(ps axo pid,rss,comm | sort -nrk 2 | head -n 5 | awk '{printf("%s:%dMB ", $3, $2/1024)}')
    
    # Print memory usage, CPU activity, and top memory-consuming processes
    echo "Memory Usage: $mem_used%"
    echo "CPU Activity: $cpu_activity"
    echo "Top Memory Consumers: $mem_consumers"
    
    # Wait for 1 second before checking again
    sleep 1
    clear
done

