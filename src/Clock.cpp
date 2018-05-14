#include "Clock.hpp"

double Clock::deltaTime = 0;

Clock::Clock() : now(SDL_GetPerformanceCounter()), last(0) {}

void Clock::Tick() {
	last = now;
	now = SDL_GetPerformanceCounter();

	deltaTime = (double) (now - last) / SDL_GetPerformanceFrequency();
}