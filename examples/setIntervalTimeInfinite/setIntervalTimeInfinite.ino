/*
  TimerEvent
  일정 시간마다 함수가 무한 반복하게 하는 예제
  2018-03-22 jjh
*/

#include <TimerEvent.h>

TimerEvent Timer;

void callback()
{
  Serial.print("Running: ");
  Serial.println(millis());
}

void setup()
{
  Serial.begin(115200);

  //반복 시간과 호출할 함수 설정
  Timer.setIntervalTime(1000);
  Timer.setIntervalCallback(callback);

  //무한반복 여부 설정
  Timer.setInfinite(true);
  Timer.start();

  Serial.print("Timer start: ");
  Serial.println(millis());
}

void loop()
{
  Timer.run();
}
