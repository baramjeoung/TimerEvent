/*
  TimerEvent.cpp
  타이머 처리를 위한 모듈
  시작 신호 후 일정 시간마다, 정해진 시간이 다 되었을 때 callback함수를 호출하는 모듈
  2017-12-19 jjh
*/
#include "TimerEvent.h"
#include "Arduino.h"

TimerEvent::TimerEvent()
{
	//생성시 초기화 한다.
	init();
}

void TimerEvent::init()
{
  mStatus = TIMEREVENT_STOP;
  mTimer = 0;
  mInterval = 0;
  mFinish = 0;
  mIntervalFunc = 0;
  mFinishFunc = 0;
  mInfinite = false;
  mIntervalChecker = false;
}

void TimerEvent::start()
{
	if( mStatus == TIMEREVENT_STOP )  mTimer = millis();
  mStatus = TIMEREVENT_RUNNING;
}

void TimerEvent::stop()
{
  mStatus = TIMEREVENT_STOP;
}

void TimerEvent::pause()
{
  mStatus = TIMEREVENT_PAUSE;
}

void TimerEvent::run()
{
  if ( mStatus == TIMEREVENT_RUNNING)
  {
    unsigned long curtime = millis();
    if ( !mInfinite && curtime - mTimer > mFinish )
    {
      mStatus = TIMEREVENT_FINISH;
      mFinishCallback();
    }
    else
    {
      if( mInterval == 0 ) return;
      if ( (curtime - mTimer ) % (mInterval*2) > mInterval)
      {
        if ( !mIntervalChecker )
        {
          mIntervalCallback();
          mIntervalChecker = true;
        }
      }
      else
      {
        if ( mIntervalChecker )
        {
          mIntervalCallback();
          mIntervalChecker = false;
        }
      }
    }
  }
}

int TimerEvent::getStatus()
{
  return mStatus;
}

void TimerEvent::setIntervalTime(unsigned long ms)
{
  mInterval = ms;
}

void TimerEvent::setFinishTime(unsigned long ms)
{
  mFinish = ms;
}

void TimerEvent::setInfinite(bool val)
{
  //작동중이 아닐 때만 설정 가능
  if ( mStatus == TIMEREVENT_RUNNING || mStatus == TIMEREVENT_PAUSE ) return;
  mInfinite = val;
}

void TimerEvent::addFinishTime(unsigned long ms)
{
	if( mStatus == TIMEREVENT_RUNNING )	mFinish += ms;
	else
	{
		setFinishTime(ms);
		start();
	}
}

void TimerEvent::setIntervalCallback(void (*func)())
{
  mIntervalFunc = func;
}

void TimerEvent::setFinishCallback(void (*func)())
{
  mFinishFunc = func;
}

void TimerEvent::mFinishCallback()
{
  if ( mFinishFunc != 0 ) mFinishFunc();
}

void TimerEvent::mIntervalCallback()
{
  if ( mIntervalFunc != 0 ) mIntervalFunc();
}

