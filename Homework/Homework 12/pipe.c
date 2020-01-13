#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
  int toParent[2], toChild[2];
  int multiplicand = 0;
  int multiplier = 0;
  int product = 0;
  pipe(toParent);
  pipe(toChild);
  int i, result;
  result = fork();
  // strcpy)obuf, "Hello\n");
  for (i = 0; i < 5; i++) {
    if (result == 0) {
      close(toParent[0]); // Child
      close(toChild[1]);
      read(toChild[0], &multiplicand, sizeof(multiplicand));
      read(toChild[0], &multiplier, sizeof(multiplier));
      product = multiplicand * multiplier;
      write(toParent[1], &product, sizeof(product));
    }
    else {
      close(toChild[0]); // parent
      close(toParent[1]);
        printf("Enter the multiplicand: ");
        scanf("%d", &multiplicand);
        printf("Enter multiplier: ");
        scanf("%d", &multiplier);
      write(toChild[1], &multiplicand, sizeof(multiplicand));
      write(toChild[1], &multiplier, sizeof(multiplier));
      read(toParent[0], &product, sizeof(product));
        printf("Product: %d\n", product);
    }
  }
  return 0;
}
