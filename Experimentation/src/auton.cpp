
#include "vex.h"
#include "auton.h"

using namespace vex;

void moveForwardSimple( int speed ){
  FrontLeft.spin(fwd, speed, pct);
  BackLeft.spin(fwd, speed, pct);
  FrontRight.spin(fwd, speed, pct);
  BackRight.spin(fwd, speed, pct);

}

void moveForwardWalk (int speed, double distanceIN){
  double wheelDiameter = 3.25;
  double circumference = 3.14 * wheelDiameter;
  double degreesToRotate = ((360 * distanceIN) / circumference);

 FrontLeft.rotateFor(fwd, degreesToRotate, rotationUnits::deg, speed, velocityUnits::pct, false);
 FrontRight.rotateFor(fwd, degreesToRotate, rotationUnits::deg, speed, velocityUnits::pct, false);
 BackLeft.rotateFor(fwd, degreesToRotate, rotationUnits::deg, speed, velocityUnits::pct, false);
 BackRight.rotateFor(fwd, degreesToRotate, rotationUnits::deg, speed, velocityUnits::pct);

}

void turnLeftSimple ( int speed ){
  FrontLeft.spin(fwd, speed, pct);
  BackLeft.spin(fwd, speed, pct);
  FrontRight.spin(fwd, -speed, pct);
  BackRight.spin(fwd, -speed, pct);
}

void turnRightSimple ( int speed ){
  FrontLeft.spin(fwd, -speed, pct);
  BackLeft.spin(fwd, -speed, pct);
  FrontRight.spin(fwd, speed, pct);
  BackRight.spin(fwd, speed, pct);
}

void turnLeftWalk (double degree, int speed){
  double ticksPerTurn = 1810;
  double ticks = degree * (ticksPerTurn / 360);
  double degreesToRotate = ticks;

  FrontLeft.rotateFor(fwd, degreesToRotate, deg, speed, velocityUnits::pct);
  BackLeft.rotateFor(fwd, degreesToRotate, deg, speed, velocityUnits::pct);
  FrontRight.rotateFor(reverse, -degreesToRotate, deg, speed, velocityUnits::pct);
  BackRight.rotateFor(reverse, -degreesToRotate, deg, speed, velocityUnits::pct);
}

void turnRightWalk (double degree, int speed){
  double ticksPerTurn = 1810;
  double ticks = degree * (ticksPerTurn / 360);
  double degreesToRotate = ticks;

  FrontLeft.rotateFor(reverse, -degreesToRotate, deg, speed, velocityUnits::pct);
  BackLeft.rotateFor(reverse, -degreesToRotate, deg, speed, velocityUnits::pct);
  FrontRight.rotateFor(fwd, degreesToRotate, deg, speed, velocityUnits::pct);
  BackRight.rotateFor(fwd, degreesToRotate, deg, speed, velocityUnits::pct);
}