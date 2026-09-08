#include <Arduino.h>

/*Motor*/
class DeviceDriverSet_Motor
{
public:
  void DeviceDriverSet_Motor_Init(void);
#if _Test_DeviceDriverSet
  void DeviceDriverSet_Motor_Test(void);
#endif
  void DeviceDriverSet_Motor_control(boolean direction_A, uint8_t speed_A, //Group A motor parameters
                                     boolean direction_B, uint8_t speed_B, //Group B motor parameters
                                     boolean controlED                     //AB enable setting (true)
  );                                                                       //motor control
private:
  // #define PIN_Motor_PWMA 5
  // #define PIN_Motor_PWMB 6
  // #define PIN_Motor_STBY 8
  // #define PIN_Motor_BIN_1 7
  // #define PIN_Motor_AIN_1 9
//TB6612
#define PIN_Motor_PWMA 5
#define PIN_Motor_PWMB 6
#define PIN_Motor_BIN_1 8
#define PIN_Motor_AIN_1 7
#define PIN_Motor_STBY 3
public:
#define speed_Max 255
#define direction_just true
#define direction_back false
#define direction_void 3

#define Duration_enable true
#define Duration_disable false
#define control_enable true
#define control_disable false
};