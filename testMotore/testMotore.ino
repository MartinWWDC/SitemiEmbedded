#include <Stepper.h>

Stepper motore(200,4,6,5,7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World!");
  motore.setSpeed(100);
  motore.step(100);
  delay(500);
  motore.step(-100);
}

void loop() {
  motore.step(800);
  //delay(500);
  //motore.step(-100);
}
