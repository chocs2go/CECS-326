/*
   The parser piece for the scheduler assignment
*/
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
/* You will need the integer queue */
#include "IQueue.h"
int main(int argc, char* argv[])
{
  int fd;
  FILE *f;
  char line[80];
  int start_time, duration;
  int i;

  struct process_struct
  {
    int process_id;
    int start_time;
    int duration;
    int time_left;
  };
  struct process_struct process_list[80];
  int process_count;

  if (argc !=2)
  {
    printf("usage a.out file_name\n");
    return 0;
  };
  f = fopen(argv[1],"r");
  process_count = 0;

  while(fgets(line,sizeof(line),f) != NULL)
  {
    sscanf(line, "%d %d", &start_time, &duration);
    process_list[process_count].process_id = process_count;
    process_list[process_count].start_time = start_time;
    process_list[process_count].duration = duration;
    process_list[process_count].time_left = duration;
    process_count++ ;
  }
  for (i = 0 ; i < process_count ; i++)
  {
      printf("process %d, start  %d, duration %d, left %d \n",
      process_list[i].process_id,
      process_list[i].start_time,
      process_list[i].duration,
      process_list[i].time_left);
  }

/* Round Robin */
int time, present, next_process;
time = 0;
next_process = 1;

printf("\nTime\nAction\n");

while((IQueueSize() != 0) || (next_process == 1)){
  next_process = 0;
  for(i = 0; i < process_count; i++){
    if(process_list[i].start_time > time){
      next_process = 1;
    }
    if(process_list[i].start_time == time){
      IQueueStore(i);
    }
  }
  if(IQueueSize() == 0){
    printf("%d\tidle\n", time);
  }
  else{
    present = IQueueRetrieve();
    printf("%d\tProcess\t%d\n", time, present);
    process_list[present].time_left = process_list[present].time_left - 5;
    if(process_list[present].time_left > 0){
      IQueueStore(present);
    }
  }
  time = time + 5;
}

  printf("%d\tidle\n", time);
  printf("DONE\n");
  close(fd);
}


