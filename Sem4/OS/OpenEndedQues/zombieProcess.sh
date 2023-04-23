#!/bin/bash

echo "Parent process $$"

# Create a child process
( sleep 60 ) &

# Print the child process PID
echo "Child process $!"

# Wait for the child process to complete
sleep 5

# Print the process table
echo "Process table:"
ps aux | grep "bash\|sleep"

