/*
File: MoveableObj3D.hpp
Description: Represent the scale, translation, and rotation of a 3D object.
*/
#ifndef __INCLUDES465__
#define __Windows__
#include "../../includes465/include465.hpp"
#endif

#ifndef MOVEABLEOBJ3D_H
#define MOVEABLEOBJ3D_H

class MoveableObj3D{

protected:

	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;
	glm::mat4 translationMatrix;
	glm::mat4 orientationMatrix;
	glm::mat4 modelMatrix;
	glm::mat4 identity;
	glm::vec3 scale;
	glm::vec3 rotationAxis;
	float rotationAmount;
	float modelSize;
	float modelBoundingRadius;
	bool orbit = false;

public:

	// Constructor
	MoveableObj3D(float modelSize, float modelBoundingRadius);

	// Returns the model matrix for the 3D object.
	glm::mat4 getModelMatrix();

	// Returns the rotational matrix for the 3D object.
	glm::mat4 getRotationMatrix();

	// Returns the orientation matrix for the 3D object.
	glm::mat4 getOrientationMatrix();

	glm::mat4 getTranslationMatrix();

	float getRotationAmount();

	// Translates the translation matrix by a passed in amount.
	void setTranslationMatrix(glm::vec3 passedTranslation);

	// Sets the translation matrix to an outside matrix.
	void setTranslationMatrix(glm::mat4 passedTranslationMatrix);

	// Sets the rotation matrix to an outside matrix.
	void setRotationMatrix(glm::mat4 passedRotationMatrix);

	// Sets the rotational rate for the 3D object.
	void setRotationAmount(float passedRadianAmount);

	// Sets the orientational matrix.
	void setOrientationMatrix(glm::mat4 newOrientation);

	// Sets the object flag to a planet orbit.
	void setOrbit();

	/* Changes the position of the object
	to a new position without affecting it's orientation.
	*/
	void setPosition(glm::vec3 newPosition);

	// Updates the rotation and orientation matrix.
	void update();
};

#endif