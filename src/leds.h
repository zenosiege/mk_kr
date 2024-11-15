template<int pin>
class LED {
    public:
        LED() = delete;
        
        static void init() {
            pinMode(pin, OUTPUT);
        }
        
        static void on() {
            digitalWrite(pin, HIGH);         
        }

        static void off() {
            digitalWrite(pin, LOW);         
        }

        static void blink(int time_msec) {
            digitalWrite(pin, HIGH); 
            delay(time_msec);
            digitalWrite(pin, LOW); 
        }

        //метод для переключения состояния условиями
        static void switchCondition(int status) {
            if (status == 0) { LED::off(); }
            else if (status == 1) { LED::on(); }
            else { return; }
        }
    private:
        
};