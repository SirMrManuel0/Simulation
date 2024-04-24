#include "../Particle.h"
#include "../../../algebra/PrecisionDouble.h"
#include "../../../geometry/Point3D.h"
#include "../../../geometry/Vector3D.h"
#include <vector>


// consts
Particle::CHARGE_E = PrecisionDouble(1.60217663, -19);
Particle::LIGHTSPEED = PrecisionDouble(2.99792458, 8)

void Particle::setLocation(Point3D& newLocation) {
	// sets Location to the new one
	this->Location = newLocation;
}
void Particle::move(Vector3D& vec) {
	// moves the Location through a vector
	this->Location += vec;
}


void Particle::addForce(Vector3D& force) {
	// adds a new force to the list of Forces
	this->Forces.push_back(force);
}

void Particle::addForces(std::vector<Vector3D> forces) {
	// adds a list of forces to the list of Forces
	for (Vector3D force : forces)
		this->Forces.push_back(force);
}
void Particle::removeForce(int index) {
	// check for index out of bound
	if (index >= this->Forces.size()) return;
	// removes a force at index
	this->Forces.erase(this->Forces.begin() + index);
}
void Particle::clearForces() {
	// deletes all forces
	this->Forces.clear();
}
void Particle::setForces(std::vector<Vector3D> forces) {
	// deletes all forces and then sets just one
	this->clearForces();
	this->addForces(forces);
}
void Particle::setForce(Vector3D& force) {
	// deletes all forces and then sets it to a list of forces
	this->clearForces();
	this->addForce(force);
}
Vector3D Particle::getForce(int index) {
	// check for index out of bound
	if (index >= this->Forces.size()) return Vector3D();
	// get force at index
	return this->Forces.at(index);
}
Vector3D Particle::getResultingForce() {
	// calculate the resulting force by
	// adding all forces together
	Vector3D ResultingForce(0, 0, 0);
	for (Vector3D force : this->Forces)
		ResultingForce += force;
	return ResultingForce;
}

// Getter
PrecisionDouble Particle::getMass() {
	return this->Mass; // in MeV/c^2
}
Point3D Particle::getLocation() {
	return this->Location;
}
std::vector<Vector3D> Particle::getForces() {
	return this->Forces;
}
int Particle::getKind()[
	return this->Kind;
]