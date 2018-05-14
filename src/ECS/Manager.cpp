#include "Manager.hpp"

void Manager::Update() {
	Refresh();
	for (auto &entity:entities) entity->Update();
}

void Manager::Draw() {
	//for (auto &entity:entities) entity->Draw();
	for (auto &tile:GetGroup(TileGroup)) tile->Draw();
	for (auto &enemy:GetGroup(EnemyGroup)) enemy->Draw();
	for (auto &player:GetGroup(PlayerGroup)) player->Draw();
}

void Manager::Refresh() {
	for (Group i = 0u; i < MaxGroups; i++) {
		auto &v(groupedEntities[i]);
		v.erase(std::remove_if(std::begin(v), std::end(v), [i](Entity *entity) {
					return !entity->IsActive() || !entity->HasGroup(i);
				}), std::end(v)
		);
	}

	entities.erase(std::remove_if(std::begin(entities), std::end(entities), [](const std::unique_ptr<Entity> &entity) {
		return !entity->IsActive();
	}), std::end(entities));
}

Entity &Manager::AddEntity(std::string name) {
	auto *entity = new Entity(std::move(name), *this);
	std::unique_ptr<Entity> unique_ptr{entity};
	entities.emplace_back(std::move(unique_ptr));
	return *entity;
}

void Manager::AddToGroup(Entity *entity, Group group) {
	groupedEntities[group].emplace_back(entity);
}

std::vector<Entity *> &Manager::GetGroup(Group group) {
	return groupedEntities[group];
}
