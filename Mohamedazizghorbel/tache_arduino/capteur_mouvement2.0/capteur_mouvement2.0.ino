#define IR_output 7
#define LED 12
char data;

void setup() {
pinMode(IR_output,INPUT);


Serial.begin(9600);
pinMode(LED,OUTPUT);
digitalWrite(LED,LOW);
}

void loop() {


  if(digitalRead(IR_output)==HIGH){
   Serial.print("1");

  }
 else if(digitalRead(IR_output)==LOW){
   Serial.print("0");
      

  }
  
if(Serial.available())
{
  data=Serial.read();
  if(data=='1')
  {
    digitalWrite(LED,HIGH);
    delay(2000);
        digitalWrite(LED,LOW);

  }
  else if(data=='0')
  {
    digitalWrite(LED,LOW);
  }
}

delay(1000);
}
