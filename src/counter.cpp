#include "counter.h"

BallCounter::BallCounter(int max) {
  maxBalls = max;
  ballCount = 0;
}

bool BallCounter::countBall() {
  lock.lock();
  if (ballCount < maxBalls) {
    ballCount++;
    lock.unlock();
    return true;
  }
  lock.unlock();
  return false;
}

bool BallCounter::removeBall() {
  lock.lock();
  if (ballCount > 0) {
    ballCount--;
    lock.unlock();
    return true;
  }
  lock.unlock();
  return false;
}

int BallCounter::balls() {
  lock.lock();
  int c = ballCount;
  lock.unlock();
  return c;
}
