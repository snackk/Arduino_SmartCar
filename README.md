# Arduino SmartCar 

## Overview

An Arduino library that provides an API to control 4 independent motors. In my particular case I used this library to build a 4 wheel drive car.

This library allows an Arduino board to control a 4WD car with a L298N chipset connected to the motors. 

## Prerequisites

Firstly, this library must be installed in the Arduino IDE, to do so download the library, you can find it here: https://www.dropbox.com/s/egcmf6bxqnzrnn1/SmartCarLib_1.0.0.zip?dl=0

Next, you should unzip the file and place it under Arduino libraries, you can find it here:
```sh
$ cd Documents/Arduino/libraries
$ # or simply
$ cd ~/Arduino/libraries
```
Afterwards restart your Arduino IDE. Once that's done, SmartCarLib should now be available under the libraries dropdown.

## Usage

Usage is pretty straightforward, first you need to follow the bellow schematic, that show how to wire the motor to the L298N chipset:

<p align="center">
  <img src="https://user-images.githubusercontent.com/9936714/73316953-7361b980-422c-11ea-946d-71c960e32a36.png" alt="schematic app" width=600>
</p>

A code example based on the above schematic:
```c
  #include <SmartCarLib.h>
    
  /*
   These are the pins you have connected to the arduino.
    LEFT_MOTOR_1 - 10
    LEFT_MOTOR_2 - 11
    LEFT_MOTOR_PWM_PIN - 6
    
    RIGHT_MOTOR_1 - 12
    RIGHT_MOTOR_2 - 13
    RIGHT_MOTOR_PWM_PIN - 5
  */
	SmartCar(LEFT_MOTOR_1, LEFT_MOTOR_2, LEFT_MOTOR_PWM_PIN, RIGHT_MOTOR_1, RIGHT_MOTOR_2, RIGHT_MOTOR_PWM_PIN)
	SmartCar smartcar(10, 11, 6, 12, 13, 5);
	
  void setup() {
	  Serial.begin(9600);
  }

  void loop() {
    /*
    handleCar receives: 
      "F\n" - Move forward
      "B\n" - Move backward
      "L\n" - Move left
      "F\n" - Move right
    To Stop simply send the same value again.
    */
	  smartcar.handleCar("F\n");
	  delay(2000);
	  
	  smartcar.handleCar("F\n");
	  delay(1000);
  }

  ```
  
  You can check an example of this library being use over bluetooth by a Windows interface: https://github.com/snackk/Arduino_BSmartCar/blob/master/BSmartCar/BSmartCar/BSmartCar.ino
  
  Written by [@snackk](https://github.com/snackk)


