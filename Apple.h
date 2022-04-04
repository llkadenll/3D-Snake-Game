#ifndef APPLE_H
#define APPLE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <time.h>

#include "constants.h"
#include "Loader.h"

class Apple :public Loader {
public:
	GLuint gold_tex;
	GLuint red_tex;
	float appleAngle;
	float appleSpeed;
	float x_position;
	float z_position;
	bool color; // 0 - red, 1 - gold
	int index;
	glm::vec3 applePositions[15];

	Apple();
	void draw(glm::mat4 P, glm::mat4 V);
};

#endif