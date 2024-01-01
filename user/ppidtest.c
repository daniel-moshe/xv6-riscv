#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int pid = 0;

    fprintf(1, "Hello from get ppid program. My pid is %d\n", getpid());
    pid = fork();
    if (pid == 0) {
        // Child process
        fprintf(1, "My parent process is %d\n", getppid());
        exit(0);
    } else {
        // Parent process
        wait(0);
        fprintf(1, "I am the parent process and my parent is %d\n", getppid());
    }

    return 0;
}
