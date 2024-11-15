//перенёс сюда этот метод из buttons.h, потому что если здесь прописать #include, то будет переопределение, на что ругается компилятор
int awaitForInput(const unsigned int pinArray[], unsigned int size) {
    
    int fixedPin = 123456; // невозможное число контакта, переменная для фиксации нажатого контакта
    int fixedArrayVal = 123456; // служебная переменная для передачи порядка контакта в массиве
    

    int awaitQuit = 0; // переменная для выхода из ожидания
    int preventRepeat = 0; // переменная для предотвращения (превентирования?) повторного засчитываения
    
  
    while (awaitQuit != 1) {
       
        for (int i = 0; i < size; i++) {
           
            if (digitalRead(pinArray[i]) == 0) {
                fixedArrayVal = i;
                fixedPin = pinArray[i];
                awaitQuit = 1;
                break;

            }
            

        }
        delay(50);

    }
   
    delay(50);

    // а вот и превентивный механизм
    // нажатие засчитается ПОСЛЕ отжатой кнопки
    while (preventRepeat != 1) {
        if (digitalRead(fixedPin) == 1) {
            preventRepeat = 1;
        }
    }

    //создаём массив из номера контакта и его порядкового номера
    
    
    return fixedArrayVal;
}

//смотрит какой символ отдать в зависимости от нажатой кнопки
int codeCharSelect(const unsigned int pins[], const char symbols[], int size) {
    //решить проблему с нединамическим switch case можно, если знать, какой по порядку контакт был нажат
   char selected = symbols[awaitForInput(pins, size)];  
   Serial.println(selected);

   return selected;
}

//сверяет последовательность цифр заданной с той, что была введена пользователем
int codeVerify(const char trueCode[], char codeToBeChecked[], int codeSize) {
    int passValue = 1;

    for (int i = 0; i < codeSize; i++) {
        if (trueCode[i] != codeToBeChecked[i]) {
            passValue = 0;
        }
    }

    return passValue;

}