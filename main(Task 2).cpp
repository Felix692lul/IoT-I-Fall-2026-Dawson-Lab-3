#include <Arduino.h>

uint8_t value;


void setup() {
  DDRD &= 0x0F; // PD7-PD4 as inputs, PB3-PB0 as outputs
  PORTD |= 0xF0;
  DDRB &= 0X0F;
  
  Serial.begin(9600);
}

void loop() {
  value = PIND; // read the full Port D register
  value &= 0xF0;
  value >>= 4;
  value = ~value;
  value &= 0x0F; // mask the upper nibble
  value = (~value + 1) & 0x0F; // 2's complement of the 4-bit value 
  PORTB = value; //Display result on LEDS
  Serial.print("Binary:");
  Serial.println(value, BIN); 
  Serial.print("Decimal:");
  Serial.println(value);
  delay(1000);
}






