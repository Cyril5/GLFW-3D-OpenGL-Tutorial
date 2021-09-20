#ifndef PLANE_GEOMETRY_CLASS_H
#define PLANE_GEOMETRY_CLASS_H

#include <glad/glad.h>
#include <vector>

class PlaneGeometry {

public:

	// Vertices coordinates
	GLfloat vertices[(3 + 3 + 2 + 3)*4] =
	{ //     COORDINATES     /        COLORS        /    TexCoord    /       NORMALS     //
		-1.0f, 0.0f,  1.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,		0.0f, 1.0f, 0.0f,
		-1.0f, 0.0f, -1.0f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f,		0.0f, 1.0f, 0.0f,
		 1.0f, 0.0f, -1.0f,		0.0f, 0.0f, 0.0f,		1.0f, 1.0f,		0.0f, 1.0f, 0.0f,
		 1.0f, 0.0f,  1.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f,		0.0f, 1.0f, 0.0f
	};

	// Indices for vertices order
	GLuint indices[6] =
	{
		0, 1, 2,
		0, 2, 3
	};

};

#endif
