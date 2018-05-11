#include <string.h>

//size_t is an unsigned integer type of at least 16 bit
size_t read(int fd, void *data, size_t size) {
  strcpy(data, "this is great!");
  //copies the string pointed to, by src to dest.
  //change the data where data pointer point to
  return 11;
}
