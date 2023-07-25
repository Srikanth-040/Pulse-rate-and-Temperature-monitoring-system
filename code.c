#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display
int pin=A1;
void setup() {
  pinMode(pin,INPUT);
  pinMode(8,OUTPUT);
  pinMode(A0,INPUT);
  digitalWrite(8,LOW);
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("    Checking ");
  lcd.setCursor(0,1); 
  lcd.print(" ");
  lcd.print(" "); 
  lcd.print("Heart Rate");
  delay(7000);
  lcd.clear(); //Move cursor to character 2 on line 1
}
void loop() {
  int data = analogRead(pin);
  float temp= analogRead(A0);
float t= (temp*500)/1023;
Serial.println(t);
  
  lcd.setCursor(0,0);
  Serial.println(data);
  lcd.print("Temperature ");
  lcd.print(t);
  digitalWrite(8,LOW);
  data = analogRead(pin);
  lcd.setCursor(0,1);
  Serial.println(data);
  lcd.print("Heart Rate : ");
  lcd.print(data/10+15);
  delay(500);
 
}
