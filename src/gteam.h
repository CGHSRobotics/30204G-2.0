#include "main.h"

// header Guard (DONT TOUCH)
#ifndef GTEAM
#define GTEAM

/*
 *	#define declarations (for controller)
 */

#define BUTTON_ROLLER_FORWARD DIGITAL_LEFT
#define BUTTON_ROLLER_REVERSE DIGITAL_RIGHT



 /*
  *	CGHS namespace where all your variables and functions are
  */
namespace Gteam {


	/*
	*	Port Numbers, Keep defined here for ease of changing them
	*	Make negative if the motor is reversed
	*/
	const int PORT_CHASSIS_LEFT_FRONT = 1;
	const int PORT_CHASSIS_LEFT_BACK = 1;
	const int PORT_CHASSIS_RIGHT_FRONT = 1;
	const int PORT_CHASSIS_RIGHT_BACK = 1;
}

#endif