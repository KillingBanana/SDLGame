#include "ECS.hpp"
//Component
//===============================================

Component::Component(Entity *entity) : entity(entity) {}

void Component::Start() {}

void Component::Update() {}

void Component::Draw() {}

Component::~Component() = default;


//===============================================
//Entity
//===============================================

Entity::Entity(std::string name) : name(std::move(name)) {}

void Entity::Update() {
	for (auto &component:components) component->Update();
}

void Entity::Draw() {
	for (auto &component:components) component->Draw();
}

bool Entity::IsActive() { return isActive; }

void Entity::Destroy() { isActive = false; }

std::ostream &operator<<(std::ostream &stream, Entity entity) {
	return stream << entity.name;
}


//===============================================
//Manager
//===============================================

void Manager::Update() {
	for (auto &entity:entities) entity->Update();
}

void Manager::Draw() {
	for (auto &entity:entities) entity->Draw();
}

void Manager::Refresh() {
	entities.erase(std::remove_if(std::begin(entities), std::end(entities),
	                              [](const std::unique_ptr<Entity> &mEntity) {
		                              return !mEntity->IsActive();
	                              }),
	               std::end(entities));
}

Entity &Manager::AddEntity(std::string name) {
	auto *entity = new Entity(std::move(name));
	std::unique_ptr<Entity> unique_ptr{entity};
	entities.emplace_back(std::move(unique_ptr));
	return *entity;
}