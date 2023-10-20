#include "EZ-Template/util.hpp"
#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.


void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.75, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.75, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}
////////////////////////////////////////////////////////////////////////////////
//Autons
////////////////////////////////////////////////////////////////////////////////

void nothing(){
  setDriveLights(0x000000);
}


void offense() {
  //offense
  setDriveLights(0x00fff2);

  chassis.set_drive_pid(4, DRIVE_SPEED); //drive to bar
  chassis.wait_drive();
  chassis.set_turn_pid(8, TURN_SPEED); //turn to bar
  chassis.wait_drive();

  wings.set_value(true);
  chassis.set_drive_pid(12, 80); //knock ball out
  chassis.wait_drive();

  chassis.set_turn_pid(-40, 40); //turn to goal
  chassis.wait_drive();

  pros::delay(500);
  wings.set_value(false);
  //align with goal
  chassis.set_drive_pid(-3, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-25, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(2, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-25, TURN_SPEED);
  chassis.wait_drive();

  //score balls
  chassis.set_drive_pid(22, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-5, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(10, 127);
  chassis.wait_drive();
  chassis.reset_gyro();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-95, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(36, DRIVE_SPEED);
  chassis.wait_drive();

  wings.set_value(true);
  chassis.set_drive_pid(12, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-83, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(7, DRIVE_SPEED);
  chassis.wait_drive();
  setDriveLights(0x000000);
}

void defense() {
  //defense
  setDriveLights(0xffb700);
  chassis.set_drive_pid(26, DRIVE_SPEED, true);
  chassis.wait_drive();
  //wings.set_value(true);

  chassis.set_turn_pid(25, TURN_SPEED);
  chassis.wait_drive();

  chassis.reset_gyro();

  chassis.set_drive_pid(12, 127);
  chassis.wait_drive();
  //wings.set_value(false);
  chassis.reset_drive_sensor();

  chassis.set_drive_pid(-5, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(8, 127);
  chassis.wait_drive();

  chassis.reset_drive_sensor(); 

  chassis.set_drive_pid(-10, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.wait_drive();

  wings.set_value(true);

  chassis.set_drive_pid(9, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.reset_gyro();

  chassis.set_swing_pid(ez::RIGHT_SWING, -60, SWING_SPEED);
  chassis.wait_drive();
  
  wings.set_value(false);

  chassis.set_turn_pid(-51, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(40, DRIVE_SPEED);
  chassis.wait_drive();
  setDriveLights(0x000000);
}