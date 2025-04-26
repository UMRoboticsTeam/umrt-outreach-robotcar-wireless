#ifndef ROBOT_EYES_H
#define ROBOT_EYES_H

#include <SPI.h>
#include <U8g2lib.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


//be sure to initialize with your display.  see https://github.com/olikraus/u8g2/wiki/setup_tutorial 
// U8G2_SH1106_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 8, /* reset=*/ 9);

extern int COLOR_WHITE;
extern int COLOR_BLACK;


// states for demo 
extern int demo_mode;
extern const int max_animation_index;
extern int current_animation_index;

//reference state
extern int ref_eye_height;
extern int ref_eye_width;
extern int ref_space_between_eye;
extern int ref_corner_radius;
//current state of the eyes
extern int left_eye_height;
extern int left_eye_width;
extern int left_eye_x;
extern int left_eye_y;
extern int right_eye_x;
extern int right_eye_y;
extern int right_eye_height;
extern int right_eye_width;
extern int corner_radius;


// extern U8G2_SH1106_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 8, /* reset=*/ 9);
extern U8G2_SH1106_128X64_NONAME_F_4W_HW_SPI u8g2;


void display_clearDisplay();
void display_fillRoundRect(int x,int y,int w, int h, int r, int color);
void display_display();
void display_fillTriangle(int x0,int y0, int x1,int y1,int x2,int y2, int color);
void draw_eyes(bool update=true);
void reset_eyes(bool update=true);
void blink(int speed=12);
void sleep();
void wakeup();
void happy_eye();
void saccade(int direction_x, int direction_y);
void move_right_big_eye();
void move_left_big_eye();
void move_big_eye(int direction);




#endif