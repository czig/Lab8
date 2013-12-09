/************************************
 * Author: C2C Caleb Ziegler
 * Date: 07 DEC 13
 * Description: Header file for
 * operating sensors on robot.
 ***********************************/

#include <msp430.h>
#ifndef SENSOR_H_
#define SENSOR_H_

// Initializes the sensors on the robot to allow sensing for the left, right, and center sensors.
// The left sensor uses A3 (P1.3), the right sensor uses A4 (P1.4), and the center sensor uses
// A5 (P1.5) to perform ADC on the sensor analog signals in the MSP430.
void initSensors(void);

// Returns the reading from the left sensor after the analog output signal from the sensor
// is passed through the ADC. Again uses A3 (P1.3)
unsigned int getLeftSensor();

// Returns the reading from the right sensor after the analog output signal from the sensor
// is passed through the ADC. Again uses A4 (P1.4)
unsigned int getRightSensor();

// Returns the reading from the center sensor after the analog output signal from the sensor
// is passed through the ADC. Again uses A5 (P1.5)
unsigned int getCenterSensor();

#endif /* SENSOR_H_ */
