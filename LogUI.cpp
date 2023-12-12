//
// Created by chase on 12/11/23.
//

#include "LogUI.h"

#ifdef LOG_UI_ENABLED
LogUI::LogUI()
{}

void LogUI::log(char* message)
{
  strcpy(logs[nextLogIndex], message);
  nextLogIndex++;
  if (nextLogIndex >= LOG_CAPACITY)
  {
    nextLogIndex = 0;
  }
}

void LogUI::draw(Arduboy2 &arduboy) {
  for (int i = 0; i < LOG_CAPACITY; ++i) {
    arduboy.setCursor(64, i * 10);
    arduboy.print(logs[i]);
  }
}
#endif
