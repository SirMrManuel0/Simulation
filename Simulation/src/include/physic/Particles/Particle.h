#pragma once
#include "../../algebra/PrecisionDouble.h"
#include "../../geometry/Point3D.h"
#include "../../geometry/Vector3D.h"
#include <vector>

class Particle
{
private:
	PrecisionDouble Mass;
	Point3D Location;
	std::vector<Vector3D> Forces;
public:
	// Location methods
	void setLocation(Point3D& newLocation);
	void move(Vector3D& vec);

	// Force methods
	void addForce(Vector3D& force);
	void addForces(std::vector<Vector3D> forces);
	void removeForce(int index);
	void clearForces();
	void setForces(std::vector<Vector3D> forces);
	void setForce(Vector3D& force);
	Vector3D getForce(int index);

	// Getter
	PrecisionDouble getMass();
	Point3D getLocation();
	std::vector<Vector3D> getForces();
	Vector3D getResultingForce();

};

