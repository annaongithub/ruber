#include "MoveableObj3D.h"
#include "Missile.h"

Missile::Missile(float modelSize, float modelBoundingRadius) : MoveableObj3D(modelSize, modelBoundingRadius){
	updateFrameCount = 0;
	AORDirection = 0;
};

void Missile::setDirection(glm::vec3 passedInDirection) {
	direction = passedInDirection;
}

glm::mat4 Missile::getTargetMatrixLocation() {
	return targetMatrixLocation;
}

glm::vec3 Missile::getDirection() {
	return direction;
}

int Missile::getUpdateFrameCount() {
	return updateFrameCount;
}

void Missile::update() {
	rotationMatrix = identity;
	translationMatrix = identity;

	// Update the orientation matrix of the missile
	orientationMatrix = orientationMatrix * translationMatrix * rotationMatrix;
}