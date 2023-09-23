#include "main.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"

okapi::ControllerButton wingsButton(okapi::ControllerDigital::B);
okapi::ControllerButton doinkerButton(okapi::ControllerDigital::down);

bool toggle = false;
bool latch = false;
bool toggle2 = false;
bool latch2 = false;

void wingsOff() {
  wings.set_value(false);
}

void wingsOn() {
  wings.set_value(true);
}

void setWings() {

  if (toggle) {
    wings.set_value(true);
  } else {
    wings.set_value(false);
  }

  if (wingsButton.isPressed()) {
    if (!latch) { // if latch false, toggle one time and set latch true
      toggle = !toggle;
      latch = true;
    }
  } else {
    latch = false; // once button is released then release the latch too
  }
}

void setDoinker() {

  if (toggle2) {
    doinker.set_value(true);
  } else {
    doinker.set_value(false);
  }

  if (doinkerButton.isPressed()) {
    if (!latch2) { // if latch false, toggle one time and set latch true
      toggle2 = !toggle2;
      latch2 = true;
    }
  } else {
    latch2 = false; // once button is released then release the latch too
  }
}