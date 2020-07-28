/*
  TimerEvent.h
  타이머 처리를 위한 모듈
  시작 신호 후 일정 시간마다, 정해진 시간이 다 되었을 때 callback함수를 호출하는 모듈
  2017-12-19 jjh

  Pause기능 현재 미완성

  2017-12-22 jjh setInfinite함수 오류 수정
  2017-12-26 jjh addfinishTime 함수 추가
*/
#ifndef _TIMEREVENT_T
#define _TIMEREVENT_T

#define TIMEREVENT_STOP 0
#define TIMEREVENT_RUNNING 1
#define TIMEREVENT_PAUSE 2
#define TIMEREVENT_FINISH 3

class TimerEvent
{
  public:
		TimerEvent();
    void init();
    void start();
    void pause();
    void stop();
    void run();

    int getStatus();

    void setFinishTime(unsigned long ms);
    void setIntervalTime(unsigned long ms );
    void setInfinite(bool val);

	void addFinishTime(unsigned long ms);

    void setIntervalCallback(void (*func)());
    void setFinishCallback(void (*func)());

  private:
    bool mInfinite;
    int mStatus;
    
    void (*mIntervalFunc)();
    void (*mFinishFunc)();

    unsigned long mTimer;
    unsigned long mInterval;
    unsigned long mFinish;
    bool mIntervalChecker;

    void mIntervalCallback();
    void mFinishCallback();
};

#endif
