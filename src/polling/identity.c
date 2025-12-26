#include "identity.h"
#include "easylogger.h"
#include <stdio.h>
#include <string.h>

struct UserInfo GetUserInfo(){
  struct UserInfo user;
  GetUserField(&user);
  
  return user;
}

void GetUserField(struct UserInfo* user){
  char* username = getenv("USER");
  FILE *fp = popen("uname -n", "r");
  EZ_ASSERT(fp!=NULL, "Command failed\n");

  char deviceName[BUFFER_SIZE];
  fgets(deviceName, BUFFER_SIZE, fp);
  pclose(fp);
  rstrip(deviceName);
  
  snprintf(user->username, BUFFER_SIZE, "USER: %s@%s", username, deviceName);
}
