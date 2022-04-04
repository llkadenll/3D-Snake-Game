#ifndef SNAKE_H
#define SNAKE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Loader.h"
#include "Apple.h"

class Snake :public Loader {
public:
	bool playing;
	float speed_x;
	float speed_z;
	float motion_x;
	float motion_z;
	float rotateAngle;
	float absSpeedValue;
	int speeding;
	int score;

	Snake();
	void draw(glm::mat4 P, glm::mat4 V, Apple& apple);
	bool scoredCollisionDetection(Apple& apple);
	bool deadlyCollisionDetection();
};

#endif
