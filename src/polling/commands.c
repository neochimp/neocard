#include "commands.h"
#include "easymemory.h"
#include "easylogger.h"
#include <stdio.h>
#include <string.h>

struct Top3Commands MostUsedCommands() {
  //struct that will get passed as a pointer and populated by ParseHistory()
  struct Top3Commands commands;
  char *shell = ShellName();
  //check a specific name based on what shell we're using
  if(strcmp(shell, "zsh") == 0){
    ParseHistory(".zsh_history", &commands);
  }else if(strcmp(shell, "bash") == 0){
    ParseHistory(".bash_history", &commands);
  }else{ 
    printf("idk where the shell history for that is lol\n");
		EZ_ERROR("Currently unsupported shell history\n");
  }

  return commands;
}

void ParseHistory(char* historyFile, struct Top3Commands* commands){
  //get the path for the current home
  const char *home = getenv("HOME");
  EZ_ASSERT(home!=NULL, "No home\n");

  //get the directory for the specific history file
  char historyPath[BUFFER_SIZE];
  snprintf(historyPath, sizeof(historyPath), "%s/%s", home, historyFile);
  
  //two halves of the command that will return the top 3 most used commands
  const char command1[] = "cut -d';' -f2- ";
  
  //two diff versions one with and without counts
  const char command2[] = " | awk '{print $1}' | sort | uniq -c | sort -nr | head -3 | awk '{print $2}'";
  //const char command2[] = " | awk '{print $1}' | sort | uniq -c | sort -nr | head -3 | awk '{print $2 \" (\" $1 \")\" }'";
  
  //concatenate the full command with the proper filepath
  size_t commandSize = strlen(command1) + strlen(historyPath) + strlen(command2) + 3;
  char command[commandSize];
  snprintf(command, commandSize, "%s'%s'%s", command1, historyPath, command2);

  //run the command
  FILE *fp = popen(command, "r");
  EZ_ASSERT(fp!=NULL, "Command failed\n");
  
  //assign the command output to the struct
  char tmp[BUFFER_SIZE];
  fgets(commands->top1, BUFFER_SIZE, fp);
  snprintf(tmp, BUFFER_SIZE, "1. %s", commands->top1);
  strcpy(commands->top1, tmp);
  rstrip(commands->top1); 

  fgets(commands->top2, BUFFER_SIZE, fp);
  snprintf(tmp, BUFFER_SIZE, "2. %s", commands->top2);
  strcpy(commands->top2, tmp);
  rstrip(commands->top2); 
  
  fgets(commands->top3, BUFFER_SIZE, fp);
  snprintf(tmp, BUFFER_SIZE, "3. %s", commands->top3);
  strcpy(commands->top3, tmp);
  rstrip(commands->top3); 
  
  pclose(fp);
  return;
}
