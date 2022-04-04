#include "Loader.h"

using namespace std;

void Loader::loadModel(string file) {
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(file,
		aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenSmoothNormals);
	cout << importer.GetErrorString() << endl;

	aiMesh* mesh = scene->mMeshes[0];

	for (int i = 0; i < mesh->mNumVertices; i++) {
		aiVector3D vertex = mesh->mVertices[i];
		verts.push_back(glm::vec4(vertex.x, vertex.y, vertex.z, 1));

		aiVector3D normal = mesh->mNormals[i];
		norms.push_back(glm::vec4(normal.x, normal.y, normal.z, 0));

		aiVector3D texCoord = mesh->mTextureCoords[0][i];
		texCoords.push_back(glm::vec2(texCoord.x, texCoord.y));
	}

	for (int i = 0; i < mesh->mNumFaces; i++) {
		aiFace& face = mesh->mFaces[i];

		for (int j = 0; j < face.mNumIndices; j++) {
			indices.push_back(face.mIndices[j]);
		}
	}

	aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

	for (int i = 0; i < 19; i++) {
		std::cout << i << " " << material->GetTextureCount((aiTextureType)i) << endl;
	}
}

GLuint Loader::readTexture(const char* filename) {
	GLuint tex;
	glActiveTexture(GL_TEXTURE0);

	vector<unsigned char> image;
	unsigned width, height;
	unsigned error = lodepng::decode(image, width, height, filename);

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
				 GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return tex;
}

void Loader::draw(glm::mat4 P, glm::mat4 V, float angle_y) {}

void Loader::drawingManagement(glm::mat4 P, glm::mat4 V, glm::mat4 M) {
	spShader->use();
	glUniformMatrix4fv(spShader->u("P"), 1, false, glm::value_ptr(P));
	glUniformMatrix4fv(spShader->u("V"), 1, false, glm::value_ptr(V));
	glUniformMatrix4fv(spShader->u("M"), 1, false, glm::value_ptr(M));

	glEnableVertexAttribArray(spShader->a("vertex"));
	glVertexAttribPointer(spShader->a("vertex"), 4, GL_FLOAT, false, 0, this->verts.data());

	glEnableVertexAttribArray(spShader->a("normal"));
	glVertexAttribPointer(spShader->a("normal"), 4, GL_FLOAT, false, 0, this->norms.data());

	glEnableVertexAttribArray(spShader->a("texCoord"));
	glVertexAttribPointer(spShader->a("texCoord"), 2, GL_FLOAT, false, 0, this->texCoords.data());

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->tex);
	glUniform1i(spShader->u("tex"), 0);

	glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, this->indices.data());

	glDisableVertexAttribArray(spShader->a("vertex"));
	glDisableVertexAttribArray(spShader->a("normal"));
	glDisableVertexAttribArray(spShader->a("texCoord"));
}
