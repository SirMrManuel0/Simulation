#include "../Point3D.h"
#include "../../algebra/PrecisionDouble.h"

Point3D::Point3D() : x(PrecisionDouble(0,0)), y(PrecisionDouble(0,0)), z(PrecisionDouble(0,0)) {}
Point3D::Point3D(PrecisionDouble x, PrecisionDouble y, PrecisionDouble z) : x(x), y(y), z(z) {}

Point3D Point3D::operator+ (Vector3D& vec) const
{
	return Point3D(x + vec.GetX(), y + vec.GetY(), z + vec.GetZ());
}
void Point3D::operator+= (Vector3D& vec)
{
	x += vec.GetX();
	y += vec.GetY();
	z += vec.GetZ();
}

Point3D Point3D::operator- (Vector3D& vec) const
{
	return Point3D(x - vec.GetX(), y - vec.GetY(), z - vec.GetZ());
}
void Point3D::operator-= (Vector3D& vec)
{
	x -= vec.GetX();
	y -= vec.GetY();
	z -= vec.GetZ();
}

Vector3D Point3D::operator- (Point3D& p2) const
{
	return Vector3D(x - p2.GetX(), y - p2.GetY(), z - p2.GetZ());
}

PrecisionDouble Point3D::GetX() const { return x; }
PrecisionDouble Point3D::GetY() const { return y; }
PrecisionDouble Point3D::GetZ() const { return z; }