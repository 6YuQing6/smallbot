#pragma once
#include "vex.h"

class BallCounter {
private:
  int ballCount;
  int maxBalls;
  vex::mutex lock;

public:
  BallCounter(int max = 2);
  bool countBall();
  bool removeBall();
  int balls();
};
