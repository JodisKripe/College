Sure! Here's a simple program in C that demonstrates a zombie process:

c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process is running\n");
        sleep(5);
        printf("Child process is exiting\n");
        exit(0);
    } else if (pid > 0) {
        // Parent process
        printf("Parent process is running\n");
        sleep(10);
        printf("Parent process is exiting\n");
    } else {
        // Error
        printf("Fork failed\n");
        exit(1);
    }

    return 0;
}

This program forks a child process, which prints a message to the console, sleeps for 5 seconds, and then exits. The parent process also prints a message to the console, sleeps for 10 seconds, and then exits.

If you run this program, you should see the following output:

arduino

Child process is running
Parent process is running
Child process is exiting

After 5 seconds, the child process exits, but its process table entry remains in the system's process table as a zombie process, as its parent process has not yet called wait() to collect its exit status. After 10 seconds, the parent process also exits.

To confirm that a zombie process was created, you can use the ps command in a separate terminal window to view the system's process table:

perl

$ ps aux | grep 'Z'

This command should show a process with a status of Z, indicating a zombie process.

To avoid zombie processes, the parent process should call the wait() system call to collect its child process's exit status. You can modify the program to do this by adding the following line before the parent process exits:

c

wait(NULL);

This tells the parent process to wait for its child process to exit and collect its exit status. If you run the modified program, you should not see any zombie processes in the system's process table.
