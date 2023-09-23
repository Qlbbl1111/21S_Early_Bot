#include "main.h"

// MOTORS
pros::Motor cata_a(1, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor cata_b(2, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
// CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// SENSORS
pros::Imu inertial(21);

// PNUEMATICS
pros::ADIDigitalOut wings('A');
pros::ADIDigitalOut doinker('B');

// SHIFT
bool shift() {
  return controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
}
