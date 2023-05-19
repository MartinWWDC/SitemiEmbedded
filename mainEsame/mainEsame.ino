#include <LiquidCrystal_I2C.h>
#include <Stepper.h>


LiquidCrystal_I2C lcd(0x27,16,2);
Stepper motore(200,4,6,5,7);


int g1=0;
int g2=0;
int g3=0;
int g4=0;
int check1=0;
int check2=0;
int check3=0;
int check4=0;
void setup() {
    setUpMonitor();
    setUpSensor();    
    Serial.begin (9600);
    Serial.println("Avvio KY-033");
    //motore.setSpeed(30);

}
 
void loop(){
  int sensore1 = digitalRead(13);
  int sensore2 = digitalRead(12);
  int sensore3 = digitalRead(11);
  int sensore4 = digitalRead(10);
  updateSensore(sensore1,sensore2, sensore3, sensore4); 

  updateMonitor();
  //motore.step(800);
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
  pinMode (13, INPUT);
    pinMode (12, INPUT);
    pinMode (11, INPUT);
    pinMode (10, INPUT);
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

}
void updateSensore(int sensore1,int sensore2,int sensore3,int sensore4){
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
  check1=sensore1;
  check2=sensore2;
  check3=sensore3;
  check4=sensore4;
}

bool i2CAddrTest(uint8_t addr) {
 Wire.begin();
 Wire.beginTransmission(addr);
 if (Wire.endTransmission() == 0) {
 return true;
 }
 return false;
}
