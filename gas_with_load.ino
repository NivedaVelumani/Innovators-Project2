#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

#define loadcell A5
#define sensorvalue A5
#define sw 1
#define MQPin A0
#define buzzer 2




long sample=0;
float val=0;
long count=0;


void setup()
{
  
  lcd.begin(16, 2);
   pinMode(MQPin, INPUT_PULLUP);
   pinMode(buzzer, OUTPUT);
    lcd.setCursor(5, 0);
    lcd.print("GAS");
    lcd.setCursor(3, 1);
    lcd.print("DETECTOR");
    delay(1000);
    lcd.clear();
  Serial.begin(9600);
  pinMode(loadcell, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.print("    Weight ");
  lcd.setCursor(0,1);
  lcd.print(" Measurement ");
  delay(1000);
  lcd.clear();
 
}

void loop()
{
  int gas_value = digitalRead(MQPin);

if(gas_value==HIGH)
{
  digitalWrite(buzzer, HIGH);
  lcd.setCursor(6, 0);
  lcd.print("GAS");
   lcd.setCursor(3, 1);
  lcd.print("DETECTED");
  delay(200);
  lcd.clear();
  delay(200);
  
}
else
{
 lcd.clear();
 digitalWrite(buzzer, LOW); 
}
  
  int sensorvalue=analogRead(loadcell);
  Serial.println(sensorvalue);
  delay(500);
  
  Serial.print("weight:");
  Serial.println("g");
  lcd.setCursor(0,0);
  lcd.print("Weight in Kg  ");
  lcd.setCursor(0,1);
  
  lcd.print("g             ");

  if(digitalRead(sw)==0)
  {
    val=0;
    sample=0;
   
    count=0;
    calibrate();
  }
}

void calibrate()
{
    lcd.clear();
  lcd.print("Calibrating...");
  lcd.setCursor(0,1);
  lcd.print("Please Wait...");
  lcd.clear();
}
 
  


  
