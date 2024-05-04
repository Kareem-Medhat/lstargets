#include <unistd.h>
#include <stdio.h>

// Must be > 0
int const BUF_SIZE = 4096;

int main(int argc, char** argv) {
  char buffer[BUF_SIZE+1]; // add 1 to set null terminating character
  int num = readlink(argv[1], buffer, BUF_SIZE);

  while (num != -1) {
    buffer[num] = '\0';
    printf("%s\n", buffer);
    num = readlink(buffer, buffer, BUF_SIZE);
  }

  return 0;
}
