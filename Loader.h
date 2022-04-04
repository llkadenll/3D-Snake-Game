#ifndef LOADER_H
#define LOADER_H

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
#include "lodepng.h"
#include "shaderprogram.h"

using namespace std;

class Loader {
public:
	GLuint tex;
	vector<glm::vec4> verts;
	vector<glm::vec4> norms;
	vector<glm::vec2> texCoords;
	vector<unsigned int> indices;

	void loadModel(string file);
	GLuint readTexture(const char* filename);
	virtual void draw(glm::mat4 P, glm::mat4 V, float angle_y);
	virtual void drawingManagement(glm::mat4 P, glm::mat4 V, glm::mat4 M);
};

#endif
