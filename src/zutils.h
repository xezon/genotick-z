
#pragma once

#include <zorro.h>

inline void RemoveTradingCosts()
{
	Spread = 0;
	Commission = 0;
	RollLong = 0;
	RollShort = 0;
	Slippage = 0;
}

inline DATE convertTime(__time32_t t32)
{
	return (double)t32/(24.*60.*60.) + 25569.; // 25569. = DATE(1.1.1970 00:00)
}

inline __time32_t convertTime(DATE date)
{
	return (__time32_t)((date - 25569.)*24.*60.*60.);
}
