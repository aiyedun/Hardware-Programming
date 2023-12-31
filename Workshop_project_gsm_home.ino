#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 2);
int Fan = 8;
int Light = 9;
int Tv = 10;
int Decoder=11;
int Sign=12;
String incomingData=""; //for storing incoming serial data
String message = "";   //for storing the message

void updateSerial()
{
  delay(500);
  while (Serial.available())
  {
    mySerial.write(Serial.read());
  }
  while (mySerial.available())
  {
    Serial.write(mySerial.read());
  }
}
void receive_message()
{
  if (mySerial.available() > 0)
  {
    Signal();
    incomingData = mySerial.readString(); // Get the data from the serial port.
    Serial.print(incomingData); 
    delay(500); 
  }
}
void send_message(String message) //Communicate with the owner of the house 
{
  mySerial.println("AT+CMGF=1");    //Set the GSM Module To mySerial Mode
  delay(200);  
  mySerial.println("AT+CMGS=\"+2348105295597\""); //mobile number of the home owner
  delay(200);
  mySerial.println(message);   // The SMS to be sent to mySerial owner
  delay(200);
  Signal();
  mySerial.println((char)30);  // ASCII code of CTRL+Z
  delay(200);
  mySerial.println();
  delay(1000);  
}
void Signal()
{
  digitalWrite(Sign, HIGH);
  delay(1000);
  digitalWrite(Sign, LOW);
}
void setup()
{
  pinMode(Fan, OUTPUT);
  pinMode(Light, OUTPUT);
  pinMode(Tv, OUTPUT);
  pinMode(Decoder, OUTPUT);
  pinMode(Sign, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("Initializing...");
  delay(1000);
  mySerial.println("AT");
  updateSerial();
  mySerial.println("ATD+2348105295597;");
  updateSerial();
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CNMI=2,2,0,0,0\r");// set gsm module to tp show the output on serial out 
  delay(500);
  updateSerial();
 // mySerial.print("INA TI DE                                                        "); //text content
  updateSerial();
  mySerial.write(26);
  digitalWrite(Fan, HIGH);
  digitalWrite(Light, HIGH);
  digitalWrite(Tv, HIGH);
  digitalWrite(Decoder, HIGH);
  digitalWrite(Sign, HIGH);
  delay(1000);
  digitalWrite(Light, LOW);
  digitalWrite(Fan, LOW);
  digitalWrite(Tv, LOW);
  digitalWrite(Decoder, LOW);
  digitalWrite(Sign, LOW);
  delay(1000);
  digitalWrite(Fan, HIGH);
  digitalWrite(Light, HIGH);
  digitalWrite(Tv, HIGH);
  digitalWrite(Decoder, HIGH);
  digitalWrite(Sign, HIGH);
  delay(1000);
  digitalWrite(Light, LOW);
  digitalWrite(Fan, LOW);
  digitalWrite(Tv, LOW);
  digitalWrite(Decoder, LOW);
  digitalWrite(Sign, LOW);
}

void loop()
{
   receive_message(); //Function for receiving sms
 
  if(incomingData.indexOf("Fan_on")>=0)// if received command is to turn on fan
  {
    
    digitalWrite(Fan, HIGH);
    message = "Fan is turned ON";
    send_message(message);// Send a sms back to confirm that the fan is turned on
  
  }
  
  if(incomingData.indexOf("Fan_off")>=0)// if received command is to turn off fan
  {
    
    digitalWrite(Fan, LOW);
    message = "Fan is turned OFF";
    send_message(message);// Send a sms back to confirm that the fan is turned off
   
  }  

        
  receive_message(); //Function for receiving sms
  
  if(incomingData.indexOf("Light_on")>=0)// if received command is to turn on Light
  {
   
    digitalWrite(Light, HIGH);
    message = "Light is turned ON";
    send_message(message);// Send a sms back to confirm that the Light is turned on
    
  }
  
  if(incomingData.indexOf("Light_off")>=0)// if received command is to turn off Light
  {
   
    digitalWrite(Light, LOW);
    message = "Light is turned OFF";
    send_message(message);// Send a sms back to confirm that the Light is turned off
   
  }

  receive_message(); //Function for receiving sms
  
  if(incomingData.indexOf("Tv_on")>=0)// if received command is to turn on Tv
  {
    digitalWrite(Tv, HIGH);
    message = "Tv is turned ON";
    send_message(message);// Send a sms back to confirm that the Tv is turned on
   
  }
  
  if(incomingData.indexOf("Tv_off")>=0)// if received command is to turn off Tv
  {
    digitalWrite(Tv, LOW);
    message = "Tv is turned OFF";
    send_message(message);// Send a sms back to confirm that the Tv is turned off

    receive_message(); //Function for receiving sms
  
  if(incomingData.indexOf("Decoder_on")>=0)// if received command is to turn on Decoder
  {
    digitalWrite(Decoder, HIGH);
    message = "Decoder is turned ON";
    send_message(message);// Send a sms back to confirm that the Decoder is turned on
   
  }
  
  if(incomingData.indexOf("Decoder_off")>=0)// if received command is to turn off Decoder
  {
    digitalWrite(Decoder, LOW);
    message = "Decoder is turned OFF";
    send_message(message);// Send a sms back to confirm that the Decoder is turned off

   receive_message(); //Function for receiving sms
  
  if(incomingData.indexOf("All_on")>=0)// if received command is to turn on All
  {
     digitalWrite(Fan, HIGH);
     digitalWrite(Light, HIGH);
     digitalWrite(Tv, HIGH);
     digitalWrite(Decoder, HIGH);
    message = "All is turned ON";
    send_message(message);// Send a sms back to confirm that the All is turned on
   
  }
  
  if(incomingData.indexOf("All_off")>=0)// if received command is to turn off All
  {
    digitalWrite(Light, LOW);
    digitalWrite(Fan, LOW);
    digitalWrite(Tv, LOW);
    digitalWrite(Decoder, LOW);
    message = "All is turned OFF";
    send_message(message);// Send a sms back to confirm that the All is turned off
   
  }                
}
  // put your main code here, to run repeatedly:


}}
