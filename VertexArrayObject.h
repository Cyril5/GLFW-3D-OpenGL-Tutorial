#pragma once

#include<glad/glad.h>
#include"VertexBufferObject.h"

class VertexArrayObject
{
	public:
		GLuint ID;
		VertexArrayObject();

		//void LinkVBO(VertexBufferObject VBO, GLuint layout);
		void LinkVBO(VertexBufferObject& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
		void Bind();
		void Unbind();
		void Delete();
};

