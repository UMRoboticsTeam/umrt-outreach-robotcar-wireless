//***********************************************************************************************
//  
//  
//  FluxGarage Robot Eyes Library
//  https://github.com/FluxGarage/RoboEyes/
//
//  L298N Motor Driver Library
//  https://github.com/AndreaLombardo/L298N
//
//
//
//***********************************************************************************************
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// #include "L298NX2.h"
#include "motor_driver.h"
DeviceDriverSet_Motor AppMotor;

#include "FluxGarage_RoboEyes.h"  // include after initializing display
roboEyes roboEyes; // create eyes



// #define EN_A 5
// #define IN1_A 7
// #define IN2_A 6

// #define IN1_B 9
// #define IN2_B 8
// #define EN_B 11


#define SERVO_PIN 11


// Initialize both motors
// L298NX2 myMotors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);


Servo HeadServo;

void setup() {

  // wdt_reset();
  // Increase PWM frequency for Timer 1 (pins 9 and 10)
  // TCCR1B = TCCR1B & 0b11111000 | 0x01; // Set Timer 1 to ~31kHz

  // Increase PWM frequency for Timer 2 (pins 3 and 11)
  // TCCR2B = TCCR2B & 0b11111000 | 0x01; // Set Timer 2 to ~31kHz


  Serial.begin(9600);


  AppMotor.DeviceDriverSet_Motor_Init();

  HeadServo.attach(SERVO_PIN);
  HeadServo.write(90);

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
} 


unsigned long next_trigger_1;
unsigned long next_trigger_2;

