#include "../TopQuark.h"
#include "../../../../algebra/PrecisionDouble.h"
#include "../../../../geometry/Point3D.h"

TopQuark::TopQuark() {
	this->Mass = PrecisionDouble(1.731, 5);
	this->Charge = CHARGE_E * (2 / 3);
	this->Spin = PrecisionDouble(5, -1);
	this->Location = Point3D();
	this->Kind = SmallestParticleKinds::QUARK_TOP;
}
