#include "Debug_Log.h"

// show info on the screen
int g_ST_INFO_OPEN = 0;
// debug log Output to the local file
int g_DEBUG_LOG_FILE_OPEN = 0;
const char LogFileName[] = "./Debug.log";

void st_Log_T(const char *format, ...)
{
	st_Time_Info TimeInfo;
	char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";
	GetTime_ms(&TimeInfo, TimeBuf, sizeof(TimeBuf));

	FILE *pFile = fopen(LogFileName, "a");
	if (!pFile)
	{
		fprintf(stderr, "Error: Can not Open %s file!\n", LogFileName);
		return ;
	}
	fprintf(pFile, "%s ", TimeBuf);
	va_list ap;
	va_start(ap, format);
	vfprintf(pFile, format, ap);
	va_end(ap);
	fclose(pFile);
}

void st_print_T(const char *format, ...)
{
	st_Time_Info TimeInfo;
	char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";
	GetTime_ms(&TimeInfo, TimeBuf, sizeof(TimeBuf));

	fprintf(stderr, "%s ", TimeBuf);
	va_list ap;
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
}

void st_info_T(const char *format, ...)
{
	st_Time_Info TimeInfo;
	char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";
	GetTime_ms(&TimeInfo, TimeBuf, sizeof(TimeBuf));

	fprintf(stderr, "%s ", TimeBuf);
	va_list ap;
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);

	if (1 == g_DEBUG_LOG_FILE_OPEN)
	{
		FILE *pFile = fopen(LogFileName, "a");
		if (!pFile)
		{
			fprintf(stderr, "Error: Can not Open %s file!\n", LogFileName);
			return ;
		}
		fprintf(pFile, "%s ", TimeBuf);
		va_list ap;
		va_start(ap, format);
		vfprintf(pFile, format, ap);
		va_end(ap);
		fclose(pFile);
	}
}

void st_debug_T(const char *format, ...)
{
	if (1 == g_ST_INFO_OPEN)
	{
		st_Time_Info TimeInfo;
		char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";
		GetTime_ms(&TimeInfo, TimeBuf, sizeof(TimeBuf));

		fprintf(stderr, "%s ", TimeBuf);
		va_list ap;
		va_start(ap, format);
		vfprintf(stderr, format, ap);
		va_end(ap);
	}
	if (1 == g_DEBUG_LOG_FILE_OPEN)
	{
		st_Time_Info TimeInfo;
		char TimeBuf[] = "[YYYY-MM-DD hh:mm:ss.xxx]";
		GetTime_ms(&TimeInfo, TimeBuf, sizeof(TimeBuf));

		FILE *pFile = fopen(LogFileName, "a");
		if (!pFile)
		{
			fprintf(stderr, "Error: Can not Open %s file!\n", LogFileName);
			return ;
		}
		fprintf(pFile, "%s ", TimeBuf);
		va_list ap;
		va_start(ap, format);
		vfprintf(pFile, format, ap);
		va_end(ap);
		fclose(pFile);
	}
}

void st_print(const char *format, ...)
{
	if (1 == g_ST_INFO_OPEN)
	{
		va_list ap;
		va_start(ap, format);
		vfprintf(stderr, format, ap);
		va_end(ap);
	}
}

void st_info(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);

	if (1 == g_DEBUG_LOG_FILE_OPEN)
	{
		FILE *pFile = fopen(LogFileName, "a");
		if (!pFile)
		{
			fprintf(stderr, "Error: Can not Open %s file!\n", LogFileName);
			return ;
		}
		va_list ap;
		va_start(ap, format);
		vfprintf(pFile, format, ap);
		va_end(ap);
		fclose(pFile);
	}
}

void st_debug(const char *format, ...)
{
	if (1 == g_ST_INFO_OPEN)
	{
		va_list ap;
		va_start(ap, format);
		vfprintf(stderr, format, ap);
		va_end(ap);
	}
	if (1 == g_DEBUG_LOG_FILE_OPEN)
	{
		FILE *pFile = fopen(LogFileName, "a");
		if (!pFile)
		{
			fprintf(stderr, "Error: Can not Open %s file!\n", LogFileName);
			return ;
		}
		va_list ap;
		va_start(ap, format);
		vfprintf(pFile, format, ap);
		va_end(ap);
		fclose(pFile);
	}
}