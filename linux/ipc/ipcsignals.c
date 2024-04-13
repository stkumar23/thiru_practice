/* Linux Inter Process Communication - Signals
  Graceful shutdown of child process from parent

  Author: Thiru
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void graceful(int signum) {
  printf("Child received the signal %i\n", signum);
  puts("Child about to terminate gracefully");
  sleep(1);
  puts("Child terminating now...");
  _exit(0);
}

void set_handler() {
  struct sigaction current;
  sigemptyset(&current.sa_mask);
  current.sa_flags = 0;
  current.sa_handler = graceful;
  sigaction(SIGTERM, &current, NULL);
}

void child_code()
{
  puts("Child process");
  set_handler();

  while(1) {
    sleep(1);
    puts("Child just woke up, going back to sleep");
  }
}

void parent_code(pid_t pid)
{
  puts("Parent process");
  sleep(5);

  if (kill(pid, SIGTERM) == -1) {
    printf("could not kill child process");
    exit(2);
  }
  wait(NULL);
  puts("Child terminated. Parent process is exiting...");
}

int main()
{
  pid_t pid = fork();
  if (pid < 0 ) {
    printf("could not fork process");
    exit(1);
  }

  if (pid == 0) {
    child_code();
  } else {
    parent_code(pid);
  }
  return 0;
}
