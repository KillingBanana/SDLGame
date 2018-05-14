#ifndef SDLGAME_COMPONENT_HPP
#define SDLGAME_COMPONENT_HPP

class Entity;

class Component {
public:
	const Entity *entity;

	explicit Component(Entity *entity);
	virtual ~Component();

	virtual void Start();

	virtual void Update();

	virtual void Draw();
};

#endif //SDLGAME_COMPONENT_HPP
