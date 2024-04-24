#include "../DownQuark.h"
#include "../../../../algebra/PrecisionDouble.h"
#include "../../../../geometry/Point3D.h"

DownQuark::DownQuark() {
	this->Mass = PrecisionDouble(4.6, 0);
	this->Charge = CHARGE_E * (-1 / 3);
	this->Spin = PrecisionDouble(5, -1);
	this->Location = Point3D();
	this->Kind = SmallestParticleKinds::QUARK_DOWN;
}