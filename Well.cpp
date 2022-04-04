#include "Well.h"

void Well::draw(glm::mat4 P, glm::mat4 V) {
	glm::mat4 M = glm::mat4(1.0f);

	M = glm::translate(M, glm::vec3(-21.05f, 0.0f, 42.0f));
	M = glm::rotate(M, -2.3f, glm::vec3(0.0f, 1.0f, 0.0f));
	M = glm::scale(M, glm::vec3(6.0f, 6.0f, 6.0f));

	drawingManagement(P, V, M);
}