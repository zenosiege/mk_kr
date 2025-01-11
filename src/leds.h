class LED {
    public:
        LED() {
            //Конструктор по умолчанию, требуется для создания массива
        }

        LED(int pin_C) {
            pin = pin_C;
        }
        
        
        void init() {
            pinMode(pin, OUTPUT);
        }
        
        void on() {
            digitalWrite(pin, HIGH);         
        }

        void off() {
            digitalWrite(pin, LOW);         
        }

        void blink(int time_msec) {
            digitalWrite(pin, HIGH); 
            delay(time_msec);
            digitalWrite(pin, LOW); 
        }

        //метод для переключения состояния условиями
        void switchCondition(int status) {
            if (status == 0) { off(); }
            else if (status == 1) { on(); }
            else { return; }
        }
    private:
        int pin;
};

void everyLED_On (LED* LEDarray, int numLED) {
    for (int i = 0; i < numLED; i++) {
        LEDarray[i].on();
    }
}

void everyLED_Off (LED* LEDarray, int numLED) {
    for (int i = 0; i < numLED; i++) {
        LEDarray[i].off();
    }
}