#include "Collision.hpp"

bool Collision::AABB(const Collider &colliderA, const Collider &colliderB) {
	if (&colliderA == &colliderB) {
		return false;
	}

	SDL_Rect a = colliderA.rect;
	SDL_Rect b = colliderB.rect;

	return a.x + a.w >= b.x &&
	       b.x + b.w >= a.x &&
	       a.y + a.h >= b.y &&
	       b.y + b.h >= a.y;
}