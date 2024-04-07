/* Linux Inter Process Communication - Unnamed Pipe
  Parent and Child processes communicating using Pipe

  Author: Thiru
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

const int readend = 0;
const int writeend = 1;

int main()
{
  int pipeFDs[2];
  char buf;
  const char* msg = "This is sample program demonstrates the Linux IPC - Unnamed Pipe\n";

  if(pipe(pipeFDs) < 0) {
    printf("Could not open pipe");
    exit(1);
  }

  pid_t cpid = fork();
  if(cpid < 0) {
    printf("Could not fork child process");
    exit(2);
  }

  if(cpid == 0) {                 // child process
    close(pipeFDs[writeend]);
    while(read(pipeFDs[readend], &buf, 1) > 0) {
      write(STDOUT_FILENO, &buf, sizeof(buf));
    }

    close(pipeFDs[readend]);
    _exit(0);                   // exit and notify parent
  } else {                      // parent process
    close(pipeFDs[readend]);

    write(pipeFDs[writeend], msg, strlen(msg));
    close(pipeFDs[writeend]);

    wait(NULL);                 // wait for child to exit
    exit(0);
  }

  return 0 ;
}
