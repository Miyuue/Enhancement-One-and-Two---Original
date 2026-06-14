#pragma once

#include <glm/glm.hpp>

// This simple struct is just for ease of use
// Author: Samuel Williamson
struct Transform
{
	glm::vec3 scaleXYZ, rotDegXYZ, positionXYZ;

	void Reset()
	{
		// Default transform
		positionXYZ = glm::vec3(0.0f, 0.0f, 0.0f);
		rotDegXYZ = glm::vec3(0.0f, 0.0f, 0.0f);
		scaleXYZ = glm::vec3(1.0f, 1.0f, 1.0f);
	}
};