#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int sensor_pins[]={8,9,10,11,12};

int sens_old[]={1,1,1,1,1};

float counter=0.0;

float value[]={0.10,0.20,1.00,0.50,2.00};

bool checkE=false;

unsigned long lastUpdateTime[sizeof(sensor_pins)];
const unsigned long UPDATEINTERVAL = 1000; 
const unsigned long ERRORINTERVAL = 3000; 


void setup() {
    setUpMonitor();   
    setUpSensor();
    for (int i = 0; i < sizeof(sensor_pins) / sizeof(sensor_pins[0]); i++) {
        lastUpdateTime[i] = 0;
    }
    
}
 
void loop() {
    bool c = false;
    unsigned long currentTime = millis();
    if(!checkE){
    for (int i = 0; i < sizeof(sensor_pins) / sizeof(sensor_pins[0]); i++) {
        int g_n = digitalRead(sensor_pins[i]);
        
        
        if (g_n < sens_old[i] && (currentTime - lastUpdateTime[i] >= UPDATEINTERVAL)) {
            c = true;
            counter+=value[i];
            lastUpdateTime[i] = currentTime;
        }
        sens_old[i] = g_n;
        if( g_n==0 &&(currentTime - lastUpdateTime[i] > ERRORINTERVAL)){
            checkE=true;
            errorPrint(i);
        }
    }

    if (c) {
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
  
        lcd.setCursor(0,0);
        lcd.print("Contatore:");
        lcd.print(counter);
    
}

void setUpMonitor(){
   if (!i2CAddrTest(0x27)) {
      lcd = LiquidCrystal_I2C(0x3F, 16, 2);
    } 
    
   lcd.init();
   lcd.backlight();
   lcd.setCursor(0,0);
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



void errorPrint(int g){
  lcd.clear();

  lcd.setCursor(0,0); 
  lcd.print("Colonna dei ");
  lcd.print(value[g]);
  lcd.setCursor(0,1); 
  lcd.print(" PIENA"); 
  


}
