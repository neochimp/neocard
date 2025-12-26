#ifndef COMMANDS_H
#define COMMANDS_H
#include "util.h"
#define TOP_LIST_LENGTH 3

typedef struct Top3Commands {
  char top1[BUFFER_SIZE];
  char top2[BUFFER_SIZE];
  char top3[BUFFER_SIZE];
}Top3Commands;

struct Top3Commands MostUsedCommands();
void ParseHistory(char* historyFile, struct Top3Commands* commands);

#endif
