#include <LiquidCrystal_I2C.h>
#include <Stepper.h>


LiquidCrystal_I2C lcd(0x27,16,2);
Stepper motore(200,4,6,5,7);

int g1_pin_const=13;
int g2_pin_const=9;
int g3_pin_const=10;
int g4_pin_const=12;
int g5_pin_const=11;

int g1=0;
int g2=0;
int g3=0;
int g4=0;
int g5=0;
int check1=0;
int check2=0;
int check3=0;
int check4=0;
int check5=0;
void setup() {
    setUpMonitor();
    setUpSensor();    
    Serial.begin (9600);
    Serial.println("Avvio KY-033");
    motore.setSpeed(100);

}
 
void loop(){
  int sensore1 = digitalRead(g1_pin_const);
  int sensore2 = digitalRead(g2_pin_const);
  int sensore3 = digitalRead(g3_pin_const);
  int sensore4 = digitalRead(g4_pin_const);
  int sensore5 = digitalRead(g5_pin_const);
  updateSensore(sensore1,sensore2, sensore3, sensore4,sensore5); 

  updateMonitor();
  motore.step(10);
  Serial.println(sensore1);



}
void setUpMonitor(){
   if (!i2CAddrTest(0x27)) {
      lcd = LiquidCrystal_I2C(0x3F, 16, 2);
    } 
    
   lcd.init(); // LCD driver initialization
   lcd.backlight(); // Open the backlight
   lcd.setCursor(0,0); // Move the cursor to row 0, column 0
}
void setUpSensor(){
    pinMode (g1_pin_const, INPUT);
    pinMode (g2_pin_const, INPUT);
    pinMode (g3_pin_const, INPUT);
    pinMode (g4_pin_const, INPUT);
    pinMode (g5_pin_const, INPUT);
}

void updateMonitor(){
    lcd.setCursor(0,0); // Move the cursor to row 1, column 0
    lcd.print("g1:"); // The count is displayed every second
    lcd.print(g1);
    lcd.setCursor(5,0); // Move the cursor to row 1, column 0
    lcd.print("g2:"); // The count is displayed every second
    lcd.print(g2);
    lcd.setCursor(11,0); // Move the cursor to row 1, column 0
    lcd.print("g3:"); // The count is displayed every second
    lcd.print(g3);
    lcd.setCursor(0,1); // Move the cursor to row 1, column 0
    lcd.print("g4:"); // The count is displayed every second
    lcd.print(g4); 
    lcd.setCursor(5,1); // Move the cursor to row 1, column 0
    lcd.print("g5:"); // The count is displayed every second
    lcd.print(g5);

}
void updateSensore(int sensore1,int sensore2,int sensore3,int sensore4,int sensore5){
    if(sensore1==0 && check1!=sensore1){
    g1++;
  }
  if(sensore2==0&& check2!=sensore2){
    g2++;
  }
  if(sensore3==0 && check3!=sensore3){
    g3++;
  }  
  if(sensore4==0 && check4!=sensore4){
    g4++;
  }
  if(sensore5==0 && check5!=sensore5){
    g5++;
  }
  check1=sensore1;
  check2=sensore2;
  check3=sensore3;
  check4=sensore4;
  check5=sensore5;
}

bool i2CAddrTest(uint8_t addr) {
 Wire.begin();
 Wire.beginTransmission(addr);
 if (Wire.endTransmission() == 0) {
 return true;
 }
 return false;
}
