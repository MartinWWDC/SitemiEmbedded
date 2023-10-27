#include <LiquidCrystal_I2C.h>

// Inizializzazione del display LCD I2C con indirizzo 0x27 e dimensioni 16x2.
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Array che contiene i pin dei sensori.
int sensor_pins[] = {8, 9, 10, 11, 12};

// Array che tiene traccia dello stato precedente dei sensori.
int sens_old[] = {1, 1, 1, 1, 1};

// Contatore per tenere traccia del valore totale delle monete rilevate.
float counter = 0.0;

// Valori delle monete corrispondenti ai sensori.
float value[] = {0.10, 0.20, 1.00, 0.50, 2.00};

// Flag per il controllo degli errori.
bool checkE = false;

// Array per memorizzare l'ultimo tempo di aggiornamento di ciascun sensore.
unsigned long lastUpdateTime[sizeof(sensor_pins)];

// Intervallo di aggiornamento dei sensori.
const unsigned long UPDATEINTERVAL = 1000;

// Intervallo di errore per il rilevamento dei sensori.
const unsigned long ERRORINTERVAL = 3000;

void setup() {
  setUpMonitor();
  setUpSensor();
  for (int i = 0; i < sizeof(sensor_pins) / sizeof(sensor_pins[0]); i++) {
    lastUpdateTime[i] = 0;
  }
}

void loop() {
  bool isCounterUpdated = false;
  unsigned long currentTime = millis();
  if (!checkE) {
    for (int i = 0; i < sizeof(sensor_pins) / sizeof(sensor_pins[0]); i++) {
      int g_n = digitalRead(sensor_pins[i]);

      if (g_n < sens_old[i] && (currentTime - lastUpdateTime[i] >= UPDATEINTERVAL)) {
        isCounterUpdated = true;
        counter += value[i];
        lastUpdateTime[i] = currentTime;
      }
      sens_old[i] = g_n;
      if (g_n == 0 && (currentTime - lastUpdateTime[i] > ERRORINTERVAL)) {
        checkE = true;
        errorPrint(i);
      }
    }

    if (isCounterUpdated) {
      updateMonitor();
    }
  }
}
// Funzione di configurazione dei sensori.
void setUpSensor() {
  for (int i = 0; i < sizeof(sensor_pins) / sizeof(sensor_pins[0]); i++) {
    pinMode(sensor_pins[i], INPUT_PULLUP);
  }
}

// Funzione di aggiornamento del monitor.
void updateMonitor() {
  lcd.setCursor(0, 0);
  lcd.print("Contatore:");
  lcd.print(counter);
}

// Funzione di configurazione del monitor
void setUpMonitor() {
  if (!i2CAddrTest(0x27)) {
    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
  }

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  updateMonitor();
}

// Funzione per il test dell'indirizzo I2C del display.
bool i2CAddrTest(uint8_t addr) {
  Wire.begin();
  Wire.beginTransmission(addr);
  if (Wire.endTransmission() == 0) {
    return true;
  }
  return false;
}

// Funzione di gestione degli errori.
void errorPrint(int g) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Colonna dei ");
  lcd.print(value[g]);
  lcd.setCursor(0, 1);
  lcd.print(" PIENA");
}
