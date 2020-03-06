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

return 0;
}
