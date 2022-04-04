#include "Grass.h"

void Grass::draw(glm::mat4 P, glm::mat4 V, glm::vec3 position) {
	
	glm::mat4 M = glm::mat4(1.0f);

	M = glm::scale(M, glm::vec3(8.0f, 8.0f, 8.0f));
	M = glm::translate(M, position);

	drawingManagement(P, V, M);
}