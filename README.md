Lab8
====

"Robot Maze"

This repository includes the files main.c, motor.h, motor.c, sensor.h, and sensor.c which allow the MSP430 to interface with the motors and sensors on the robot in order to allow the robot to navigate the robot maze. Motor.h and motor.c were obtained from the motor library and provide the functions required to move the robot. Sensor.h and sensor.c were obtained from the sensor library and provide the functions required to obtain readings from the sensors. 

##Grading

 - Prelab....................... 11
 - Required Functionality....... 40
 - B-Functionality.............. 10
 - A-Functionality.............. 10
 - Bonus........................ 10

##Operation: 

 - Requirements: robot must always start at home position, robot must find one of three exits and move partially out of maze, robot must solve maze in less than three minutes, robot cannot touch the wall more than twice, and the robot must use the IR sensors to find its path through the maze.

 - Required Functionality - The robot must navigate the maze and move out of door 1.
 - B-Functionality - The robot must navigate the maze and move out door 2.
 - A-Functionality - The robot must navigate the maze and move out door 3.
 - Bonus - The robot must navigate from the A-door back to the entrance

##Functions: 

All functions used are the same as those in the motor library and sensor library, with the exception of four. The four new functions that were created for this lab may been seen in motor.c and motor.h. Four new functions needed to be created in order to move the robot through the maze while effectively utilizing the sensors. These four functions are shown below. 

```
void moveLeftWheelForwardSlowly(void);
```
 - Moves the left wheel forward at 39% duty cycle

```
void moveRightWheelForwardSlowly(void);
```
 - Moves right wheel forward at 39% duty cycle

```
void veerRobotRight();
```
 - Uses moveLeftWheelForward and moveRightWheelForwardSlowly to cause the robot to slowly veer to the right

```
void veerRobotLeft();
```
 - Uses moveRightWheelForward and moveLeftWheelForwardSlowly to cause the robot to slowly veer to the left


##Documentation
 
 - Captain Branchflower's demo of his robot's functionality gave me ideas as to how to obtain functionality in his robot. His demo gave me the idea to create veer functions. Also, I discussed ways to optimize the robot with Captain Branchflower.

##Licensing

 - Anyone is free to use and modify this code for any reason as long as it is documented. 
