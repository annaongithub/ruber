#pragma once
#define __Windows__
#include "../../includes465/include465.hpp"

class Camera {
private:
	glm::vec3 eye_;
	glm::vec3 at_;
	glm::vec3 up_;
public:
	void setEye(glm::vec3 eye);
	void setAt(glm::vec3 at);
	void setUp(glm::vec3 up);
	glm::vec3 getEye();
	glm::vec3 getAt();
	glm::vec3 getUp();
};