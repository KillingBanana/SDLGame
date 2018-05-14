#include "Entity.hpp"
#include "Manager.hpp"

Entity::Entity(std::string name, Manager &manager) : name(std::move(name)), manager(manager) {}

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

bool Entity::HasGroup(Group group) {
	return groupBitset[group];
}

void Entity::AddGroup(Group group) {
	groupBitset[group] = true;
	manager.AddToGroup(this, group);
}

void Entity::AddGroups(std::initializer_list<Group> groups) {
	for (Group group:groups) {
		AddGroup(group);
	}
}

void Entity::RemoveGroup(Group group) {
	groupBitset[group] = false;
}

void Entity::RemoveGroups(std::initializer_list<Group> groups) {
	for (Group group:groups) {
		RemoveGroup(group);
	}
}
