#include "Util.h"

int Util::Clamp(int value, int min, int max)
{
	if (value < min)
	{
		value = min;
	}
	else if (value > max)
	{
		value = max;
	}
	return value;
}

float Util::Clamp01(float value)
{
	if (double(value) < 0.0)
	{
		return 0.0f;
	}
	if (double(value) > 1.0)
	{
		return 1.0f;
	}
		
	return value;
}

float Util::Min(float a, float b)
{
	if (double(a) < double(b))
	{
		return a;
	}
	return b;
}

float Util::Max(float a, float b)
{
	if (double(a) > double(b))
	{
		return a;
	}
	return b;
}
