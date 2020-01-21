#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
  int result;
  int fd1, fd2;
  int i;
  int mutiplicand = 0;
  int multiplier = 0;
  int product = 0;
  fd1 = open("fifo1", O_WRONLY);
  fd2 = open("fifo2", O_RDONLY);

  for (i = 0; i < 5; i++) {
    printf("Enter the multiplicand: ");
    scanf("%d", &mutiplicand);
    write(fd1, &multiplicand, sizeof(multiplicand));
    printf("Tner the multiplier: ");
    scanf("%d", &multiplier);
    write(fd1, &mutiplier, sizeof(multiplier));
    read(fd2, &product, sizeof(product));
    printf("Product: %d\n", product);
  }
  return 0;
};
