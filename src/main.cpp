/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// FrontLeft            motor         5               
// BackLeft             motor         8               
// FrontRight           motor         3               
// BackRight            motor         7               
// LiftMotor            motor         19              
// ClawMotor            motor         21              
// LiftMotor2           motor         20              
// BackClaw             motor         17              
// ---- END VEXCODE CONFIGURED DEVICES ----
 
#include "vex.h"
 
using namespace vex;
 
// A global instance of competition
competition Competition;
 
// define your global instances of motors and other devices here

double Pi = 3.1415;

void goF(int duration, int pw = 100){
 FrontLeft.spin(directionType::fwd,pw,velocityUnits::pct);
 BackLeft.spin(directionType::fwd,pw,velocityUnits::pct);
 FrontRight.spin(directionType::fwd,pw,velocityUnits::pct);
 BackRight.spin(directionType::fwd,pw,velocityUnits::pct);
 task::sleep(duration);
}
 
void goB(int duration, int pw = 100){
 FrontLeft.spin(directionType::rev,pw,velocityUnits::pct);
 BackLeft.spin(directionType::rev,pw,velocityUnits::pct);
 FrontRight.spin(directionType::rev,pw,velocityUnits::pct);
 BackRight.spin(directionType::rev,pw,velocityUnits::pct);
 task::sleep(duration);
}

void ClawClose(int duration, int pw =100 ) {
  ClawMotor.spin(vex::directionType::rev, pw, vex::velocityUnits::pct);
  task::sleep(duration);
}

void ClawOpen(int duration, int pw = 100) {
  ClawMotor.spin(vex::directionType::fwd, pw, vex::velocityUnits::pct);
  task::sleep(duration);
}

void drawButtonUi( int x, int y, bool isCircle = true, std::string str = "") {

}
// idk about tr and tl 
// change speed? 

// perhaps run with rpm to have it self regulate -- more consistency.

void Tr( void ){
 FrontLeft.spin(directionType::rev,100,velocityUnits::pct);
 BackLeft.spin(directionType::rev,100,velocityUnits::pct);
 FrontRight.spin(directionType::fwd,100,velocityUnits::pct);
 BackRight.spin(directionType::fwd,100,velocityUnits::pct);
 task::sleep(515);
}
 
void Tl( void ){
 FrontLeft.spin(directionType::fwd,100,velocityUnits::pct);
 BackLeft.spin(directionType::fwd,100,velocityUnits::pct);
 FrontRight.spin(directionType::rev,100,velocityUnits::pct);
 BackRight.spin(directionType::rev,100,velocityUnits::pct);
 task::sleep(515);
}

void allStop( void ){
 FrontLeft.stop();
 FrontRight.stop();
 BackLeft.stop();
 BackRight.stop();
 LiftMotor.stop();
 LiftMotor2.stop();
 ClawMotor.stop();
}
 
void newLine(int row, bool isCont = false){
  if (isCont == false) {
    Brain.Screen.setCursor(row, 1);
    Brain.Screen.clearLine();
 // } else {
    //Controller1.Screen.setCursor(row, 1);
    //Controller1.Screen.clearLine();
  }
}
// pee pee poo poo

void makeButtonDisp(int x, int y, char *label, color col, color col2){  
  Brain.Screen.drawCircle(x, y, 10, col);
  Brain.Screen.setPenColor(col2);
  Brain.Screen.printAt(x-4, y+5, false, label);
  Brain.Screen.setPenColor(vex::color::white);  // set back to default
}

