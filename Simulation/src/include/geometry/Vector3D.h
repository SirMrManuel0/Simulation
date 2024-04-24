#pragma once
#include "../algebra/PrecisionDouble.h"

class Vector3D {
public:
	Vector3D();
	Vector3D(PrecisionDouble x, PrecisionDouble y, PrecisionDouble z);
	Vector3D operator+ (Vector3D& vec2) const;
	void operator+= (Vector3D& vec2);
	Vector3D operator- (Vector3D& vec2) const;
	Vector3D operator- ();
	void operator-= (Vector3D& vec2);
	PrecisionDouble operator* (Vector3D& vec2) const;
	Vector3D operator* (PrecisionDouble scalar) const;
	void operator*= (PrecisionDouble scalar);
	Vector3D operator* (double scalar) const;
	void operator*= (double scalar);
	bool operator|| (Vector3D& vec2) const;
	bool operator== (Vector3D& vec2) const;
	PrecisionDouble GetX() const;
	PrecisionDouble GetY() const;
	PrecisionDouble GetZ() const;
	PrecisionDouble Length() const;
	enum AXIS { X, Y, Z };
	Vector3D rotate(double Theta, AXIS axis) const;
private:
	PrecisionDouble x, y, z;
};