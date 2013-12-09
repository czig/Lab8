/************************************
 * Author: C2C Caleb Ziegler
 * Date: 21 NOV 13
 * Description: Implementation file for
 * operating motor and moving robot.
 ***********************************/
#include <msp430.h>
#include "motor.h"

//Defines pins as outputs and enables timer subsystems. Two different timers are used with two different control registers for each timer.
void initRobot(void)
{
	P1DIR |= BIT1|BIT2;
	P1SEL |= BIT1|BIT2;
	P2DIR |= BIT0|BIT1;
	P2SEL |= BIT0|BIT1;
	TA0CTL &= ~(MC1|MC0); //Stop the timer
	TA0CTL |= TACLR;  //Clear the timer
	TA0CTL |= TASSEL1; //Select SMCLK
	TA1CTL |= TACLR; //Clear the other timer
	TA1CTL |= TASSEL1; //Select SMCLK
	TA0CCR0 = 100; //Define period as 100
	TA0CCR1 = 50; //Defines 50% duty cycle when uses with OUTMOD_7 (reset/set)
	TA1CCR0 = 100; //Define period as 100
	TA1CCR1 = 50; //Defines 50% duty cycle when uses with OUTMOD_7 (reset/set)
	TA0CTL |= MC0;  //Enables the clock by having it count up to TA0CCR0
	TA1CTL |= MC0;  //Enables the clock by having it count up to TA1CCR0
}

void moveLeftWheelForward(void)
{
	TA0CTL &= ~(MC1|MC0);
	TA0CCR0 = 100; //Define period as 100
	TA0CCR1 = 50; //Defines 50% duty cycle when uses with OUTMOD_7 (reset/set)
	TA0CCTL0 &= ~(OUTMOD_4|OUTMOD_5); //Clears bits in OUTMOD so no errors when writing a new mode(only modes 4 and 5 used for first pin)
	TA0CCTL1 &= ~(OUTMOD_7|OUTMOD_5); //Same thing but clears modes 7 and 5 because they are the only ones used on the second pin
	TA0CCTL0 |= OUTMOD_5;         //Reset mode for ground on P1.1
	TA0CCTL1 |= OUTMOD_7;         //Reset/set mode to send PWM signal on P1.2 to positive terminal
	TA0CTL |= MC0;                //Count up to TACCR0 mode
	__delay_cycles(100);

}

void moveLeftWheelBack(void)
{
	TA0CTL &= ~(MC1|MC0);
	TA0CCR0 = 100; //Define period as 100
	TA0CCR1 = 50; //Defines 50% duty cycle when uses with OUTMOD_7 (reset/set)
	TA0CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA0CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA0CCTL0 |= OUTMOD_4;         //Toggle output at TA0CCR0 to make PWM visible on P1.1
	TA0CCTL1 |= OUTMOD_5;         //Reset mode for ground on P1.2
	TA0CTL |= MC0;
	__delay_cycles(100);
}

void moveRightWheelForward(void)
{
	TA1CTL &= ~(MC1|MC0);
	TA1CCR0 = 100; //Define period as 100
	TA1CCR1 = 50; //Defines 50% duty cycle when uses with OUTMOD_7 (reset/set)
	TA1CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA1CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA1CCTL0 |= OUTMOD_5;        //Reset mode for ground on P2.0
	TA1CCTL1 |= OUTMOD_7;        //Reset/set mode to send PWM signal on P2.1 to positive terminal
	TA1CTL |= MC0;
	__delay_cycles(100);
}

void moveRightWheelBack(void)
{
	TA1CTL &= ~(MC1|MC0);
	TA1CCR0 = 100; //Define period as 100
	TA1CCR1 = 50; //Defines 50% duty cycle when uses with OUTMOD_7 (reset/set)
	TA1CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA1CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA1CCTL0 |= OUTMOD_4;        //Toggle output at TA1CCR0 to make PWM visible on P2.0
	TA1CCTL1 |= OUTMOD_5;        //Reset mode for ground on P2.1
	TA1CTL |= MC0;
	__delay_cycles(100);
}

void stopLeftWheel(void)
{
	TA0CTL &= ~(MC1|MC0);
	TA0CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA0CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA0CCTL0 |= OUTMOD_5;
	TA0CCTL1 |= OUTMOD_5;         //Both terminals become ground to make motor stop
	TA0CTL |= MC0;
	__delay_cycles(100);
}

void stopRightWheel(void)
{
	TA1CTL &= ~(MC1|MC0);
	TA1CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA1CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA1CCTL0 |= OUTMOD_5;
	TA1CCTL1 |= OUTMOD_5;        //Again, both terminals ground
	TA1CTL |= MC0;
	__delay_cycles(100);
}

void moveRobotForward(void)
{
	moveRightWheelForward();
	moveLeftWheelForward();
}

void moveRobotBackward(void)
{
    moveRightWheelBack();
    moveLeftWheelBack();
}

void turnRobotRight(void)
{
    moveRightWheelBack();
    moveLeftWheelForward();
}

void turnRobotLeft(void)
{
    moveRightWheelForward();
    moveLeftWheelBack();
}

void stopRobot(void)
{
    stopRightWheel();
    stopLeftWheel();
}

// Lab 8 new part

void moveLeftWheelForwardSlowly(void)
{
	TA0CTL &= ~(MC1|MC0);
	TA0CCR0 = 100; //Define period as 100
	TA0CCR1 = 30; //Defines 20% duty cycle when uses with OUTMOD_7 (reset/set)
	TA0CCTL0 &= ~(OUTMOD_4|OUTMOD_5); //Clears bits in OUTMOD so no errors when writing a new mode(only modes 4 and 5 used for first pin)
	TA0CCTL1 &= ~(OUTMOD_7|OUTMOD_5); //Same thing but clears modes 7 and 5 because they are the only ones used on the second pin
	TA0CCTL0 |= OUTMOD_5;         //Reset mode for ground on P1.1
	TA0CCTL1 |= OUTMOD_7;         //Reset/set mode to send PWM signal on P1.2 to positive terminal
	TA0CTL |= MC0;                //Count up to TACCR0 mode
	__delay_cycles(100);
}

void moveRightWheelForwardSlowly(void)
{
	TA1CTL &= ~(MC1|MC0);
	TA1CCR0 = 100; //Define period as 100
	TA1CCR1 = 30; //Defines 20% duty cycle when uses with OUTMOD_7 (reset/set)
	TA1CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA1CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA1CCTL0 |= OUTMOD_5;        //Reset mode for ground on P2.0
	TA1CCTL1 |= OUTMOD_7;        //Reset/set mode to send PWM signal on P2.1 to positive terminal
	TA1CTL |= MC0;
	__delay_cycles(100);
}

void veerRobotRight(void)
{
	moveRightWheelForwardSlowly();
	moveLeftWheelForward();
}

void veerRobotLeft(void)
{
	moveRightWheelForward();
	moveLeftWheelForwardSlowly();
}
