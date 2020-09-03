#include "Arduino.h"

#define PIN_DIR 2
#define PIN_STEP 3
#define PIN_CS 4
#define PIN_SOL_FALL 5
#define PIN_SOL_LINE 6
#define PIN_SW 7
#define PIN_LED 8

#define PIN_SENSOR A0
#define PIN_SENSOR A1

#define THRESHOLD_SENSOR 800
#define DIR_FLIP 0
#define DIR_RESET 1
#define THRESHOLD 980
#define TIMEOUT 2000

#define StepPeriodUs_flip 4
#define StepPeriodUs_reset 80

#define FLIP_DELAY 10000000 //us
