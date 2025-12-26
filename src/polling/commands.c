#include "commands.h"
#include "easymemory.h"
#include "easylogger.h"
#include <stdio.h>
#include <string.h>

struct Top3Commands MostUsedCommands() {
  struct Top3Commands commands;
  char *shell = ShellName();
  if(strcmp(shell, "zsh") == 0){
    ParseHistory(".zsh_history", &commands);
  }else if(strcmp(shell, "bash") == 0){
    ParseHistory(".bash_history", &commands);
  }else{ 
    printf("idk where the shell history for that is lol\n");
  }

  return commands;
}

void ParseHistory(char* historyFile, struct Top3Commands* commands){
  const char *home = getenv("HOME");
  EZ_ASSERT(home!=NULL, "No home\n");
  char historyPath[BUFFER_SIZE];
  snprintf(historyPath, sizeof(historyPath), "%s/%s", home, historyFile);

  const char command1[] = "cut -d';' -f2- ";
  const char command2[] = " | awk '{print $1}' | sort | uniq -c | sort -nr | head -10 | awk '{print $2}'";
  size_t commandSize = strlen(command1) + strlen(historyPath) + strlen(command2) + 3;
 
  char command[commandSize];
  snprintf(command, commandSize, "%s'%s'%s", command1, historyPath, command2);

  FILE *fp = popen(command, "r");
  EZ_ASSERT(fp!=NULL, "Command failed\n");
  
  fgets(commands->top1, BUFFER_SIZE, fp);
  fgets(commands->top2, BUFFER_SIZE, fp);
  fgets(commands->top3, BUFFER_SIZE, fp);

  pclose(fp);
  return;
}
