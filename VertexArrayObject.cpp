#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject()
{
	glGenVertexArrays(1, &ID); // creation du vao
}

void VertexArrayObject::LinkVBO(VertexBufferObject& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) 
{
	VBO.Bind();
	/*
	*  layout : emplacement
	*  numComponents : par exemple 3 si ont stocke des vecteurs3
	* dernier param : offset
	*/
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout); // on place les elements au premier emplacement

	VBO.Unbind();
}

void VertexArrayObject::Bind() 
{
	glBindVertexArray(ID); // bind du vao
}

void VertexArrayObject::Unbind()
{
	glBindVertexArray(0); // unbind le vao 
}

void VertexArrayObject::Delete() 
{
	glDeleteVertexArrays(1, &ID); // suppression du VAO

}