void updateScreen( int minJoystickVal ) {

  // The image should be no larger than the V5 Screen, that is, a maximum of 480 pixels wide by 272 pixels high
  // 5 px margins
  if (Controller1.ButtonL1.pressing()) {
    Brain.Screen.drawRectangle(15, 25, 50, 30, vex::color::white);
  } else {
    Brain.Screen.drawRectangle(15, 25, 50, 30, vex::color::black);
  }
  if (Controller1.ButtonL2.pressing()) {
    Brain.Screen.drawRectangle(15, 60, 50, 30, vex::color::white);
  } else {
    Brain.Screen.drawRectangle(15, 60, 50, 30, vex::color::black);
   }

  if (Controller1.ButtonR1.pressing()) {
    Brain.Screen.drawRectangle(80, 25, 50, 30, vex::color::white);
  } else {
    Brain.Screen.drawRectangle(80, 25, 50, 30, vex::color::black);
  }
  if (Controller1.ButtonR2.pressing()) {
    Brain.Screen.drawRectangle(80, 60, 50, 30, vex::color::white);
  } else {
    Brain.Screen.drawRectangle(80, 60, 50, 30, vex::color::black);
  }

  if (Controller1.ButtonX.pressing()) {
    makeButtonDisp(166, 40, "x", vex::color::white, vex::color::black);
  } else {
    makeButtonDisp(166, 40, "x", vex::color::black, vex::color::white);
  }

  if (Controller1.ButtonA.pressing()) {
    makeButtonDisp(182, 65, "a", vex::color::white, vex::color::black);
  } else {
    makeButtonDisp(182, 65, "a", vex::color::black, vex::color::white);
  }

  if (Controller1.ButtonB.pressing()) {
    makeButtonDisp(166, 90, "b", vex::color::white, vex::color::black);
  } else {
    makeButtonDisp(166, 90, "b", vex::color::black, vex::color::white);
  }

  if (Controller1.ButtonY.pressing()) {
    makeButtonDisp(150, 65, "y", vex::color::white, vex::color::black);
  } else {
    makeButtonDisp(150, 65, "y", vex::color::black, vex::color::white);
  }


  newLine(7);
  Brain.Screen.print("Controller axis 3 : ");
  Brain.Screen.print(Controller1.Axis3.value() );
  Brain.Screen.print(" Controller axis 4 : ");
  Brain.Screen.print(Controller1.Axis4.value() );
  newLine(8);
  Brain.Screen.print("Controller axis 2 : ");
  Brain.Screen.print(Controller1.Axis2.value() );
  Brain.Screen.print(" Controller axis 1 : ");
  Brain.Screen.print(Controller1.Axis1.value() );
  vex::task::sleep(20);

  // DONT PRINT TO THE CONTROLLER'S SCREEN
  // (it makes the robot have a delay in it's controls)
}

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
 
void pre_auton(void) {
 // Initializing Robot Configuration. DO NOT REMOVE!
 vexcodeInit();
 
 // All activities that occur before the competition starts
 // Example: clearing encoders, setting servo positions, ...
}
 
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
 
void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  newLine(1);
  Brain.Screen.print("Autonomous program started");

  //strafeL(1500); // no clue if this is the right amount of time

  // For AutonThrow (slot 2) (depreciated)
  //LiftMotor.spin(vex::directionType::fwd, (100/8), vex::velocityUnits::pct);
  //task::sleep(360);
  //LiftMotor.spin(vex::directionType::rev, (100/8), vex::velocityUnits::pct);
  //task::sleep(360);

  // move forward, drop claw 
  goF(1050, (100/4));
  
  ClawClose( 75, 30 );
  task::sleep(75);

  task::sleep(900);
  goB(1550, (100/3));

  ClawOpen( 75, 20);
  task::sleep(75);

 // For Backup onto seesaw or pushing goal (slot 3) 
 //goB(950, 50);
 //goB(700, 25);

 allStop();
}
 
 
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
 
