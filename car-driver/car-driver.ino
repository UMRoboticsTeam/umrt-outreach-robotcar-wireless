//***********************************************************************************************
//  This example shows how to create Robo Eyes animation sequences without the use of delay(); 
//
//  Hardware: You'll need a breadboard, an arduino nano r3, an I2C oled display with 1306   
//  or 1309 chip and some jumper wires.
//  
//  Published in September 2024 by Dennis Hoelscher, FluxGarage
//  www.youtube.com/@FluxGarage
//  www.fluxgarage.com
//
//***********************************************************************************************

#include <ArduinoJson.h>
// #include <Arduino_JSON.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include "FluxGarage_RoboEyes.h"
roboEyes roboEyes; // create eyes



#include "L298NX2.h"


#define EN_A 5
#define IN1_A 6
#define IN2_A 7

#define IN1_B 8
#define IN2_B 9
#define EN_B 10


// Initialize both motors
L298NX2 myMotors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);


// EVENT TIMER
// unsigned long eventTimer; // will save the timestamps
// bool event1wasPlayed = 0; // flag variables
// bool event2wasPlayed = 0;
// bool event3wasPlayed = 0;




// // json buffer
// StaticJsonDocument<16> doc; // Use a smaller size if possible
// const size_t bufferSize = 16; // Adjust based on the expected JSON size
// char jsonBuffer[bufferSize];   // Buffer to store incoming JSON string

// void handleCmd1(const JsonDocument& doc);
// void handleCmd3(const JsonDocument& doc);
// void handleCmd102(const JsonDocument& doc);


void setup() {
  // Increase PWM frequency for Timer 1 (pins 9 and 10)
// TCCR1B = TCCR1B & 0b11111000 | 0x01; // Set Timer 1 to ~31kHz

// Increase PWM frequency for Timer 2 (pins 3 and 11)
// TCCR2B = TCCR2B & 0b11111000 | 0x01; // Set Timer 2 to ~31kHz


  Serial.begin(9600);

  // OLED Display
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Startup robo eyes
  roboEyes.begin(SCREEN_WIDTH, SCREEN_HEIGHT, 100); // screen-width, screen-height, max framerate - 60-100fps are good for smooth animations
  roboEyes.setPosition(DEFAULT); // eye position should be middle center
  roboEyes.close(); // start with closed eyes 
  
  roboEyes.setAutoblinker(ON, 3, 2); // Start auto blinker animation cycle -> bool active, int interval, int variation -> turn on/off, set interval between each blink in full seconds, set range for random interval variation in full seconds
  roboEyes.setIdleMode(ON, 2, 2); // Start idle animation cycle (eyes looking in random directions) -> turn on/off, set interval between each eye repositioning in full seconds, set range for random time interval variation in full seconds
  

  // eventTimer = millis(); // start event timer from here
  myMotors.setSpeed(10);
  // myMotors.setSpeedA(1);
  // myMotors.setSpeedB(1);
  myMotors.forward();
} // end of setup


