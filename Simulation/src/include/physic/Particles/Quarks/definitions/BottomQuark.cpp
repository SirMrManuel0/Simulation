#include "../BottomQuark.h"
#include "../../../../algebra/PrecisionDouble.h"
#include "../../../../geometry/Point3D.h"

BottomQuark::BottomQuark() {
	this->Mass = PrecisionDouble(4.18, 3);
	this->Charge = CHARGE_E * (-1 / 3);
	this->Spin = PrecisionDouble(5, -1);
	this->Location = Point3D();
	this->Kind = SmallestParticleKinds::QUARK_UP;
}
