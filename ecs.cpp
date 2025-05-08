#include "ecs.h"

Position::Position(float x, float y) : x(x), y(y) {}
Velocity::Velocity(float x, float y) : velX(x), velY(y) {}
Size::Size(float w, float h) : width(w), height(h) {}


Entity::Entity(int id) : id(id) {}



Entity& ECS::createEntity() {
	entities.push_back(Entity(entities.size()));
	return entities.back();
}


void ECS::update(float deltaTime) {
	for (auto& entity : entities) {
		if (entity.position && entity.velocity) {
			entity.position->x += entity.velocity->velX * deltaTime;
			entity.position->y += entity.velocity->velY * deltaTime;
		}
	}
}