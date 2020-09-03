#include "ballFall.h"
#include "define.h"

//LED点滅
void ballFall::ledFlash() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(PIN_LED, HIGH);
    delay(300);
    digitalWrite(PIN_LED, LOW);
    delay(300);
  }
}

//投擲装置のソレノイド制御
void ballFall::ballDrop(bool state) {
  if (state == true)
    digitalWrite(PIN_SOL_DROP, HIGH);
  else
    digitalWrite(PIN_SOL_DROP, LOW);
}

//送り装置のソレノイド制御
void ballFall::ballRoad(bool state) {
  if (state == true)
    digitalWrite(PIN_SOL_ROAD, HIGH);
  else
    digitalWrite(PIN_SOL_ROAD, LOW);
}

//ソレノイドリセット
void ballFall::solReset() {
  digitalWrite(PIN_SOL_ROAD, LOW);
  digitalWrite(PIN_SOL_DROP, LOW);
}

//通過センサのチェック
bool ballFall::ballCheck() {
  if (analogRead(PIN_BALL_SENSOR) < THRESHOLD_BALL) return true;
  else return false;
}
