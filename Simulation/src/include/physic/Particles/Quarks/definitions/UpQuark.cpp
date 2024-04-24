#include "../UpQuark.h"
#include "../../../../algebra/PrecisionDouble.h"
#include "../../../../geometry/Point3D.h"

UpQuark::UpQuark() {
	this->Mass = PrecisionDouble(2.2,0);
	this->Charge = CHARGE_E * (2 / 3);
	this->Spin = PrecisionDouble(5, -1);
	this->Location = Point3D();
	this->Kind = SmallestParticleKinds::QUARK_UP;
}