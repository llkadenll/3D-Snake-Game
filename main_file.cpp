#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <vector>

#include "constants.h"
#include "allmodels.h"
#include "lodepng.h"
#include "shaderprogram.h"
#include "Loader.h"
#include "Apple.h"
#include "WoodenLog.h"
#include "Rock.h"
#include "Well.h"
#include "Grass.h"
#include "Fence.h"
#include "Snake.h"
#include "Tail.h"

using namespace std;

int delay = floor(1000 / FPS);

Apple apple;
WoodenLog woodenLog;
Rock rock;
Well well;
Grass grass;
Fence fence;
Snake snake;
Tail tail(snake);

void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mod) {

	if (action == GLFW_PRESS) {

		if (key == GLFW_KEY_LEFT && (snake.rotateAngle != -4.65f)) {
			snake.speed_x = snake.absSpeedValue;
			snake.speed_z = 0;
			snake.rotateAngle = -7.87f;
		}
		if (key == GLFW_KEY_RIGHT && (snake.rotateAngle != -7.87f)) {
			snake.speed_x = -snake.absSpeedValue;
			snake.speed_z = 0;
			snake.rotateAngle = -4.65f;
		}
		if (key == GLFW_KEY_UP && (snake.rotateAngle != 0.0f)) {
			snake.speed_z = snake.absSpeedValue;
			snake.speed_x = 0;
			snake.rotateAngle = -9.45f;
		}
		if (key == GLFW_KEY_DOWN && (snake.rotateAngle != -9.45f)) {
			snake.speed_z = -snake.absSpeedValue;
			snake.speed_x = 0;
			snake.rotateAngle = 0.0f;
		}
		if (key == GLFW_KEY_SPACE) {
			apple.tex = apple.gold_tex;
			apple.color = 1;
		}
	}

	if (action == GLFW_RELEASE) {
		if (key == GLFW_KEY_SPACE) {
			apple.tex = apple.red_tex;
			apple.color = 0;
		}
	}
}

void initOpenGLProgram(GLFWwindow* window) {
	initShaders();

	woodenLog.tex = woodenLog.readTexture("models/log/log_tex.png");
	apple.red_tex = apple.readTexture("models/apple/apple_tex.png");
	apple.gold_tex = apple.readTexture("models/apple/gold_tex.png");
	apple.tex = apple.red_tex;
	apple.color = 0;
	rock.tex = rock.readTexture("models/rock/rock_tex.png");
	well.tex = well.readTexture("models/well/well_tex.png");
	grass.tex = grass.readTexture("models/grass/grass_tex.png");
	fence.tex = fence.readTexture("models/fence/fence_tex.png");
	snake.tex = snake.readTexture("models/snake/snake_tex.png");
	tail.tex = tail.readTexture("models/snake/snake_tex.png");

	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);

	woodenLog.loadModel(string("models/log/log_model.obj"));
	rock.loadModel(string("models/rock/rock_model.fbx"));
	well.loadModel(string("models/well/well_model.fbx"));
	grass.loadModel(string("models/grass/grass_model.obj"));
	fence.loadModel(string("models/fence/fence_model.fbx"));
	snake.loadModel(string("models/snake/snake_model.fbx"));
	tail.loadModel(string("models/tail/barrel.fbx"));
	apple.loadModel(string("models/apple/apple_model.fbx"));

	glfwSetKeyCallback(window, key_callback);
}

void freeOpenGLProgram(GLFWwindow* window) {
	glDeleteTextures(1, &(woodenLog.tex));
	glDeleteTextures(1, &(rock.tex));
	glDeleteTextures(1, &(well.tex));
	glDeleteTextures(1, &(fence.tex));
	glDeleteTextures(1, &(grass.tex));
	glDeleteTextures(1, &(snake.tex));
	glDeleteTextures(1, &(tail.tex));
	glDeleteTextures(1, &(apple.red_tex));
	glDeleteTextures(1, &(apple.gold_tex));
	glDeleteTextures(1, &(apple.tex));
}

