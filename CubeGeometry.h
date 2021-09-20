#pragma once

#include <glad/glad.h>

class CubeGeometry {

public:

	// Attention il n'y a que les vertex coordinates

	GLfloat vertices[24] =
	{
		-0.1f, -0.1f,  0.1f,
		-0.1f, -0.1f, -0.1f,
		0.1f, -0.1f, -0.1f,
		0.1f, -0.1f,  0.1f,
		-0.1f,  0.1f,  0.1f,
		-0.1f,  0.1f, -0.1f,
		0.1f,  0.1f, -0.1f,
		0.1f,  0.1f,  0.1f
	};

	GLuint indices[3*12]
	{
		0, 1, 2,
		0, 2, 3,
		0, 4, 7,
		0, 7, 3,
		3, 7, 6,
		3, 6, 2,
		2, 6, 5,
		2, 5, 1,
		1, 5, 4,
		1, 4, 0,
		4, 5, 6,
		4, 6, 7
	};

};