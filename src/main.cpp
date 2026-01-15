

#include "vex.h"

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
//ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//HOLONOMIC_TWO_ENCODER
//HOLONOMIC_TWO_ROTATION
//
//Write it here:
ZERO_TRACKER_NO_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(Right1,Right2,Right3),

//Right Motors:
motor_group(Left1,Left2,Left3),


//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT7,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.75,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-2,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);


/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

 void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  OpticalBottom.setLightPower(100, percent);
  OpticalTop.setLightPower(100, percent);
  OpticalBottom.setLight(ledState::on);
  OpticalTop.setLight(ledState::on);

  vexcodeInit();
  default_constants();
}


// void IntakeParallel() {
//   while (true) {
//     FirstStage.spin(fwd,12000,voltageUnits::mV);
//     SecondStage.spin(fwd,12000,voltageUnits::mV);
//     ThirdStage.spin(ThirdStageDirection,12000,voltageUnits::mV);
//     wait(10, msec);
//   }
// }

// void sortRedTimedColor(int timeSeconds) {

//   Brain.resetTimer();

//   while (Brain.timer(sec) < timeSeconds) {
//     Brain.Screen.print(Brain.timer(sec));

//     // Verificar que hay objeto
//     if (Optical.isNearObject()) {

//       int hue = Optical.hue();

//       // ROJO: 350–359 y 0–10
//       if ( (hue >= 350 && hue <= 359) ||
//            (hue >= 0   && hue <= 10) ) {

//         // Abrir pistón
//         ColorSort.set(true);

//         // Mantener abierto
//         wait(300, msec);

//         // Cerrar pistón
//         ColorSort.set(false);

//         // Evitar múltiples disparos
//         wait(50, msec);
//       }
//     }

//     // Delay de estabilidad
//     wait(10, msec);
//   }
// }

// void sortBlueTimedColor(int timeSeconds) {

//   Brain.resetTimer();

//   while (Brain.timer(sec) < timeSeconds) {

//     // Verificar que hay objeto
//     if (Optical.isNearObject()) {

//       int hue = Optical.hue();

//       // AZUL: 210–240
//       if (hue >= 210 && hue <= 240) {

//         // Abrir pistón
//         ColorSort.set(true);

//         // Mantener abierto
//         wait(400, msec);

//         // Cerrar pistón
//         ColorSort.set(false);

//         // Evitar múltiples disparos
//         wait(300, msec);
//       }
//     }

//     // Delay de estabilidad
//     wait(20, msec);
//   }
// }


void auto_Isolation(void) {

/*Optical.setLightPower(100, percent);
Expansion.set(true);

chassis.drive_max_voltage = 8;
chassis.drive_distance(38);// Va adelante

chassis.turn_to_angle(90);  // se alinea con el long goal
chassis.drive_distance(-17);// va atras hacia el long goal

Mathcloader.set(true);
SecondStage.spin(fwd,12000,voltageUnits::mV);
ThirdStage.spin(fwd,12000,voltageUnits::mV);
wait(600,msec);
chassis.drive_max_voltage = 6;
chassis.drive_distance(22);// va hacia adelante rapido
FirstStage.spin(fwd,12000,voltageUnits::mV);
SecondStage.spin(fwd,6000,voltageUnits::mV);
ThirdStage.stop(hold);
chassis.drive_max_voltage = 4;
chassis.drive_distance(9.5);// adelante lento
sortBlueTimedColor(4);

//wait(4000,msec);
chassis.drive_max_voltage = 6;
chassis.drive_distance(-28);
SecondStage.spin(fwd,12000,voltageUnits::mV);
ThirdStage.spin(fwd,12000,voltageUnits::mV);

/*wait(2000,msec);

Optical.setLightPower(100, percent);
Expansion.set(true);
Mathcloader.set(false);


chassis.drive_max_voltage = 8;
chassis.drive_distance(22);// Va adelante
chassis.turn_to_angle(225);  // se alinea con el middle goal
chassis.drive_distance(20);// Va adelante
FirstStage.spin(fwd,0,voltageUnits::mV);
SecondStage.spin(fwd,6000,voltageUnits::mV);
ThirdStage.stop(hold);
chassis.drive_distance(40);// Va adelante
FirstStage.spin(reverse,12000,voltageUnits::mV);
SecondStage.spin(reverse,12000,voltageUnits::mV);
ThirdStage.spin(reverse,12000,voltageUnits::mV);
chassis.drive_distance(-5);// va atras hacia el long goal*/


chassis.drive_with_voltage(0,0);
FirstStage.spin(fwd,12000,voltageUnits::mV);
// sortRedTimedColor(100);

}





