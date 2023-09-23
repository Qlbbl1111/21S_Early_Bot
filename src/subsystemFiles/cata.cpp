#include "main.h"

void setCataMotors(int value) {
  cata_a = value;
  cata_b = value;
}

void setCata() {
  cata_a.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  cata_b.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && !shift()) {
    setCataMotors(75);
  } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && shift()) {
    //setCataMotors(-30);
  } else {
    setCataMotors(0);
  }
}