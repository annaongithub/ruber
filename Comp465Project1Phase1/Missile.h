#pragma once
# define __Windows__
#include "MoveableObj3D.h"
#include "../includes465/include465.hpp"

class Missile : public MoveableObj3D {
private:
	int updateFrameCount;
	float AORDirection;
	glm::vec3 AOR;
	glm::vec3 direction;
	glm::vec3 distance;
	glm::vec3 missileVector;
	glm::vec3 missileLocation;
	glm::vec3 translationAmount;
	glm::mat4 targetMatrixLocation;
	glm::quat quaternion;
public:
	Missile(float modelSize, float modelBoundingRadius);
	void update();
	void setDirection(glm::vec3 passedInDirection);
	glm::mat4 getTargetMatrixLocation();
	glm::vec3 getDirection();
	float getSpeed();
	int getUpdateFrameCount();
};