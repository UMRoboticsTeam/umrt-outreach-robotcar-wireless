# Communication Protocol
### ELEGOO - Smart Robot Car V4.0 With Camera
Copied from ```Communication protocol for Smart Robot Car.pdf```

## Motor
### Command
Command { "H": ID , "N" :1 , "D1": parameter 1 , "D2": parameter 2 , "D3": parameter 3 }
Function Select the motor to set the rotation direction and speed.
Return { ID_ ok}
Parameter
Description
Parameter 1 ( select the corresponding motor )
0 : All motors
1 : Left motor
2 : Right motor
Parameter 2 ( the rotation speed value of the selected motor )
The range of speed value: 0~ 255
Parameter 3 ( select the rotation direction of the selected motor)
1 : Clockwise
2 : Counterclockwise