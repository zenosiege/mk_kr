class BUTTON {
    public:
        BUTTON (int pin_C, char symbol_C) {
            pin = pin_C;
            symbol = symbol_C;
        }

        BUTTON() = delete; //чтобы память не занимал
        
        void init() {
            pinMode(pin, INPUT_PULLUP);
        }
        
        char getSymbol() {
            return symbol;
        }

        int getPin() {
            return pin;
        }

    private:
        int pin;
        char symbol;
        
};

int awaitForInput(BUTTON *butArray, unsigned int size) {
    
    int fixedPin = 123456; // невозможное число контакта, переменная для фиксации нажатого контакта
    int fixedArrayVal = 123456; // служебная переменная для передачи порядка контакта в массиве
    

    int awaitQuit = 0; // переменная для выхода из ожидания
    int preventRepeat = 0; // переменная для предотвращения (превентирования?) повторного засчитываения
    
  
    while (awaitQuit != 1) {
       
        for (int i = 0; i < size; i++) {
           
            if (digitalRead(butArray[i].getPin()) == 1) {
                fixedArrayVal = i;
                fixedPin = butArray[i].getPin();
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
        if (digitalRead(fixedPin) == 0) {
            preventRepeat = 1;
        }
    }


    return fixedArrayVal;
}

//смотрит какой символ отдать в зависимости от нажатой кнопки
char codeCharSelect(BUTTON *butArray, int size) {
   
   char selected = butArray[awaitForInput(butArray, size)].getSymbol();  
   Serial.println(selected);

   return selected;
}
