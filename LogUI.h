//
// Created by chase on 12/11/23.
//

#ifndef ARDUBOY_BIRTHDAY_GAME_LOGUI_H
#define ARDUBOY_BIRTHDAY_GAME_LOGUI_H

#define LOG_UI_ENABLED
#ifdef LOG_UI_ENABLED

#include <Arduboy2.h>

#define LOG_CAPACITY 5
#define LOG_MESSAGE_MAX_LENGTH 20

class LogUI {
public:
    LogUI();
    void log(char* message);
    void draw(Arduboy2 &arduboy);
private:
    char logs[LOG_CAPACITY][LOG_MESSAGE_MAX_LENGTH];
    int nextLogIndex = 0;
};

#endif
#endif //ARDUBOY_BIRTHDAY_GAME_LOGUI_H
