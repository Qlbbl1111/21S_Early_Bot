#include "main.h"

void setPuncherMotors(int value) {
  puncher_a = value;
  puncher_b = value;
}

void setPuncher() {
  puncher_a.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  puncher_b.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && !shift()) {
    setPuncherMotors(127);
  } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && shift()) {
    setPuncherMotors(-127);
  } else {
    setPuncherMotors(0);
  }
}