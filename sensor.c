/************************************
 * Author: C2C Caleb Ziegler
 * Date: 07 DEC 13
 * Description: Implementation file for
 * operating sensor on robot.
 ***********************************/

#include <msp430.h>
#include "sensor.h"

void initSensors(void)
{
	ADC10CTL0 &= ~ENC;                          // Disable the core to make changes to control bits in ADC
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // Select longest sampling period (sample-and-hold time), turn on subsystem, and enable interrupts
	ADC10AE0 |= BIT3|BIT4|BIT5;                 // Set P1.3, P1.4, and P1.5 (A3, A4, A5) as analog input for ADC
	ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;         // Select SMCLK to be ADC clock source
	ADC10CTL1 |= BIT7|BIT6|BIT5;                // Divide SMCLK by 8 to ensure slowest possible clock time to prevent problems due to loading (makes ADC more accurate at close distances)
}

unsigned int getLeftSensor()
{
	 ADC10CTL0 &= ~ENC;                         // Disable the core to make changes to control bits in ADC
	 ADC10CTL1 &= ~(INCH_15);                   // Clear input channel
	 ADC10CTL1 |= INCH_3;                       // Set input channel to A3
	 ADC10CTL0 |= ENC + ADC10SC;                // Enable the core and begin sampling/conversion
	 __bis_SR_register(CPUOFF + GIE);           // Go into low power mode and enable interrupts

	 return ADC10MEM;
}

unsigned int getRightSensor()
{
	ADC10CTL0 &= ~ENC;                          // Disable the core to make changes to control bits in ADC
	ADC10CTL1 &= ~(INCH_15);					// Clear input channel
	ADC10CTL1 |= INCH_4;                        // Set input channel to A4
	ADC10CTL0 |= ENC + ADC10SC;                 // Enable the core and begin sampling/conversion
	__bis_SR_register(CPUOFF + GIE);            // Go into low power mode and enable interrupts

	return ADC10MEM;

}

unsigned int getCenterSensor()
{
	ADC10CTL0 &= ~ENC;      					// Disable the core to make changes to control bits in ADC
	ADC10CTL1 &= ~(INCH_15);					// Clear input channel
	ADC10CTL1 |= INCH_5;                        // Set input channel to A5
	ADC10CTL0 |= ENC + ADC10SC;                 // Enable the core and begin sampling/conversion
	__bis_SR_register(CPUOFF + GIE);            // Go into low power mode and enable interrupts

	return ADC10MEM;

}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);            // Re-enable CPU and execute next instructions after low power mode was set
}
