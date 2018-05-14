#ifndef SDLGAME_COLLISION_HPP
#define SDLGAME_COLLISION_HPP

#include <SDL.h>
#include "ECS/Collider.hpp"

class Collision {
public:
	static bool AABB(const Collider &colliderA, const Collider &colliderB);
private:
};

#endif //SDLGAME_COLLISION_HPP
