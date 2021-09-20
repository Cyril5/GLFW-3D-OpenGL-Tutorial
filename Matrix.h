#ifndef MATRIX4D_CLASS_H
#define MATRIX4D_CLASS_H

#include <glm/fwd.hpp>
#include <iostream>

#include<glm/gtc/matrix_transform.hpp>

class Matrix4D
{

	public:
		glm::mat4 value;

		Matrix4D(); // Créer une matrice d'identité --> glm::mat4(1.0)

		static void Translate(Matrix4D matrix, glm::vec3 vector);

		void Translate(glm::vec3 vector);
};

#endif
