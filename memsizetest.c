#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    printf(1, "The process is using: %d\n", sys_memsize());
    void *ptr = malloc(1<<11);
    printf(1, "The process is using: %d\n", sys_memsize());
    free(ptr);
    printf(1, "The process is using: %d\n", sys_memsize());
  exit();
}
