/************************************
 * Author: C2C Caleb Ziegler
 * Date: 21 NOV 13
 * Description: Header file for
 * operating motor and moving robot.
 ***********************************/

#include <msp430.h>
#ifndef MOTOR_H_
#define MOTOR_H_

//Initializes the pins to be used (P1.1,P1.2,P2.0,P2.1), sets up the timer, and
//sets up a 50% duty cycle in the PWM (does not define the output modes yet).
void initRobot(void);

//Makes left motor operate in "forward" direction. Sets OUTMOD in the Timer A Capture/Compare Control Register to allow P1.2 to
//carry the PWM signal at 50% duty cycle while P1.1 carries ground (P1.1 is connected to the black
//terminal and P1.2 is connected to the red terminal).
void moveLeftWheelForward(void);

//Reverses direction of left motor. Sets OUTMOD in the Timer A Capture/Compare Control Register to allow P1.1 to
//carry the PWM signal at 50% duty cycle while P1.2 carries ground (P1.1 is connected to the black
//terminal and P1.2 is connected to the red terminal).
void moveLeftWheelBack(void);

//Makes right motor move in "forward direction". Sets OUTMOD in the Timer A capture/compare control register so that
//P2.1 carries the PWM signal at 50% duty cycle while P2.0 carries
//ground (P2.1 connected to red terminal and P2.0 connected to black terminal).
void moveRightWheelForward(void);

//Reverses direction of left motor. Sets OUTMOD in the Timer A capture/compare control register so that
//P2.0 carries the PWM signal at 50% duty cycle while P2.1 carries
//ground (P2.1 connected to red terminal and P2.2 connected to black terminal).
void moveRightWheelBack(void);

//Stops the left motor by setting both pins (P1.1 and P1.2) to ground. Sets OUTMOD in the Timer A Capture/Compare Control
//register to make this happen.
void stopLeftWheel(void);

//Stops the right motor by setting both pins (P2.0 and P2.1) to ground. Sets OUTMOD in the Timer A Capture/Compare Control
//register to make this happen.
void stopRightWheel(void);

//Uses moveLeftWheelForward and moveRightWheelForward to make the robot move forward.
void moveRobotForward(void);

//Uses moveLeftWheelBack and moveRightWheelBack to make the robot move in reverse.
void moveRobotBackward(void);

//Uses moveRightWheelBack and moveLeftWheelForward to make the robot turn right.
void turnRobotRight(void);

//Uses moveLeftWheelBack and moveRightWheelForward to make the robot turn left.
void turnRobotLeft(void);

//Uses stopLeftWheel and stopRightWheel to make the robot come to a stop.
void stopRobot(void);

//Lab 8 new part

//Moves the left wheel forward at 39% duty cycle
void moveLeftWheelForwardSlowly(void);

//Moves right wheel forward at 39% duty cycle
void moveRightWheelForwardSlowly(void);

//Uses moveLeftWheelForward and moveRightWheelForwardSlowly to cause the robot to slowly veer to the right
void veerRobotRight();

//Uses moveRightWheelForward and moveLeftWheelForwardSlowly to cause the robot to slowly veer to the left
void veerRobotLeft();


#endif /* MOTOR_H_ */
