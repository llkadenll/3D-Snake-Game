#ifndef TAIL_H
#define TAIL_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Loader.h"
#include "Snake.h"

class Tail :public Loader {
public:
	float speed_x;
	float speed_z;
	float motion_x[200];
	float motion_z[200];
	float rotateAngle[200];
	float absSpeedValue;
	int length;

	Tail(Snake& snake);
	void draw(glm::mat4 P, glm::mat4 V, Snake& snake, int level);
	void movement(Snake& snake);
	bool collision(Snake& snake);
};

#endif