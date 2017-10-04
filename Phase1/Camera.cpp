#define __Windows__
#include "../../includes465/include465.hpp"
#include "Camera.h"

void Camera::setEye(glm::vec3 eye) {
	eye_ = eye;
}

void Camera::setAt(glm::vec3 at) {
	at_ = at;
}

void Camera::setUp(glm::vec3 up) {
	up_ = up;
}

glm::vec3 Camera::getEye() {
	return eye_;
}

glm::vec3 Camera::getAt() {
	return at_;
}

glm::vec3 Camera::getUp() {
	return up_;
}