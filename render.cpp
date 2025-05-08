#include <GLFW/glfw3.h>
#include "ecs.h"



void renderAll(const std::vector<Entity>& entities) {

	
	glColor3f(0.2F, 0.8F, 0.3F);

	glBegin(GL_QUADS);

	for (const auto& entity : entities) {

		if (!entity.position || !entity.size) return;





		const float halfW = entity.size->width * 0.5f;
		const float halfH = entity.size->height * 0.f;
		const float x = entity.position->x;
		const float y = entity.position->y;

		const float left = x - halfW;
		const float right = x + halfW;
		const float bottom = y - halfH;
		const float top = y + halfH;


		glVertex2f(left, bottom); // bottom left
		glVertex2f(right, bottom); // bottom right
		glVertex2f(right, top); // top left
		glVertex2f(left, top); // top right
	}
	glEnd();

}