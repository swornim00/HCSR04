/*

Wrriten By Swornim Shrestha
Monday November 12, 2016
1:52 PM Nepal
Email:srestaswrnm@gmail.com


*/

#ifndef H_HCSR04
#define H_HCSR04

class UltraSonic{
private:
  int echo,trig;

public:
  UltraSonic(int,int);
  int getMicroseconds();
  int getCentimeters();
  int getInces();
  void SerialPrint(char);
};


#endif
