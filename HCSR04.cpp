/*

The MIT License (MIT)

Copyright (c) 2016 Swornim Shrestha

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Written By Swornim Shrestha
Monday November 12, 2016
1:52 PM Nepal
Email:srestaswrnm@gmail.com


*/
#include<Arduino.h>
#include<HCSR04.h>

/*

  Constructor. Accepts two parameters pin number connected to the echo pin and trigger pin of HCSR04 UltraSonic Sensor.

*/
UltraSonic::UltraSonic(int _echo,int _trig){
  trig = _trig;
  echo = _echo;
}

int UltraSonic::getMicroseconds(){
  /*

    Here at first to trigger the sensor on, atleast 10us high level pulse should be sent to
    trigger pin. Then as the sensor is triggered then we can listen with pin echo.

  */

  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10); //10 Microseconds delay to trigger the sensor.
  digitalWrite(trig,LOW);

  int _ms = pulseIn(echo,HIGH);
  return _ms;

}

//Get Centimeters
int UltraSonic::getCentimeters(){
  int _ms = UltraSonic::getMicroseconds();
  int _cm = _ms / 29 / 2;
  return _cm; //Calculated.
}

//Get Distance in inches
int UltraSonic::getInces(){
  int _ms = UltraSonic::getMicroseconds();
  int _in = _ms / 72 / 2;
  return _in;
}

/*

  To Serial print the Distance. Usage:

  us.SerialPrint(CM/MS/IN)
  CM: Centimeters
  IN: Inches
  MS: Microseconds

  
*/
void SerialPrint(char mode){
  switch(mode){
    MS:
    _val = UltraSonic::getMicroseconds();

    CM:
    _val = UltraSonic::getCentimeters();

    IN:
    _val = UltraSonic::getInces();
  }

  Serial.println(_val);
}
