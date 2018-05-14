#ifndef SDLGAME_MAP_HPP
#define SDLGAME_MAP_HPP

#include "ECS/ECS.hpp"
#include <fstream>

class Map {
public:
	static void Load(const char *path);
private:
	static bool Parse(char c, int *result);
	static bool ParseUntil(std::fstream *stream, char sep, int *result);
};

#endif //SDLGAME_MAP_HPP
