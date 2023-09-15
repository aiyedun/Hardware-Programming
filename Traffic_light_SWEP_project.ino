int lightR1 =2; 
int lightR2 =5;
int lightY1 =3;
int lightY2 =6;
int lightG1 =4;
int lightG2 =7;
void setup() {
  pinMode(lightR1,OUTPUT);
  pinMode(lightR2,OUTPUT);
  pinMode(lightY1,OUTPUT);
  pinMode(lightY2,OUTPUT);
  pinMode(lightG1,OUTPUT);
  pinMode(lightG2,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(lightR1,HIGH);
  digitalWrite(lightG2,HIGH);
  delay(45000);
  digitalWrite(lightR1,LOW);
  digitalWrite(lightY1,HIGH);
  delay(15000);
  digitalWrite(lightG1,HIGH);
  digitalWrite(lightR2,HIGH);
  digitalWrite(lightY1,LOW);
  digitalWrite(lightG2,LOW);
  delay(30000);
digitalWrite(lightR2,HIGH);
  digitalWrite(lightG1,HIGH);
  delay(45000);
  digitalWrite(lightR2,LOW);
  digitalWrite(lightY2,HIGH);
  delay(15000);
  digitalWrite(lightG2,HIGH);
  digitalWrite(lightR1,HIGH);
  digitalWrite(lightY2,LOW);
  digitalWrite(lightG1,LOW);
  
  
  
  
  
  // put your main code here, to run repeatedly:

}
