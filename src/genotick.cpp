
#pragma comment(lib, "genotickcpplib.lib")

#include "genotick.h"
#include <common/util_log.h>

#define GENOTICK_DEBUG 0

CGenotick::~CGenotick()
{
	Shutdown();
}

bool CGenotick::Init()
{
	CreateConsole();

	util::clog("Initializing Genotick Z");

	TGenotickCreationSettings settings;
	settings.utf8jvmDllPath = "C:\\Program Files (x86)\\Java\\jre1.8.0_144\\bin\\client\\jvm.dll";
	settings.javaClassPath = "include\\genotick\\genotick.jar";
#if GENOTICK_DEBUG
	settings.javaDebugAddress = "127.0.0.1:8888";
#endif

	EGenotickResult result = GenotickGetOrCreate(&m_pGenotick, &settings);

	if (result != EGenotickResult::Success)
	{
		util::clog("Failed to start Genotick");
		return false;
	}
	return true;
}

void CGenotick::Shutdown()
{
	DestroyConsole();
}

void CGenotick::CreateConsole()
{
	if (GenotickSpawnConsole() == EGenotickResult::Success)
	{
		m_bSpawnedConsole = true;
	}
}

void CGenotick::DestroyConsole()
{
	if (m_bSpawnedConsole)
	{
		GenotickDestroyConsole();
		m_bSpawnedConsole = false;
	}
}
