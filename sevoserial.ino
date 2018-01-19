// Controlling a servo position using Serial Port
// by Juan Andrés Viera M   andresviera1@hotmail.com

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
int val,num;    // variable to read the value from the analog pin 
 
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  while(Serial.available()==0)
  {
    val=0;
  }
  while(Serial.available()>0)
  { 
    num=Serial.read();
    num=num-48;
    val=val*10;
    val=val+num;
    delay(100);
    }
  Serial.println(val);
   myservo.write(val);                  // sets the servo position according to the scaled value 
  delay(15);

                           // waits for the servo to get there 
} 
