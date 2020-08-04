#include<NewPing.h> ///Library for ultrasonic sensor
#include<StopWatch.h>  ///Library to start the timers and store values
StopWatch timer1;      ///Constructor for stopwatch library
StopWatch timer2;
StopWatch timer3;
 
#define trig1 11      ///pin defined for sensor1
#define echo1 10      ///pin defined for sensor1
#define trig2 9       ///pin defined for sensor2
#define echo2 6       ///pin defined for sensor2
#define MAX_DISTANCE 370  ///maximum distance for which you want the sensor to sense.
NewPing sonar1(trig1, echo1, MAX_DISTANCE);  ///sensor 1 gets activated and start sensing
NewPing sonar2(trig2, echo2, MAX_DISTANCE);  ///////sensor 1 gets actiuvated and start sensing
int sensor_1 = 0;
int sensor_2 = 0;
int count = 0;
int flag1;
int flag2;
long int t1;
long int t2;
long int t3;
int entry = 0;
int Exit = 0;
long duration1, distance1;
long duration2, distance2;
 
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop() 
{
 
  delay(50);// Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS1 = sonar1.ping(); // Send ping, get ping time in microseconds (uS).
  distance1 = sonar1.convert_cm(uS1);
 
  if (distance1 > 4) 
  {
    timer1.start();  ///timer started
  }
  if (distance1 == 0) 
  {
    
    if (timer1.isRunning())
    {
        Serial.print("millis() : ");
        Serial.print(millis());
        Serial.print(", stopwatch : ");
        Serial.println(timer1.ms());
        t1=timer1.ms();
    }
    timer1.stop();   ///timer stoped
  }
  unsigned int uS2 = sonar2.ping(); // Send ping, get ping time in microseconds (uS).
 
  distance2 = sonar2.convert_cm(uS2);
 
  if (distance2 > 4) 
  {
    timer2.start();   ///timer started
  }
  if (distance2 == 0) 
  {
 
    
   if (timer2.isRunning())
    {
        Serial.print("millis() : ");
        Serial.print(millis());
        Serial.print(", stopwatch : ");
        Serial.println(timer2.ms());
        t2=timer2.ms();
    }
    timer2.stop();    ///timer stoped
  }
  if ((distance1 > 4) && (distance2 > 4)) 
  {
    timer3.start();   ///timer started
  }
  if ((distance1 == 0) && (distance2 == 0)) 
  {
    if (timer3.isRunning())
    {
        Serial.print("millis() : ");
        Serial.print(millis());
        Serial.print(", stopwatch : ");
        Serial.println(timer3.ms());
        t3=timer3.ms();
    }
    timer3.stop();    ///timer stoped
    if (t3 > 0 && t1 > 0 && t2 > 0 ) 
    {
      if ((t1 >= t3) && (t3 >= t2)) 
      {
        entry++;   ////Entry Incremented
        Serial.println(entry);
        entry=entry;   ////Entry updated
      }
      else if ((t1 > t2) && (t2 > t3) && (t3 > 650)) 
      {
        entry++;     ///entry incremented
        Serial.println(entry);  
        entry = entry;   ///entry updated
      }
      timer1.restart();   ///reset timers to use again from zero value.
      timer2.restart();
      timer3.restart();
    }
  }
}
