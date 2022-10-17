# Arduino-RC-Car
## Rc car
* Basic motor functions
    *  Split into 9 different areas for the control, specific joystick range assigned for each
    *  Forward, forwardRight, forwardLeft, right, left, back, backRight, backLeft, stop
    *  Motor speeds adjusted to make it turn
* Special functions:  dance, go
    * Dance: turn right for 2 seconds then turn left for 2 seconds to return to the same position
    * Go: when a lever is switched on the controller, rc car moves around by itself without crashing into a wall, performs random functions unless: lever is toggled again, car gets near a wall
* Auto when near a wall with a ultrasonic sensor
    * Automatically goes backwards when it senses that it is within 10 cm of a wall/blockage


## Controller
* Joystick
    * Xvalues and yvalues gathered as a variable
    * Values determine the specific direction the vehicle will be controlled in. range of x and y values are set for the basic motor functions
* Lever
    * Lever toggles Go() function
       * If switch yields a value of 0, follow the joystick
       * If switch yields a value of 1, activate Go() function
       * Autostop still works
* Button
    * If button is pressed --> dance function
       * Delay 2 seconds to wait until one cycle of dance ends before a new cycle begins
       * If butten is not pressed, do nothing


## Bluetooth
* Input values sent from controller to rc car for it to perform a specific fucntion
* If joystick is in certain range, input1 = something input 2 = something --> corresponding one is found in the rc car code to perform a set function
* Values also asigned for special functions

## Test video
### Basic control  
![1 gifgifgifgif](https://user-images.githubusercontent.com/47979979/196147836-0ba2c617-93f8-49d0-898f-80fa639ae6bf.gif)


### Avoding crash  
![2 gif](https://user-images.githubusercontent.com/47979979/196149101-cebd481a-ef3c-451c-b307-4529b8221acd.gif)


### Dance    
![3 gif](https://user-images.githubusercontent.com/47979979/196149141-4cac788a-dc9b-4ecd-9626-9ada13f30c2e.gif)


### Go (Autopilot)    
![4 gif](https://user-images.githubusercontent.com/47979979/196149179-790070ab-9819-4e92-986e-c7897ccfef95.gif)
