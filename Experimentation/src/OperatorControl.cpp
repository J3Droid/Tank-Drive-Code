#include "vex.h"
#include "OperatorControl.h"

using namespace vex;

void joyStickControl (){
  FrontLeft.spin(fwd,Controller1.Axis3.position(), pct);
  BackLeft.spin(fwd,Controller1.Axis3.position(), pct);
  FrontRight.spin(fwd,Controller1.Axis2.position(), pct);
  BackRight.spin(fwd,Controller1.Axis2.position(), pct);
}

void intakeControl (){
  if (Controller1.ButtonR1.pressing()){
    Intake1.spin(fwd, 100, pct);
    Intake2.spin(fwd, 100, pct);
  }
  else if (Controller1.ButtonR2.pressing()){
    Intake1.spin(fwd, -100, pct);
    Intake2.spin(fwd, -100, pct);
  }
  else{
    Intake1.stop(brake);
    Intake2.stop(brake);
  }

}