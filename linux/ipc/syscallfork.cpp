// Linux System Call - Fork
// Fork - Create a child process
// Creates a new process by duplicating the calling process.
// The Parent and the Child processes run in separate memory spaces.
// At the time of fork() both memory spaces have the same content.
//
// Return values: 0 - In the Child process
//                PID - In the Parent process (any non-zero positive value)
//                -1 - Failure. No child process is created. Read errno

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// main
int main()
{
  pid_t pid;
  int rv;

  switch(pid = fork()) {
    case -1:
      printf("Failure to create child process");
      exit(1);
    case 0:
      printf("Child process\n");
      printf("PID %d\n", getpid());
      printf("Parent PID %d\n", getppid());
      printf("Enter the exit status: ");
      scanf("%d", &rv);
      printf("Child process is exiting...\n");
      exit(rv); // This exit status is send to Parent process
    default:
      printf("Parent process\n");
      printf("PID %d\n", getpid());
      printf("Child PID %d\n", pid);
      printf("Waiting for Child to exit\n");

      // Can be replaced with waitpid(<pid>) to wait for
      // specific child process with that pid
      wait(&rv);
      printf("Child's exit status %d\n", WEXITSTATUS(rv));
      printf("Parent process is exiting...\n");
  }
  return 0;
}
