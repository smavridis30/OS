#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler for the child process
void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        printf("Child process: Received SIGUSR1 signal from parent.\n");
    }
}

int main() {
    pid_t pid;

    // Fork to create a child process
    pid = fork();

    if (pid == -1) { // Error in fork
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        // Register signal handler for SIGUSR1
        if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
            perror("signal");
            exit(EXIT_FAILURE);
        }

        printf("Child process: Waiting for signal...\n");

        // Infinite loop to keep the child alive for signal handling
        while (1) {
            pause(); // Wait for a signal
        }

    } else { // Parent process
        printf("Parent process: Sending SIGUSR1 signal to child (PID = %d).\n", pid);

        // Sleep for 2 seconds to ensure child is ready
        sleep(2);

        // Send SIGUSR1 signal to child
        if (kill(pid, SIGUSR1) == -1) {
            perror("kill");
            exit(EXIT_FAILURE);
        }

        // Sleep for 1 second before terminating the child
        sleep(1);

        // Terminate the child process
        printf("Parent process: Sending SIGTERM to child (PID = %d).\n", pid);
        if (kill(pid, SIGTERM) == -1) {
            perror("kill");
            exit(EXIT_FAILURE);
        }

        // Wait for the child process to terminate
        wait(NULL);
        printf("Parent process: Child terminated.\n");
    }

    return 0;
}
