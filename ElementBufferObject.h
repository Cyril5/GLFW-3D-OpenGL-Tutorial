#pragma once

#include<glad/glad.h>
#include <vector>

class ElementBufferObject
{
	public:
		GLuint ID;
		//ElementBufferObject(GLuint* indices, GLsizeiptr size);

		ElementBufferObject(std::vector<GLuint>& indices);

		void Bind();
		void Unbind();
		void Delete();
};

