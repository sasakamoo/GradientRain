#include "App.h"

void App::start() {
	if (demo.Construct(1280, 720, 1, 1))
		demo.Start();
}