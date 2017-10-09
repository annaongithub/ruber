#include "MoveableObj3D.h"

MoveableObj3D::MoveableObj3D(float modelSize, float modelBoundingRadius) {
	// Scale the model to the desired size
	scale = glm::vec3(modelSize / modelBoundingRadius);
	scaleMatrix = glm::scale(glm::mat4(), glm::vec3(scale));

	identity = glm::mat4();		// initialize the identity matrix

								// No initial rotation, orientation, or translation
	rotationMatrix = identity;
	orientationMatrix = identity;
	translationMatrix = identity;

	modelMatrix = identity;

	rotationAxis = glm::vec3(0, 1, 0);
}

glm::mat4 MoveableObj3D::getModelMatrix() {
	return orientationMatrix * scaleMatrix;
}

glm::mat4 MoveableObj3D::getRotationMatrix() { 
	return rotationMatrix;
}

glm::mat4 MoveableObj3D::getOrientationMatrix()
{
	return orientationMatrix;
}

glm::mat4 MoveableObj3D::getTranslationMatrix()
{
	return translationMatrix;
}

float MoveableObj3D::getRotationAmount()
{
	return rotationAmount;
}

void MoveableObj3D::setTranslationMatrix(glm::vec3 passedTranslation)
{
	translationMatrix = glm::translate(translationMatrix, passedTranslation);
}

void MoveableObj3D::setTranslationMatrix(glm::mat4 passedTranslationMatrix)
{
	translationMatrix = passedTranslationMatrix;
}

void MoveableObj3D::setRotationMatrix(glm::mat4 passedRotationMatrix)
{
	rotationMatrix = passedRotationMatrix;
}

void MoveableObj3D::setRotationAmount(float passedRadianAmount)
{
	rotationAmount = passedRadianAmount;
}

// Sets the orientational matrix.
void MoveableObj3D::setOrientationMatrix(glm::mat4 newOrientation)
{
	orientationMatrix = newOrientation;
}

// Sets the object flag to a planet orbit.
void MoveableObj3D::setOrbit()
{
	orbit = true;
}

/* Changes the position of the object
to a new position without affecting it's orientation.
*/
void MoveableObj3D::setPosition(glm::vec3 newPosition)
{
	orientationMatrix[3][0] = newPosition.x;
	orientationMatrix[3][1] = newPosition.y;
	orientationMatrix[3][2] = newPosition.z;
}

// Updates the rotation and orientation matrix.
void MoveableObj3D::update()
{
	rotationMatrix = glm::rotate(rotationMatrix, rotationAmount, rotationAxis);

	// Set the orientation matrix based on what type of object it is:
	if (orbit == true)
	{
		orientationMatrix = rotationMatrix * translationMatrix;
	}
	else
	{
		orientationMatrix = translationMatrix * rotationMatrix;
	}
}