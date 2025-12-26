#include "util.h"
#include "easymemory.h"
#include "easylogger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ShellName() {
  char *shellRaw = getenv("SHELL");
  EZ_ASSERT(shellRaw, "No shell environment variable found\n");

  // gets the last instance of '/'
  char *shell = strrchr(shellRaw, '/') + 1;
  return shell;
}
