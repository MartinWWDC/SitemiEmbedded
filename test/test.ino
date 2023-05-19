#include <Stepper.h>

Stepper motore(200,8,10,9,11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World!");
  motore.setSpeed(30);
  motore.step(100);
  delay(500);
  motore.step(-100);
}

void loop() {
  motore.step(100);
  //delay(500);
  //motore.step(-100);
}
