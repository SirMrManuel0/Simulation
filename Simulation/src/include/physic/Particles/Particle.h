#pragma once
#include "../../algebra/PrecisionDouble.h"
#include "../../geometry/Point3D.h"
#include "../../geometry/Vector3D.h"
#include <vector>

class Particle
{
protected:
	// Mass in MeV/c^2
	PrecisionDouble Mass;
	PrecisionDouble Charge;
	PrecisionDouble Spin;
	Point3D Location;
	std::vector<Vector3D> Forces;
	int Kind;
public:
	static PrecisionDouble CHARGE_E;
	static PrecisionDouble LIGHTSPEED;

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
	PrecisionDouble getMass(); // in MeV/c^2
	Point3D getLocation();
	std::vector<Vector3D> getForces();
	Vector3D getResultingForce();
	int getKind(); // returns the corresponding enum int

	enum SmallestParticleKinds {
		QUARK_UP,
		QUARK_DOWN,
		QUARK_CHARM,
		QUARK_STRANGE,
		QUARK_TOP,
		QUARK_BOTTOM,
		LEPTON_ELECTORN,
		LEPTRON_ELECTRON_NEUTRINO,
		LEPTON_MUON,
		LEPTON_TAU,
		LEPTON_TAU_NEUTRINO,
		LEPTON_POSITRON,
		LEPTON_ANTIMUON,
		LEPTRON_ELECTRON_ANTINEUTRINO,
		BOSONS_PHOTON,
		BOSONS_W_BOSONS,
		BOSONS_Z_BOSONS,
		BOSONS_GLUON,
		BOSONS_HIGGS_BOSON
	};
};

