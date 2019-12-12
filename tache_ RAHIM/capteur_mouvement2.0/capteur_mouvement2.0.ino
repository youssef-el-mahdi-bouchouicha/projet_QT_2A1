#define IR_output 7
#define LED 12
#define BIP 13
char data;

void setup() {
pinMode(IR_output,INPUT);


Serial.begin(9600);
pinMode(LED,OUTPUT);
digitalWrite(LED,LOW);
pinMode(BIP,OUTPUT);
digitalWrite(BIP,LOW);
}

void loop() {


  if(digitalRead(IR_output)==HIGH){
   Serial.print("1");
   for(int i=0;i<4;i++)
   {
    digitalWrite(LED,HIGH);
    delay(500);
        digitalWrite(LED,LOW);
            delay(500);

   }
    


  }
 else if(digitalRead(IR_output)==LOW){
   Serial.print("0");
      

  }
  
if(Serial.available())
{
  data=Serial.read();
  if(data=='1')
  {
     for(int i=0;i<4;i++)
   {
    digitalWrite(BIP,HIGH);
    delay(500);
        digitalWrite(BIP,LOW);
            delay(500);

   }

  }
  else if(data=='0')
  {
    digitalWrite(BIP,LOW);
  }
}

delay(2000);
}
