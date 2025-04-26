// https://github.com/intellar/oled_eye_display
// https://github.com/intellar/oled_eye_display/blob/main/arduino/control_display_u8g2/control_display_u8g2.ino



// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes?tab=readme-ov-file
// https://github.com/FluxGarage/RoboEyes

#include "robot-eyes.h"
#include <SPI.h>
// #include <U8g2lib.h>

void setup() {
  // put your setup code here, to run once:
  u8g2.setI2CAddress(0x78);
  u8g2.setDisplayRotation(U8G2_R0);
  u8g2.begin();

  sleep();
  u8g2.setFont(u8g2_font_ncenB10_tr);
  
  u8g2.drawStr(0,10,"intellar.ca");
  
  display_display();
  delay(3000);
  
}



void launch_animation_with_index(int animation_index)
{

  

  if(animation_index>max_animation_index)
  {
    animation_index=8;
  }

  switch(animation_index)
      {
        case 0:
          wakeup();
          break;
        case 1:
          reset_eyes(true);
          break;
        case 2:
          move_right_big_eye();
          break;
        case 3:
          move_left_big_eye();
          break;
        case 4:      
          blink(12);
          delay(1000);
          break;
        case 5:
          blink(12);
          break;
        case 6:
          happy_eye();      
          break;
        case 7:
          sleep();
          break;
        case 8:
          break;
          reset_eyes(true);
          for(int i=0;i<20;i++)
          { 
            int dir_x = random(-1, 2);
            int dir_y = random(-1, 2);
            saccade(dir_x,dir_y);
            delay(1);
            saccade(-dir_x,-dir_y);
            delay(1);     
          }
          break;
          
      }
}



void loop() {

  if(demo_mode == 1)
  {
    // cycle animations
    launch_animation_with_index(current_animation_index++);
    if(current_animation_index > max_animation_index)
    {
      current_animation_index = 0;
    }
  }

  
  //send "Ax" for animation x  (ex. A2 will launch animation 2)
  if(Serial.available()) {
    String data = Serial.readString();
    data.trim();
    char cmd = data[0];
    
    if(cmd == 'A')
    {
      demo_mode = 0;

      String arg = data.substring(1,data.length());
      int anim = arg.toInt();
      launch_animation_with_index(anim);
      Serial.print(cmd);
      Serial.print(arg);   
    }
  }


}
