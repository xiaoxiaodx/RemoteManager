#ifndef _STTIME_H_
#define _STTIME_H_

#include <stdio.h>
#include <time.h> // localtime_r
#include <errno.h>

#if defined WINDOWS
#include <windows.h>
#elif defined LINUX
#include <unistd.h> // usleep
#include <string.h> // memset fd_set
#include <sys/time.h> // gettimeofday
#endif // #if defined WINDOWS

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int Year;
    int Mon;
    int Day;
    int Week;
    int Hour;
    int Min;
    int Sec;
    int mSec;
    unsigned long TimeTick_Sec;
    unsigned long long TimeTick_mSec;
} st_Time_Info;
#define ST_TIME_USED    (int)(TimeEnd.TimeTick_mSec-TimeBegin.TimeTick_mSec)
#define ST_TIME_USED_MS(TimeBegin, TimeEnd)    (int)(TimeEnd.TimeTick_mSec-TimeBegin.TimeTick_mSec)

#if defined(WIN32DLL) || defined(WINDOWS)
#define     SNPRINTF                _snprintf
#elif defined(LINUX)
#define     SNPRINTF                snprintf
#endif

void my_GetCurrentTime(st_Time_Info *Time);
// format to YYYY-MM-DD hh:mm:ss
void _TimeFormat_Sec(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize);
// format to YYYY-MM-DD hh:mm:ss.xxx
void _TimeFormat_ms(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize);
// format to [YYYY-MM-DD hh:mm:ss]
void TimeFormat_Sec(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize);
// format to [YYYY-MM-DD hh:mm:ss.xxx]
void TimeFormat_ms(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize);

// GetTime_ms: will call gettimeofday to get current time.
void _GetTime_Sec(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize);
// GetTime_ms: will call gettimeofday to get current time.
void _GetTime_ms(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize);
// GetTime_ms: will call gettimeofday to get current time.
void GetTime_Sec(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize);
// GetTime_ms: will call gettimeofday to get current time.
void GetTime_ms(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize);
void _mSecSleep(unsigned int ms);

#ifdef __cplusplus
}
#endif
#endif 	// _STTIME_H_
