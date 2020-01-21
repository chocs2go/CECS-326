#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main () {
  int i;
  int re1, re2;
  int fd1, fd2;
  int multiplicand = 0;
  int multiplier = 0;
  int product = 0;
  re1 = mkfifo("fifo1", 0600);
  re2 = mkfifo("fifo2", 0600);
  fd1 = open("fifo1", O_RDONLY);
  fd2 = open("fifo2", O_WRONLY);

  for ( i = 0; i < 5; i++) {
    read(fd1, &multiplicand, sizeof(multiplicand));
    read(fd1, &multiplier, sizeof(multiplier))l
    product = multiplicand * multiplier;
    write(fd2, &product, sizeof(product));
  }
  return 0;
};

