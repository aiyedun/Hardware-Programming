#define echoPin 2 
#define trigPin 3 
#define OP 4  
#define CL 5

// defines variables
long duration; 
int distance; 


//digitalWrite(OP,LOW);
//digitalWrite(CL,LOW);

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
  
    pinMode(OP, OUTPUT);
    pinMode(CL, OUTPUT);
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
 
    if( (distance) <= 80) {
      digitalWrite(OP,HIGH);
      Serial.println("Door Open");
      delay (10000);
   }else {
      digitalWrite(OP,LOW);
      //digitalWrite(CL,HIGH);
      Serial.println("Door Closed"); 
      delay (500);   
   }
   
}

  
