#include "Arduino.h"

#define PIN_DIR 2
#define PIN_STEP 3
#define PIN_CS 4
#define PIN_SOL_DROP 5
#define PIN_SOL_ROAD 6
#define PIN_SW 7
#define PIN_LED 8

#define PIN_PLATE_SENSOR A0
#define PIN_BALL_SENSOR A1

#define THRESHOLD_PLATE 800
#define THRESHOLD_BALL 980
#define DIR_FLIP 0
#define DIR_RESET 1
#define TIMEOUT 3000

#define StepPeriodUs_flip 30
#define StepPeriodUs_reset 30

#define FLIP_DELAY 330 //ボール落下からフリップするまでの時間