void loop() {
 roboEyes.update(); // update eyes drawings

  // LOOPED ANIMATION SEQUENCE
  // Do once after defined number of milliseconds
  // if(millis() >= eventTimer+2000 && event1wasPlayed == 0){
  //   event1wasPlayed = 1; // flag variable to make sure the event will only be handled once
  //   roboEyes.open(); // open eyes 
  // }
  // // Do once after defined number of milliseconds
  // if(millis() >= eventTimer+4000 && event2wasPlayed == 0){
  //   event2wasPlayed = 1; // flag variable to make sure the event will only be handled once
  //   roboEyes.setMood(HAPPY);
  //   roboEyes.anim_laugh();
  //   //roboEyes.anim_confused();
  // }
  // // Do once after defined number of milliseconds
  // if(millis() >= eventTimer+6000 && event3wasPlayed == 0){
  //   event3wasPlayed = 1; // flag variable to make sure the event will only be handled once
  //   roboEyes.setMood(TIRED);
  //   //roboEyes.blink();
  // }
  // // Do once after defined number of milliseconds, then reset timer and flags to restart the whole animation sequence
  // if(millis() >= eventTimer+8000){
  //   roboEyes.close(); // close eyes again
  //   roboEyes.setMood(DEFAULT);
  //   // Reset the timer and the event flags to restart the whole "complex animation loop"
  //   eventTimer = millis(); // reset timer
  //   event1wasPlayed = 0; // reset flags
  //   event2wasPlayed = 0;
  //   event3wasPlayed = 0;
  // }
  // END OF LOOPED ANIMATION SEQUENCE

  // if (Serial.available()) {
  //   char cmd = Serial.read();

  //   if (cmd == '0') {
  //     // setSpeedA();
  //     // setSpeedB();
  //     // myMotors.setSpeed(0);
  //     myMotors.stop();
  //   }
  //   else if (cmd == '1') {
  //       myMotors.setSpeed(10);
  //      myMotors.forward();
  //   }
  //   else if (cmd == '2') {
  //       myMotors.setSpeed(20);
  //      myMotors.forward();
  //   }
  //   else if (cmd == '3') {
  //       myMotors.setSpeed(30);
  //      myMotors.forward();
  //   }
  //   else if (cmd == '4') {
  //       myMotors.setSpeed(40);
  //      myMotors.forward();
  //   }
  //   else if (cmd == '5') {
  //       myMotors.setSpeed(50);
  //      myMotors.forward();
  //   }
  //   else if (cmd == '6') {
  //       myMotors.setSpeed(60);
  //      myMotors.forward();
  //   }
  //   else if (cmd == '7') {
  //       myMotors.setSpeed(70);
  //      myMotors.forward();
  //   }
  //   else if (cmd == '8') {
  //       myMotors.setSpeed(80);
  //      myMotors.forward();
  //   }
  //   else if (cmd == '9') {
  //       myMotors.setSpeed(90);
  //      myMotors.forward();
  //   }
    
  //   // else {
  //   //   myMotors.stop();
  //   // }
  // }


  // Serial.println(myMotors.getSpeedA());







  /*
  if (Serial.available()) {
    
    // size_t len = Serial.readBytesUntil('\n', jsonBuffer, bufferSize - 1);
    // jsonBuffer[len] = '\0';

    // // Parse the JSON message
    // StaticJsonDocument<bufferSize> doc;
    // DeserializationError error = deserializeJson(doc, jsonBuffer);

    // if (error) {
    //   Serial.print("JSON parse error: ");
    //   Serial.println(error.c_str());
    //   return;
    // }

    // if (doc.containsKey("N")) {
    //   int command = doc["N"];

      
    //   switch (command) {
    //     case 1:
    //       handleCmd1(doc);
    //       break;
    //     case 3:
    //       handleCmd3(doc);
    //       break;
          
    //     case 102:
    //       handleCmd102(doc);
    //       break;


    //     default:
    //       Serial.print("Unknown command: ");
    //       Serial.println(command);
    //       break;
    //   }
    // } else {
    //   Serial.println("Invalid JSON: Missing 'N' field.");
    // }

    static String inputString = "";
    char incomingChar = Serial.read();

    if (incomingChar == '\n') {

      inputString.trim();
      inputString.toCharArray(jsonBuffer, bufferSize);
      Serial.print("Received: ");
      Serial.println(jsonBuffer);
      
      inputString = ""; // Clear the buffer
    } else {
      inputString += incomingChar;
    }
  }*/

  handleCmdJson();
} 


// W {"N":3,"D1":3,"D2":255}
// S {"N":3,"D1":4,"D2":255}
// A {"N":102,"D1":3,"D2":255}
// D {"N":102,"D1":4,"D2":255}


// WA {"N":102,"D1":5,"D2":255}
// WD {"N":102,"D1":7,"D2":255}
// SA {"N":102,"D1":6,"D2":255}
// SD {"N":102,"D1":8,"D2":255}


