// Linux System Call - Signal Handler (sigaction)
// The system call sigaction is used to change the action taken by a process
// on receipt of a specific signal.
//
// Return values: 0 - On Success
//                -1 - Failure. Read errno

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

void sigint_handler(int sig) {
  const char msg[] = "SIGINT action handler\n";
  // write system call is for async nature. does not block
  write(0, &msg, sizeof(msg));
}

// main
int main()
{
  char s[200];
  struct sigaction sa;
  sa.sa_handler = sigint_handler;
  // SA_RESTART will restart the flow.
  sa.sa_flags = SA_RESTART; // Can be 0 also

  if (sigaction(SIGINT, &sa, NULL) == -1) {
    perror("sigaction");
    exit(1);
  }

  printf("Enter a string: \n");

  if (fgets(s, sizeof(s), stdin) == NULL)
    perror("fgets");
  else
    printf("You entered: %s\n", s);

  return 0;
}
