#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char * argv[]) {
  char s[100];
  fgets(s, 100, stdin);

  char * args[50]; //array to store tokens
  char * token; //will store start of token
  char * line = s; //the complete line stored as a pointer
  int i=0;//index of args we are up to

  while (token != NULL) {
    token = strsep(&line, " ");
    args[i] = token;
    i++;
  }

  printf("%s\n", s);

  //print each index in args:
  int c = 0;
  for (c=0;c<i;c++) {
    printf("[%s]\n", args[c]);
  }
  //remove escape key from last arg
  args[i-1] = 

  execvp(args[0], args);

}
