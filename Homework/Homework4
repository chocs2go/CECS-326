/*
   The parser piece for the minishell assignment
   Replace the part that prints the parsed command
   with you code that does the fork, exec, wait.
*/
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  char line[40];
  char *nargs[10];
  char *space = " ";
  char *where;

  int ch,result;

  while(1)
  {
    int i = 0;
    printf("Your command please: ");
    fgets(line,sizeof(line),stdin);
    line[strlen(line)-1] = '\0';
    where = strtok(line,space);
    nargs[i++] = where;
    while (where != NULL)
    {
      where = strtok(NULL,space);
      nargs[i++] = where;
    }
    /* Print the results */
   // printf("Your parsed command was:\n");

    result = fork();
    for (i = 0 ; nargs[i] != NULL; i++)
    {
        if (result == 0)
           execvp(nargs[i], nargs);
        else
           wait3(&ch, 0, NULL);
     // printf(" %s\n", nargs[i]);
    }
  }
}
