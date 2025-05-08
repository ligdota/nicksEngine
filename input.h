#ifndef INPUT_H
#define INPUT_H
#include "GLFW/glfw3.h"
#include "ecs.h"
void processInput(GLFWwindow* window, Entity& player);

void clampPosition(Position& pos, const Size& size);


#endif
