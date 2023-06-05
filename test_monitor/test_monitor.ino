#include <LiquidCrystal_I2C.h>
/*
* note:If lcd1602 uses PCF8574T, IIC's address is 0x27,
* or lcd1602 uses PCF8574AT, IIC's address is 0x3F.
*/
int j=0;
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
 if (!i2CAddrTest(0x27)) {
 lcd = LiquidCrystal_I2C(0x3F, 16, 2);
 }
 lcd.init(); // LCD driver initialization
 lcd.backlight(); // Open the backlight
 lcd.setCursor(0,0); // Move the cursor to row 0, column 0
 lcd.print("hello world"); // The print content is displayed on the LCD
}
void loop() {
 lcd.setCursor(0,1); // Move the cursor to row 1, column 0
 lcd.print("Counter:"); // The count is displayed every second
 lcd.print(j);
 j++;
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