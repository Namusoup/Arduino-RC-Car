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
       * If switch yields a value of 0, follow the joystick
       * If switch yields a value of 1, activate Go() function
       * autostop still works
* button
    * if button is pressed --> dance function
       * delay 2 seconds to wait until one cycle of dance ends before a new cycle begins
       * If butten is not pressed, do nothing


## bluetooth
* input values sent from controller to rc car for it to perform a specific fucntion
* if joystick is in certain range, input1 = something input 2 = something --> corresponding one is found in the rc car code to perform a set function
* values also asigned for special functions

## Test video
Basic control
![1 gifgifgifgif](https://user-images.githubusercontent.com/47979979/196147836-0ba2c617-93f8-49d0-898f-80fa639ae6bf.gif)
Avoding crash
![2 gif](https://user-images.githubusercontent.com/47979979/196149101-cebd481a-ef3c-451c-b307-4529b8221acd.gif)
Dance
![3 gif](https://user-images.githubusercontent.com/47979979/196149141-4cac788a-dc9b-4ecd-9626-9ada13f30c2e.gif)
Go (Autopilot)
![4 gif](https://user-images.githubusercontent.com/47979979/196149179-790070ab-9819-4e92-986e-c7897ccfef95.gif)
