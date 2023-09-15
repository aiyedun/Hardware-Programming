#include<SoftwareSerial.h> // For serial communication
SoftwareSerial myHome(3, 2); //2=Rx on arduino board:3=Tx on arduino board
int Fan = 5;
int Light = 6;
int Tv = 7;
int Led=8;
String incomingData=""; //for storing incoming serial data
String message = "";   //for storing the message


void setup() {
  
  Serial.begin(9600); // baudrate for serial monitor
  myHome.begin(9600); // baudrate for GSM module
  Serial.println("Initializing..."); 
  myHome.println("AT"); //Once the connection is successful, it will back to OK
  updateSerial();
  delay(1000);
  pinMode(Fan, OUTPUT);
  pinMode(Light, OUTPUT);
  pinMode(Tv, OUTPUT);
  pinMode(Led, OUTPUT);
  myHome.println("AT+CMGF=1\r"); // set SMS mode to myHome mode
  updateSerial();
  delay(500);
  myHome.println("AT+CNMI=2,2,0,0,0\r");// set gsm module to tp show the output on serial out 
  updateSerial();
  delay(500);
  digitalWrite(Fan, HIGH);
  digitalWrite(Light, HIGH);
  digitalWrite(Tv, HIGH);
  digitalWrite(Led, HIGH);
  delay(1000);
  digitalWrite(Light, LOW);
  digitalWrite(Fan, LOW);
  digitalWrite(Tv, LOW);    
  digitalWrite(Led, LOW);
  
  // put your setup code here, to run once:

}

void loop() {
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
   
  }                
}
  // put your main code here, to run repeatedly:


void receive_message()
{
  if (myHome.available() > 0)
  {
    Signal();
    incomingData = myHome.readString(); // Get the data from the serial port.
    Serial.print(incomingData); 
    updateSerial();
    delay(500); 
  }
}
void send_message(String message) //Communicate with the owner of the house 
{
  myHome.println("AT+CMGF=1");    //Set the GSM Module To myHome Mode
  updateSerial();
  delay(200);  
  myHome.println("AT+CMGS=\"+2348105295597\""); //mobile number of the home owner
  updateSerial();
  delay(200);
  myHome.println(message);   // The SMS to be sent to myHome owner
  updateSerial();
  delay(200);
  Signal();
  myHome.println((char)30);  // ASCII code of CTRL+Z
  updateSerial();
  delay(200);
  myHome.println();
  updateSerial();
  delay(1000);  
}
void Signal()
{
  digitalWrite(Led, HIGH);
  delay(1000);
  digitalWrite(Led, LOW);
}
void updateSerial()
{  
  delay(500);
  while (Serial.available()) 
  {
    myHome.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(myHome.available()) 
  {
    Serial.write(myHome.read());//Forward what Software Serial received to Serial Port
  }
}
