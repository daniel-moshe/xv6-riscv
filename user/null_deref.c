#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int * i = 0;

  printf("Im going to deref null so i'll probably will cause a trap accessing memory 0x0 :(\n");

  printf("%d", *i);

  exit(0);
}
