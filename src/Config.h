#pragma once
#ifndef __CONFIG__
#define __CONFIG__
#include <basetsd.h>

// Singleton
class Config
{
public:
	Config() = default;
	~Config() = default;
	
	static const UINT32 WIDTH = 800;
	static const UINT32 HEIGHT = 600;
	static const UINT32 FPS = 60;
	static const UINT32 DELAY_TIME = 1000.0f / FPS;
	
};

#endif /* defined (__CONFIG) */