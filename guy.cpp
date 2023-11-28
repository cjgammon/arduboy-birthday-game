
#include "guy.h"
#include "property.h"

const int moodCount = 8;
const String moods[moodCount] = {"HAPPY", "HUNGRY", "BORED", "SAD", "TIRED", "SICK", "DEAD", "ANNOYED"};

unsigned long previousMillis = 0;
const long interval = 1000;

bool sleeping = false;
bool despair = false;
bool dead = false;
bool diedOfOldAge = false;

int secondCounter = 0;
int age = 0;

Property hunger = Property("HUNGRY", 10, 0, 5, 0, 1.0); //name, max, min, mid, value, inc
Property boredom = Property("BORED", 10, 0, 5, 0, 0.6);
Property sadness = Property("SAD", 10, 0, 5, 0, 0.3);
Property annoyed = Property("ANNOYED", 50, 0, 5, 0, 0); //annoyed increases by other means..
Property tiredness = Property("TIRED", 10, 0, 5, 0, 0.1);

Property death = Property("DEAD", 10, 0, 5, 0, 1);

const int statusCount = 5;
Property statuses[statusCount] = {hunger, boredom, sadness, annoyed, tiredness};

Guy::Guy(Arduboy2 arduboy)
{
  _arduboy = arduboy;
}

void Guy::draw() {

/*
  _arduboy.setCursor(100, 0);
  _arduboy.print(death.value);

  for (int i = 0; i < statusCount; i++) {
    _arduboy.setCursor(0, i * 10);
    _arduboy.print(statuses[i].value);
  }
*/
  
  _arduboy.setCursor(0, 40);
  _arduboy.print(moods[_mood]);

  if (sleeping) {
    _mood = 4;
    int sleepFrame = secondCounter % 2 == 0 ? 1 : 0;
    Sprites::drawOverwrite (83, 5, sleep, sleepFrame);
  }

  if (age < 1) {
      Sprites::drawOverwrite (48, 13, baby, _mood);
  } else if (age == 1) {
      Sprites::drawOverwrite (48, 13, kid, _mood);
  } else {
      Sprites::drawOverwrite (48, 13, adult, _mood);
  }

  if (diedOfOldAge) {
    _arduboy.setCursor(0, 0);
    _arduboy.print("You died of old age..");
    _arduboy.setCursor(0, 8);
    _arduboy.print("err.. won!");
  }

}

void Guy::update() {
  
  if (dead) {
    return;
  }
  
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {

    secondCounter++;
    if (secondCounter == 60) { //60 - 1 min
      age = 1;
    } else if (secondCounter == 120) { //120 - 2 min
      age = 2;
    } else if (secondCounter == 300) { //300 - 5 min
      dead = true;
      _mood = 6;
      diedOfOldAge = true;
      return;
    }

    if (sleeping) {
      if (statuses[4].value > statuses[4].min) {
        statuses[4].value --;
      } else {
        statuses[4].value = statuses[4].min;
        sleeping = false;
      }
    }

    if (!sleeping) {
      for (int i = 0; i < statusCount; i++) {
        statuses[i].value += statuses[i].inc;
      }    
    }

    if (despair) {
      death.value += death.inc;
    } else {
      death.value = death.min;
    }
    
    previousMillis = currentMillis;
  }

  checkMood();
}

void Guy::checkMood() {
    int tmpMood = 0;
    int maxCount = 0;
    
    for (int i = 0; i < statusCount; i++) {
      if (statuses[i].value > statuses[i].mid) {
        
        for (int j = 0; j < moodCount; j++) {
          if (statuses[i].name == moods[j]) {
            if (tmpMood == 0) {
               tmpMood = j;
            }
          }
        }
        
      }

      if (int(statuses[i].value) > statuses[i].max) {
        maxCount++;
      }
    }

    if (maxCount > 0) {
      tmpMood = 5; //sick
      despair = true;
    } else {
      despair = false;
    }

    if (death.value > death.max) {
      dead = true;
      tmpMood = 6;
    }

    _mood = tmpMood;
}

void Guy::apply(int action) {
  if (sleeping) {
    sleeping = false;
    statuses[3].value = statuses[3].mid + 1;
    return;  
  }
  
  if (action == 0) { //feed
    statuses[0].value = statuses[0].min;
    
    if (_mood == 1) {
      statuses[3].value = annoyed.min;
    } else {
      statuses[3].value ++;
    }
    
  } else if (action == 1) { //play
    statuses[1].value = statuses[1].min;
    
    if (_mood == 2) {
      statuses[3].value = annoyed.min;
    } else {
      statuses[3].value ++;
    }
    
  }else if (action == 2) { //pet
    statuses[2].value = statuses[2].min;
    
    if (_mood == 3) {
      statuses[3].value = annoyed.min;
    } else {
      statuses[3].value ++;
    }

  } else if (action == 3) { //nap
    sleeping = true;
  } else { // is annoying..
    statuses[3].value ++;
  }
  
}
