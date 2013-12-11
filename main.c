/************************************
 * Author: C2C Caleb Ziegler
 * Date: 7 DEC 13
 * Description: Uses right wall
 * following to make robot navigate
 * maze.
 ***********************************/

#include <msp430.h> 
#include "motor.h"
#include "sensor.h"

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    initRobot();
    initSensors();
    __delay_cycles(3000000); //Delay here to give user time to get robot to floor

    while (1)
    {
    	if (getRightSensor() < 0x2B8)
    	{
    		veerRobotRight();
    		__delay_cycles(1000);
    	}
    	else
    	{
    		veerRobotLeft();
    		__delay_cycles(1000);
    	}

    	if (getCenterSensor() > 0x30A)
    	{
    		moveRobotBackward();
    		__delay_cycles(300000);
    		turnRobotLeft();
    		__delay_cycles(400000);
    		stopRobot();
    		__delay_cycles(1000);
    	}

    }

}
