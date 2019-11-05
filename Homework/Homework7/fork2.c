#include <stdlib.h> /* Needed for fork */
#include <stdio.h> /* Needed for printf. */
#include <stdbool.h> /* Needed for bool, optional. */
#include <unistd.h> /* Needed for fork and exit. */
#include <sys/types.h>
#include <sys/wait.h>

int sum;
int main (int argc, char* argv[]) {
  int i, result, input;
  sum = 0;
 // fork();  /* create a new process */
 //result = fork();

//  if (result == 0){
//      printf("C");
//      sleep(2);
//  }
// else{
//      printf("P");
//      sleep(1);
// return 0;
// }

  printf("Sleeping\n");
  sleep(5);

  result = fork();

  for (i=1; i<=10; i++){

  if (result == 0){
        input = getchar();
        printf("C");
        sleep(2);
  }
  else{
        input = getchar();
        printf("P");
        sleep(1);
  }

    sum += i;
    printf("   sum is %d %c \n", sum, input);
    fflush(stdout);

  }

  if (argc > 1 && result >= 0){
        int ch;
        wait3(&ch, 0, NULL);
        return result;
  }
  else
        return 0;

 // if(argc == 0 || result == 0){
//      return 0;




 // printf("hello world\n");
  return 0;
}
                    
