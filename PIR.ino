//#include<LiquidCrystal.h>
//LiquidCrystal lcd(12,11,5,4,3,2);
int s = 5;
int b = 4;
int s1,s2;
int l = 0;
void readsens()
{
  s1 = digitalRead(s);
  //Serial.println("sensor value");
  //Serial.println(s1);
  //Serial.begin(9600);
}


void setup() 
{
 pinMode(s,INPUT);
 pinMode(l,OUTPUT);
 pinMode(b,OUTPUT);
 digitalWrite(l,1);
 //pinMode(l, INPUT_PULLUP);
 //lcd.begin(16,2);
 //lcd.print("CALIB SENSOR... ");
 //delay(3000);
 //lcd.clear();
 //lcd.setCursor(0,1);
    for(int i = 30; i >=0; i--)
    { 
      
      //lcd.setCursor(5,1);
      //lcd.print("Seconds.....");
      //lcd.setCursor(8,0);
      //lcd.print(i);
      delay(700);
    }
    //lcd.setCursor(0,0);
    //lcd.clear();
    //lcd.print("SENSOR ACTIVE");
    digitalWrite(b,1);
    delay(2000);
    digitalWrite(b,0); 
  
}

void loop() 
{
  //lcd.clear();
  readsens();
  Serial.print(s1);
  if(s1==1)
  {
    //lcd.clear();
    //lcd.print("LOCKING DOOR....");
    digitalWrite(b,1);
    delay(2500);
    digitalWrite(b,0);
    digitalWrite(l,LOW);
    delay(3000);
    while(1)
    {
    digitalWrite(l,LOW);
    //lcd.clear();
    //lcd.print("RESTROOM ENGAGED.......");
    //delay(1000);
    s2 = digitalRead(s);
    Serial.println(s2);

    if(s2==1)
    {
      //lcd.clear();
      //lcd.print("LOCKING DOOR....");
      digitalWrite(b,1);
      delay(1000);
      digitalWrite(b,0);
      delay(9000);
      break;
    }
    
    }
    //lcd.clear();
    //lcd.print("CAMEOUT...");
    digitalWrite(b,1);
    delay(2000);
    digitalWrite(b,0);
   
  }

  else
  {
   //lcd.clear();
   //lcd.print("RESTROOM VACANT");
    digitalWrite(l,HIGH);
    delay(1000);
  }
   
}
