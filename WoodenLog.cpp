#include "WoodenLog.h"

void WoodenLog::draw(glm::mat4 P, glm::mat4 V) {
	glm::mat4 M = glm::mat4(1.0f);

	M = glm::translate(M, glm::vec3(3.0f, 0.5f, 13.0f));
	M = glm::rotate(M, 13.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	M = glm::rotate(M, -1.6f, glm::vec3(0.0f, 1.0f, 0.0f));
	M = glm::scale(M, glm::vec3(0.1f, 0.1f, 0.1f));

	drawingManagement(P, V, M);
}

void WoodenLog::drawingManagement(glm::mat4 P, glm::mat4 V, glm::mat4 M) {
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
