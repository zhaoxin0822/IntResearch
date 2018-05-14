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

typedef int (*orig_socket_f_type)(int domain, int type, int protocol);
//The typedef is an advance feature in C language which allows us to create an alias or new name for an existing type or user defined type. The syntax of typedef is as follows:
int socket(int domain, int type, int protocol){
  printf("the domain is '%d'\n", domain);
  printf("the type is '%d'\n", type);
  printf("the protocol is '%d'\n", protocol);

  if(protocol == 1){
     printf("you code has been injected at '%d'!!!\n", domain);
     orig_socket_f_type socket_orig;
     socket_orig = (orig_socket_f_type)dlsym(RTLD_NEXT,"socket");
     return socket_orig(domain, type, protocol);
  }
  else{
    orig_socket_f_type socket_orig;
  // dlsym find the next defined socket function in your library, whcih is the original one in this case
  // then defin socket_orig as the second socket function
  socket_orig = (orig_socket_f_type)dlsym(RTLD_NEXT,"socket");
  return socket_orig(domain, type, protocol);
  }
}

