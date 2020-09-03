#include "ballFlip.h"
#include "define.h"

//1ステップ回転
void ballFlip::step() {
  // The STEP minimum high pulse width is 1.9 microseconds.
  digitalWrite(PIN_STEP, HIGH);
  delayMicroseconds(3);
  digitalWrite(PIN_STEP, LOW);
  delayMicroseconds(3);
}

//回転方向設定
void ballFlip::setDirection(bool dir) {
  delayMicroseconds(1);
  digitalWrite(PIN_DIR, dir);
  delayMicroseconds(1);
}

//フリップ
void ballFlip::flip(int deg) {
  Serial.println("flip");
  setDirection(DIR_FLIP);
  unsigned int stp = 400.0 * 64.0 * double(deg / 360.0);
  Serial.println(stp);
  for (unsigned int i = 0; i < stp; i++) {
    step();
    delayMicroseconds(StepPeriodUs_flip);
  }
}

//位置リセット
void ballFlip::posReset() {
  setDirection(DIR_RESET);
  while (checkSensor() == LOW) {
    step();
    delayMicroseconds(StepPeriodUs_reset);
  }
}

//センサチェック
bool ballFlip::checkSensor() {
  if (analogRead(PIN_PLATE_SENSOR) > THRESHOLD_PLATE) return true;
  else return false;
}