/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        Auto_Interaction Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous interaction*/
/*  phase of a VEX AI Competition.                                           */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


void auto_Interaction(void) {

  OpticalBottom.setLightPower(100, percent);
  OpticalTop.setLightPower(100, percent);
  Expansion.set(true);
  Mathcloader.set(false);


  chassis.drive_max_voltage = 8;
  chassis.drive_distance(22);// Va
  chassis.turn_to_angle(225);  // se alinea con el middle goal
  chassis.drive_distance(20);// Va adelante
  FirstStage.spin(fwd,0,voltageUnits::mV);
  SecondStage.spin(fwd,6000,voltageUnits::mV);
  ThirdStage.stop(hold);
  chassis.drive_distance(40);// Va adelante
  FirstStage.spin(reverse,12000,voltageUnits::mV);
  SecondStage.spin(reverse,12000,voltageUnits::mV);
  ThirdStage.spin(reverse,12000,voltageUnits::mV);
  chassis.drive_distance(-5);// va atras hacia el long goal
}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          AutonomousMain Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
BallCounter counter;

// called when bottom optical *detects* a new object
void onBottomDetected() {
  // attempt to add a ball
  if (counter.countBall()) {
    Brain.Screen.printAt(10, 50, "Ball added! Count: %d", counter.balls());
  } else {
    Brain.Screen.printAt(10, 50, "Count full (%d)", counter.balls());
  }
  Brain.Screen.print("Bottom detected");

  int hue = OpticalBottom.hue();
  bool shouldSort = false;

  if (TEAMCOLOR == BallBlue) {
    // RED: 350–359 and 0–10
    if ((hue >= 350 && hue <= 359) ||
        (hue >= 0   && hue <= 10)) {
      shouldSort = true;
    }
  }
  else if (TEAMCOLOR == BallRed) {
    // BLUE: 210–240
    if (hue >= 210 && hue <= 240) {
      shouldSort = true;
    }
  }

  if (shouldSort) {
    ColorSort.set(true);
    wait(150, msec);
  }
  ColorSort.set(false);
}

// called when top optical *detects* a new object being sorted out
void onTopDetected() {
    // Brain.Screen.print("Top detected");

  int hue = OpticalTop.hue();
  bool shouldSort = false;

  if (TEAMCOLOR == BallBlue) {
    // RED: 350–359 and 0–10
    if ((hue >= 350 && hue <= 359) ||
        (hue >= 0   && hue <= 30)) {
      shouldSort = true;
    }
  }
  else if (TEAMCOLOR == BallRed) {
    // BLUE: 210–240
    if (hue >= 210 && hue <= 240) {
      shouldSort = true;
    }
  }

  if (shouldSort) {
    // SecondStage.spin(forward, 12000,voltageUnits::mV);
    // ThirdStage.spin(reverse,12000,voltageUnits::mV);
    SecondStage.spinToPosition(2, rev, true);
    ThirdStage.spinToPosition(-2, rev, true);
      // attempt to remove a ball
    if (counter.removeBall()) {
      Brain.Screen.printAt(10, 70, "Ball removed! Count: %d", counter.balls());
    }
  } else { // if theres ball of same color stop the intake and hold top ball
    ThirdStage.stop(hold);
    SecondStage.stop(hold);
  }
  
}


bool firstAutoFlag = true;

void autonomousMain(void) {
  // ..........................................................................
  // The first time we enter this function we will launch our Isolation routine
  // When the field goes disabled after the isolation period this task will die
  // When the field goes enabled for the second time this task will start again
  // and we will enter the interaction period. 
  // ..........................................................................
  OpticalBottom.objectDetected(onBottomDetected);
  OpticalTop.objectDetected(onTopDetected);
  // FirstStage.spin(forward, 100, percent);
  // SecondStage.spin(forward,100,percent);
  // ThirdStage.spin(forward, 100, percent);
  // thread colorSort = thread(ColorSortBottomParallel);
  // thread colorSortTop = thread(ColorSortTopParallel);

  // might cause race condition
  // thread intakeSpin = thread(IntakeParallel);
    FirstStage.spin(fwd,12000,voltageUnits::mV);
    // SecondStage.spin(fwd,12000,voltageUnits::mV);
  // if(firstAutoFlag)
  //   auto_Isolation();
  // else 
  //   auto_Interaction();

  firstAutoFlag = false;
}

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    thread colorSort = thread(ColorSortBottomParallel);
    thread colorSortTop = thread(ColorSortTopParallel);
    FirstStage.spin(fwd,12000,voltageUnits::mV);
    SecondStage.spin(fwd,12000,voltageUnits::mV);
    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    chassis.control_arcade();

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomousMain);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
