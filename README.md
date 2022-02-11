# Arduino-RC-Car
## rc car
* basic motor functions
    *  split into 9 different areas for the control, specific joystick range assigned for each
    *  forward, forwardRight, forwardLeft, right, left, back, backRight, backLeft, stop
    *  motor speeds adjusted to make it turn
* special functions:  dance, go
    * dance: turn right for 2 seconds then turn left for 2 seconds to return to the same position
    * go: when a lever is switched on the controller, rc car moves around by itself without crashing into a wall, performs random functions unless: lever is toggled again, car gets near a wall
* auto when near a wall with a ultrasonic sensor
    * automatically goes backwards when it senses that it is within 10 cm of a wall/blockage


## controller
* joystick
    * xvalues and yvalues gathered as a variable
    * values determine the specific direction the vehicle will be controlled in. range of x and y values are set for the basic motor functions
* lever
    * lever toggles Go() function
       * moves around by itself
       * joystick values ignored when Go()
       * autostop still works :)
* button
    * if button is pressed --> dance function


## bluetooth
* input values sent from controller to rc car for it to perform a specific fucntion
* if joystick is in certain range, input1 = something input 2 = something --> corresponding one is found in the rc car code to perform a set function
* values also asigned for special functions
