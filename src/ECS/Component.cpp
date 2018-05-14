#include "Component.hpp"

Component::Component(Entity *entity) : entity(entity) {}

void Component::Start() {}

void Component::Update() {}

void Component::Draw() {}

Component::~Component() = default;