// Q {"H":1,"N":5,"D1":1,"D2":120}
// E {"H":1,"N":5,"D1":1,"D2":90}

// STOP {"N":1,"D1":0,"D2":0,"D3":1}

void handleCmdJson() {
  static String inputString = ""; // Buffer to store incoming serial data

  // Check if data is available on Serial
  if (Serial.available()) {
    char incomingChar = Serial.read(); // Read one character from Serial

    if (incomingChar == '\n') { // End of command
      inputString.trim(); // Remove any leading/trailing whitespace

      Serial.print(F("Received: "));
      Serial.println(inputString);

      // Parse the command
      int command = 0, d1 = 0, d2 = 0, d3 = 0;
      int parsed = sscanf(inputString.c_str(), "%d %d %d %d", &command, &d1, &d2, &d3);

      if (parsed >= 1) {
        Serial.print(F("Command: "));
        Serial.println(command);

        // Handle the command
        switch (command) {
          case 1:
            handleCmd1(d1, d2, d3);
            break;
          case 3:
            handleCmd3(d1, d2);
            break;
          case 102:
            handleCmd102(d1, d2);
            break;
          default:
            Serial.print(F("Unknown command: "));
            Serial.println(command);
            break;
        }
      } else {
        Serial.println(F("Invalid command format."));
      }

      inputString = ""; // Clear the buffer
    } else {
      inputString += incomingChar; // Append character to the input buffer
    }
  }
}

/*
void handleCmd1(const JsonDocument& doc) {
  if (doc.containsKey("D1") && doc.containsKey("D2") && doc.containsKey("D3")) {
    int selection = doc["D1"];
    int speed = doc["D2"];
    int direction = doc["D3"];

    if (direction == 0) {
      if (selection != 2) {
        // Left Side
        myMotors.setSpeedA(speed);
        myMotors.forwardA();
      } 
      if (selection != 1) {
        // Right Side
        myMotors.setSpeedB(speed);
        myMotors.forwardB();
      }
    }
    else {
      if (selection != 2) {
        // Left Side
        myMotors.setSpeedA(speed);
        myMotors.backwardA();
      } 
      if (selection != 1) {
        // Right Side
        myMotors.setSpeedB(speed);
        myMotors.backwardB();
      }
    }
  }
  Serial.println("Handled CMD 1");
}

void handleCmd3(const JsonDocument& doc) {
  if (doc.containsKey("D1") && doc.containsKey("D2")) {
    int direction = doc["D1"];
    int speed = doc["D2"];


    myMotors.setSpeed(speed);
    if (direction == 3) {
      // 3 - forward
      myMotors.forward();
    }
    else if (direction == 4) {
      // 4 - backward
      myMotors.backward();
    }
    else if (direction == 1) {
      // 1 - turn left
      myMotors.backwardA();
      myMotors.forwardB();
    }
    else if (direction == 2) {
      // 2 - turn right
      myMotors.forwardA();
      myMotors.backwardB();
    }
  }
  Serial.println("Handled CMD 3");
}

void handleCmd102(const JsonDocument& doc) {
  if (doc.containsKey("D1") && doc.containsKey("D2")) {
    int direction = doc["D1"];
    int speed = doc["D2"];
    


    // myMotors.setSpeed(speed);
    if (direction == 1) {
      // 1 - Forward
      myMotors.setSpeed(speed);
      myMotors.forward();
    }
    if (direction == 2) {
      // 2 - Backward
      myMotors.setSpeed(speed);
      myMotors.backward();
    }
    if (direction == 3) {
      // 3 - Turn Left
      myMotors.setSpeed(speed);
      myMotors.backwardA();
      myMotors.forwardB();
    }
    if (direction == 4) {
      // 4 - Turn right
      myMotors.setSpeed(speed);
      myMotors.forwardA();
      myMotors.backwardB();
    }
    if (direction == 5) {
      // 5 - Left Forward
      myMotors.setSpeedA(speed / 2);
      myMotors.setSpeedB(speed);
      myMotors.forward();
    }
    if (direction == 6) {
      // 6 - Left Backward
      myMotors.setSpeedA(speed / 2);
      myMotors.setSpeedB(speed);
      myMotors.backward();
    }
    if (direction == 7) {
      // 7 - Right Forward
      myMotors.setSpeedA(speed);
      myMotors.setSpeedB(speed / 2);
      myMotors.forward();
    }
    if (direction == 8) {
      // 8 - Right Backward
      myMotors.setSpeedA(speed);
      myMotors.setSpeedB(speed / 2);
      myMotors.backward();
    }
    
  }
  Serial.println("Handled CMD 102");
}
*/


