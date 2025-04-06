# umrt-outreach-robotcar-wireless

Showcase program for the outreach car with wireless camera and control with the Elegoo Smart Robot Car Kit v4.0

Has programs for:
* ESPCAM wireless webserver
* Robot car controller

## Project Specifics
* ESP Camera: ```Elegoo ESP32S3 Camera v1.0```
* Motor Driver: ```TB6612```
* Gyro Module: ```MPU6050```


## ESP Camera Arduino IDE Setup
Arduino IDE: 
* Board Manager > Install ```esp32 by Espressif Systems v2.0.14```
* Configure Tools:
  * Board: ```ESP32S3 Dev Module```
  * USB CDC On Boot: ```Enabled```
  * Flash Size: ```8MB (64Mb)```
  * Partition Scheme: ```8M with spiffs (3MB APP/1.5MB SPIFFS)```
  * PSRAM ```OPI PSRAM```

## RobotCar Controller Arduino IDE Setup
* Board: ```Arduino UNO```
