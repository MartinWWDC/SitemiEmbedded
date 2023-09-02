const int sensorPins[] = {9,10,11,12,13};  // Pin dei sensori KY-033
const int numSensors = 5;  // Numero di sensori
int lastSensorActivated = -1;  // Inizialmente nessun sensore attivato

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < numSensors; i++) {
    pinMode(sensorPins[i], INPUT);
    attachInterrupt(digitalPinToInterrupt(sensorPins[i]), sensorChange, CHANGE);
  }
}

void loop() {
  // Il loop principale può continuare a eseguire altre operazioni
}

void sensorChange() {
  for (int i = 0; i < numSensors; i++) {
    int sensorValue = digitalRead(sensorPins[i]);

    if (sensorValue == HIGH) {
      if (i != lastSensorActivated) {  // Verifica se questo è un nuovo sensore attivato
        Serial.print("Sensore ");
        Serial.print(i + 1); // Per tenere traccia di quale sensore ha scatenato l'interrupt
        Serial.println(" rilevato!");
        lastSensorActivated = i;
      }
    }
  }
}