void usercontrol( void ) {
 // User control code here, inside the loop
 //Display that the program has started to the screen.
 //Use these variables to set the speed of the arm and claw.
 int armSpeedPCT = 60;
 //int clawSpeedPCT = 100;
 int minJoystickVal = 30;
 while (1) {
    int powerDiv = 1;
    //Create an infinite loop so that the program can pull remote control values every iteration.
    
    //This loop causes the program to run forever.
      
    //This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
  
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    //================================================= 
  
    //Drive Control
    //Set the left and right motor to spin forward using the controller Axis values as the velocity value.
    newLine(1);
    
    Brain.Screen.print("Competition User Control Started");
    updateScreen( minJoystickVal );

    if ( Controller1.ButtonR1.pressing() && Controller1.ButtonR2.pressing() ) {
      powerDiv = powerDiv * 8;
    } else if ( Controller1.ButtonR1.pressing() && !Controller1.ButtonR2.pressing() ) {
      powerDiv = powerDiv * 4;
    } else if ( !Controller1.ButtonR1.pressing() && Controller1.ButtonR2.pressing() ) {
      powerDiv = powerDiv / 1;
    }

    if ( Controller1.ButtonL1.pressing() && Controller1.ButtonL2.pressing() ) {
      powerDiv = powerDiv * 8;
    } else if ( Controller1.ButtonL1.pressing() && !Controller1.ButtonL2.pressing() ) {
      powerDiv = powerDiv * 4;
    } else if ( !Controller1.ButtonL1.pressing() && Controller1.ButtonL2.pressing() ) {
      powerDiv = powerDiv / 1;
    }

    // math for 1 joystick
    // 
    // going forward / backward: 
    // use axis 3
    // 
    // turning right: 
    // right motors get less power
    // left motors get more power
    // positive axis 4 & positive axis 3
    // negative axis 4 & negative axis 3  
    // 
    // turning left: 
    // right motors get more power
    // left motors get less power
    // negative axis 4 & positive axis 3
    // positive axis 4 & negative axis 3  

    if ( (Controller1.Axis3.value() < ( minJoystickVal * -1 ) || Controller1.Axis3.value() > minJoystickVal)) {
      double RmotorPowerPCT = ( ( (Controller1.Axis3.value() + Controller1.Axis4.value() ) / 127) * 100 ) - ( (Controller1.Axis4.value() / 127) * 100) / powerDiv ;
      double LmotorPowerPCT = ( ( (Controller1.Axis3.value() + Controller1.Axis4.value() ) / 127) * 100 ) + ( (Controller1.Axis4.value() / 127) * 100) / powerDiv ;

      FrontRight.spin(vex::directionType::fwd, RmotorPowerPCT, vex::velocityUnits::pct);
      BackRight.spin(vex::directionType::fwd, RmotorPowerPCT , vex::velocityUnits::pct);

      FrontLeft.spin(vex::directionType::fwd, LmotorPowerPCT, vex::velocityUnits::pct);
      BackLeft.spin(vex::directionType::fwd, LmotorPowerPCT, vex::velocityUnits::pct);
      task::sleep(20);
    } // forward & backward (and turning) 

    if (
      ( Controller1.Axis3.value() >= (minJoystickVal * -1) && Controller1.Axis4.value() >= (minJoystickVal * -1) ) &&
      ( Controller1.Axis3.value() <= (minJoystickVal *  1) && Controller1.Axis4.value() <= (minJoystickVal *  1))) {
      FrontLeft.spin(vex::directionType::fwd, (0), vex::velocityUnits::pct);
      BackLeft.spin(vex::directionType::fwd, (0), vex::velocityUnits::pct);
      FrontRight.spin(vex::directionType::fwd, (0), vex::velocityUnits::pct);
      BackRight.spin(vex::directionType::fwd, (0), vex::velocityUnits::pct);
      task::sleep(20);
    } // stopping

    //https://docs.google.com/document/d/1MOMd-QA1tYjjyFQMGFb24nPcB9Q2MZVH7CbmG1IY6RA/edit
      // why does this end the while loop
     //Arm Control
     if(Controller1.ButtonL1.pressing()) { //If L1 is pressed...
       //...Spin the arm motor forward.
       LiftMotor.spin(vex::directionType::rev, (armSpeedPCT), vex::velocityUnits::pct);
       LiftMotor2.spin(vex::directionType::fwd, (armSpeedPCT), vex::velocityUnits::pct);
     }
     else if(Controller1.ButtonL2.pressing()) { //If the L2 is pressed...
       //...Spin the arm motor backward.
       LiftMotor.spin(vex::directionType::fwd, (armSpeedPCT), vex::velocityUnits::pct);
       LiftMotor2.spin(vex::directionType::rev, (armSpeedPCT), vex::velocityUnits::pct);
     }
     else { //If L1 or L2 is not pressed...
       //...Stop the arm motor.
       LiftMotor.stop(vex::brakeType::brake);
       LiftMotor2.stop(vex::brakeType::brake);
       // PASSIVE KEEP ARM UP (CODE THIS SOON)
       //LiftMotor2.spin(vex::directionType::rev, 0.45, (vex::velocityUnits::pct));
     }
 
     //Claw Control
     if(Controller1.ButtonA.pressing()) {
       ClawMotor.spin(vex::directionType::rev, 80, vex::velocityUnits::pct);
     }
     else if(Controller1.ButtonX.pressing()) { 
       ClawMotor.spin(vex::directionType::fwd, 80, vex::velocityUnits::pct);
     }
     else { //If R1 or R2 are not pressed...
       //...Stop the claw motor.
       ClawMotor.stop(vex::brakeType::brake);
     }

    if(Controller1.ButtonY.pressing()) {
       BackClaw.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
     }
     else if(Controller1.ButtonB.pressing()) { 
       BackClaw.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
     }
     else { //If R1 or R2 are not pressed...
       //...Stop the claw motor.
       BackClaw.stop(vex::brakeType::brake);
     }
    }
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources.
 }

 
//
// Main will set up the competition functions and callbacks.
//
int main() {
 // Set up callbacks for autonomous and driver control periods.
 Competition.autonomous(autonomous);
 Competition.drivercontrol(usercontrol);
 
 // Run the pre-autonomous function.
 pre_auton();
  
 // Prevent main from exiting with an infinite loop.
 while (true) {
   wait(100, msec);
 }
}