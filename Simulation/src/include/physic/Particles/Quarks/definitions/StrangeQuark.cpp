#include "../StrangeQuark.h"
#include "../../../../algebra/PrecisionDouble.h"
#include "../../../../geometry/Point3D.h"

StrangeQuark::StrangeQuark() {
	this->Mass = PrecisionDouble(9.6, 1);
	this->Charge = CHARGE_E * (-1 / 3);
	this->Spin = PrecisionDouble(5, -1);
	this->Location = Point3D();
	this->Kind = SmallestParticleKinds::QUARK_STRANGE;
}
