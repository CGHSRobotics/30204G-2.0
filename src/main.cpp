#include "gteam.h"


// Chassis constructor
Drive chassis(

	// Left Chassis Ports (negative port will reverse it!)
	{ Gteam::PORT_CHASSIS_LEFT_FRONT, Gteam::PORT_CHASSIS_LEFT_BACK }

	// Right Chassis Ports (negative port will reverse it!)
	, { Gteam::PORT_CHASSIS_RIGHT_FRONT, Gteam::PORT_CHASSIS_RIGHT_BACK }

	// IMU Port
	, 20

	// Wheel Diameter (Remember, 4" wheels are actually 4.125!)
	, 2.5

	// Cartridge RPM
	, 1200

	// External Gear Ratio (MUST BE DECIMAL)
	, 0.6
);


/**
 * 	Initialization Function
 */
void initialize() {

	pros::delay(500); // Stop the user from doing anything while legacy ports configure.

	// Configure your chassis controls
	chassis.toggle_modify_curve_with_controller(true); // Enables modifying the controller curve with buttons on the joysticks
	chassis.set_active_brake(0); // Sets the active brake kP. We recommend 0.1.
	chassis.set_curve_default(0, 0); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
	default_constants(); // Set the drive to your own constants from autons.cpp!

	// Autonomous Selector using LLEMU
	ez::as::auton_selector.add_autons({
	  Auton("Example Drive\n\nDrive forward and come back.", drive_example),
	  Auton("Example Turn\n\nTurn 3 times.", turn_example),
	  Auton("Drive and Turn\n\nDrive forward, turn, come back. ", drive_and_turn),
	  Auton("Drive and Turn\n\nSlow down during drive.", wait_until_change_speed),
	  Auton("Swing Example\n\nSwing, drive, swing.", swing_example),
	  Auton("Combine all 3 movements", combining_movements),
	  Auton("Interference\n\nAfter driving forward, robot performs differently if interfered or not.", interfered_example),
		});

	// Initialize chassis and auton selector
	chassis.initialize();
	ez::as::initialize();
}


/**
 * 	Disabled Function
 */
void disabled() {
	// . . .
}


/**
 * 	Competition Init (For the most part, ignore)
 */
void competition_initialize() {
	// . . .
}


/**
 *	Autonomous Function
 */
void autonomous() {
	chassis.reset_pid_targets(); // Resets PID targets to 0
	chassis.reset_gyro(); // Reset gyro position to 0
	chassis.reset_drive_sensor(); // Reset drive sensors to 0
	chassis.set_drive_brake(MOTOR_BRAKE_HOLD); // Set motors to hold.  This helps autonomous consistency.

	ez::as::auton_selector.call_selected_auton(); // Calls selected auton from autonomous selector.
}


/**
 * 	User Control
 */
void opcontrol() {
	// This is preference to what you like to drive on.
	chassis.set_drive_brake(MOTOR_BRAKE_COAST);

	while (true) {

		chassis.tank(); // Tank control

		pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
	}
}