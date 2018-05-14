#ifndef SDLGAME_POSITIONCOMPONENT_HPP
#define SDLGAME_POSITIONCOMPONENT_HPP

#include "../Vector2.hpp"
#include "Entity.hpp"

class Transform : public Component {
public:
	Transform(Entity *entity, int x, int y);
	Vector2 position, velocity = Vector2(0, 0);

	void Update() override;

	///position.x cast to an int
	int X();

	///position.y cast to an int
	int Y();

	///position cast to a Vector2int
	Vector2int IntPosition();
};

#endif //SDLGAME_POSITIONCOMPONENT_HPP
