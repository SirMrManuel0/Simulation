#include "../Vector3D.h"
#include <cmath>
#include <iostream>


Vector3D::Vector3D() : x(0), y(0), z(0) {}
Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

Vector3D Vector3D::operator+ (Vector3D& vec2) const
{
	return Vector3D(x + vec2.GetX(), y + vec2.GetY(), z + vec2.GetZ());
}

void Vector3D::operator+= (Vector3D& vec2)
{
	x += vec2.GetX();
	y += vec2.GetY();
	z += vec2.GetZ();
}

Vector3D Vector3D::operator- (Vector3D& vec2) const
{
	return Vector3D(x - vec2.GetX(), y - vec2.GetY(), z - vec2.GetZ());
}

Vector3D Vector3D::operator- ()
{
	return (*this) * (-1);
}

void Vector3D::operator-= (Vector3D& vec2)
{
	x -= vec2.GetX();
	y -= vec2.GetY();
	z -= vec2.GetZ();
}

double Vector3D::operator* (Vector3D& vec2) const
{
	return x * vec2.GetX() + y * vec2.GetY() + z * vec2.GetZ();
}

Vector3D Vector3D::operator* (double scalar) const
{
	return Vector3D(x * scalar, y * scalar, z * scalar);
}

void Vector3D::operator*= (double scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

bool Vector3D::operator|| (Vector3D& vec2) const
{
	return  x / vec2.GetX() == y / vec2.GetY() == z / vec2.GetZ();
}

bool Vector3D::operator== (Vector3D& vec2) const
{
	return x == vec2.GetX() && y == vec2.GetY() && z == vec2.GetZ();
}

double Vector3D::Length() const
{
	return std::sqrt(x * x + y * y + z * z);
}

Vector3D Vector3D::rotate(double Theta, AXIS axis) const
{


	long double n_x, n_y, n_z = 0;

	Theta = Theta * (3.141 / 180);


	if (axis == Vector3D::X)
	{
		n_x = x;
		n_y = y * cos(Theta) - z * sin(Theta);
		n_z = y * sin(Theta) + z * cos(Theta);

	}
	else if (axis == Vector3D::Y)
	{
		n_x = x * cos(Theta) + z * sin(Theta);
		n_y = y;
		n_z = -(x * sin(Theta)) + z * cos(Theta);
	}
	else if (axis == Vector3D::Z)
	{
		n_x = x * cos(Theta) - y * sin(Theta);
		n_y = x * sin(Theta) + y * cos(Theta);
		n_z = z;
	}

	//if (n_x < pow(10, -10) && n_x > -pow(10, -10)) n_x = 0;
	//if (n_y < pow(10, -10) && n_y > -pow(10, -10)) n_y = 0;
	//if (n_z < pow(10, -10) && n_z > -pow(10, -10)) n_z = 0;


	return Vector3D(n_x, n_y, n_z);
}

double Vector3D::GetX() const { return x; }
double Vector3D::GetY() const { return y; }
double Vector3D::GetZ() const { return z; }

// vec2 = -vec
// null - vect
// return vec * -1