# Arduino_SmartCar
4WD Smart Car library for the Arduino.


This library allows an Arduino board to control a 4WD car with a L298N chipset connected to the motors. 

To use, first download the library, you can find it here: https://www.dropbox.com/s/egcmf6bxqnzrnn1/SmartCarLib_1.0.0.zip?dl=0

Next, you should install the library, you can either do it manually or automatically.

Then restart the Arduino software if necessary, and SmartCarLib should be available under the libraries dropdown.

Usage is pretty straightforward, first you need to connect the motors to the L298N, like so:

![alt tag](https://www.dropbox.com/s/ajhv19hcuea3n10/SmartCar_bb.png?dl=1)

Based on this schematic, the code is:
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
  In the above example the car will go forward for 2sec, stop by 1sec, and then repeat it.
  
  You can check an example of this library being use over bluetooth by a Windows interface: https://github.com/snackk/Arduino_BSmartCar/blob/master/BSmartCar/BSmartCar/BSmartCar.ino
  
Written by Diogo Santos.

