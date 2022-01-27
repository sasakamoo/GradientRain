#include "GradientRain.h"
#include "Poly.h"

int main()
{
	Poly demo;
	if (demo.Construct(1280, 720, 1, 1))
		demo.Start();
	return 0;
}