#ifndef SDLGAME_ECS_HPP
#define SDLGAME_ECS_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

constexpr std::size_t MaxComponents = 32;

using ComponentID = std::size_t;
using ComponentBitSet = std::bitset<MaxComponents>;
using ComponentArray = std::array<Component *, MaxComponents>;

inline ComponentID GetNewComponentTypeID() {
	static ComponentID lastID = 0u;
	return lastID++;
}

template<typename T>
inline ComponentID GetComponentTypeID() noexcept {
	static ComponentID typeID = GetNewComponentTypeID();
	return typeID;
}

class Component {
public:
	const Entity *entity;

	explicit Component(Entity *entity);
	virtual ~Component();

	virtual void Start();

	virtual void Update();

	virtual void Draw();
};

class Entity {
public:
	std::string name;

	explicit Entity(std::string name);

	void Update();

	void Draw();

	bool IsActive();

	void Destroy();

	friend std::ostream &operator<<(std::ostream &stream, Entity entity);

	template<typename T>
	bool HasComponent() const {
		return componentBitSet[GetComponentTypeID<T>()];
	}

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

private:
	bool isActive = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
};

class Manager {
public:
	void Update();

	void Draw();

	void Refresh();

	Entity &AddEntity(std::string name);

private:
	std::vector<std::unique_ptr<Entity>> entities;
};

#endif //SDLGAME_ECS_HPP
