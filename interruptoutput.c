#include<wiringPi.h>   

const int LEDpin = 1;

int main()
{
      if(-1==wiringPiSetup())
      {
      }
      pinMode(LEDpin,OUTPUT);      


      {
	        digitalWrite(LEDpin,LOW);
                digitalWrite(LEDpin,HIGH); 
                digitalWrite(LEDpin,LOW);
   
      }
        
      return 0;   
}
