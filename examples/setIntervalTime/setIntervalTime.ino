/*
  TimerEvent
  일정 시간마다 함수가 작동하고 정해진 시간이 되면 반복을 종료하는 예제
  2018-03-22 jjh
*/

#include <TimerEvent.h>

TimerEvent Timer;

void callback()
{
  Serial.print("Running: ");
  Serial.println(millis());
}

void lastcallback()
{
  Serial.print("Timer end: ");
  Serial.println(millis());
}

void setup()
{
  Serial.begin(115200);

  //종료 시간과 호출할 함수 설정
  Timer.setFinishTime(5500);
  Timer.setFinishCallback(lastcallback);

  //반복 시간과 호출할 함수 설정
  Timer.setIntervalTime(1000);
  Timer.setIntervalCallback(callback);

  //무한반복 여부 설정
  Timer.setInfinite(false); //기본값이 false이므로 선언하지 않아도 된다.
  Timer.start();

  Serial.print("Timer start: ");
  Serial.println(millis());
}

void loop()
{
  Timer.run();
}
