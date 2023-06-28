#include "main.h"

void setIntakeMotors(int value) {
  intake_a = value;
  intake_b = value;
}

void setIntake() {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && !shift()) {
    setIntakeMotors(127);
  } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && shift()) {
    setIntakeMotors(-127);
  } else {
    setIntakeMotors(0);
  }
}