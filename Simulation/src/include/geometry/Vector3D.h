#pragma once
class Vector3D {
public:
	Vector3D();
	Vector3D(double x, double y, double z);
	Vector3D operator+ (Vector3D& vec2) const;
	void operator+= (Vector3D& vec2);
	Vector3D operator- (Vector3D& vec2) const;
	Vector3D operator- ();
	void operator-= (Vector3D& vec2);
	double operator* (Vector3D& vec2) const;
	Vector3D operator* (double scalar) const;
	void operator*= (double scalar);
	bool operator|| (Vector3D& vec2) const;
	bool operator== (Vector3D& vec2) const;
	double GetX() const;
	double GetY() const;
	double GetZ() const;
	double Length() const;
	enum AXIS { X, Y, Z };
	Vector3D rotate(double Theta, AXIS axis) const;
private:
	double x, y, z;
};