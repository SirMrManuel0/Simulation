#pragma once
#include "Vector3D.h"

class Point3D
{
private:
	double x, y, z;
public:
	Point3D();
	Point3D(double x, double y, double z);
	Point3D operator+ (Vector3D& vec) const;
	void operator+= (Vector3D& vec);
	Vector3D operator- (Point3D& p2) const;
	double GetX() const;
	double GetY() const;
	double GetZ() const;
};