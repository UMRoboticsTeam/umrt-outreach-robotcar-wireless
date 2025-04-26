//***********************************************************************************************
//  This example shows how to use the basic methods of the FluxGarage Robo Eyes library. 
//
//  Hardware: You'll need a breadboard, a microcontroller such as arduino nano v3 or better an esp32, 
//  an I2C oled display with sh1106 chip and some jumper wires.
//
//  Use the dedicated I2C pins of your microcontroller, on ESP32-WROOM-32 module use pin 22 for SCL and pin 21 for SDA.
//  Please note: This example turned out to have slow refresh rates on Arduino Uno. Did not find a fix yet.
//  
//  Published in January 2025 by Dennis Hoelscher, FluxGarage
//  www.youtube.com/@FluxGarage
//  www.fluxgarage.com
//
//***********************************************************************************************

// #include <SPI.h>
// #include <Wire.h>

// #include <Adafruit_GFX.h>
// #include <Adafruit_SH110X.h>
#include <U8g2lib.h>

/* Uncomment the initialize the I2C address , uncomment only one, If you get a totally blank screen try the other*/
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's
// #define i2c_Address 0x3d //initialize with the I2C addr 0x3D Typically Adafruit OLED's

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO

// Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
// U8G2_SH1106_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 8, /* reset=*/ 9);
// Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
// https://github.com/adafruit/Adafruit_SH110x/blob/master/Adafruit_SH1106G.cpp
// (width, height, mosi, sclk, dc, rst, cs)
// Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, 11, 13, 8, 9, 10);
// Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, 8, 9, 10);

// u8g2 LIB
U8G2_SH1106_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 8, /* reset=*/ 9);
// U8G2_SH1106_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 8, /* reset=*/ 9);

// #include <FluxGarage_RoboEyes.h>
// #include "FluxGarage_RoboEyes.h"
#include "FluxGarage_u8g2.h"
roboEyes roboEyes; // create RoboEyes instance


void setup()   {
  Serial.begin(9600);
  Serial.println("Starting...");
  delay(250); // wait for the OLED to power up
  // display.begin(i2c_Address, true); // Address 0x3C default
  //display.setContrast (0); // dim display
  // if (!display.begin()) {
  //   Serial.println("Display initialization failed!");
  //   while (1);
  // }
  u8g2.setI2CAddress(0x78);
  u8g2.setDisplayRotation(U8G2_R0);
  u8g2.begin();

  // Startup robo eyes
  roboEyes.begin(SCREEN_WIDTH, SCREEN_HEIGHT, 100); // screen-width, screen-height, max framerate

  // Define some automated eyes behaviour
  roboEyes.setAutoblinker(ON, 3, 2); // Start auto blinker animation cycle -> bool active, int interval, int variation -> turn on/off, set interval between each blink in full seconds, set range for random interval variation in full seconds
  roboEyes.setIdleMode(ON, 2, 2); // Start idle animation cycle (eyes looking in random directions) -> turn on/off, set interval between each eye repositioning in full seconds, set range for random time interval variation in full seconds
  
  // Define eye shapes, all values in pixels
  //roboEyes.setWidth(36, 36); // byte leftEye, byte rightEye
  //roboEyes.setHeight(36, 36); // byte leftEye, byte rightEye
  //roboEyes.setBorderradius(8, 8); // byte leftEye, byte rightEye
  //roboEyes.setSpacebetween(10); // int space -> can also be negative

  // Cyclops mode
  //roboEyes.setCyclops(ON); // bool on/off -> if turned on, robot has only on eye

  // Define mood, curiosity and position
  //roboEyes.setMood(DEFAULT); // mood expressions, can be TIRED, ANGRY, HAPPY, DEFAULT
  //roboEyes.setPosition(DEFAULT); // cardinal directions, can be N, NE, E, SE, S, SW, W, NW, DEFAULT (default = horizontally and vertically centered)
  //roboEyes.setCuriosity(ON); // bool on/off -> when turned on, height of the outer eyes increases when moving to the very left or very right

  // Set horizontal or vertical flickering
  //roboEyes.setHFlicker(ON, 2); // bool on/off, byte amplitude -> horizontal flicker: alternately displacing the eyes in the defined amplitude in pixels
  //roboEyes.setVFlicker(ON, 2); // bool on/off, byte amplitude -> vertical flicker: alternately displacing the eyes in the defined amplitude in pixels

  // Play prebuilt oneshot animations
  //roboEyes.anim_confused(); // confused - eyes shaking left and right
  //roboEyes.anim_laugh(); // laughing - eyes shaking up and down
  Serial.println("End of startup");
} // end of setup




// extern int __heap_start, *__brkval;
// int freeMemory() {
//   int v;
//   return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
// }


void loop() {
  // Serial.println("Starting loop...");
  // Serial.print("Free memory: ");
  // Serial.println(freeMemory()); // Monitor free memory

  roboEyes.update(); // update eyes drawings
  // Dont' use delay() here in order to ensure fluid eyes animations.
  // Check the AnimationSequences example for common practices.
  // delay(500);
}
