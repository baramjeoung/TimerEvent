# TimerEvent
일정시간후 또는 일정시간마다 특정 callback 함수를 호출하는 라이브러리.

## 작성 목적
+ Arduino 시간함수를 사용한 반복에 익숙치 않은 신입 개발자를 위해 작성.
+ Callback함수를 지정하고 이를 적절한 타이밍에 호출하는 일종의 라이브러리 예제.

## 개요
+ [Constructor](#constructor)
+ [Reference](#reference)
  + [init](#init)
  + [start](#start)
  + [pause](#pause)
  + [stop](#stop)
  + [run](#run)
  + [getStatus](#getstatus)
  + [setFinishTime](#setfinishtime)
  + [setIntervalTime](#setintervaltime)
  + [setInfinite](#setinfinite)
  + [addFinishTime](#addfinishtime)
  + [setIntervalCallback](#setintervalcallback)
  + [setFinishCallback](#setfinishcallback)
+ Examples
  + [setFinishTime](./examples/setFinishTime/setFinishTime.ino)
  + [setIntervalTime](./examples/setIntervalTime/setIntervalTime.ino)
  + [setIntervalTimeInfinite](./examples/setIntervalTimeInfinite/setIntervalTimeInfinite.ino)
  
## Constructor
+ **Prototype:**
```cpp
TimerEvent::TimerEvent()
```
+ **Description:** 기본 생성자로 생성 시 ```init()```가 호출된다.
+ **Arguments:**
+ **Example:**
```cpp
TimerEvent Timer;
```

## Reference
### init
+ **Prototype:**
```cpp
void TimerEvent::init()
```
+ **Description:** ```TimerEvent```를 사용하기 위해 초기화한다. 별도로 호출하지 않아도 생성자에서 1회 실행된다.
+ **Arguments:**
+ **Return:**
+ **Example:**

### start
+ **Prototype:**
```cpp
void TimerEvent::start()
```
+ **Description:** 타이머를 시작 상태로 만든다.
+ **Arguments:**
+ **Return:**
+ **Example:**
```cpp
Timer.start();
```

### pause
+ **Prototype:**
```cpp
void TimerEvent::pause()
```
+ **Description:** 타이머를 일시정지 상태로 만든다. 현재 일시정지 관련 기능은 미구현이다.
+ **Arguments:**
+ **Return:**
+ **Example:**
```cpp
Timer.pause();
```

### stop
+ **Prototype:**
```cpp
void TimerEvent::stop()
```
+ **Description:** 타이머를 정지 상태로 만든다. 
+ **Arguments:**
+ **Return:**
+ **Example:**
```cpp
Timer.stop();
```

### run
+ **Prototype:**
```cpp
void TimerEvent::run()
```
+ **Description:** 타이머의 작동을 보장하기 위해 loop에서 항시 실행되어야 하는 함수이다.
+ **Arguments:**
+ **Return:**
+ **Example:**
```cpp
void loop()
{
  Timer.run();
}
```

### getStatus
+ **Prototype:**
```cpp
int TimerEvent::getStatus()
```
+ **Description:** 타이머의 현재 상태를 가져온다.
+ **Arguments:**
+ **Return:** 타이머의 현재 상태
```cpp
#define TIMEREVENT_STOP 0
#define TIMEREVENT_RUNNING 1
#define TIMEREVENT_PAUSE 2
#define TIMEREVENT_FINISH 3
```
+ **Example:**
```cpp
int status = Timer.getStatus();
```

### setFinishTime
+ **Prototype:**
```cpp
void TimerEvent::setFinishTime(unsigned long ms)
```
+ **Description:** 타이머를 실행하고 얼마 후에 종료할지 결정한다. 
+ **Arguments:** ```ms```: 타이머가 실행될 시간.
+ **Return:**
+ **Example:**
```cpp
Timer.setFinishTime(5000); //타이머 실행시키면 5초 후 종료
```

### setIntervalTime
+ **Prototype:**
```cpp
void TimerEvent::setIntervalTime(unsigned long ms)
```
+ **Description:** 타이머 실행 중 IntervalCallback함수를 어느 주기마다 호출할 지 결정한다.
+ **Arguments:** ```ms```: IntervalCallback함수 호출 주기
+ **Return:**
+ **Example:**
```cpp
Timer.setIntervalTime(1000); //타미어 실행시키면 1초마다 IntervalCallback 호출
```

### setInfinite
+ **Prototype:**
```cpp
void TimerEvent::setInfinite(bool val)
```
+ **Description:** 타이머 종료 없이 무한 반복 시킬 것인지 결정한다.
+ **Arguments:** ```val```: 타이머 무한 반복 여무
+ **Return:**
+ **Example:**
```cpp
Timer.setInfinite(true); //타이머 무한 반복. 초기값은 false
```

### addFinishTime
+ **Prototype:**
```cpp
void TimerEvent::addFinishTime(unsigned long ms)
```
+ **Description:** 타이머 종료시간을 늘려서 작동시간을 연장할 때 사용한다.
+ **Arguments:** ```ms```: 연장하려는 시간.
+ **Return:**
+ **Example:**
```cpp
Timer.addFinishTime(10000); //타이머 종료시간을 10초 연장한다.
```

### setIntervalCallback
+ **Prototype:**
```cpp
void TimerEvent::setIntervalCallback(void(*func))
```
+ **Description:** IntervalCallback을 설정하는 함수. 설정된 함수는 interval시간마다 반복해서 호출된다.
+ **Arguments:** ```*func```: 호출하고자 하는 함수의 포인터
+ **Return:**
+ **Example:**
```cpp
void callback()
{
  Serial.println("running");
}

Timer.setIntervalCallback(callback);
```

### setFinishCallback
+ **Prototype:**
```cpp
void TimerEvent::setFinishCallback(void (*func))
```
+ **Description:** FinishCallback을 설정하는 함수. 설정된 함수는 타이머 종료 시 호출된다.
+ **Arguments:** ```*func```: 호출하고자 하는 함수 포인터.
+ **Return:**
+ **Example:**
```cpp
void finish()
{
  Serial.println("end");
}

Timer.setFinishCallback(finish);
```

