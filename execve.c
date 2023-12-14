#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * execute_command - Executes the given command.
 * @command: The command to execute.
 */
void execute_command(const char *command) {
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        /* Child process */
        if (execlp(command, command, (char *)NULL) == -1) {
            perror("execlp");
            exit(EXIT_FAILURE);
        }
    } else {
        /* Parent process */
        if (waitpid(child_pid, &status, 0) == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            fprintf(stderr, "Command exited with non-zero status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            fprintf(stderr, "Command terminated by signal %d\n", WTERMSIG(status));
        }
    }
}

int main(void) {
    char command[MAX_COMMAND_LENGTH];
    int c;
    int index = 0;

    while (1) {
        // Display prompt
        printf("$ ");

        // Read command
        while ((c = getchar()) != '\n') {
            if (c == EOF) {
                if (index == 0) {
                    printf("\n");
                    exit(EXIT_SUCCESS);
                } else {
                    fprintf(stderr, "Error: Incomplete command at end of file\n");
                    exit(EXIT_FAILURE);
                }
            }
            if (index < MAX_COMMAND_LENGTH - 1) {
                command[index++] = (char)c;
            }
        }

        // Null-terminate the command string
        command[index] = '\0';

        // Execute the command
        execute_command(command);

        // Reset command buffer
        index = 0;
    }

    return 0;
}
