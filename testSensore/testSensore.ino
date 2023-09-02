
int g2_pin_const=9;



void setup() {
    setUpSensor();    
    Serial.begin (9600);
    Serial.println("Avvio KY-033");


}
 
void loop(){
  int g=digitalRead(g2_pin_const);
  if(g==0){
    Serial.println("c");
   
  }
}


void setUpSensor(){
    pinMode (g2_pin_const, INPUT_PULLUP);
}
