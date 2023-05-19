#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);


int g1=0;
int g2=0;
int g3=0;
void setup() {
    if (!i2CAddrTest(0x27)) {
      lcd = LiquidCrystal_I2C(0x3F, 16, 2);
    } 
    pinMode (13, INPUT);
    pinMode (12, INPUT);
    pinMode (11, INPUT);
    lcd.init(); // LCD driver initialization
    lcd.backlight(); // Open the backlight
    lcd.setCursor(0,0); // Move the cursor to row 0, column 0
    Serial.begin (9600);
    Serial.println("Avvio KY-033");
}
 
void loop(){
int sensore = digitalRead(13);
int sensore2 = digitalRead(12);
int sensore3 = digitalRead(11);
  if(sensore==0){
    g++;
    delay(1000);
  }
  if(sensore2==0){
    g2++;
    delay(1000);
  }
  if(sensore3==0){
    g3++;
    delay(1000);
  }
  if(sensore==0 ||sensore2==0 ||sensore3==0){
    //printSeerial();

  }
  updateMonitor();


}
void updateMonitor(){
   lcd.setCursor(0,0); // Move the cursor to row 1, column 0
    lcd.print("g:"); // The count is displayed every second
    lcd.print(g);

}

void printSerial(){
   Serial.println("----");
    Serial.print(sensore);
    Serial.print("  ");

    Serial.println(g);
    
    Serial.print(sensore2);
    Serial.print("  ");

    Serial.println(g2);
    Serial.print(sensore3);
    Serial.print("  ");

    Serial.println(g3);

    Serial.println("----");
        delay(1000);
}
bool i2CAddrTest(uint8_t addr) {
 Wire.begin();
 Wire.beginTransmission(addr);
 if (Wire.endTransmission() == 0) {
 return true;
 }
 return false;
}
