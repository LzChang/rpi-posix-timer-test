#include <wiringPi.h>
#define pwm_pin 1    //定义PWM引脚 GPIO.1
int main (void)
{
    wiringPiSetup ();               // wiringPi库初始化
    pwmSetMode(PWM_MODE_MS);
    pinMode (pwm_pin, PWM_OUTPUT);   // 设置GPIO.1为PWM输出    
    pwmSetClock(235);
    int val =10;
    while(1)
    {
      pwmWrite(pwm_pin,val); // 输出占空比为val/1024的pwm波
  }
  return 0 ;
}