void loop() {
  // Handle commands from serial
  handleCmdJson();

  // Trigger random animations every 4s
  if (millis() > next_trigger_1) {
    next_trigger_1 = millis() + 3000 + random(0, 4) * 1000; // 3s-5s
    
    // change eye shape
    // roboEyes.anim_laugh();
    roboEyes.setMood(random(0, 2) * 3); // 0-Default, 1-Tired, 2-Angry, 3-Happy
    roboEyes.setCuriosity(random(0, 2));
  }

  // if (millis() > next_trigger_2) {
  //   next_trigger_2 = millis() + 2000 + random(0, 3) * 1000; // 2s-4s
  //   // change eye position

  //   roboEyes.eyeLxNext = random(roboEyes.getScreenConstraint_X());
  //   roboEyes.eyeLyNext = random(roboEyes.getScreenConstraint_Y());
  // }
  

  // Update robot eyes
  roboEyes.update();
  
  
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
  static String inputString = "";

  if (Serial.available()) {
    char incomingChar = Serial.read();

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



void handleCmd1(int selection, int speed, int direction) {

  // if (direction == 0) {
  //   if (selection != 2) {
  //     // Left Side
  //     // myMotors.setSpeedA(speed);
  //     // myMotors.forwardA();
  //     // AppMotor.DeviceDriverSet_Motor_control(true, speed, false, speed, true);

  //     lookLeft();
  //   } 
  //   if (selection != 1) {
  //     // Right Side
  //     // myMotors.setSpeedB(speed);
  //     // myMotors.forwardB();
  //     // AppMotor.DeviceDriverSet_Motor_control(false, speed, true, speed, true);

  //     lookRight();
  //   }
  // }
  // else {
  //   if (selection != 2) {
  //     // Left Side
  //     // myMotors.setSpeedA(speed);
  //     // myMotors.backwardA();

  //     lookLeft();
  //   } 
  //   if (selection != 1) {
  //     // Right Side
  //     // myMotors.setSpeedB(speed);
  //     // myMotors.backwardB();

  //     lookRight();
  //   }
  // }


  // TO DO:
  // IMPLEMENT THIS PROPERLY
  // RIGHT NOW ITS ONLY BEING USED FOR STOPPING THE MOTORS
  // SO THIS IS FINE
  if (selection == 0) {
    // all motors
    if (direction == 1) {
      // clockwise?
      AppMotor.DeviceDriverSet_Motor_control(true, speed, true, speed, true);
    }
    else {
      // counterclockwise?
      AppMotor.DeviceDriverSet_Motor_control(false, speed, false, speed, true);
    }
  }
  
  if (speed == 0) {lookIdle();}
  Serial.println("Handled CMD 1");
}

void handleCmd3(int direction, int speed) {

  // myMotors.setSpeed(speed);
  if (direction == 3) {
    // 3 - forward
    // myMotors.forward();
    AppMotor.DeviceDriverSet_Motor_control(true, speed, true, speed, true);

    lookStraight();
  }
  else if (direction == 4) {
    // 4 - backward
    // myMotors.backward();
    AppMotor.DeviceDriverSet_Motor_control(false, speed, false, speed, true);

    lookStraight();
  }
  else if (direction == 1) {
    // 1 - turn left
    // myMotors.backwardA();
    // myMotors.forwardB();
    AppMotor.DeviceDriverSet_Motor_control(true, speed, false, speed, true);

    lookLeft();
  }
  else if (direction == 2) {
    // 2 - turn right
    // myMotors.forwardA();
    // myMotors.backwardB();
    AppMotor.DeviceDriverSet_Motor_control(false, speed, true, speed, true);

    lookRight();
  }

  if (speed == 0) {lookIdle();}
  Serial.println("Handled CMD 3");
}

void handleCmd102(int direction, int speed) {

  // myMotors.setSpeed(speed);
  if (direction == 1) {
    // 1 - Forward
    // myMotors.setSpeed(speed);
    // myMotors.forward();
    AppMotor.DeviceDriverSet_Motor_control(true, speed, true, speed, true);

    lookStraight();
  }
  if (direction == 2) {
    // 2 - Backward
    // myMotors.setSpeed(speed);
    // myMotors.backward();
    AppMotor.DeviceDriverSet_Motor_control(false, speed, false, speed, true);

    lookStraight();
  }
  if (direction == 3) {
    // 3 - Turn Left
    // myMotors.setSpeed(speed);
    // myMotors.forwardA();
    // myMotors.backwardB();
    AppMotor.DeviceDriverSet_Motor_control(true, speed, false, speed, true);
    
    lookLeft();
  }
  if (direction == 4) {
    // 4 - Turn right
    // myMotors.setSpeed(speed);
    // myMotors.backwardA();
    // myMotors.forwardB();
    AppMotor.DeviceDriverSet_Motor_control(false, speed, true, speed, true);

    lookRight();
  }
  if (direction == 5) {
    // 5 - Left Forward
    // myMotors.setSpeedA(speed);
    // myMotors.setSpeedB(speed / 2);
    // myMotors.forward();
    AppMotor.DeviceDriverSet_Motor_control(true, speed, true, speed / 2, true);

    lookLeft();
  }
  if (direction == 6) {
    // 6 - Left Backward
    // myMotors.setSpeedA(speed);
    // myMotors.setSpeedB(speed / 2);
    // myMotors.backward();
    AppMotor.DeviceDriverSet_Motor_control(false, speed, false, speed / 2, true);

    lookLeft();
  }
  if (direction == 7) {
    // 7 - Right Forward
    // myMotors.setSpeedA(speed / 2);
    // myMotors.setSpeedB(speed);
    // myMotors.forward();
    AppMotor.DeviceDriverSet_Motor_control(true, speed / 2, true, speed, true);

    lookRight();
  }
  if (direction == 8) {
    // 8 - Right Backward
    // myMotors.setSpeedA(speed / 2);
    // myMotors.setSpeedB(speed);
    // myMotors.backward();
    AppMotor.DeviceDriverSet_Motor_control(false, speed / 2, false, speed, true);

    lookRight();
  }
  
  if (speed == 0) {lookIdle();}
  Serial.println("Handled CMD 102");
}



void lookStraight() {
  roboEyes.idleAnimationTimer = -1; // hold idle animation
  roboEyes.setPosition('X');
  HeadServo.write(90);
}
void lookLeft() {
  roboEyes.idleAnimationTimer = -1; // hold idle animation
  roboEyes.setPosition(W);
  HeadServo.write(150);
}
void lookRight() {
  roboEyes.idleAnimationTimer = -1; // hold idle animation
  roboEyes.setPosition(E);
  HeadServo.write(30);
}
void lookIdle() {
  // continue idle animation
  roboEyes.idleAnimationTimer = 0;  // resume idle animation
  HeadServo.write(90);
}