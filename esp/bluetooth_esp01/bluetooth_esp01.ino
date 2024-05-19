#include <SoftwareSerial.h>// import the serial library

SoftwareSerial BT(2, 3); // RX, TX
int BluetoothData; // the data given from Computer

void setup() 
{
  // put your setup code here, to run once:
  BT.begin(9600);
  pinMode(5,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (BT.available())
  {
    BluetoothData=BT.read();
    if(BluetoothData=='1')
    {   
      digitalWrite(5,1);
    }
    if(BluetoothData=='0')
    {   
      digitalWrite(5,0);
    }
delay(100);// prepare for next data ...
  }
}
