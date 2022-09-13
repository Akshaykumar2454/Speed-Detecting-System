#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int timer1;
int timer2;
float Time;
int flag1 = 0;
int flag2 = 0;
float distance = 10.0;
float speed;
int ir_s1 = A0;
int ir_s2 = A1;
int buzzer = 12;
int ledred=13;
void setup(){
pinMode(ir_s1, INPUT);
pinMode(ir_s2, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(ledred, OUTPUT);
lcd.begin(16,2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" SSD PROJECT ");
lcd.setCursor(0,1);
lcd.print("BATCH-2");
delay(2000);
lcd.clear();
}
void loop() {
if(digitalRead (ir_s1) == LOW && flag1==0){timer1 = millis(); flag1=1;}
if(digitalRead (ir_s2) == LOW && flag2==0){timer2 = millis(); flag2=1;}
if (flag1==1 && flag2==1){
if(timer1 > timer2){Time = timer1 - timer2;}
else if(timer2 > timer1){Time = timer2 - timer1;}
Time=Time/1000; speed=(distance/Time);
speed=speed*3600;
speed=speed/1000;
} 
