#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    printf(1, "Hello World XV6\n");

    int status;
    int pid = fork();
    if( pid == 0 ){
      exit(4);
    } else{
      wait(&status);
      printf(1, "child's exit status is : %d\n", status);
    }
  exit(0);
}
