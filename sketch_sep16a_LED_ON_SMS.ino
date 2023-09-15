#include <SoftwareSerial.h> // Library for using serial communication
SoftwareSerial mySerial(3, 2);

String incomingData;   // for storing incoming serial data
String message = "";   // A String for storing the message
int led = 12;    // Initialized a pin for led

void setup()
{
  Serial.begin(9600); // baudrate for serial monitor
  mySerial.begin(9600); // baudrate for GSM shield
  Serial.println("Initializing..."); 
  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  delay(1000);
  
  pinMode(led, OUTPUT);   // Setting led pin as output pin
  digitalWrite(led, HIGH);  // Making led pin initailly low
  delay(1000);
  digitalWrite(led, LOW);
  // set SMS mode to temySerialt mode
  mySerial.print("AT+CMGF=1\r");  
  delay(100);
  
  // set gsm module to tp show the output on serial out
  mySerial.print("AT+CNMI=2,2,0,0,0\r"); 
  delay(100);
}

void loop()
{
  //Function for receiving sms
  receive_message();

  // if received command is to turn on led
  if(incomingData.indexOf("Led_on")>=0)
  {
    digitalWrite(led, HIGH);
    message = "Led is turned ON";
    // Send a sms back to confirm that the led is turned on
    send_message(message);
  }
  
  // if received command is to turn off led
  if(incomingData.indexOf("Led_off")>=0)
  {
    digitalWrite(led, LOW);
    message = "Led is turned OFF";
    // Send a sms back to confirm that the led is turned off
    send_message(message);
  }        
}

void receive_message()
{
  if (mySerial.available() > 0)
  {
    incomingData = mySerial.readString(); // Get the data from the serial port.
    Serial.print(incomingData); 
    delay(10); 
  }
}

void send_message(String message)
{
  mySerial.println("AT+CMGF=1");    //Set the GSM Module in TemySerialt Mode
  delay(100);  
  mySerial.println("AT+CMGS=\"+2348105295597\""); // Replace it with your mobile number
  delay(100);
  mySerial.println(message);   // The SMS temySerialt you want to send
  delay(100);
  mySerial.println((char)26);  // ASCII code of CTRL+Z
  delay(100);
  mySerial.println();
  delay(1000);  
}
