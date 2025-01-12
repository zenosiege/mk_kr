class LED {
    public:
        LED(int pin_C) {
            pin = pin_C;
        }

        LED() = delete;
        
        void init() {
            pinMode(pin, OUTPUT);
        }
        
        void on() {
            digitalWrite(pin, HIGH);         
        }

        void off() {
            digitalWrite(pin, LOW);         
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