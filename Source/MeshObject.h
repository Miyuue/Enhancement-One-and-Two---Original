#pragma once

#include "Transform.h"
#include "Color.h"
#include <string>

// This is a simple struct for containing the typical data that would be associated with
// rendering a mesh. It helps simplify the rendering and collection of such data.
// Author: Samuel Williamson

enum Mesh
{
	BOX,
	CONE,
	CYLINDER,
	PLANE,
	PRISM,
	SPHERE,
	TAPERED_CYLINDER,
	TORUS
};

struct MeshObject
{
	Transform transform;
	Color color;
	Mesh mesh;
	std::string texture = "NONE";
	std::string material = "NONE";
};