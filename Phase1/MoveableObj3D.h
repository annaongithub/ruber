#pragma once
#define __Windows__
#include "../../includes465/include465.hpp"

class MoveableObj3D {

private:
	const int id_;
	char* modelFileName_;
	const GLuint nVertices;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;
	glm::mat4 translationMatrix;
	glm::vec3 rotationAxis;
	float radians;
	bool orbital;

public:
	MoveableObj3D(int number);
	glm::mat4 getModelMatrix(void);
	void setModelFileName(char* fileName);
	void update(void);
	
	//vectors for models
	glm::vec4 vertex();
	glm::vec3 normal();
	glm::vec4 diffuseColorMaterial();
};