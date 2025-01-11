class BUTTON {
    public:
        BUTTON (int pin_C, char symbol_C) {
            pin = pin_C;
            symbol = symbol_C;
        }

        BUTTON() = delete;
        
        void init() {
            pinMode(pin, INPUT_PULLUP);
        }
        
        char getSymbol() {
            return symbol;
        }

        char getPin() {
            return pin;
        }

        //у Ардуино странная логика - отжатая кнопка возвращается "1", а нажатая "0"
        //этот метод инвертирует эту логику
        int statusCheck() {
            if (digitalRead(pin) == 1) {
                return 0;
            }
            else { 
                return 1;
            }         
        }
    private:
        int pin;
        char symbol;
        
};

