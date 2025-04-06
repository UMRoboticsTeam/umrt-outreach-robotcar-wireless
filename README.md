# umrt-outreach-robotcar-wireless

Showcase program for the outreach car with wireless camera and control with the Elegoo Smart Robot Car Kit v4.0

Has programs for:
* ESPCAM wireless webserver
* Robot car controller


## Source Code
[ELEGOO Smart Robot Car Kit v4.0 Tutorial](https://www.elegoo.com/blogs/arduino-projects/elegoo-smart-robot-car-kit-v4-0-tutorial?srsltid=AfmBOoqMivfDJrTS4gy-7ch7kX_ipVF3AapzQ6OrKHgQfm_FXfPVEX2j)
* Contains base code for motor controller - Be sure to check **Project Specifics**!

[ELEGOO Smart Robot Car V4.0 with Camera: Upload code to the camera module](https://www.elegoo.com/blogs/learn/elegoo-smart-robot-car-v4-0-with-camera-upload-code-to-the-camera-module?srsltid=AfmBOorwSPXrGH27v5DquohfgNhWwHpXve6odx9NIjyzJDFCGTwSDMKD)
* Contains **UPDATED** camera code for the ESP32S3 Camera V1.0.

## Project Specifics
The template programs change depending on your specific parts. 
* ESP Camera: ```Elegoo ESP32S3 Camera v1.0```
* Motor Driver: ```TB6612```
* Gyro Module: ```MPU6050```


## ESP Camera Arduino IDE Setup
* Board Manager > Install ```esp32 by Espressif Systems v2.0.14```
* Configure Tools:
  * Board: ```ESP32S3 Dev Module```
  * USB CDC On Boot: ```Enabled```
  * Flash Size: ```8MB (64Mb)```
  * Partition Scheme: ```8M with spiffs (3MB APP/1.5MB SPIFFS)```
  * PSRAM ```OPI PSRAM```

## RobotCar Controller Arduino IDE Setup
* Board: ```Arduino UNO```




## converter.py
Quick tool to convert HTML into compressed GZ bytes
#### Usage:
```
> python ./converter.py html_to_txt
```

Compresses **index_ov3660.html** into **index_ov3660_html_gz.txt**.
Now you can copy and paste the output into the bottom of ```camera_index.h``` which stores all of the compressed HTML files.

```
> python ./converter.py txt_to_html
```
The decompression process if desired.
