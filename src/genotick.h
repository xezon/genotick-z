
#pragma once

#include <igenotick.h>
#include <igenotick_utils.h>

class CGenotick
{
public:
	~CGenotick();
	bool Init();
	void Shutdown();

private:
	void CreateConsole();
	void DestroyConsole();

	IGenotick* m_pGenotick = nullptr;
	bool m_bSpawnedConsole = false;
};
