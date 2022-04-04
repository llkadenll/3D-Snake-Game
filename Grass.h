#ifndef GRASS_H
#define GRASS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Loader.h"

class Grass :public Loader {
public:
	void draw(glm::mat4 P, glm::mat4 V, glm::vec3 position);
};

#endif