#ifndef SDLGAME_MANAGER_HPP
#define SDLGAME_MANAGER_HPP

#include <memory>
#include <vector>
#include "Entity.hpp"

class Manager {
public:
	void Update();
	void Draw();
	Entity &AddEntity(std::string name);
	void AddToGroup(Entity *entity, Group group);
	std::vector<Entity *> &GetGroup(Group group);

private:
	std::vector<std::unique_ptr<Entity>> entities;
	std::array<std::vector<Entity *>, MaxGroups> groupedEntities;
	void Refresh();
};
#endif //SDLGAME_MANAGER_HPP
