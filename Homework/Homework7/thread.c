#include <stdlib.h> /* Needed for fork */
#include <stdio.h> /* Needed for printf. */
#include <stdbool.h> /* Needed for bool, optional. */
#include <unistd.h> /* Needed for fork and exit. */
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

int sum;
char result, input;

int  ChildThread(){
  int i;
  for (i=1; i<=10; i++){

        input = getchar();
        printf("C  ");
        //sleep(2);
        sum += i;
        printf("   sum is %d %c \n", sum, input);
        fflush(stdout);

  }

}
int main (int argc, char* argv[]) {

  pthread_t th;
  pthread_attr_t ta;
  (void) pthread_attr_init(&ta);
  (void) pthread_attr_setdetachstate(&ta, PTHREAD_CREATE_DETACHED);
  pthread_create(&th, &ta, (void * (*)(void *))ChildThread, NULL);

  sum = 0;

  printf("Sleeping\n");
  sleep(5);

 // result = fork();
  int i;

  for (i=1; i<=10; i++){

        input = getchar();
        printf("P  ");
        //sleep(1);
        sum += i;
        printf("   sum is %d %c \n", sum, input);
        fflush(stdout);
  }
  return 0;
}
