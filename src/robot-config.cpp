#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor FrontLeft = motor(PORT15, ratio18_1, true);
motor BackLeft = motor(PORT8, ratio18_1, true);
motor FrontRight = motor(PORT3, ratio18_1, false);
motor BackRight = motor(PORT7, ratio18_1, false);
motor LiftMotor = motor(PORT19, ratio18_1, true);
motor ClawMotor = motor(PORT21, ratio18_1, false);
motor LiftMotor2 = motor(PORT20, ratio18_1, true);
motor BackClaw = motor(PORT17, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}