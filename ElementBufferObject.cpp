#include "ElementBufferObject.h"

ElementBufferObject::ElementBufferObject(GLuint* indices, GLsizeiptr size) 
{
	glGenBuffers(1, &ID); // creation du ebo
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID); // bind ebo
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void ElementBufferObject::Bind() 
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID); // bind ebo
}

void ElementBufferObject::Unbind() 
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); //unbind le ebo
}

void ElementBufferObject::Delete() 
{
	glDeleteBuffers(1, &ID); // suppression du EBO
}