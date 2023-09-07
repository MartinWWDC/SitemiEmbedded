#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int sensor_pins[]={8,9,10,11,12  };

int g_old[]={1,1,1,1,1};

float counter=0.0;

float value[]={0.10,0.20,1.00,0.50,2.00};

int monitor_cord[sizeof(sensor_pins)][2]={{0,0},{5,0},{11,0},{0,1},{5,1}};


unsigned long lastUpdateTime[sizeof(sensor_pins)];
const unsigned long updateInterval = 1000; // 1 secondo
const unsigned long errorInterval = 2000; // 1 secondo


void setup() {
    setUpMonitor();    

    //setUpSensor();
     for (int i = 0; i < sizeof(sensor_pins) / sizeof(sensor_pins[0]); i++) {
        lastUpdateTime[i] = 0;
    }
    
}
 
void loop() {
    bool c = false;
    unsigned long currentTime = millis();

    for (int i = 0; i < sizeof(sensor_pins) / sizeof(sensor_pins[0]); i++) {
        int g_n = digitalRead(sensor_pins[i]);
  
        if (g_n < g_old[i] && (currentTime - lastUpdateTime[i] >= updateInterval)) {
            c = true;
            counter+=value[i];
            lastUpdateTime[i] = currentTime; // Aggiorna il tempo dell'ultimo aggiornamento.
        }
        g_old[i] = g_n;
    }

    if (c) {
        updateMonitor();
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



void errorPrint(int g){


 lcd.setCursor(0,0); // Move the cursor to row 1, column 0
 lcd.print("Errore!"); // The count is displayed every second

  lcd.setCursor(0,1); // Move the cursor to row 1, column 0
  lcd.print("Colonna g");
  lcd.print(g);
  lcd.print(" PIENA"); // The count is displayed every second


}
