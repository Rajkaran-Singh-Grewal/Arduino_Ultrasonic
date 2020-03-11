#define switchs 12
#define light 13
void setup()
{
Serial.begin(9600);
pinMode(switchs,INPUT);
pinMode(light,OUTPUT);
}
void loop()
{
    if(pulseIn(switchs,HIGH))
    {
        digitalWrite(light,HIGH);
        Serial.println("High")    
    }
    else
    {
        digitalWrite(light,LOW);
        Serial.println("LOW")
    }
    
}