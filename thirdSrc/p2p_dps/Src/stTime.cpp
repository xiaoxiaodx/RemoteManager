#include "stTime.h"

void _mSecSleep(unsigned int ms)
{
#if defined(WIN32DLL) || defined(WINDOWS)
    Sleep(ms);
#elif defined LINUX
    usleep(ms * 1000);
#endif
}

void my_GetCurrentTime(st_Time_Info *Time)
{
#if  defined(WINDOWS) || defined(WIN32DLL)
    SYSTEMTIME mTime = {0};
    GetLocalTime(&mTime);
    Time->Year = mTime.wYear;
    Time->Mon = mTime.wMonth;
    Time->Day = mTime.wDay;
    Time->Week = mTime.wDayOfWeek;
    Time->Hour = mTime.wHour;
    Time->Min = mTime.wMinute;
    Time->Sec = mTime.wSecond;
    Time->mSec = mTime.wMilliseconds;
    Time->TimeTick_Sec = time(NULL);
    Time->TimeTick_mSec = GetTickCount();
#elif defined(LINUX)
    struct timeval mTime;
    int ret = gettimeofday(&mTime, NULL);
    if (0 != ret)
    {
        printf("gettimeofday failed!! errno=%d\n", errno);
        memset(Time, 0, sizeof(st_Time_Info));
        return ;
    }
    //struct tm *ptm = localtime((const time_t *)&mTime.tv_sec);
    struct tm st_tm = {0};
    struct tm *ptm = localtime_r((const time_t *)&mTime.tv_sec, &st_tm);
    if (!ptm)
    {
        printf("localtime_r failed!!\n");
        memset(Time, 0, sizeof(st_Time_Info));
        Time->TimeTick_mSec = ((unsigned long long)mTime.tv_sec)*1000 + mTime.tv_usec/1000; // ->ms
    }
    else
    {
        Time->Year = st_tm.tm_year+1900;
        Time->Mon = st_tm.tm_mon+1;
        Time->Day = st_tm.tm_mday;
        Time->Week = st_tm.tm_wday;
        Time->Hour = st_tm.tm_hour;
        Time->Min = st_tm.tm_min;
        Time->Sec = st_tm.tm_sec;
        Time->mSec = (int)(mTime.tv_usec/1000);
        Time->TimeTick_Sec = mTime.tv_sec; // 1970年1月1日0点至今的秒数。
        Time->TimeTick_mSec = ((unsigned long long)mTime.tv_sec)*1000 + mTime.tv_usec/1000; // ->ms
    }
#endif
}

// format to YYYY-MM-DD hh:mm:ss
void _TimeFormat_Sec(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize)
{
    if (!TimeInfo || !TimeBuf || 0 == TimeBufSize) return ;
    SNPRINTF(TimeBuf, TimeBufSize, "%04d-%02d-%02d %02d:%02d:%02d",
                                                        TimeInfo->Year,
                                                        TimeInfo->Mon,
                                                        TimeInfo->Day,
                                                        TimeInfo->Hour,
                                                        TimeInfo->Min,
                                                        TimeInfo->Sec);
}

// format to YYYY-MM-DD hh:mm:ss.xxx
void _TimeFormat_ms(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize)
{
    if (!TimeInfo || !TimeBuf || 0 == TimeBufSize) return ;
    SNPRINTF(TimeBuf, TimeBufSize, "%04d-%02d-%02d %02d:%02d:%02d.%03d",
                                                        TimeInfo->Year,
                                                        TimeInfo->Mon,
                                                        TimeInfo->Day,
                                                        TimeInfo->Hour,
                                                        TimeInfo->Min,
                                                        TimeInfo->Sec,
                                                        TimeInfo->mSec);
}

// format to [YYYY-MM-DD hh:mm:ss]
void TimeFormat_Sec(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize)
{
    if (!TimeInfo || !TimeBuf || 0 == TimeBufSize) return ;
    SNPRINTF(TimeBuf, TimeBufSize, "[%04d-%02d-%02d %02d:%02d:%02d]",
                                                        TimeInfo->Year,
                                                        TimeInfo->Mon,
                                                        TimeInfo->Day,
                                                        TimeInfo->Hour,
                                                        TimeInfo->Min,
                                                        TimeInfo->Sec);
}

// format to [YYYY-MM-DD hh:mm:ss.xxx]
void TimeFormat_ms(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize)
{
    if (!TimeInfo || !TimeBuf || 0 == TimeBufSize) return ;
    SNPRINTF(TimeBuf, TimeBufSize, "[%04d-%02d-%02d %02d:%02d:%02d.%03d]",
                                                        TimeInfo->Year,
                                                        TimeInfo->Mon,
                                                        TimeInfo->Day,
                                                        TimeInfo->Hour,
                                                        TimeInfo->Min,
                                                        TimeInfo->Sec,
                                                        TimeInfo->mSec);
}

// GetTime_ms: will call gettimeofday to get current time.
void _GetTime_Sec(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize)
{
    if (!TimeInfo || !TimeBuf || 0 == TimeBufSize) return ;
    my_GetCurrentTime(TimeInfo);
    _TimeFormat_Sec(TimeInfo, TimeBuf, TimeBufSize);
}

// GetTime_ms: will call gettimeofday to get current time.
void _GetTime_ms(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize)
{
    if (!TimeInfo || !TimeBuf || 0 == TimeBufSize) return ;
    my_GetCurrentTime(TimeInfo);
    _TimeFormat_ms(TimeInfo, TimeBuf, TimeBufSize);
}

// GetTime_ms: will call gettimeofday to get current time.
void GetTime_Sec(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize)
{
    if (!TimeInfo || !TimeBuf || 0 == TimeBufSize) return ;
    my_GetCurrentTime(TimeInfo);
    TimeFormat_Sec(TimeInfo, TimeBuf, TimeBufSize);
}
// GetTime_ms: will call gettimeofday to get current time.
void GetTime_ms(st_Time_Info *TimeInfo, char *TimeBuf, unsigned int TimeBufSize)
{
    if (!TimeInfo || !TimeBuf || 0 == TimeBufSize) return ;
    my_GetCurrentTime(TimeInfo);
    TimeFormat_ms(TimeInfo, TimeBuf, TimeBufSize);
}
