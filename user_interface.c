#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <errno.h>

#include <sys/shm.h>

#include <unistd.h>
#include <fcntl.h>

#include <ctype.h>

#include <sys/stat.h>

// ============================================================================

int main() {

  printf("=====================================\n");

  int mkfifo_call_1 = mkfifo("a", 0777);
  int mkfifo_call_2 = mkfifo("b", 0777);

  int open_call_1 = open("a", O_WRONLY, 0777);
  int open_call_2 = open("b", O_RDONLY, 0777);

  while (42) {

    char input[1000];

    printf("enter input: ");
    fgets(input, 1000, stdin);

    write(open_call_1, input, strlen(input));

    read(open_call_2, input, sizeof(input));

    printf("     output: %s", input);

    printf("=====================================\n");

  }

}
