#include "Fence.h"

void Fence::draw(glm::mat4 P, glm::mat4 V, float angle_x, float angle_y, float angle_z, glm::vec3 position, float scale_x, float scale_y, float scale_z) {
	glm::mat4 M = glm::mat4(1.0f);

	M = glm::translate(M, position);
	M = glm::rotate(M, angle_x, glm::vec3(1.0f, 0.0f, 0.0f));
	M = glm::rotate(M, angle_y, glm::vec3(0.0f, 0.0f, 1.0f));
	M = glm::rotate(M, angle_z, glm::vec3(0.0f, 1.0f, 0.0f));
	M = glm::scale(M, glm::vec3(scale_x, scale_y, scale_z));

	drawingManagement(P, V, M);
}