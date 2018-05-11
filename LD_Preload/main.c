#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[]) {
  char buffer[1000]; // specify the char array as size 1000
  int amount_read;
  int fd;

  fd = fileno(stdin);
  //read in value will be stored here
  amount_read = read(fd, buffer, sizeof buffer);
  if (amount_read == -1) {
    perror("error reading");
    return EXIT_FAILURE;
  }

  if (fwrite(buffer, sizeof(char), amount_read, stdout) == -1) {
    perror("error writing");
    return EXIT_FAILURE;
  }
  // EXIT_SUCCESS is a value in library
  return EXIT_SUCCESS;
}
