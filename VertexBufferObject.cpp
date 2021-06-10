#include "VertexBufferObject.h"

VertexBufferObject::VertexBufferObject(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID); // creation du vbo
	glBindBuffer(GL_ARRAY_BUFFER, ID); // bind vbo
	// introduit les vertices dans le vbo
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VertexBufferObject::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VertexBufferObject::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBufferObject::Delete() {
	glDeleteBuffers(1, &ID);
}
