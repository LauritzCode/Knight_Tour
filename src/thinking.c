#include "thinking.h"
#include <stdio.h>
#include <windows.h>

void simulate_thinking(unsigned int time1, unsigned int time2) {
  printf("\n\nThinking...");
  Sleep(time1);
  printf("\n\nAlmost there...\n\n");
  Sleep(time2);
}