#define trigPin 8
#define echoPin 9
long duration;
double distanceInch;
int timer;
byte x[2];
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin,LOW);
delayMicroseconds("2");
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
duration=pulseIn(echoPin,HIGH);
distanceInch = duration * 0.0133 /2;
if(distanceInch<=10)
{
Serial.print(distanceInch);
Serial.print(",");
if(distanceInch>=0.00 && distanceInch<1.00)
{
Serial.println("0");
}
else if(distanceInch>=1.00 && distanceInch<2.00)
{
Serial.println("1");
}

else if(distanceInch>=2.00 && distanceInch<3.00)
{
Serial.println("2");
}
else if(distanceInch>=3.00 && distanceInch<4.00)
{
Serial.println("3");
}
else if(distanceInch>=4.00 && distanceInch<5.00)
{
Serial.println("4");
}
else if(distanceInch>=5.00 && distanceInch<6.00)
{
Serial.println("5");
}
else if(distanceInch>=6.00 && distanceInch<7.00)
{
Serial.println("6");
}
else if(distanceInch>=7.00 && distanceInch<8.00)
{
Serial.println("7");
}
else if(distanceInch>=8.00 && distanceInch<9.00)
{
Serial.println("8");
}
else if(distanceInch>=9.00 && distanceInch<10.00)
{
Serial.println("9");  
}
//Serial.println((uint8_t*)x,2);
String a=x[0]+","+x[1];
Serial.println(x[1]);
delay(500);
}
else
{
  Serial.print("10,");
  Serial.println("10");
  //Serial.println((uint8_t*)x,2);
  delay(500);
  }
}
