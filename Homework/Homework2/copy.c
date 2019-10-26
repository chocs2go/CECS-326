#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
int main (int argc, char* argv[]) {
  int src_fd, dstn_fd;
  char filebuf[256]; /* a small buffer used to copy the file */
  ssize_t readSize;

  src_fd = open(argv[1],O_RDONLY);
 // dstn_fd = open(argv[2], (O_CREAT|O_RDWR), (S_IRUSR|S_IWUSR|S_IRGRP| S_IROTH));
  if (src_fd < 0){
    printf("Error\n");
    return 0;
  }

  dstn_fd = open(argv[2], (O_CREAT|O_RDWR), (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)); //owner can read and write. group and others can only read
  while (( readSize = read(src_fd, filebuf, sizeof(filebuf)-1)) > 0)
  {
    // I turn it into a string only because I'm using printf;
    // making a copy using "write" would not need this.
    // filebuf[readSize] = '\0';
    // printf("%s",filebuf);

    write(dstn_fd, filebuf, (size_t)readSize);

  }
  close(src_fd);
  close(dstn_fd);
  return 0;
}
