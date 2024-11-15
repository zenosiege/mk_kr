template<int pin, char symbol>
class BUTTON {

    public:
        Button() = delete;
        
        static void init() {
            pinMode(pin, INPUT_PULLUP);
        }
        
        static char getSymbol() {
            return symbol;
        }

        static char getPin() {
            return pin;
        }

        //у Ардуино странная логика - отжатая кнопка возвращается "1", а нажатая "0"
        //этот метод инвертирует эту логику
        static int statusCheck() {
            if (digitalRead(pin) == 1) {
                return 0;
            }
            else { 
                return 1;
            }         
        }
    private:
        
};

