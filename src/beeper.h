
class Beeper {
    public:
        Beeper(int pin_C) {
            pin = pin_C;
        }

        Beeper() = delete;
        
        void init() {
            pinMode(pin, OUTPUT);
        }

        // Пояснение - int Alarmed нужна, чтобы звук бипера не прерывал сигнализацию.
        // Конечно, никто не мешает поставить отдельный бипер под это дело, 
        // но вдруг конструкционные особенности не позволят.
        void silence(int Alarmed) {
            if (Alarmed == 0) {
                noTone(pin);      
            }
        }
        
        void play(int Hertz, int Alarmed) {
            // используем без третьего параметра, ибо это пригодится ещё
            // (третий параметр позволяет использовать tone без прерывания выполнения программы)
            if (Alarmed == 0) {
                tone(pin, Hertz);
            }
            else {};
        }

        void playForMs(int Hertz, int ms, int Alarmed) {
            // тут уже с третьим параметром
            if (Alarmed == 0) {
                tone(pin, Hertz, ms);
            }
            else {};
        }

        void alarmPlay() {
                tone(pin, 3136, 86400000);
        }

        
    private:
        int pin;
        
};

