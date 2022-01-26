#include "GradientRain.h"

int main()
{
	GradientRain demo;
	if (demo.Construct(1280, 720, 1, 1))
		demo.Start();
	return 0;
}