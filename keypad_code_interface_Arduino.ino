int sinx[3] = {4, 5, 6};
int souty[4] = {7,8, 9, 10};
char key;
char akey;
void setup() {
  for (int x = 0; x <= 2; x++) {
    pinMode (sinx[x], OUTPUT);
  }
  for (int y = 0; y <= 3; y++)
  {
    pinMode(souty[y], INPUT_PULLUP);
  }
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  for (int x = 0; x <= 2; x++) { //nested loop
    for (int y = 0; y <= 2; y++) {
      digitalWrite (sinx[y], 1);
    }
    digitalWrite(sinx[x], 0);
    for (int z = 0; z <= 3; z++) {
      if (digitalRead(souty[z]) == 0) {
        akey = keypressed(x,z);
        Serial.println(akey);
      }
    }
  }
  // put your main code here, to run repeatedly:

}
char keypressed (int x, int z) {
  if (x == 0 && z == 0)
  
    key = '1';
  delay(15);
  if (x == 1 && z == 0)
  
    key = '2';
  delay(15);
  if (x == 2 && z == 0)
  
    key = '3';
  delay(15);
  if (x == 0 && z == 1)
  
    key = '4';
  delay(15);
  if (x == 1 && z == 1)
  
    key = '5';
  delay(15);
  if (x == 2 && z == 1)
  
    key = '6';
  delay(15);
  if (x == 0 && z == 2)
  
    key = '7';
  delay(15);
  if (x == 1 && z == 2)
  
    key = '8';
  delay(15);
  if (x == 2 && z == 2)
  
    key = '9';
  delay(15);
  if (x == 0 && z == 3)
  
    key = '*';
  delay(15);
  if (x == 1 && z == 3)
  
    key = '0';
  delay(15);
  if (x == 2 && z == 3)
  
    key = '#';
    delay(15);
  return key;
}
