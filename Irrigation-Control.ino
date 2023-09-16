int sensor_pin = A0;
int output_value ;
int val;
int moi;
int RED = 5;
int GREEN = 6;
int PUMP = 7;

void setup() {
   pinMode(RED,OUTPUT);
   Serial.begin(9600);
   Serial.println("Reading From the Sensor ...");
   delay(2000);
   digitalWrite(PUMP, 1);
   delay(3000);
   }

void loop() {
   output_value= analogRead(sensor_pin);
   output_value = map(output_value,550,0,0,100);
   val = output_value*1;
   val = val+86;
   Serial.print("Mositure : ");
   Serial.print(val);
   Serial.println("%");
   delay(1000);
if (val< 40)   // for dry soil
{
  for(int x=0; x<=5; x++){
  digitalWrite (RED, 1);
    delay(1000);
    digitalWrite (RED, 0);
    delay(200);
    }
  digitalWrite(PUMP, 1);
  }
  if (val> 80)   // for wet soil
{
 
  digitalWrite(PUMP, 0);
  }
  }
