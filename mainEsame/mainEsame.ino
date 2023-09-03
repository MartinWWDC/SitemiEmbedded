#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int sensor_pins[]={9,10,11,12,13};

int g_old[]={1,1,1,1,1};


int g_c[]={0,0,0,0,0};

int monitor_cord[sizeof(sensor_pins)][2]={{0,0},{5,0},{11,0},{0,1},{5,1}};

void setup() {
    setUpMonitor();    

    setUpSensor();
    //Serial.begin(9600);
    
}
 
void loop(){
  
  bool c=false;
  for (int i = 0; i < sizeof(sensor_pins) / sizeof(sensor_pins[0]); i++) {
      
    int g_n=digitalRead(sensor_pins[i]);
  
    if(g_n<g_old[i]){
      c=true;
      g_c[i]++;
    } 
   
    g_old[i]=g_n;
  
    if(c){
     updateMonitor();    
    }
  }

}


void setUpSensor(){

  for (int i = 0; i < sizeof(sensor_pins) / sizeof(sensor_pins[0]); i++) {
      pinMode(sensor_pins[i], INPUT_PULLUP);
  }


}
void updateMonitor(){
    //Serial.println(sizeof(sensor_pins));
    for (int i = 0; i < sizeof(sensor_pins) / sizeof(sensor_pins[0]); i++) {
        lcd.setCursor(monitor_cord[i][0], monitor_cord[i][1]);
        lcd.print("g" + String(i) + ":");
        lcd.print(g_c[i]);
    }

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
