/*
 * TODO  
 * - USE PWM TO INNCREASE OR DECREASE BRIGHTNESS
 * - WRITE LIGHT SEQUENCES
 * 
 * 
 * 
 * 
 */



#include <IRremote.h>
#include "keydefinitions.h"

#define IR_SIGNAL_PIN 11
#define RED 7
#define GREEN 8
#define YELLOW 9
#define DEBUG


IRrecv IR(IR_SIGNAL_PIN);
unsigned long res;
void setup() {

  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW,OUTPUT);

   IR.enableIRIn();  // Start the receiver
   IR.blink13(true); // Enable feedback LED
#ifdef DEBUG
    Serial.begin(115200);
    Serial.println("Enabling IRin");
    Serial.print(F("Ready to receive IR signals at pin "));
    Serial.println(IR_SIGNAL_PIN);
#endif

}

void loop() {
  if (IR.decode())
  {
#ifdef DEBUG
        IR.printResultShort(&Serial);
        Serial.println();
        Serial.print("my res: ");
        Serial.println(res,HEX);
#endif
       res = IR.results.value; 
        switch(res)
        {
          case ZERO:
          digitalWrite(RED,!digitalRead(RED));break;
          case ONE:
          digitalWrite(YELLOW,!digitalRead(YELLOW));break;
          case TWO:
          digitalWrite(GREEN,!digitalRead(GREEN));break;
        }
  
        IR.resume(); // Receive the next value
    }
}
