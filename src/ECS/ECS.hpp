#ifndef SDLGAME_ECS_HPP
#define SDLGAME_ECS_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include "Component.hpp"

using ComponentID = std::size_t;
constexpr ComponentID MaxComponents = 32;
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

using Group = std::size_t;
constexpr Group MaxGroups = 32;
using GroupBitset = std::bitset<MaxGroups>;

enum GroupLabel : Group {
	TileGroup,
	ColliderGroup,
	CharacterGroup,
	PlayerGroup,
	EnemyGroup,
};

#endif //SDLGAME_ECS_HPP
