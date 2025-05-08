#ifndef ECS_H
#define ECS_H

#include <vector>
#include <memory>

struct Position {
	float x, y;
	Position(float x = 0.0f, float y = 0.0f);
};

struct Velocity {
	float velX, velY;
	Velocity(float x = 0.0f, float y = 0.0f);
};


struct Size {
	float width;
	float height;
	Size(float w = 0.1f, float h = 0.1f);
};


class Entity {
public:
	int id;
	std::unique_ptr<Position> position;
	std::unique_ptr<Velocity> velocity;
	std::unique_ptr<Size> size;

	explicit Entity(int id);

};


class ECS {
public:
	std::vector<Entity> entities;

	Entity& createEntity();
	void update(float deltaTime);

	
};


#endif