#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int parent_pid = getpid();
  int pid = fork();
  int id = 7;
  if (pid) {
    char *in_buf = "hello from sending process!";
    int len = send(id, in_buf, strlen(in_buf));
    if (len == 0) {
      printf("send() has failed\n");
    }
    wait(0);
  } else if (pid == 0) {
    char out_buf[30];
    int len = recv(id, out_buf, 30);
    if (len) {
      printf("Recieved %d bytes from process[%d]\n", len, parent_pid);
      printf("Recieved Data: %s\n", out_buf);
    } else {
      printf("recv() has failed\n");
    }
    exit(0);
  } else {
    printf("Failed to fork\n");
  }

  exit(0);
}
