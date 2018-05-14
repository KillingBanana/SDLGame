#ifndef SDLGAME_KEYBOARDCONTROLLER_HPP
#define SDLGAME_KEYBOARDCONTROLLER_HPP

#include "Transform.hpp"

class KeyboardController : public Component {
public:
	Transform *transform;

	explicit KeyboardController(Entity *entity);

	void Start() override;

	void Update() override;
private:
	float speed = 64;
};

#endif //SDLGAME_KEYBOARDCONTROLLER_HPP
