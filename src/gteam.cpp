#include "gteam.h"

namespace Gteam {

	//	Sets
	void spinMotor(pros::Motor motor, float percent) {
		motor.move_voltage(12000.0 * percent / 100.0);
	};

}