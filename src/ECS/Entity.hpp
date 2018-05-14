#ifndef SDLGAME_ENTITY_HPP
#define SDLGAME_ENTITY_HPP

#include "ECS.hpp"

class Manager;

class Entity {
public:
	std::string name;

	explicit Entity(std::string name, Manager &manager);

	void Update();

	void Draw();

	bool IsActive();

	void Destroy();

	friend std::ostream &operator<<(std::ostream &stream, Entity entity);

	template<typename T, typename ...TArgs>
	T *AddComponent(TArgs &&...args) {
		T *component = new T(this, std::forward<TArgs>(args)...);
		std::unique_ptr<Component> unique_ptr{component};
		components.emplace_back(std::move(unique_ptr));

		componentArray[GetComponentTypeID<T>()] = component;
		componentBitSet[GetComponentTypeID<T>()] = true;

		component->Start();

		return component;
	}

	template<typename T>
	T *GetComponent() const {
		if (!HasComponent<T>()) return nullptr;
		auto *ptr(componentArray[GetComponentTypeID<T>()]);

		return static_cast<T *>(ptr);
	}

	template<typename T>
	bool HasComponent() const {
		return componentBitSet[GetComponentTypeID<T>()];
	}

	bool HasGroup(Group group);

	void AddGroup(Group group);
	void AddGroups(std::initializer_list<Group> groups);

	void RemoveGroup(Group group);
	void RemoveGroups(std::initializer_list<Group> groups);

private:
	Manager &manager;
	bool isActive = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
	GroupBitset groupBitset;
};

#endif //SDLGAME_ENTITY_HPP
