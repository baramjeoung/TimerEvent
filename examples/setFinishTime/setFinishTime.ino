/*
  TimerEvent
  정해진 시간이 되면 함수가 작동하게 하는 예제
  2018-03-22 jjh
*/

#include <TimerEvent.h>

TimerEvent Timer;

void callback()
{
  Serial.print("Timer end: ");
  Serial.println(millis());
}

void setup()
{
  Serial.begin(115200);

  //종료 시간과 호출할 함수 설정
  Timer.setFinishTime(5000);
  Timer.setFinishCallback(callback);
  Timer.start();

  Serial.print("Timer start: ");
  Serial.println(millis());
}

void loop()
{
  Timer.run();
}
