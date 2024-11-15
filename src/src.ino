#include "buttons.h"
#include "leds.h"

using Builtin_LED = LED<13>;
using Button1 = BUTTON<6>;
using LED1 = LED<2>;

void setup() {
  Builtin_LED::init();
  Button1::init();
  LED1::init();
  Serial.begin(115200);
}

void loop() {
  Builtin_LED::on();                    
  LED1::switchCondition(Button1::statusCheck());
  delay(1000);     
  LED1::switchCondition(Button1::statusCheck());
  Builtin_LED::off();  
  delay(1000);                  
}