void drawScene(GLFWwindow* window, float angle_y, float angle_x) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 P = glm::perspective(glm::radians(50.0f), 1.0f, 0.1f, 200.0f);
	glm::mat4 V = glm::lookAt(
		glm::vec3(0.0f, 75.0f, -75.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);

	// I line from bottom
	grass.draw(P, V, glm::vec3(0.0f, 0.0f, -3.0f));
	grass.draw(P, V, glm::vec3(-5.95f, 0.0f, -3.0f));
	grass.draw(P, V, glm::vec3(5.95f, 0.0f, -3.0f));
	// II line
	grass.draw(P, V, glm::vec3(0.0f, 0.0f, 2.95f));
	grass.draw(P, V, glm::vec3(-5.95f, 0.0f, 2.95f));
	grass.draw(P, V, glm::vec3(5.95f, 0.0f, 2.95f));
	// III line
	grass.draw(P, V, glm::vec3(-7.5f, 0.0f, 8.9f));
	grass.draw(P, V, glm::vec3(-1.6f, 0.0f, 8.9f));
	grass.draw(P, V, glm::vec3(4.3f, 0.0f, 8.9f));
	grass.draw(P, V, glm::vec3(10.2f, 0.0f, 8.9f));
	// IV line
	grass.draw(P, V, glm::vec3(-8.7f, 0.0f, 14.8f));
	grass.draw(P, V, glm::vec3(-2.75f, 0.0f, 14.8f));
	grass.draw(P, V, glm::vec3(3.2f, 0.0f, 14.8f));
	grass.draw(P, V, glm::vec3(9.15f, 0.0f, 14.8f));

	//bottom
	fence.draw(P, V, -1.3f, 0.0f, 0.0f, glm::vec3(-8.3f, 0.0f, -45.0f), 0.225f);
	//left
	fence.draw(P, V, -1.3f, 4.71f, -0.27f, glm::vec3(24.1f, 0.0f, -24.0f));
	fence.draw(P, V, -1.3f, 4.71f, -0.27f, glm::vec3(24.0f, 0.0f, 22.0f));
	//right
	fence.draw(P, V, -1.55f, -4.71f, 0.0f, glm::vec3(-30.0f, 0.0f, -14.0f));
	fence.draw(P, V, -1.55f, -4.71f, 0.0f, glm::vec3(-29.88f, -0.8f, 30.5f));
	//up
	fence.draw(P, V, -1.3f, 3.13f, 0.0f, glm::vec3(2.2f, 0.0f, 50.0f), 0.222f);

	well.draw(P, V);
	rock.draw(P, V);
	woodenLog.draw(P, V);
	apple.draw(P, V);
	snake.draw(P, V, apple);

	for (int i = 1; i <= tail.length; i++) {
		tail.draw(P, V, snake, i);
	}

	glfwSwapBuffers(window);
}

int main(void) {

	GLFWwindow* window;

	srand(time(NULL));

	glfwSetErrorCallback(error_callback);

	if (!glfwInit()) {
		fprintf(stderr, "GLFW could not be initialized.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Python", NULL, NULL);

	if (!window) {
		fprintf(stderr, "Unable to create window.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "GLFW could not be initialized.\n");
		exit(EXIT_FAILURE);
	}

	initOpenGLProgram(window);

	float angle_y = 0;
	float angle_x = 0;
	int previousIndex;

	glfwSetTime(0);

	while (!glfwWindowShouldClose(window)) {
		if (!snake.playing) break;
		if (snake.speeding > 0) {
			snake.speeding--;
		} else {
			delay = 1000 / FPS;
		}

		if (snake.scoredCollisionDetection(apple)) {

			// if the apple is gold 2 points are added
			if (apple.color == 1) {
				snake.score += 2;

				// after eating a golden apple, the snake speeds up 8 times
				if (delay == floor(1000 / FPS)) delay /= 8;

				// for 60 cycles (1 second) the hose moves faster
				snake.speeding = 60;
			}
			else {
				snake.score++;
			}

			tail.length++;

			// a newly added tail in place of the last tail
			tail.motion_x[tail.length] = tail.motion_x[tail.length - 1];
			tail.motion_z[tail.length] = tail.motion_z[tail.length - 1];

			// draws the array index with the apple's position
			previousIndex = apple.index;
			do {
				apple.index = rand() % 14 + 1;
			} while (apple.index == previousIndex);
		}

		if (snake.deadlyCollisionDetection() || tail.collision(snake)) {
			snake.playing = false;
		}

		angle_y += snake.speed_x * glfwGetTime();
		angle_x += snake.speed_z * glfwGetTime();

		if (snake.speed_x != 0 || snake.speed_z != 0) {
			if (snake.speed_x > 0)
				snake.motion_x += 0.5;
			else if (snake.speed_x < 0)
				snake.motion_x -= 0.5;
			else if (snake.speed_z > 0)
				snake.motion_z += 0.5;
			else if (snake.speed_z < 0)
				snake.motion_z -= 0.5;

			tail.movement(snake);
		}

		Sleep(delay);

		apple.appleAngle += apple.appleSpeed * glfwGetTime();
		glfwSetTime(0);
		drawScene(window, angle_y, angle_x);
		glfwPollEvents();

	}

	printf("Game Over. Your score is: %d\n", snake.score);

	freeOpenGLProgram(window);
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
