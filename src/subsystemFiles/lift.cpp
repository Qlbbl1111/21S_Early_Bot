#include "main.h"

bool toggleLock = false;
bool latchLock = false;
okapi::ControllerButton lockButton(okapi::ControllerDigital::X);

void setLift() {
  liftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        liftMotor = 75;
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        liftMotor = -75;
    } else {
        liftMotor = 0;
}}

void lock() {
    if (toggleLock) {
    liftLock.set_value(true);
  } else {
    liftLock.set_value(false);
  }

  if (lockButton.isPressed()) {
    if (!latchLock) { // if latch false, toggle one time and set latch true
      toggleLock = !toggleLock;
      latchLock = true;
    }
  } else {
    latchLock = false; // once button is released then release the latch too
  }
}
