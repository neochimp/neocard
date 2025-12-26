#ifndef IDENTITY_H
#define IDENTITY_H
#include "util.h"
typedef struct UserInfo {
  char username[BUFFER_SIZE];
  char kernel[BUFFER_SIZE];
  char shell[BUFFER_SIZE];
}UserInfo;

struct UserInfo GetUserInfo();

void GetUserField(struct UserInfo* user);

void GetKernelField(struct UserInfo* user);

#endif
