#include "Collider.hpp"
#include "../Game.hpp"

Collider::Collider(Entity *entity, int x, int y, int width, int height, std::string tag) : Component(entity), offset(x, y), size(width, height), tag(std::move(tag)) {}

void Collider::Start() {
	transform = entity->GetComponent<Transform>();
	Game::colliders.push_back(this);
}

void Collider::Update() {
	rect.w = size.x;
	rect.h = size.y;

	rect.x = transform->X() - rect.w / 2 + offset.x;
	rect.y = transform->Y() - rect.h / 2 + offset.y;
}
