#ifndef FENCE_H
#define FENCE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Loader.h"

class Fence :public Loader {
public:
	void draw(glm::mat4 P, glm::mat4 V, float angle_x, float angle_y, float angle_z, glm::vec3 position, float scale_x = 0.2f, float scale_y = 0.2f, float scale_z = 0.2f);
};

#endif