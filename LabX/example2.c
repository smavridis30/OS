#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipefd[2]; // Array to hold pipe file descriptors
    pid_t pid;
    char buffer[100];
    const char *message = "Hello from parent!";

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork to create a child process
    pid = fork();

    if (pid == -1) { // Error in fork
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        close(pipefd[1]); // Close unused write end of the pipe

        // Read the message from the parent
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received message: %s\n", buffer);

        close(pipefd[0]); // Close the read end
        exit(0);
    } else { // Parent process
        close(pipefd[0]); // Close unused read end of the pipe

        // Send a message to the child
        write(pipefd[1], message, strlen(message) + 1);
        printf("Parent sent message: %s\n", message);

        close(pipefd[1]); // Close the write end

        // Wait for the child to finish
        wait(NULL);
    }

    return 0;
}
