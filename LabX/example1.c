#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("Original Process: PID = %d\n", getpid());

    for (int i = 0; i < 3; i++) {
        pid_t pid = fork(); // Create a new process

        if (pid < 0) { // Fork failed
            perror("Fork failed");
            return 1;
        }

        if (pid == 0) { // Child process
            printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
            return 0; // Exit the child process
        }
    }

    // Parent process waits for children
    sleep(1); // Ensures output is readable
    return 0;
}
