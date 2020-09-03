#include <SPI.h>
#include <HighPowerStepperDriver.h>
#include "ballFall.h"
#include "ballFlip.h"
#include "define.h"

long timeNow = 0;
long timeThen = 0;

//インスタンス生成
HighPowerStepperDriver sd;
ballFall bFall;
ballFlip bFlip;

void setup() {
  pinMode(PIN_STEP, OUTPUT);
  pinMode(PIN_DIR, OUTPUT);
  pinMode(PIN_SOL_FALL, OUTPUT);
  pinMode(PIN_SOL_LINE, OUTPUT);
  pinMode(PIN_SW, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_STEP, LOW);
  digitalWrite(PIN_DIR, LOW);

  bFall.ledFlash(); //LED点滅
  bFall.solReset(); //ソレノイドリセット

  SPI.begin();
  sd.setChipSelectPin(PIN_CS);

  //電源ONのための遅延
  delay(1);

  sd.resetSettings();
  sd.clearStatus();
  sd.setDecayMode(HPSDDecayMode::AutoMixed);
  sd.setCurrentMilliamps36v4(1000);
  sd.setStepMode(HPSDStepMode::MicroStep64); //分解能の設定
  sd.enableDriver();

  Serial.begin(115200);
  Serial.println("position resetting...");
  bFlip.posReset();
  Serial.println("system ready!");
}

void loop() {
  
  //1.トリガー待ち
  Serial.println("trigger waiting...");
  digitalWrite(PIN_LED, HIGH);
  while (1) {
    if (digitalRead(PIN_SW) == LOW)
        break;
    delay(10);
  }
  digitalWrite(PIN_LED, LOW);

  //2.ボール落下
  Serial.println("ball fall");
  bFall.ballDrop(true);
  delay(FLIP_DELAY);
  bFlip.flip(30); //打ち出し(引数:角度)

  //3.位置リセット
  delay(500);
  Serial.println("position resetting...");
  bFall.ballDrop(false);
  bFlip.posReset();

  //4.ボールロード
  Serial.println("ball loading...");
  bFall.ballRoad(true);
  delay(1000);
  bFall.ballRoad(false);

  //5.ボール通過待ち
  Serial.println("Waiting to pass...");
  timeThen = millis();
  while (bFall.ballCheck() == false) {
    timeNow = millis();
    if ((timeNow - timeThen) > TIMEOUT)
      break;
  }
  delay(1000);
}
