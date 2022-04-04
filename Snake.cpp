#include "Snake.h"

Snake::Snake() {
	this->playing = true;
	this->motion_x = 0.0;
	this->motion_z = -10.0;
	this->absSpeedValue = 1.0;
	this->speed_x = -this->absSpeedValue;
	this->speed_z = 0.0;
	this->rotateAngle = -4.65f;
	this->speeding = 0;
	this->score = 0;
}

bool Snake::deadlyCollisionDetection() {

	// well
	if (this->motion_x <= -16.0f && this->motion_z >= 36.0f) {
		return true;
	}

	//fence
	if (this->motion_z >= 48.0f || this->motion_z <= -42.0f ||
		this->motion_x >= 21.5f || this->motion_x <= -28.0f) {
		return true;
	}

	//wooden log
	if (this->motion_x <= 16.0f && this->motion_z >= 12.0f &&
		this->motion_z <= 18.0f && this->motion_x >= -10.0f) {
		return true;
	}

	//rock
	if (this->motion_x <= -0.5f && this->motion_z <= -17.0f &&
		this->motion_z >= -27.0f && this->motion_x >= -12.0f) {
		return true;
	}

	return false;
}

bool Snake::scoredCollisionDetection(Apple& apple) {
	if (this->motion_x <= apple.x_position + 4.5 &&
		this->motion_x >= apple.x_position - 4.5 &&
		this->motion_z >= apple.z_position - 4.5 &&
		this->motion_z <= apple.z_position + 4.5) {
		return true;
	}
	return false;
}

void Snake::draw(glm::mat4 P, glm::mat4 V, Apple& apple) {
	glm::mat4 M = glm::mat4(1.0f);

	M = glm::translate(M, glm::vec3(this->motion_x, 2.0f, this->motion_z));
	M = glm::rotate(M, -7.7f, glm::vec3(1.0f, 0.0f, 0.0f));
	M = glm::rotate(M, this->rotateAngle, glm::vec3(0.0f, 0.0f, 1.0f));
	M = glm::scale(M, glm::vec3(0.8f, 0.6f, 0.8f));

	drawingManagement(P, V, M);
}
