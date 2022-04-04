#ifndef WOODENLOG_H
#define WOODENLOG_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Loader.h"

class WoodenLog :public Loader {
public:
	GLuint reflection_tex;

	void draw(glm::mat4 P, glm::mat4 V);
	void drawingManagement(glm::mat4 P, glm::mat4 V, glm::mat4 M);
};

#endif