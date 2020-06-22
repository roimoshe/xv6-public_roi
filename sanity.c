#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char k_buf[1<<10];
char m_comp_buf[(1<<20) - (70 * (1<<10))];

int
main(int argc, char *argv[])
{
  int fd = open("sanity", O_CREATE|O_RDWR);
  for (int i = 0; i < 6; i++){
    write(fd, k_buf, (1<<10));
  }
  printf(1, "Finished writing 6KB ( direct )\n");
  
  for (int i = 0; i < 64; i++){
    write(fd, k_buf, (1<<10));
  }
  printf(1, "Finished writing 70KB ( single indirect )\n");

  write(fd, m_comp_buf, (1<<20) - (70 * (1<<10)));
  printf(1, "Finished writing 1MB\n");
  
  close(fd);
  exit();
}
