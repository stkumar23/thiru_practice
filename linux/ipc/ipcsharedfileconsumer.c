/* Linux Inter Process Communication - Shared Files
  Consumer program. Program which reads the data from a file

  Author: Thiru
  */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define FILENAME "/tmp/msg.txt"

// main()
int main()
{
  struct flock lock;
  lock.l_type = F_WRLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 0;
  lock.l_pid = getpid();

  int fd;
  if((fd = open(FILENAME, O_RDONLY)) < 0) {
    printf("File open to read failed\n");
    exit(1);
  }

  fcntl(fd, F_GETLK, &lock);
  if(lock.l_type != F_UNLCK) {
    printf("File is still write locked\n");
    exit(2);
  }

  lock.l_type = F_RDLCK;
  if(fcntl(fd, F_SETLK, &lock) < 0) {
    printf("File read lock is failed\n");
    exit(3);
  }

  int ch;
  while(read(fd, &ch, 1) > 0) {
    write(STDOUT_FILENO, &ch, 1);
  }

  // release the lock
  lock.l_type = F_UNLCK;
  if(fcntl(fd, F_SETLK, &lock) < 0) {
    printf("explicit unlocking failed\n");
    exit(4);
  }

  close(fd);

  return 0;
}
