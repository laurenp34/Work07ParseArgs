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

  while (line != NULL) {
    token = strsep(&line, " ");
    args[i] = token;
    //printf("%d: [%s]\n",i,token);
    i++;
  }
  //remove escape key from last index
  args[i-1] = strsep(&(args[i-1]), "\n");
  args[i] = NULL;
  // char line2[100] = "woah-this-is-cool";
  // char *s1 = line2;
  // printf("[%s]\n", strsep( &s1, "-" ));
  // printf("[%s]\n", s1);
  //
  // printf("[%s]\n", strsep( &s1, "-" ));
  // printf("[%s]\n", s1);
  //
  // printf("[%s]\n", strsep( &s1, "-" ));
  // printf("[%s]\n", s1);
  //
  // printf("[%s]\n", strsep( &s1, "-" ));
  // printf("[%s]\n", s1);

  // printf("%s\n", s);
  // printf("%s\n", args[0]);
  // //print each index in args:
  int c = 0;
  printf("[");
  for (c=0;c<i;c++) {
    printf("'%s', ", args[c]);
  }
  printf("]\n");


  execvp(args[0], args);

  // //testing:
  // char * a2[3];
  // a2[0] = "ls";
  // a2[1] = "-la";
  // a2[2] = NULL;
  // execvp("ls", a2);

}
