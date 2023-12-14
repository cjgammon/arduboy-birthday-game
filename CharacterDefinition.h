//
// Created by chase on 12/13/23.
//

#ifndef ARDUBOY_BIRTHDAY_GAME_CHARACTERDEFINITION_H
#define ARDUBOY_BIRTHDAY_GAME_CHARACTERDEFINITION_H


struct CharacterDefinition
{
  const char* name;
  const char* description;

  uint8_t frameCount_Idle;
  uint8_t frameCount_Walking;
  uint8_t frameCount_Jump;
  uint8_t frameCount_Descend;
  uint8_t frameCount_Fall;

  uint8_t frameChangeInterval_Idle;
  uint8_t frameChangeInterval_Walking;
  uint8_t frameChangeInterval_Jump;
  uint8_t frameChangeInterval_Descend;
  uint8_t frameChangeInterval_Fall;

  float radius;
  float gravity;
  float jumpPower;
  float extraJumpPower;
  float stopJumpDamping;
  uint8_t jumpCount;
  bool canHover;


};

const CharacterDefinition CharacterDefinition_Jonas PROGMEM  =
        {
                "JONAS",
                "ABILITY: Hover",

                2, // idle frames
                8, // walking frames
                1, // jumping frames
                1, // descend frames
                1, // fall frames

                10, // idle frame change interval
                6,  // walking frame change interval
                1,  // jump frame change interval
                1,  // descend frame change interval
                1,  // fall frame change interval

                8, // radius
                0.2, // gravity
                -3.3, // jump power
                0, // extra jump power
                0.3, // stop jump damping
                1, // jump count
                true, // can hover
        };
const CharacterDefinition CharacterDefinition_Henry PROGMEM  =
        {
                "HENRY",
                "ABILITY: Double Ollie",

                2, // idle frames
                6, // walking frames
                1, // jumping frames
                1, // descend frames
                1, // fall frames

                10, // idle frame change interval
                6,  // walking frame change interval
                1,  // jump frame change interval
                1,  // descend frame change interval
                1,  // fall frame change interval

                8, // radius
                0.3, // gravity
                -4.0, // jump power
                -4.0, // extra jump power
                0.5, // stop jump damping
                2, // jump count
                false, // can hover
        };
const CharacterDefinition CharacterDefinition_Jaxon PROGMEM  =
        {
                "JAXON",
                "ABILITY: Butt Stomp",

                4, // idle frames
                8, // walking frames
                1, // jumping frames
                1, // descend frames
                1, // fall frames

                16, // idle frame change interval
                6,  // walking frame change interval
                1,  // jump frame change interval
                1,  // descend frame change interval
                1,  // fall frame change interval

                8, // radius
                0.2, // gravity
                -4.6, // jump power
                9, // extra jump power
                0.1, // stop jump damping
                1, // jump count
                false, // can hover
        };
const CharacterDefinition CharacterDefinition_Mason PROGMEM  =
        {
                "MASON",
                "ABILITY: Double Jump",

                2, // idle frames
                8, // walking frames
                1, // jumping frames
                1, // descend frames
                1, // fall frames

                10, // idle frame change interval
                6,  // walking frame change interval
                1,  // jump frame change interval
                1,  // descend frame change interval
                1,  // fall frame change interval

                5, // radius
                0.18, // gravity
                -2.1, // jump power
                -3.1, // extra jump power
                0.5, // stop jump damping
                2, // jump count
                false, // can hover
        };
const CharacterDefinition CharacterDefinition_Ruhaan PROGMEM  =
        {
                "RUHAAN",
                "ABILITY: Dragon Punch",

                2, // idle frames
                8, // walking frames
                1, // jumping frames
                1, // descend frames
                1, // fall frames

                20, // idle frame change interval
                6,  // walking frame change interval
                1,  // jump frame change interval
                1,  // descend frame change interval
                1,  // fall frame change interval

                8, // radius
                0.25, // gravity
                -4.0, // jump power
                -2.3, // extra jump power
                0.2, // stop jump damping
                2, // jump count
                false, // can hover
        };
const CharacterDefinition CharacterDefinition_Nola PROGMEM  =
        {
                "NOLA",
                "ABILITY: Triple Jump",

                3, // idle frames
                8, // walking frames
                1, // jumping frames
                2, // descend frames
                1, // fall frames

                10, // idle frame change interval
                6,  // walking frame change interval
                1,  // jump frame change interval
                5,  // descend frame change interval
                1,  // fall frame change interval

                8, // radius
                0.18, // gravity
                -3.0, // jump power
                -2.25, // extra jump power
                0.5, // stop jump damping
                3, // jump count
                false, // can hover
        };



#endif //ARDUBOY_BIRTHDAY_GAME_CHARACTERDEFINITION_H
