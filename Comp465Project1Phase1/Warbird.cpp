#pragma once

#include "Warbird.h"


Warbird::Warbird(float modelSize, float modelBoundingRadius) : MoveableObj3D(modelSize, modelBoundingRadius) {
	updateFrameCount = 0;
	AORDirection = 0;
};

void Warbird::setDirection(glm::vec3 passedInDirection) {
	direction = passedInDirection;
}

glm::mat4 Warbird::getTargetMatrixLocation() {
	return targetMatrixLocation;
}

glm::vec3 Warbird::getDirection() {
	return direction;
}

int Warbird::getUpdateFrameCount() {
	return updateFrameCount;
}

void Warbird::update() {
	rotationMatrix = identity;
	translationMatrix = identity;

	// Update the orientation matrix of the missile
	orientationMatrix = orientationMatrix * translationMatrix * rotationMatrix;
}
