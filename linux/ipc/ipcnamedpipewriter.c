/* Linux Inter Process Communication - Named Pipe
  Parent and Child processes communicating using Pipe - Writer
  Use this program with ipcnamedpipereader. Run this program first and then
  run the reader program.

  Author: Thiru
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
  const char msg[80] = "This sample program demonstrates Linux IPC - Named Pipe";
  const char* pipeName = "./fifoChannel";
  mkfifo(pipeName, 0666); // Create Named Pipe with access permission

  int fd = open(pipeName, O_WRONLY | O_CREAT);
  if(fd < 0) {
    printf("Could not open named pipe");
    exit(1);
  }


  write(fd, msg, strlen(msg));

  close(fd);
  unlink(pipeName);

  return 0;
}
