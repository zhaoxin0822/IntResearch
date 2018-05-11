#define _GNU_SOURCE
/*  _GNU_SOURCE
    1,access to lots of nonstandard GNU/Linux extension functions
    2,access to traditional functions which were omitted from the POSIX standard (often for good reason, such as being replaced with better alternatives, or being tied to particular legacy implementations)
    3,access to low-level functions that cannot be portable, but that you sometimes need for implementing system utilities like mount, ifconfig, etc.
    4,broken behavior for lots of POSIX-specified functions, where the GNU folks disagreed with the standards committee on how the functions should behave and decided to do their own thing.
*/

#include <string.h>
#include <dlfcn.h> // Provide function to retrieve symbols
#include <stdio.h>

typedef ssize_t (*real_read_t)(int, void *, size_t);

ssize_t real_read(int fd, void *data, size_t size) {
  return ((real_read_t)dlsym(RTLD_NEXT, "read"))(fd, data, size);
}// return apointer of that function

ssize_t read(int fd, void *data, size_t size) {
  strcpy(data, "this is great");
  return 12;
}
