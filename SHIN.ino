#include "BluetoothSerial.h" 
BluetoothSerial ESP_BT; 

int trai_tien = 4;
int trai_lui = 16;

int phai_tien = 17; 
int phai_lui = 5;
 
int red = 27;
int white = 26;

int trailed = 25;
int phailed = 33;
 
int incoming;

void motor_low(){
   digitalWrite(trai_tien, LOW);
   digitalWrite(trai_lui, LOW);
   digitalWrite(phai_tien, LOW);
   digitalWrite(phai_lui, LOW);

   digitalWrite(red, LOW);
}
// DIEU HUONG
void up(){
   digitalWrite(trai_tien, HIGH);
   digitalWrite(trai_lui, LOW);
   digitalWrite(phai_tien, HIGH);
   digitalWrite(phai_lui, LOW);
}
void down(){
   digitalWrite(trai_tien, LOW);
   digitalWrite(trai_lui, HIGH);
   digitalWrite(phai_tien, LOW);
   digitalWrite(phai_lui, HIGH);

   digitalWrite(red, HIGH);
}
void left(){
   digitalWrite(trai_tien, LOW);
   digitalWrite(trai_lui, HIGH);
   digitalWrite(phai_tien, HIGH);
   digitalWrite(phai_lui, LOW);  
}
void right(){
   digitalWrite(trai_tien, HIGH);
   digitalWrite(trai_lui, LOW);
   digitalWrite(phai_tien, LOW);
   digitalWrite(phai_lui, HIGH);
}
// DEN PHA
void PHA_on(){
  digitalWrite(white, HIGH);
}
void PHA_off(){
  digitalWrite(white, LOW);
}
// XINHAN
//TRAI
void LL_on(){
  digitalWrite(trailed, HIGH);
}
void LL_off(){
  digitalWrite(trailed, LOW);
}
//PHAI
void RR_on(){
  digitalWrite(phailed, HIGH);
}
void RR_off(){
  digitalWrite(phailed, LOW);
}
//GIUA
void GG_on(){
  digitalWrite(trailed, HIGH);
  digitalWrite(phailed, HIGH);
}
void GG_off(){
  digitalWrite(trailed, LOW);
  digitalWrite(phailed, LOW);
}
//******
void setup() {
  Serial.begin(19200);
  ESP_BT.begin("ESP32_Control"); 

  pinMode (trai_tien, OUTPUT);
  pinMode (trai_lui, OUTPUT);
  
  pinMode (phai_tien, OUTPUT);
  pinMode (phai_lui, OUTPUT);

  pinMode (red, OUTPUT);
  pinMode (white, OUTPUT);
  pinMode (trailed, OUTPUT); 
  pinMode (phailed, OUTPUT);

  motor_low();
  PHA_off();
  LL_off();
  RR_off();
  GG_off();
}

void loop() {
  
  if (ESP_BT.available()) 
  {
    incoming = ESP_BT.read(); //Read what we receive 
    
    int tt = incoming;    
    //left
    if (tt == 10) motor_low();
    if (tt == 11) left();
    //right
    if (tt == 20) motor_low();
    if (tt == 21) right(); 
    //up
    if (tt == 30) motor_low();
    if (tt == 31) up();
    //down
    if (tt == 40) motor_low();
    if (tt == 41) down();
    //white led
    if (tt == 50) PHA_off();
    if (tt == 51) PHA_on();
    //left led
    if (tt == 60) {LL_off();}
    if (tt == 61) {LL_on(); RR_off();}
    //right led
    if (tt == 70) {RR_off();}
    if (tt == 71) {RR_on(); LL_off();}
    //giua led 
    if (tt == 80) {GG_off();}
    if (tt == 81) {GG_on();;}
}
}
