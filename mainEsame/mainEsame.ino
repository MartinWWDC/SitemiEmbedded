#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);


int g2_pin_const=9;
int g3_pin_const=10;
int g4_pin_const=11;
int g5_pin_const=12;
int g6_pin_const=13;



int g1_c=0;
int g2_c=0;
int g3_c=0;
int g4_c=0;
int g5_c=0;
int g1_old=1;
int g2_old=1;
int g3_old=1;
int g4_old=1;
int g5_old=1;


void setup() {
    setUpMonitor();    

    setUpSensor();


}
 
void loop(){
  bool c=false;
  int g1=digitalRead(g2_pin_const);
  int g2=digitalRead(g3_pin_const);
  int g3=digitalRead(g4_pin_const);
  int g4=digitalRead(g5_pin_const);
  int g5=digitalRead(g6_pin_const);

  
  if(g1<g1_old){
    c=true;
    g1_c++;
  } 
  if(g2<g2_old){
     c=true;
     g2_c++;


  } 
  if(g3<g3_old){
     c=true;
     g3_c++;


  } 
  if(g4<g4_old){
    c=true;
    g4_c++;


  } 
  if(g5<g5_old){
    c=true;
    g5_c++;
  }
  g1_old=g1;
  g2_old=g2;
  g3_old=g3;
  g4_old=g4;
  g5_old=g5;
  if(c){
   updateMonitor();    
  }
}


void setUpSensor(){
    pinMode (g2_pin_const, INPUT_PULLUP);
    pinMode (g3_pin_const, INPUT_PULLUP);
    pinMode (g4_pin_const, INPUT_PULLUP);
    pinMode (g5_pin_const, INPUT_PULLUP);
    pinMode (g6_pin_const, INPUT_PULLUP);
}
void updateMonitor(){
    lcd.setCursor(0,0); // Move the cursor to row 1, column 0
    lcd.print("f1:"); // The count is displayed every second
    lcd.print(g1_c);
    lcd.setCursor(5,0); // Move the cursor to row 1, column 0
    lcd.print("g2:"); // The count is displayed every second
    lcd.print(g2_c);
    lcd.setCursor(11,0); // Move the cursor to row 1, column 0
    lcd.print("g3:"); // The count is displayed every second
    lcd.print(g3_c);
    lcd.setCursor(0,1); // Move the cursor to row 1, column 0
    lcd.print("g4:"); // The count is displayed every second
    lcd.print(g4_c); 
    lcd.setCursor(5,1); // Move the cursor to row 1, column 0
    lcd.print("g5:"); // The count is displayed every second
    lcd.print(g5_c);

}

void setUpMonitor(){
   if (!i2CAddrTest(0x27)) {
      lcd = LiquidCrystal_I2C(0x3F, 16, 2);
    } 
    
   lcd.init(); // LCD driver initialization
   lcd.backlight(); // Open the backlight
   lcd.setCursor(0,0); // Move the cursor to row 0, column 0
   updateMonitor();
}


bool i2CAddrTest(uint8_t addr) {
 Wire.begin();
 Wire.beginTransmission(addr);
 if (Wire.endTransmission() == 0) {
 return true;
 }
 return false;
}
