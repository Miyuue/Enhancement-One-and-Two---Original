#pragma once

// This simple struct is just for ease of use
// Author: Samuel Williamson
struct Color
{
	float r, g, b, a; // red, green, blue, alpha (transparency)

	void Reset()
	{
		r = g = b = a = 1.0f; // Set default color (white)
	}
};