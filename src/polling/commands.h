#ifndef COMMANDS_H
#define COMMANDS_H
#include "util.h"
#define TOP_LIST_LENGTH 3

typedef struct Top3Commands {
  char top1[BUFFER_SIZE];
  char top2[BUFFER_SIZE];
  char top3[BUFFER_SIZE];
}Top3Commands;

//Returns a struct with the top 3 most used commands based on shell history
struct Top3Commands MostUsedCommands();

//helper function for MostUsedCommands()
void ParseHistory(char* historyFile, struct Top3Commands* commands);

#endif
