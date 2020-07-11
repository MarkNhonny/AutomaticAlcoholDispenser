//ALCOHOL DISPENSER
#define trigger 5
#define echo 4
#define Relay 6

float time=0,distance=0;
 
void setup()
{
Serial.begin(9600);

 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(Relay,OUTPUT);

 delay(200);
}
 
void loop()
{
 measure_distance();

 if(distance<5)
 {
   digitalWrite(Relay,HIGH);
 }
 else
 {
   digitalWrite(Relay,LOW);
 }
 delay(50);
}

void measure_distance()
{
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH);
 
 distance=time*200/20000;
}
