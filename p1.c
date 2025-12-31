#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("Child process created. PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("Child executing 'ls -l' using execvp...\n");
        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args);
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else {
        printf("Parent process. PID = %d\n", getpid());
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child terminated normally with exit status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child terminated abnormally.\n");
        }
        printf("Parent continues after child termination.\n");
    }

    return 0;
}
