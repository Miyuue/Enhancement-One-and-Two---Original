#pragma once

#include "MeshObject.h"
#include <vector>

// This is a class enabling multiple MeshObjects to be collected together, and have their individual transforms
// be relative to a central transform. This allows for a complex "mesh" to be constructed from multiple simple
// meshes, as well as the ability to move the individual meshes (or MeshObjects) as one cohesive unit (or CompositeMeshObject).
// Author: Samuel Williamson

class CompositeMeshObject
{
private:
	Transform transform;
	std::vector<MeshObject> children;

public:
	CompositeMeshObject() { transform.Reset(); }

	void AddChild(MeshObject child) { children.push_back(child); }

	std::vector<MeshObject> GetChildren() { return children; }

	void SetTransform(Transform transform);
};