// void handleCmd1(const JsonDocument& doc) {Serial.println(F("Handled CMD 1"));}
// void handleCmd3(const JsonDocument& doc) {Serial.println(F("Handled CMD 3"));}
// void handleCmd102(const JsonDocument& doc) {Serial.println(F("Handled CMD 102"));}

// void handleCmd1(int d1, int d2, int d3) {Serial.println(F("Handled CMD 1"));}
// void handleCmd3(int d1, int d2) {Serial.println(F("Handled CMD 3"));}
// void handleCmd102(int d1, int d2) {Serial.println(F("Handled CMD 102"));}


void handleCmd1(int selection, int speed, int direction) {

  if (direction == 0) {
    if (selection != 2) {
      // Left Side
      myMotors.setSpeedA(speed);
      myMotors.forwardA();
    } 
    if (selection != 1) {
      // Right Side
      myMotors.setSpeedB(speed);
      myMotors.forwardB();
    }
  }
  else {
    if (selection != 2) {
      // Left Side
      myMotors.setSpeedA(speed);
      myMotors.backwardA();
    } 
    if (selection != 1) {
      // Right Side
      myMotors.setSpeedB(speed);
      myMotors.backwardB();
    }
  }
  
  Serial.println("Handled CMD 1");
}

void handleCmd3(int direction, int speed) {

  myMotors.setSpeed(speed);
  if (direction == 3) {
    // 3 - forward
    myMotors.forward();
  }
  else if (direction == 4) {
    // 4 - backward
    myMotors.backward();
  }
  else if (direction == 1) {
    // 1 - turn left
    myMotors.backwardA();
    myMotors.forwardB();
  }
  else if (direction == 2) {
    // 2 - turn right
    myMotors.forwardA();
    myMotors.backwardB();
  }
  Serial.println("Handled CMD 3");
}

void handleCmd102(int direction, int speed) {

  // myMotors.setSpeed(speed);
  if (direction == 1) {
    // 1 - Forward
    myMotors.setSpeed(speed);
    myMotors.forward();
  }
  if (direction == 2) {
    // 2 - Backward
    myMotors.setSpeed(speed);
    myMotors.backward();
  }
  if (direction == 3) {
    // 3 - Turn Left
    myMotors.setSpeed(speed);
    myMotors.backwardA();
    myMotors.forwardB();
  }
  if (direction == 4) {
    // 4 - Turn right
    myMotors.setSpeed(speed);
    myMotors.forwardA();
    myMotors.backwardB();
  }
  if (direction == 5) {
    // 5 - Left Forward
    myMotors.setSpeedA(speed / 2);
    myMotors.setSpeedB(speed);
    myMotors.forward();
  }
  if (direction == 6) {
    // 6 - Left Backward
    myMotors.setSpeedA(speed / 2);
    myMotors.setSpeedB(speed);
    myMotors.backward();
  }
  if (direction == 7) {
    // 7 - Right Forward
    myMotors.setSpeedA(speed);
    myMotors.setSpeedB(speed / 2);
    myMotors.forward();
  }
  if (direction == 8) {
    // 8 - Right Backward
    myMotors.setSpeedA(speed);
    myMotors.setSpeedB(speed / 2);
    myMotors.backward();
  }
  
  Serial.println("Handled CMD 102");
}