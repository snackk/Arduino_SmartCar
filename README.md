# Arduino_SmartCar
4WD Smart Car library for the Arduino.

To use, first download the library, you can find it here: https://www.dropbox.com/s/egcmf6bxqnzrnn1/SmartCarLib_1.0.0.zip?dl=0

Next, you should install the library, you can either do it manually or automatically.

Then restart the Arduino software if necessary, and SmartCarLib should be available under the libraries dropdown.

Usage is pretty straightforward, on you code simple do the following:
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
    To Stop simply send the same again
    */
	  smartcar.handleCar("F\n");
	  delay(2000);
	  
	  smartcar.handleCar("F\n");
	  delay(1000);
  }

  ```
  In the above example the car will go forward for 2sec, stop by 1sec, and then repeat it.
  
  You can check an example of this library being use over bluetooth by a GUI aplication for Windows: https://github.com/snackk/Arduino_BSmartCar/blob/master/BSmartCar/BSmartCar/BSmartCar.ino
Written by Diogo Santos.

