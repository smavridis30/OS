#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    FILE *file;

    // Open a file for writing
    file = fopen("pids.txt", "w");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    pid = fork();

    if (pid == -1) { // Error during fork
        perror("fork");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        fprintf(file, "Child Process: PID = %d\n", getpid());
        fclose(file); // Close the file
        exit(0);
    } else { // Parent process
        fprintf(file, "Parent Process: PID = %d\n", getpid());
        fclose(file); // Close the file

        // Wait for the child process to finish
        wait(NULL);
        printf("Parent: Both processes have written to the file.\n");
    }

    return 0;
}
