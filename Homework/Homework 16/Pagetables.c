#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
/* File: pagetables.c */
/*
 Implement page tables.
 To make this simple, we have a page side of 1 integer (4 bytes).
*/
void* userprogram(void *);

int a1[3] = {0,3,6};
int a2[3] = {1,4,7};
int a3[3] = {2,5,8};
int memory[9];

int main ()
{
  pthread_t th;
  pthread_attr_t ta;

  if (pthread_attr_init(&ta)<0)
  {
    return -1;
  }
  if (pthread_attr_setdetachstate(&ta,PTHREAD_CREATE_DETACHED)<0)
  {
    return -1;
  }

  /*
    Create 3 child threads, give each of them access to a
    different set of pages. The first child will be using
    pages 0,3,6; the second child will be using pages 1,3,7;
    and the third child will be using pages 2,4,8.
  */
  pthread_create(&th,&ta,userprogram,a1);
  pthread_create(&th,&ta,userprogram,a2);
  pthread_create(&th,&ta,userprogram,a3);

return 0;
}
