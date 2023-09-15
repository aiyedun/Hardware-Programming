#include<SoftwareSerial.h>
SoftwareSerial agrobot(2, 3); 
int tyreLF1 = 4; //Left front tyre :IN1
int tyreLF2 = 5; //Left back tyre  :IN2
int tyreRF1 = 6; //Right back tyre :IN3
int tyreRF2 = 7; //right front tyre:IN4
int size_increase = 8; // Increase in agrobot size
int size_decrease = 9; // Decrease in agrobot size
int Blade = 11;  //Blade
int B_motor_up = 12; //Blade motor controller
int B_motor_down = 13; //Blade motor controller
char bot;


void setup()
{
  pinMode(tyreLF1, OUTPUT); //set to IN1
  pinMode(tyreLF2, OUTPUT); //set to IN2
  pinMode(tyreRF1, OUTPUT); //set to IN3
  pinMode(tyreRF2, OUTPUT); //set to IN4
  pinMode(size_increase, OUTPUT);
  pinMode(size_decrease, OUTPUT);
  pinMode(Blade, OUTPUT);
  pinMode(B_motor_up, OUTPUT);
  pinMode(B_motor_down, OUTPUT);


  Serial.begin(9600);
  agrobot.begin(9600);
  digitalWrite(tyreLF1, HIGH);
    digitalWrite(tyreLF2, HIGH);
    digitalWrite(tyreRF1, HIGH);
    digitalWrite(tyreRF2, HIGH);
    digitalWrite(Blade, HIGH);
}


void loop()
{
    
  if (agrobot.available() > 0)
  {
    bot = agrobot.read();
  }

// agrobot motion

  if ( bot == 'F')     //Forward
  {
    digitalWrite(tyreLF1, HIGH);
    digitalWrite(tyreLF2, LOW);
    digitalWrite(tyreRF1, HIGH);
    digitalWrite(tyreRF2, LOW);
  }
  if ( bot == 'R')     //Reverse
  {
    digitalWrite(tyreLF1, LOW);
    digitalWrite(tyreLF2, HIGH);
    digitalWrite(tyreRF1, LOW);
    digitalWrite(tyreRF2, HIGH);
  }
  
  else if (bot == 'r') // Right
  {
    digitalWrite(tyreLF1, HIGH);
    digitalWrite(tyreLF2, LOW);
    digitalWrite(tyreRF1, LOW);
    digitalWrite(tyreRF2, HIGH);
  }
  else if (bot == 'l') //Left
  {
    digitalWrite(tyreLF1, LOW);
    digitalWrite(tyreLF2, HIGH);
    digitalWrite(tyreRF1, HIGH);
    digitalWrite(tyreRF2, LOW);
  }
  else if (bot == 'B') //Break
  {

    digitalWrite(tyreLF1, LOW);
    digitalWrite(tyreLF2, LOW);
    digitalWrite(tyreRF1, LOW);
    digitalWrite(tyreRF2, LOW);
  }

// agrobot size

  else if (bot == 'I') //Increase in size
  {
    digitalWrite(size_increase, HIGH);
    digitalWrite(size_decrease, LOW);
  }
  else if (bot == 'D') //Decrease in size
  {
    digitalWrite(size_increase, LOW);
    digitalWrite(size_decrease, HIGH);
  }
  else if (bot == 'd') // Stop increasing and Decreasing in size
  {
    digitalWrite(size_increase, LOW);
    digitalWrite(size_decrease, LOW);
  }

// cutting of the grass

  else if (bot == 'C') //Cutting Start
  {
    digitalWrite(Blade, LOW);
  }
  else if (bot == 'c') //Cutting Stop
  {
    digitalWrite(Blade, HIGH);
  }

// Raising the blade up  

  else if (bot == 'U') //Blade Raised up
  {
    digitalWrite(B_motor_up, HIGH);
    digitalWrite(B_motor_down, LOW);
  }
  else if (bot == 'u') //Blade lowered down
  {
    digitalWrite(B_motor_up, LOW);
    digitalWrite(B_motor_down, HIGH);
  }
  else if (bot == 's') //Blade to stop
  {
    digitalWrite(B_motor_up, LOW);
    digitalWrite(B_motor_down, LOW);
  }
}
