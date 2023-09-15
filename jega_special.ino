#include <SoftwareSerial.h>
SoftwareSerial nodemcu(2,3);
 
long int data; 
int firstVal, secondVal,thirdVal;
 
 
String myString; // complete message from arduino, which consistors of snesors data
char rdata; // received charactors
String cdata; // complete data
 
// for L298N motor driver
int ena = 5; 
int enb = 6; 
int pre=13;
int in1 = 8; 
int in2 = 9; 
int in3 = 10; 
int in4 = 11;
const int pingPin2 = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin2 = 4; // Echo Pin of Ultrasonic Sensor 
const int pingPin1 = A0; // Trigger Pin of Ultrasonic Sensor
const int echoPin1 = A2; // Echo Pin of Ultrasonic Sensor
boolean autom = false;
long duration1, inches1, cm1;
long duration2, inches2, cm2;
//int ena = 5; 
//int enb = 6; 
// 
//int in1 = 8; 
//int in2 = 9; 
//int in3 = 10; 
//int in4 = 11;
 
 
void setup()
{
Serial.begin(9600); 
nodemcu.begin(9600);

pinMode(ena, OUTPUT); 
  pinMode(enb, OUTPUT); 
  pinMode(pre, INPUT_PULLUP);
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
// pinMode(ena, OUTPUT); 
//  pinMode(enb, OUTPUT); 
// 
//  pinMode(in1, OUTPUT); 
//  pinMode(in2, OUTPUT);
//  pinMode(in3, OUTPUT);
//  pinMode(in4, OUTPUT);

 analogWrite(ena, 0); 
 analogWrite(enb, 0);
 
}
 
void loop()
{
  if(digitalRead(pre)==LOW){

    autom=!autom;
    delay(1000);
    Serial.println("pressed");
  }

if(autom){
pinMode(pingPin2, OUTPUT);
digitalWrite(pingPin2, LOW);
delayMicroseconds(2);
digitalWrite(pingPin2, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin2, LOW);
pinMode(echoPin2, INPUT);
duration2 = pulseIn(echoPin2, HIGH);
inches2 = microsecondsToInches(duration2);
cm2 = microsecondsToCentimeters(duration2);
Serial.print(inches2);
Serial.print("in, ");
Serial.print(cm2);
Serial.print("cm");
Serial.println();
delay(20);

pinMode(pingPin1, OUTPUT);
digitalWrite(pingPin1, LOW);
delayMicroseconds(2);
digitalWrite(pingPin1, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin1, LOW);
pinMode(echoPin1, INPUT);
duration1 = pulseIn(echoPin1, HIGH);
inches1 = microsecondsToInches(duration1);
cm1 = microsecondsToCentimeters(duration1);
Serial.print(inches1);
Serial.print("in1, ");
Serial.print(cm1);
Serial.print("cm1");
Serial.println();


delay(20);
  if((cm2<80)||(cm1<40)){
  //if(cm1<40){
  rt();  
 
  }

if((cm2>80)&&(cm1>40)){
    Serial.println("forward");
    fw();
  }
}
else{

                digitalWrite(ena,0);
                digitalWrite(enb,0);
                digitalWrite(in1,0);
                digitalWrite(in2, 0); 
                digitalWrite(in3,0); 
                digitalWrite(in4,0); 
                delay(1000);

  
}


   
if(nodemcu.available() == 0 )
{
 
   delay(100); // 100 milli seconds
 
}
 
if ( nodemcu.available() > 0 ) 
{
 
      rdata = nodemcu.read(); 
    myString = myString+ rdata; 
    //Serial.print(rdata);
    if( rdata == '\n')
    {
Serial.println(myString);
// new code
String l = getValue(myString, ',', 0);
String m = getValue(myString, ',', 1);
String n = getValue(myString, ',', 2); 
 
 
firstVal = l.toInt(); // for left and right
secondVal = m.toInt(); // forward and reverse
thirdVal = n.toInt(); // speed
 
  myString = "";
 
 
            if ( (firstVal == 2) && (secondVal == 2) ) // for joystic normal position
            {
                analogWrite(ena,0);
                analogWrite(enb,0);
                digitalWrite(in1,LOW);
                digitalWrite(in2,LOW); 
                digitalWrite(in3,LOW); 
                digitalWrite(in3,LOW);
                
            } else
            
            if ( (firstVal == 2) && (secondVal > 3) ) // Forward direction
            {
                analogWrite(ena,thirdVal);
                analogWrite(enb,thirdVal);
                  digitalWrite(in1,HIGH);
                  digitalWrite(in2, LOW); 
                  digitalWrite(in3,LOW); 
                  digitalWrite(in4,HIGH); 
            }else
 
            if ( (firstVal == 2) && (secondVal < 1) ) // reverse direction
            {
                analogWrite(ena,thirdVal);
                analogWrite(enb,thirdVal);
                digitalWrite(in1,LOW);
                digitalWrite(in2, HIGH); 
                digitalWrite(in3,HIGH); 
                digitalWrite(in4,LOW); 
            }else
 
           if ( (firstVal > 3) && (secondVal == 2) ) // Right
            {
                analogWrite(ena,thirdVal);
                analogWrite(enb,thirdVal);
                digitalWrite(in1,HIGH);
                digitalWrite(in2, LOW); 
                digitalWrite(in3,HIGH); 
                digitalWrite(in4,LOW); 
            } else
 
            
           if ( (firstVal < 1) && (secondVal == 2) ) // left
            {
                analogWrite(ena,thirdVal);
                analogWrite(enb,thirdVal);
                digitalWrite(in1,LOW);
                digitalWrite(in2, HIGH); 
                digitalWrite(in3,LOW); 
                digitalWrite(in4,HIGH); 
            }
    }
  
}
 
}
 
 
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
 
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
long microsecondsToInches(long microseconds)
{
return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}

void fw(){
                  analogWrite(ena,255);
                  analogWrite(enb,255);
                  digitalWrite(in1,HIGH);
                  digitalWrite(in2, LOW); 
                  digitalWrite(in3,LOW); 
                  digitalWrite(in4,HIGH); 
  
}

void lf(){
                analogWrite(ena,255);
                analogWrite(enb,255);
                digitalWrite(in1,LOW);
                digitalWrite(in2, HIGH); 
                digitalWrite(in3,LOW); 
                digitalWrite(in4,HIGH); 
                delay(2000);
  
}
void rt(){

                analogWrite(ena,0);
                analogWrite(enb,0);
                digitalWrite(in1,0);
                digitalWrite(in2, 0); 
                digitalWrite(in3,0); 
                digitalWrite(in4,0); 
                delay(1000);

               analogWrite(ena,180);
                analogWrite(enb,180);
                digitalWrite(in1,LOW);
                digitalWrite(in2, HIGH); 
                digitalWrite(in3,HIGH); 
                digitalWrite(in4,LOW); 
 
                analogWrite(ena,255);
                analogWrite(enb,255);
                digitalWrite(in1,HIGH);
                digitalWrite(in2, LOW); 
                digitalWrite(in3,HIGH); 
                digitalWrite(in4,LOW); 
                delay(200);
                 analogWrite(ena,0);
                analogWrite(enb,0);
                digitalWrite(in1,0);
                digitalWrite(in2, 0); 
                digitalWrite(in3,0); 
                digitalWrite(in4,0); 
                delay(1000);
}

void bk(){
                analogWrite(ena,180);
                analogWrite(enb,180);
                digitalWrite(in1,LOW);
                digitalWrite(in2, HIGH); 
                digitalWrite(in3,HIGH); 
                digitalWrite(in4,LOW); 
  
}
