#include "CompositeMeshObject.h"

void CompositeMeshObject::SetTransform(Transform transform)
{
	// Set each child MeshObject's position relative to the composite's position
	for (MeshObject& child : children)
	{
		child.transform.positionXYZ += transform.positionXYZ;
	}

	this->transform = transform; // Set the central CompositeMeshObjects transform
}
