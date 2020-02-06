#pragma once
#ifndef __UTIL__
#define __UTIL__
class Util
{
public:
	static int Clamp(int value, int min, int max);
	static float Clamp01(float value);
	static float Min(float a, float b);
	static float Max(float a, float b);
};
#endif /* defined (__UTIL__)*/