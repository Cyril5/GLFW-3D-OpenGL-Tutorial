#include "Mesh.h"

const unsigned int VECTOR3_TOTAL_ELEMENT = 3;
const unsigned int VECTOR2_TOTAL_ELEMENT = 2;


Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures) 
{
	Mesh::vertices = vertices;
	Mesh::indices = indices;
	Mesh::textures = textures;

	VAO.Bind();

	VertexBufferObject VBO(vertices);
	ElementBufferObject EBO(indices);

	// Link vertex to VAO
	// Link the positions first
	VAO.LinkVBO(VBO, 0, VECTOR3_TOTAL_ELEMENT, GL_FLOAT, sizeof(Vertex), (void*)0);
	// lier les normals
	VAO.LinkVBO(VBO, 1, VECTOR3_TOTAL_ELEMENT, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	// lier les colors
	VAO.LinkVBO(VBO, 2, VECTOR3_TOTAL_ELEMENT, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
	//link texture coords
	VAO.LinkVBO(VBO, 3, VECTOR2_TOTAL_ELEMENT, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));

	VAO.Unbind();
	VBO.Unbind();
	EBO.Unbind();
}

void Mesh::Draw(Shader& shader, Camera& camera, glm::vec3 translation, glm::vec3 scale)
{
	shader.Activate();
	VAO.Bind();

	unsigned int numDiffuse = 0;
	unsigned int numSpecular = 0;

	for (unsigned int i = 0; i < textures.size(); i++)
	{
		std::string num;
		std::string type = textures[i].type;

		if (type == "diffuse")
		{
			num = std::to_string(numDiffuse++);
		}
		else if ("specular") {
			num = std::to_string(numSpecular++);
		}

		textures[i].texUnit(shader, (type + num).c_str(), i);
		textures[i].Bind();
	}

	// Take care of the camera Matrix
	glUniform3f(glGetUniformLocation(shader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
	camera.Matrix(shader, "camMatrix");

	// Initialize matrices
	glm::mat4 trans = glm::mat4(1.0f);
	glm::mat4 scal = glm::mat4(1.0f);

	// Transform the matrices to their correct form
	trans = glm::translate(trans, translation);
	scal = glm::scale(scal, scale);

	// Push the matrices to the vertex shader
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "translation"), 1, GL_FALSE, glm::value_ptr(trans));
	//glUniformMatrix4fv(glGetUniformLocation(shader.ID, "rotation"), 1, GL_FALSE, glm::value_ptr(rot));
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "scale"), 1, GL_FALSE, glm::value_ptr(scal));

	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(trans * scal));

	// Draw the actual mesh
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}
