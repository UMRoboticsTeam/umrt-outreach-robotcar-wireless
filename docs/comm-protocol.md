# Communication Protocol
### ELEGOO - Smart Robot Car V4.0 With Camera
Copied from `Communication protocol for Smart Robot Car.pdf`

This was initially for the serial communication to the smart car, but since the REST API is implemented on the camera web server, you just need to send a POST request to the `/json_command` endpoint with your json command.

Not all commands are tested. 


# Motor
```json
{"H": ID, "N": 1, "D1": selection, "D2": speed, "D3": direction}
```
Select the motor to set the rotation direction and speed

| Parameter | Name | Description |
|----|-|-|
| D1 | Selection | 0: All Motors<br>1: Left Motors<br>2: Right Motors |
| D2 | Speed | Motor Speed 0-255 |
| D3 | Direction | 0: Clockwise<br>1: Counterclockwise |

```json
{"H": ID, "N": 3, "D1": direction, "D2": speed}
```
Set the direction and speed of the car
| Parameter | Name | Description |
|-|-|-|
| D1 | Direction | 1: Turn Left<br>2: Turn Right<br>3: Forward<br>4: Back |
| D2 | Speed | 0-255 |

```json
{"H": ID, "N": 3, "D1": left_speed, "D2": right_speed}
```
Set the speed of the left and right motors separately
| Parameter | Name | Description |
|-|-|-|
| D1 | Left Motor Speed | 0-255 |
| D2 | Right Motor Speed | 0-255 |




# Servo Motor
```json
{"H": ID, "N": 5, "D1": servo_id, "D2": angle}
```
Set the rotation angle of the servo motor
| Parameter | Name | Description |
|-|-|-|
| D1 | Servo ID | 0 or 1 |
| D2 | Rotation Angle | 0-180 |



## Camera Rotation (Wrapper of Servo Motor?)
```json
{"N": 106, "D1": direction}
```
Set the rotation direction of the camera
| Parameter | Name | Description |
|-|-|-|
| D1 | Direction | 1: Up<br>2: Down<br>3: Left<br>4: Right  |



# Clear Mode
```json
{"N": 100}
```
Clear all functions being executed.
```json
{"H": ID, "N": 110}
```
Clears all functions being executed, and does not enter standby mode


# Switch Car Mode
```json
{"N": 101, "D1": mode}
```
Switch the car mode
| Parameter | Name | Description |
|-|-|-|
| D1 | Mode | 1: Tracking mode<br>2: Obstacle-avoidance mode<br>3: Follow mode |



# Joystick Movement
```json
{"N": 102, "D1": direction, "D2": speed}
```
Make the car move in a certain direction
| Parameter | Name | Description |
|-|-|-|
| D1 | Direction | 1: Forward<br>2: Back<br>3: Turn Left<br>4: Turn Right<br>5: Left Forward<br>6: Left Back<br>7:Right Forward<br>8: Right Back|
| D2 | Speed | 0-255 |




# Ultrasonic Module
```json
{"H": ID, "N": 21, "D1": option}
```
Check whether an obstacle is detected
| Parameter | Name | Description |
|-|-|-|
| D1 | option | 1: Obstacle is detected? Returns `{ID_false}` or `{ID_true}`<br>2: Sensor Value? Returns `{ value }` |



# Infared Module
```json
{"H": ID, "N": 22, "D1": infared_id}
```
Check the value of the infared sensor
| Parameter | Name | Description |
|-|-|-|
| D1 | Infared ID | 0: Left Sensor<br>1: Middle Sensor<br>2: Right Sensor |
Returns `{ ID_ value }`

```json
{"H": ID, "N": 23}
```
Check if the car leaves the ground
Returns `{ ID_ false }` or `{ ID_ true }`



# Threshold Adjustment
```json
{"N": 104, "D1": value}
```
Adjust the tracking sensitivity of the car
| Parameter | Name | Description |
|-|-|-|
| D1 | Value | 50-1000 |




