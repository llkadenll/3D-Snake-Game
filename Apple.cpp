#include "Apple.h"

Apple::Apple() {
	this->applePositions[0] = glm::vec3(0.0f, 2.0f, -10.0f);
	this->applePositions[1] = glm::vec3(0.0f, 2.0f, 25.0f);
	this->applePositions[2] = glm::vec3(12.0f, 2.0f, 34.0f);
	this->applePositions[3] = glm::vec3(12.0f, 2.0f, -15.0f);
	this->applePositions[4] = glm::vec3(5.0f, 2.0f, -28.0f);
	this->applePositions[5] = glm::vec3(-20.0f, 2.0f, -7.0f);
	this->applePositions[6] = glm::vec3(13.0f, 2.0f, -7.0f);
	this->applePositions[7] = glm::vec3(-20.5f, 2.0f, 15.5f);
	this->applePositions[8] = glm::vec3(17.0f, 2.0f, 29.0f);
	this->applePositions[9] = glm::vec3(11.2f, 2.0f, 38.3f);
	this->applePositions[10] = glm::vec3(-11.0f, 2.0f, 10.0f);
	this->applePositions[11] = glm::vec3(16.0f, 2.0f, -36.5f);
	this->applePositions[12] = glm::vec3(7.5f, 2.0f, -36.5f);
	this->applePositions[13] = glm::vec3(-19.0f, 2.0f, -14.0f);
	this->applePositions[14] = glm::vec3(-3.0f, 2.0f, 10.0f);

	this->appleAngle = 0.0f;
	this->appleSpeed = PI;
	this->color = 0;
	this->index = 5;
}

void Apple::draw(glm::mat4 P, glm::mat4 V) {
	glm::mat4 M = glm::mat4(1.0f);
	
	this->x_position = this->applePositions[this->index].x;
	this->z_position = this->applePositions[this->index].z;

	M = glm::translate(M, this->applePositions[this->index]);
	M = glm::rotate(M, this->appleAngle, glm::vec3(0.0f, 1.0f, 0.0f));
	M = glm::scale(M, glm::vec3(0.1f, 0.1f, 0.1f));

	drawingManagement(P, V, M);
}