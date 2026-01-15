#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;


void ColorSortBottomParallel() {
  while (true) {
  if (OpticalBottom.isNearObject()) {
        Brain.Screen.clearScreen();
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
        wait(50, msec);
    }
  }
}

void ColorSortTopParallel() {
  while (true) {
    ThirdStage.spin(forward, 12000, voltageUnits::mV);
    if (OpticalTop.isNearObject()) {
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
        ThirdStage.spin(reverse,12000,voltageUnits::mV);
        wait(500, msec);
      }
      wait(50, msec);
   }
  }
}
