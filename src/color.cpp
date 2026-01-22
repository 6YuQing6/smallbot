#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

BallCounter counter(6);
vex::timer ColorSortTimer;

// called when bottom optical *detects* a new object
void onBottomDetected() {
  // attempt to add a ball
  Brain.Screen.print("Bottom detected");
  int hue = OpticalBottom.hue();
  int detected = BallUndefined;

    // RED: 350–359 and 0–10
  if ((hue >= 300 && hue <= 359) ||
      (hue >= 0   && hue <= 50)) {
    detected = BallRed;
  }

  // BLUE: 210–240
  if (hue >= 160 && hue <= 240) {
    detected = BallBlue;
  }

  if (TEAMCOLOR != detected) {
    ColorSort.set(true);
    wait(150, msec);
  } else {
    if (counter.countBall()) {
      Brain.Screen.printAt(10, 50, "Ball added! Count: %d", counter.balls());
    } else {
      Brain.Screen.printAt(10, 50, "Count full (%d)", counter.balls());
    }
  }

  ColorSort.set(false);
}

// called when top optical *detects* a new object being sorted out
void onTopDetected() {
    // Brain.Screen.print("Top detected");

  int hue = OpticalTop.hue();
  // bool shouldSort = false;
  int detected = BallUndefined;

  if ((hue >= 300 && hue <= 359) ||
      (hue >= 0   && hue <= 50)) {
    // shouldSort = true;
    detected = BallRed;
  }
  // BLUE: 210–240
  if (hue >= 60 && hue <= 260) {
    detected = BallBlue;
  }
  
  Brain.Screen.printAt(10, 90, "Detected hue: %d Color: %d", hue, detected);

  if (TEAMCOLOR != detected) {
    ColorSortTimer.event([](){
        // stop intake after 1 second if still detecting object
        ThirdStage.spin(reverse,12000,voltageUnits::mV);
        wait(500, msec);
        ThirdStage.stop(hold);
    }, 200);
      // attempt to remove a ball
    if (counter.removeBall()) {
      Brain.Screen.printAt(10, 70, "Ball removed! Count: %d", counter.balls());
    }
  } else { // if theres ball of same color stop the intake and hold top ball
    ThirdStage.stop(hold);
    ColorSortTimer.event([](){
      if (OpticalTop.isNearObject()) {
        // stop intake after 1 second if still detecting object
        ThirdStage.spinFor(forward, 1, rev, false);
        SecondStage.spinFor(reverse, 1, rev, false);
        // SecondStage.stop(hold);
      } 
    }, 500);
    // SecondStage.stop(hold);
  }
}