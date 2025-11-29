#ifndef __SEL_USERINFO__
  #define __SEL_USERINFO__

#include "constant_def.h"

extern const uint32_t uid_len;
extern const uint32_t name_limit; 

typedef struct user_info_t {
  char *name;
  long uid;

  void (*destructor)(struct user_info_t* const); // function pointer -> destructor
  struct user_info_t* (*set_uid)(struct user_info_t* const); // function pointer -> set_uid
} usr_info;

usr_info* create_usr(usr_info* const this);
void release_usr(usr_info* const this);
usr_info* generate_uid(usr_info* const this);

usr_info* make_usr_info(usr_info* const this);

#endif
