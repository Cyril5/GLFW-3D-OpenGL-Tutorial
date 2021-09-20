#include "Matrix.h"


Matrix4D::Matrix4D() 
{
	value = glm::mat4(1.0); // créer une nouvelle matrice d'identité
}



void Matrix4D::Translate(Matrix4D matrix,glm::vec3 vector)
{
	glm::translate(matrix.value,vector);
}

void Matrix4D::Translate(glm::vec3 vector)
{
	glm::translate(value, vector);
}
