#include "Tail.h"

Tail::Tail(Snake& snake) {
	this->length = 2;
	for (int i = 1; i <= length; i++) {
		this->motion_x[i] = snake.motion_x + 1.5 * (i - 1);
		this->motion_z[i] = snake.motion_z;
		this->rotateAngle[i] = snake.rotateAngle;
	}
	this->speed_x = 0.0;
	this->speed_z = 0.0;
	this->absSpeedValue = 15.0;
}

void Tail::draw(glm::mat4 P, glm::mat4 V, Snake& snake, int level) {
	glm::mat4 M = glm::mat4(1.0f);

	M = glm::translate(M, glm::vec3(this->motion_x[level], 1.4f, this->motion_z[level]));
	M = glm::rotate(M, -4.25f, glm::vec3(1.0f, 0.0f, 0.0f));
	M = glm::rotate(M, this->rotateAngle[level], glm::vec3(0.0f, 0.0f, 1.0f));
	M = glm::scale(M, glm::vec3(0.2f, 0.1f, 0.3f));

	drawingManagement(P, V, M);
}

void Tail::movement(Snake& snake) {
	for (int i = this->length; i > 1; i--) {
		this->motion_x[i] = this->motion_x[i - 1];
		this->motion_z[i] = this->motion_z[i - 1];
		this->rotateAngle[i] = this->rotateAngle[i - 1];
	}
	this->motion_x[1] = snake.motion_x;
	this->motion_z[1] = snake.motion_z;
	this->rotateAngle[1] = snake.rotateAngle;
}

bool Tail::collision(Snake& snake) {
	for (int i = 2; i <= this->length; i++) {
		if (snake.motion_x == this->motion_x[i] && snake.motion_z == this->motion_z[i])
			return true;
	}
	return false;
}