#include "buttons.h"
#include "leds.h"
#include "code_manipul.h"
#include "beeper.h"

constexpr char CODE[4] {'1', '3', '5', '4'};

//отдельно выведем список пинов, это потребуется, если контакты заменяются на другие
constexpr unsigned int bPin[5] {6, 7, 8, 9, 10};

//отдельно список символов, сответственно привязанных к кнопкам
constexpr char bSymbol[5] {'1', '2', '3', '4', '5'};

using Builtin_LED = LED<13>;

//кнопка - какой контакт + за ввод какого символа отвечает
using Button1 = BUTTON<bPin[0], bSymbol[0]>;
using Button2 = BUTTON<bPin[1], bSymbol[1]>;
using Button3 = BUTTON<bPin[2], bSymbol[2]>;
using Button4 = BUTTON<bPin[3], bSymbol[3]>;
using Button5 = BUTTON<bPin[4], bSymbol[4]>;

using LED1 = LED<2>;
using LED2 = LED<3>;
using LED3 = LED<4>;
using LED4 = LED<5>;

using Beeper1 = Beeper<11>;




// НЕ ЗАБЫВАЙ НОВЫЕ ОБЪЕКТЫ INIT-ИТЬ
void setup() {
  Builtin_LED::init();

  Button1::init();
  Button2::init();
  Button3::init();
  Button4::init();
  Button5::init();

  LED1::init();
  LED2::init();
  LED3::init();
  LED4::init();

  Beeper1::init();

  Serial.begin(115200);
}

void loop() {

  char inputCode[4] = {};

  // Ардуино будет ожидать, когда пользователь нажмёт ЧТО-ТО из кнопок
  // нужен механизм, отслеживающий конкретную кнопку
  // с превентивным механизмом, чтобы предыдущий ввод случайно не засчитался (сделано)

  // нужно придумать, как передать шаблонный объект в функцию

  Serial.println("Enter the first number");
  
  inputCode[0] = codeCharSelect(bPin, bSymbol, 5);

  LED1::on();

  delay(50);     


  Serial.println("Enter the second number");
  
  inputCode[1] = codeCharSelect(bPin, bSymbol, 5);

  LED2::on();

  delay(50);  


  Serial.println("Enter the third number");
  
  inputCode[2] = codeCharSelect(bPin, bSymbol, 5);

  LED3::on();

  delay(50);   


  Serial.println("Enter the fourth number");
  
  inputCode[3] = codeCharSelect(bPin, bSymbol, 5);

  LED4::on();

  delay(50);     

  LED1::off();
  LED2::off();
  LED3::off();
  LED4::off();
  delay(500);

  if (codeVerify(CODE, inputCode, 4) == 1) {
    Serial.println("Right!!");
    LED1::on();
    LED2::on();
    LED3::on();
    LED4::on();
    delay(200);
    LED1::off();
    LED2::off();
    LED3::off();
    LED4::off();
    delay(400);
    
    //автозапирание

    for (int i = 0; i < 8; i++) {
      LED1::on();
      delay(200);

      LED1::off();
      LED2::on();
      delay(200);

      LED2::off();
      LED3::on();
      delay(200);

      LED3::off();
      LED4::on();
      delay(200);

      LED4::off();
      delay(200);
    }

    LED1::on();
    LED2::on();
    LED3::on();
    LED4::on();
    delay(200);
    LED1::off();
    LED2::off();
    LED3::off();
    LED4::off();
    delay(200);

    // автозапирание закончилось
  }
  else {
    Serial.println("WRONG");
    for (int i = 0; i < 2; i++) {
      LED1::on();
      LED2::on();
      LED3::on();
      LED4::on();
      delay(200);
      LED1::off();
      LED2::off();
      LED3::off();
      LED4::off();
      delay(200);
    }
    
  
  }
  
              
}