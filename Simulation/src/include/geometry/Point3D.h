#pragma once
#include "Vector3D.h"
#include "../algebra/PrecisionDouble.h"

class Point3D
{
private:
	PrecisionDouble x, y, z;
public:
	Point3D();
	Point3D(PrecisionDouble x, PrecisionDouble y, PrecisionDouble z);
	Point3D operator+ (Vector3D& vec) const;
	Point3D operator- (Vector3D& vec) const;
	void operator+= (Vector3D& vec);
	void operator-= (Vector3D& vec);
	Vector3D operator- (Point3D& p2) const;
	PrecisionDouble GetX() const;
	PrecisionDouble GetY() const;
	PrecisionDouble GetZ() const;
};