#include "buttons.h"
#include "leds.h"
#include "code_manipul.h"
#include "beeper.h"
#include "SoftServo.h"

constexpr char CODE[4] {'1', '3', '5', '4'};

//отдельно выведем список пинов, это потребуется, если контакты заменяются на другие
constexpr unsigned int bPin[5] {6, 7, 8, 10, 12};

//отдельно список символов, сответственно привязанных к кнопкам
constexpr char bSymbol[5] {'1', '2', '3', '4', '5'};

LED Builtin_LED(13);

//кнопка - какой контакт + за ввод какого символа отвечает
BUTTON Button1(bPin[0], bSymbol[0]);
BUTTON Button2(bPin[1], bSymbol[1]);
BUTTON Button3(bPin[2], bSymbol[2]);
BUTTON Button4(bPin[3], bSymbol[3]);
BUTTON Button5(bPin[4], bSymbol[4]);

LED LED1(2);
LED LED2(3);
LED LED3(4);
LED LED4(5);

using Beeper1 = Beeper<11>;

// переменные сигнализации. Да, глобальная, но иначе в loop она будет сбрасываться
int alarmStatus = 0; // статус 
int alarmAttempts = 3; // сколько попыток осталось

//починить серво, переписать код
SoftServo myservo;

// НЕ ЗАБЫВАЙ НОВЫЕ ОБЪЕКТЫ INIT-ИТЬ
void setup() {
  Builtin_LED.init();

  Button1.init();
  Button2.init();
  Button3.init();
  Button4.init();
  Button5.init();

  LED1.init();
  LED2.init();
  LED3.init();
  LED4.init();

  Beeper1::init();

  myservo.attach(9);
  
  myservo.delayMode();


  Serial.begin(115200);
}

void loop() {

  char inputCode[4] = {};
  myservo.write(100);
  
  // Ардуино будет ожидать, когда пользователь нажмёт ЧТО-ТО из кнопок
  // нужен механизм, отслеживающий конкретную кнопку
  // с превентивным механизмом, чтобы предыдущий ввод случайно не засчитался (сделано)

  // Массив объектов класса светодиодов, чтобы их поочередно включать
  const int nLeds = 4; //сколько светодиодов используется. Для удобства
  LED ledArray[nLeds] = {LED1, LED2, LED3, LED4}; 

  // Набор кода

  for (int i = 0; i < 4; i++) {
    inputCode[i] = codeCharSelect(bPin, bSymbol, 5);
    ledArray[i].on();
  }
  
  //
  everyLED_Off(ledArray, nLeds);
  delay(500);

  
  if (codeVerify(CODE, inputCode, 4) == 1) {

    // СЦЕНАРИЙ, ЕСЛИ КОД ВВЕДЁН ПРАВИЛЬНО

    // сброс попыток до трёх обратно
    alarmAttempts = 3;
    // сброс сигнализации
    alarmStatus = 0;

    Serial.println("Right!!");

    everyLED_On(ledArray, nLeds);
    delay(200);
    everyLED_Off(ledArray, nLeds);
    delay(400);
    
    myservo.write(90);

    //ожидание нажатия любой кнопки для закрытия
    int awaitingInput1 = awaitForInput(bPin, 5);

    //запирание
    everyLED_On(ledArray, nLeds);
    delay(200);
    everyLED_Off(ledArray, nLeds);
    delay(200);
    myservo.write(0);
    //запирание закончилось

  }
  else {

    // СЦЕНАРИЙ, ЕСЛИ КОД БЫЛ ВВЕДЁН НЕВЕРНО

    // Вычитает попытку
    alarmAttempts -= 1;

    // Проверяет, если попытки кончились. В случае, если "да", то включает сигнализацию.
    if (alarmAttempts <= 0) {
      alarmStatus = 1;
    }

    Serial.println("WRONG");
    for (int i = 0; i < 2; i++) {
      everyLED_On(ledArray, nLeds);
      delay(200);
      everyLED_Off(ledArray, nLeds);
      delay(200);
    }
    
    
  
  }
  
              
}