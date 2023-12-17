// Sound.h
#ifndef SOUND_H
#define SOUND_H

#include "Vars.h"

#ifdef SOUND_ENABLED
#include <ArduboyTones.h>
extern ArduboyTones sound;
#endif

#endif // SOUND_H