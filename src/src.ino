#include "buttons.h"
#include "leds.h"
#include "code_manipul.h"
#include "beeper.h"
#include "SoftServo.h"
#include "pitches.h"

constexpr char CODE[4] {'1', '3', '5', '4'};
constexpr int ALARM_INPUT_DELAY {15 * 1000}; //нужное количество секунд * 1 секунда в микросекундах

//кнопка - какой контакт + за ввод какого символа отвечает
BUTTON Button1(6, '1');
BUTTON Button2(7, '2');
BUTTON Button3(8, '3');
BUTTON Button4(10, '4');
BUTTON Button5(12, '5');

//светодиоды
LED LED1(2);
LED LED2(3);
LED LED3(4);
LED LED4(5);

//бипер
Beeper Beeper1(11);

// переменные сигнализации. Да, глобальная, но иначе в loop она будет сбрасываться
int alarmStatus = 0; // статус 
int alarmAttempts = 3; // сколько попыток осталось

SoftServo myservo;

void setup() {

  Button1.init();
  Button2.init();
  Button3.init();
  Button4.init();
  Button5.init();

  LED1.init();
  LED2.init();
  LED3.init();
  LED4.init();

  Beeper1.init();

  myservo.attach(9);
  
  myservo.delayMode(); // сервопривод в режиме задержек, в asyncMode работа может быть нестабильной
  

  Serial.begin(115200);
}

void loop() {
  
  
  char inputCode[4] = {};
  myservo.setDegree(180); 
  
  // Ардуино будет ожидать, когда пользователь нажмёт ЧТО-ТО из кнопок
  // нужен механизм, отслеживающий конкретную кнопку
  // с превентивным механизмом, чтобы предыдущий ввод случайно не засчитался (сделано)

  // Массив объектов класса светодиодов, чтобы их поочередно включать
  const int nLeds = 4; //сколько светодиодов используется. Для удобства
  LED ledArray[nLeds] = {LED1, LED2, LED3, LED4}; 

  // Массив объектов класса кнопок, чтобы их передать в методы code_manipul.h
  const int nButtons = 5; //сколько кнопок используется. Для удобства
  BUTTON buttonArray[nButtons] = {Button1, Button2, Button3, Button4, Button5}; 

  // Включение звуковой сигнализации, если она сработала
  if (alarmStatus == 1) {
      Beeper1.alarmPlay();
      delay(ALARM_INPUT_DELAY); 
  }

  // Набор кода 
  
  for (int i = 0; i < 4; i++) {
    inputCode[i] = codeCharSelect(buttonArray, 5);
    ledArray[i].on();
    Beeper1.playForMs(NOTE_C7, 100, alarmStatus);
  }

  
  if (codeVerify(CODE, inputCode, 4) == 1) {

    // СЦЕНАРИЙ, ЕСЛИ КОД ВВЕДЁН ПРАВИЛЬНО
    
   
    // сброс попыток до трёх обратно
    alarmAttempts = 3;
    // сброс сигнализации
    alarmStatus = 0;

    Beeper1.silence(alarmStatus);

    Serial.println("Right!!");

    myservo.setDegree(90); //отпирание
    
    everyLED_On(ledArray, nLeds);
    Beeper1.play(NOTE_F7, alarmStatus);
    delay(200);
    Beeper1.silence(alarmStatus);

    

    //ожидание нажатия любой кнопки для закрытия
    int awaitingInput1 = awaitForInput(buttonArray, 5);
    Beeper1.playForMs(NOTE_A6, 200, alarmStatus);
    
    //запирание
    myservo.setDegree(180);
    everyLED_Off(ledArray, nLeds);
    //запирание закончилось

  }
  else {

    // СЦЕНАРИЙ, ЕСЛИ КОД БЫЛ ВВЕДЁН НЕВЕРНО

    
    Serial.println("WRONG");
    for (int i = 0; i < 2; i++) {
      everyLED_On(ledArray, nLeds);
      Beeper1.play(NOTE_C6, alarmStatus);
      delay(200);

      everyLED_Off(ledArray, nLeds);
      Beeper1.silence(alarmStatus);
      delay(200);
    }
    
    // Вычитает попытку
    alarmAttempts -= 1;

    // Проверяет, если попытки кончились. В случае, если "да", то включает сигнализацию.
    if (alarmAttempts <= 0) {
      alarmStatus = 1;
    }

  
  }
  
              
}