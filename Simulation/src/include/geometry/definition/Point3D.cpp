#include "../Point3D.h"

Point3D::Point3D() : x(0), y(0), z(0) {}
Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

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

double Point3D::GetX() const { return x; }
double Point3D::GetY() const { return y; }
double Point3D::GetZ() const { return z; }