# Simple Setup

### 1) Turn car on
Turn battery switch ON  
Ensure switch on Arduino hat is set to CAM, not UPLOAD

### 2) Connect to Car's Wifi
Use your device to connect to its WIFI, it should be `UMRT-CAR-1`
pwd is `umrt2025`

Once your connected, the green LED on the ESP32 should go from FLASHING to SOLID

### 3) Connect to UI
Open a browser and connect to `192.168.4.1`  
You should see the UMRT browser with the camera feed

### 4) Configure
To configure the speed, click "SmartRobot" in the top left corner. The first option is "Speed".  
The default speed is 60 and can go up to 255.

### 5) Controlling
The device is controlled with the arrow keys AND NOW A JOYSTICK!  
If controlled with a controller connected through USB, it only uses one joystick. Probably the leftside joystick.


### Debugging
Camera feed cut out? Restart car  
Car not responding to commands? Restart Car  
Car stuck driving? Restart car  

Sometimes if its just the motors that are tweaking (not the camera), you can try pressing the red button on the Arduino to restart just the motor controller


If you do restart, the speed also defaults back to 60