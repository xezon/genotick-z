
#define ZORRO_DLLMAIN
#define ZORRO_EXPECT_ALL_FUNCTIONS
#define ZORRO_USE_EVENT_CLASS
#include "zorro_impl.h"
#include "genotick.h"

CGenotick g_genotick;

void CZorroEvents::main()
{
	set(EZorroFlag::OPENEND);
	set(EZorroFlag::TICKS);
	LookBack = 0;
	BarPeriod = PERIOD_D1;
	StartDate = 20130101;
	EndDate = 20150101;

	g_genotick.Init();

	for (uint32_t assetId = 0; string assetName = Assets[assetId]; ++assetId)
	{
		asset(assetName);
	}
}

void CZorroEvents::run()
{

}

void CZorroEvents::tick()
{

}

void CZorroEvents::tock()
{

}

void CZorroEvents::click(int row, int col)
{
	(void)row;
	(void)col;
}

void CZorroEvents::evaluate(const PERFORMANCE* pPerformance)
{
	(void)pPerformance;
}

var CZorroEvents::objective()
{
	return objectivePRR();
}

EOrderResult CZorroEvents::order(EOrderAction type)
{
	(void)type;

	return EOrderResult::OK;
}

var CZorroEvents::neural(ENeuralMode mode, int model, int numSignals, const void* pData)
{
	(void)mode;
	(void)model;
	(void)numSignals;
	(void)pData;

	return 0.0;
}

EBarAction CZorroEvents::bar(cvars open, cvars high, cvars low, cvars close, cvars price, DATE start, DATE time)
{
	(void)open;
	(void)high;
	(void)low;
	(void)close;
	(void)price;
	(void)start;
	(void)time;

	return EBarAction::CLOSE_NORMALLY;
}
