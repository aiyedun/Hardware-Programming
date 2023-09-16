unsigned long startMillis;  
unsigned long currentMillis;
const unsigned long period =28800000;
int c4w=0;
 
#define feopen 4 // feed open
#define feclose 5 // feed close
#define forcedfeed 13 // forced feeding


#define eo 10 // water exit open
#define oo 9  // water inlet open
#define button 12 // forced changing water system 

#define lo 31 // minimum water level
#define hi 20 // maximum water level

#define echoPin A0 //ultrasonic echo
#define trigPin A1 //ultrasonic trig


long duration ;
int distance, dist;


int count;







void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  
  pinMode(feopen, OUTPUT);
  pinMode(feclose, OUTPUT);
  pinMode(forcedfeed, INPUT_PULLUP);

  pinMode(eo, OUTPUT);
  pinMode(oo, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  
 
  
  digitalWrite(oo, 1);
  digitalWrite(eo, 1);
 
  digitalWrite(feopen, 1);
  digitalWrite(feclose, 1);
  
  //closefeed();


}

void loop() {

//currentMillis = millis();
//if (currentMillis - startMillis >= period)  //test whether the period has elapsed
//  {
//  c4w++;
//
//
//
//if(c4w==3){
//  watersystem();
//  c4w=0;
//}
//
//    
//   ffeeding();
//
//    startMillis=millis();
//    
//  }




////






dist=discal();
Serial.println(dist);
delay(1000);




  if (digitalRead(button) == 0) {

    //count=1;
    watersystem();

  }
  if (digitalRead(forcedfeed) == 0) {


    feeding();
  }



}








void watersystem() {
  wexit();
  Serial.print("wexitopen()");
  delay(3000);
  wentry();
  Serial.print("wentryopen");
  delay(3000);

}

void wexit() {

  Serial.println("wexitopen 1  ");
    dist=discal();
  while (dist > lo) {
    dist=discal();
    digitalWrite(eo, 0);
    delay(500);
    }
     digitalWrite(eo, 1);
      delay(500);
  Serial.println("wexitopen 2 ");

}

void wentry() {

  Serial.println("wentyropen 1  ");
    dist=discal();
  while (dist < hi) {
    dist=discal();
    digitalWrite(oo, 0);
    delay(500);
    }
    digitalWrite(oo, 1);
     delay(500);
  

}







void openfeed() {
    digitalWrite(feopen, 0);
    delay(50);
    digitalWrite(feopen,1);
    delay(300);
    Serial.println("Fopened");
}

void closefeed() {
    digitalWrite(feclose, 0);
    delay(50);
    digitalWrite(feclose,1);
    delay(300);
    Serial.println("Fclosed");

}


void feeding() {
  openfeed();
  delay(1000);
  closefeed();
  delay(1000);

}




float discal() {

  digitalWrite (trigPin, LOW);
  delayMicroseconds (2);
  digitalWrite (trigPin, HIGH);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  return distance;


}

//void ffeeding(){
//
//openfeed();
////delay(1000);
//closefeed();
//
//  
//}

//void confwexitopen() {
//  if (count == 1) {
//    dist=discal();
//    while (dist<lo) {
//      Serial.println("confwexitopen  ");
//
//       dist=discal();
//
//
//      Serial.println("onfwexitopen 2");
//      Serial.println(count);
//
//    }
//
//  }
//  count = 2;
//}
//void confwentryopen() {
//  if (count == 4) {
//    dist=discal();
//    while (dist>hi) {
//      Serial.println("confwentryopen  ");
//
//      count = 5;
//      Serial.println(count);
//      dist=discal();
//    }
//    Serial.println("confwentryopen");
//
//
//  }
//
//}
