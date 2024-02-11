#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

char buf[BSIZE];

int main()
{
    int num_blocks;
    int fd, i, j;

    num_blocks = 11 + 256 + 256*256; // Suppose to be 65803 blocks

    unlink("bigfile.dat");

    printf("Running bigfile test\n");
    printf("Going to create a bigfile of %d blocks\n", num_blocks);
    fd = open("bigfile.dat", O_CREATE | O_RDWR);
    if (fd < 0)
    {
        printf("Cannot create bigfile");
        exit(1);
    }

    memset(buf, 0x24, BSIZE);
    // Divided to 23 parts so we can get a log about where we at
    for (j = 0; j < 23; j++)
    {
        for (i = 0; i < num_blocks/23; i++)
        {
            if (write(fd, buf, BSIZE) != BSIZE)
            {
                printf("Writing to bigfile has failed\n");
                exit(1);
            }
        }
        printf("Wrote part #%d/23\n", j+1);
    }
    close(fd);

    exit(0);
}