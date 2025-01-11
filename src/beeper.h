#include "pitches.h"

template<int pin>
class Beeper {
    public:
        Beeper() = delete;
        
        static void init() {
            pinMode(pin, OUTPUT);
        }
        
        static void on() {
            digitalWrite(pin, HIGH);         
        }

        static void off() {
            digitalWrite(pin, LOW);         
        }

        // сделать метод на случай если звук бипера прерывается или наоборот не останавливается
        
        static void play(int Hertz) {
            // используем без третьего параметра, ибо это пригодится ещё
            // (третий параметр позволяет использовать tone без прерывания выполнения программы)
            tone(pin, Hertz);
        }

        static void playForMs(int Hertz, int ms) {
            // тут уже с третьим параметром
            tone(pin, Hertz, ms);
        }

        //метод для переключения состояния условиями
        static void switchCondition(int status) {
            if (status == 0) { Beeper::off(); }
            else if (status == 1) { Beeper::on(); }
            else { return; }
        }
    private:
        
};

