#include "Transform.hpp"
#include "../Clock.hpp"

Transform::Transform(Entity *entity, int x, int y) : Component(entity), position(x, y) {}

void Transform::Update() {
	position += Clock::DeltaTime() * velocity;
}

int Transform::X() {
	return static_cast<int>(position.x);
}

int Transform::Y() {
	return static_cast<int>(position.y);
}

Vector2int Transform::IntPosition() {
	return {X(), Y()};
}
