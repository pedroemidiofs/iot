#include <SoftwareSerial.h>// import the serial library

SoftwareSerial BT(2, 3); // RX, TX
int BluetoothData; // the data given from Computer

void setup() 
{
  // put your setup code here, to run once:
  BT.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (BT.available())
  {
    BluetoothData=BT.read();
    if(BluetoothData=='F')
    {   
      forward();
    }
    if(BluetoothData=='B')
    {   
      backward();
    }
    if(BluetoothData=='R')
    {   
      right();
    }
    if(BluetoothData=='L')
    {   
      left();
    }
    if(BluetoothData=='S')
    {   
      stop();
    }
  }
delay(100);// prepare for next data ...
}

void forward(){
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(9,1);
  digitalWrite(10,0);
}

void backward(){
  digitalWrite(5,0);
  digitalWrite(6,1);
  digitalWrite(9,0);
  digitalWrite(10,1);
}

void right(){
  digitalWrite(5,0);
  digitalWrite(6,1);
  digitalWrite(9,1);
  digitalWrite(10,0);
}

void left(){
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(9,0);
  digitalWrite(10,1);
}

void stop(){
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(9,0);
  digitalWrite(10,0);
}



