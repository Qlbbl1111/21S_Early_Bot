#include "main.h"

// MOTORS
pros::Motor cata_a(1, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor cata_b(10, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor liftMotor(14, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
// CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// SENSORS
pros::Imu inertial(21);

// PNUEMATICS
pros::ADIDigitalOut wings('B');

// LIGHTS
sylib::Addrled leftDriveLights(22,7,52);
sylib::Addrled rightDriveLights(22,8,52);