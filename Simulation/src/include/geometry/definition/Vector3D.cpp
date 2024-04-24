#include "../Vector3D.h"
#include "../../algebra/PrecisionDouble.h"
#include <cmath>
#include <iostream>


Vector3D::Vector3D() : x(PrecisionDouble(0, 0)), y(PrecisionDouble(0, 0)), z(PrecisionDouble(0,0)) {}
Vector3D::Vector3D(PrecisionDouble x, PrecisionDouble y, PrecisionDouble z) : x(x), y(y), z(z) {}

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

PrecisionDouble Vector3D::operator* (Vector3D& vec2) const
{
	return x * vec2.GetX() + y * vec2.GetY() + z * vec2.GetZ();
}

Vector3D Vector3D::operator* (PrecisionDouble scalar) const
{
	return Vector3D(x * scalar, y * scalar, z * scalar);
}

void Vector3D::operator*= (PrecisionDouble scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
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
	PrecisionDouble xScalar = x / vec2.GetX();
	PrecisionDouble yScalar = y / vec2.GetY();
	PrecisionDouble zScalar = z / vec2.GetZ();
	bool one = xScalar == yScalar;
	bool two = yScalar == zScalar;
	return  one && two;
}

bool Vector3D::operator== (Vector3D& vec2) const
{
	return x == vec2.GetX() && y == vec2.GetY() && z == vec2.GetZ();
}

PrecisionDouble Vector3D::Length() const
{
	return PrecisionDouble(std::sqrt((x * x + y * y + z * z).ToDouble()),0);
}

Vector3D Vector3D::rotate(double Theta, AXIS axis) const
{


	PrecisionDouble n_x, n_y, n_z(0,0);

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
		n_z = PrecisionDouble(-1,0) * (x * sin(Theta)) + z * cos(Theta);
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

PrecisionDouble Vector3D::GetX() const { return x; }
PrecisionDouble Vector3D::GetY() const { return y; }
PrecisionDouble Vector3D::GetZ() const { return z; }

// vec2 = -vec
// null - vect
// return vec * -1