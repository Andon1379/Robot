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
// FrontLeft            motor         1               
// BackLeft             motor         8               
// FrontRight           motor         3               
// BackRight            motor         7               
// LiftMotor            motor         11              
// ClawMotor            motor         21              
// LiftMotor2           motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----
 
#include "vex.h"
 
using namespace vex;
 
// A global instance of competition
competition Competition;
 
// define your global instances of motors and other devices here

void goF(int speed){
 FrontLeft.spin(directionType::fwd,100,velocityUnits::pct);
 BackLeft.spin(directionType::fwd,100,velocityUnits::pct);
 FrontRight.spin(directionType::fwd,100,velocityUnits::pct);
 BackRight.spin(directionType::fwd,100,velocityUnits::pct);
 task::sleep(speed);
}
 
void goB(int duration, int pw = 100){
 FrontLeft.spin(directionType::rev,pw,velocityUnits::pct);
 BackLeft.spin(directionType::rev,pw,velocityUnits::pct);
 FrontRight.spin(directionType::rev,pw,velocityUnits::pct);
 BackRight.spin(directionType::rev,pw,velocityUnits::pct);
 task::sleep(duration);
}

// idk about tr and tl 
// change speed? 

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
  } else {
    //Controller1.Screen.setCursor(row, 1);
    //Controller1.Screen.clearLine();
  }
}
// pee pee poo poo
void updateScreen( void ) { 
  newLine(2);
  Brain.Screen.print("Controller axis 1 : ");
  Brain.Screen.print(Controller1.Axis1.value() );
  Brain.Screen.print(" Controller axis 2 : ");
  Brain.Screen.print(Controller1.Axis2.value() );
  newLine(3);
  Brain.Screen.print("Controller axis 3 : ");
  Brain.Screen.print(Controller1.Axis3.value() );
  Brain.Screen.print(" Controller axis 4 : ");
  Brain.Screen.print(Controller1.Axis4.value() );
  newLine(4);
  Brain.Screen.print("Controller button L1 : ");
  Brain.Screen.print(Controller1.ButtonL1.pressing());
  Brain.Screen.print(" Controller button L2 : ");
  Brain.Screen.print(Controller1.ButtonL2.pressing());
  newLine(5);
  Brain.Screen.print("Controller button R1 : ");
  Brain.Screen.print(Controller1.ButtonR1.pressing());
  Brain.Screen.print(" Controller button R2 : ");
  Brain.Screen.print(Controller1.ButtonR2.pressing());

  // DONT PRINT TO THE CONTROLLER'S BRAIN
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

 // For AutonThrow (slot 2)
 LiftMotor.spin(vex::directionType::fwd, (100/8), vex::velocityUnits::pct);
 task::sleep(360);
 LiftMotor.spin(vex::directionType::rev, (100/8), vex::velocityUnits::pct);
 task::sleep(360);
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
 int armSpeedPCT = 100;
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
    updateScreen();

    if ( Controller1.ButtonR1.pressing() && Controller1.ButtonR2.pressing() ) {
      powerDiv = powerDiv * 8;
    } else if ( Controller1.ButtonR1.pressing() && !Controller1.ButtonR2.pressing() ) {
      powerDiv = powerDiv * 4;
    } else if ( !Controller1.ButtonR1.pressing() && Controller1.ButtonR2.pressing() ) {
      powerDiv = powerDiv / 1;
    }
    
    if ( Controller1.Axis2.value() < ( minJoystickVal * -1 ) || Controller1.Axis2.value() > minJoystickVal  ) {
      FrontRight.spin(vex::directionType::fwd, (Controller1.Axis2.value()/powerDiv), vex::velocityUnits::pct);
      BackRight.spin(vex::directionType::fwd, (Controller1.Axis2.value()/powerDiv), vex::velocityUnits::pct);
      task::sleep(20);
    } // forward & backward (right)
    
    if ( Controller1.Axis3.value() < ( minJoystickVal * -1 ) || Controller1.Axis3.value() > minJoystickVal  ) {
      FrontLeft.spin(vex::directionType::fwd, (Controller1.Axis3.value()/powerDiv), vex::velocityUnits::pct);
      BackLeft.spin(vex::directionType::fwd, (Controller1.Axis3.value()/powerDiv), vex::velocityUnits::pct);
      task::sleep(20);
    } // forward & backward (left) 
    
    if (
      ( Controller1.Axis3.value() >= (minJoystickVal * -1) && Controller1.Axis2.value() >= (minJoystickVal * -1) ) &&
      ( Controller1.Axis3.value() <= (minJoystickVal *  1) && Controller1.Axis2.value() <= (minJoystickVal *  1))) {
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
       LiftMotor.spin(vex::directionType::fwd, (armSpeedPCT/4), vex::velocityUnits::pct); // powerdiv overwritten to 4
       //LiftMotor2.spin(vex::directionType::rev, (armSpeedPCT/powerDiv), vex::velocityUnits::pct);
     }
     else if(Controller1.ButtonL2.pressing()) { //If the L2 is pressed...
       //...Spin the arm motor backward.
       LiftMotor.spin(vex::directionType::rev, (armSpeedPCT/4), vex::velocityUnits::pct);
       //LiftMotor2.spin(vex::directionType::fwd, (armSpeedPCT/powerDiv), vex::velocityUnits::pct);
     }
     else { //If L1 or L2 is not pressed...
       //...Stop the arm motor.
       LiftMotor.stop(vex::brakeType::brake);
       //LiftMotor2.stop(vex::brakeType::brake);
       // PASSIVE KEEP ARM UP (CODE THIS SOON)
       //LiftMotor2.spin(vex::directionType::rev, 0.45, (vex::velocityUnits::pct));
     }
 
     //Claw Control
     if(Controller1.ButtonR1.pressing()) { //If the R1 is pressed...
       //...Spin the claw motor forward.
       //ClawMotor.spin(vex::directionType::fwd, clawSpeedPCT, vex::velocityUnits::pct);
     }
     else if(Controller1.ButtonR2.pressing()) { //If the R2 is pressed...
       //...Spin the claw motor backward.
       //ClawMotor.spin(vex::directionType::rev, clawSpeedPCT, vex::velocityUnits::pct);
     }
     else { //If R1 or R2 are not pressed...
       //...Stop the claw motor.
       //ClawMotor.stop(vex::brakeType::brake);
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