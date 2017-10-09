#include "MoveableObj3D.h"
#include "../../includes465/include465.hpp"

MoveableObj3D::MoveableObj3D(int id){
	id_ = id;
	int random = rand();
	switch (random % 4) {
	case 0: scaleMatrix = glm::scale(glm::mat4(), glm::vec3(20, 20, 20)); break;
	case 1: scaleMatrix = glm::scale(glm::mat4(), glm::vec3(20, 30, 40)); break;
	case 2: scaleMatrix = glm::scale(glm::mat4(), glm::vec3(30, 40, 20)); break;
	case 3: scaleMatrix = glm::scale(glm::mat4(), glm::vec3(40, 20, 30)); break;
	default: printf("Shape:: randomRotate selection error \n");
		exit(-1); 
	}

	rotationMatrix = glm::mat4();	//no initial orientation
	//Set cube's rotation axis and rotation radians
	switch (random % 3) {
	case 0: rotationAxis = glm::vec3(1,  0,  0); break;
	case 1: rotationAxis = glm::vec3(0,  1,  0); break;
	case 2: rotationAxis = glm::vec3(0,  0, -1); break;
	default: printf("Shape: randomRotate selection error \n");
		exit(-1);
	}

	//rotate between 0.1 and 2.0 degrees
	radians = glm::radians(0.1f + (random % 20) / 10.0f);
	//random initial placement +/- 500 from origin in X, Y, Z
	translationMatrix = glm::translate(glm::mat4(), 
		glm::vec3(-500 + rand() % 1000, -500 + rand() % 1000,
				  -500 + rand() % 1000));
	//determine rotation type
	orbital = (random % 2 == 0) ? true : false;
}

glm::mat4 MoveableObj3D::getModelMatrix() {
	//orbital rotation
	if (orbital) 
		return (rotationMatrix * translationMatrix * scaleMatrix);
	else
		return (translationMatrix, rotationMatrix, scaleMatrix);
}

void MoveableObj3D::update() {
	rotationMatrix = glm::rotate(rotationMatrix, radians, rotationAxis);
	//translationMatrix = glm::translate(translationMatrix, translation);
}