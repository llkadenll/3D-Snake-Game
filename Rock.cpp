#include "Rock.h"

void Rock::draw(glm::mat4 P, glm::mat4 V) {
	glm::mat4 M = glm::mat4(1.0f);

	M = glm::translate(M, glm::vec3(-6.0f, 2.5f, -22.0f));
	M = glm::rotate(M, -1.6f, glm::vec3(1.0f, 0.0f, 0.0f));
	M = glm::scale(M, glm::vec3(3.0f, 3.0f, 3.0f));

	drawingManagement(P, V, M);
}