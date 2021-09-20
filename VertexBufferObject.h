#ifndef VERTEX_BUFFER_OBJECT_CLASS_H
#define VERTEX_BUFFER_OBJECT_CLASS_H

#include<glad/glad.h>
#include <glm/glm.hpp>
#include <vector>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texUV;
};

class VertexBufferObject
{
	public:
		GLuint ID;

		//Avant : VertexBufferObject(GLfloat* vertices, GLsizeiptr size);
		VertexBufferObject(std::vector<Vertex>& vertices);

		void Bind();
		void Unbind();
		void Delete();
};

#endif