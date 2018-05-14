#ifndef SDLGAME_CLOCK_HPP
#define SDLGAME_CLOCK_HPP

#include <SDL.h>

class Clock {
public:
	Clock();

	void Tick();

	static double DeltaTime() { return deltaTime; }

private:
	Uint64 now, last;
	static double deltaTime;
};

#endif //SDLGAME_CLOCK_HPP
