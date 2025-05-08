#include "input.h"


extern float aspectRatio;

void processInput(GLFWwindow* window, Entity& player)
{

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) 
		 player.position->y += 0.1f;
	
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) 
		 player.position->y -= 0.1f;

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) 
		 player.position->x -= 0.1f;
	
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) 
		 player.position->x += 0.1f;
	
	clampPosition(*player.position, *player.size);
}




void clampPosition(Position& pos, const Size& size) {
	float halfWidth = size.width / 2.0f;
	float halfHeight = size.height / 2.0f;

	float maxX = aspectRatio - halfWidth;
	float minX = -aspectRatio + halfWidth;
	float maxY = 1.0f - halfHeight;
	float minY = -1.0f + halfHeight;

	if (pos.x > maxX) pos.x = maxX;
	if (pos.x < minX) pos.x = minX;
	if (pos.y > maxY) pos.y = maxY;
	if (pos.y < minY) pos.y = minY;

}