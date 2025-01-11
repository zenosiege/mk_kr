
// Можно шаблон бипера не трогать, он никуда не передаётся и конструктор проще получается.
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

        // Пояснение - int Alarmed нужна, чтобы звук бипера не прерывал сигнализацию.
        // Конечно, никто не мешает поставить отдельный бипер под это дело, но вдруг конструкционные особенности не позволят.
        static void silence(int Alarmed) {
            if (Alarmed == 0) {
                noTone(pin);      
            }
        }
        
        static void play(int Hertz, int Alarmed) {
            // используем без третьего параметра, ибо это пригодится ещё
            // (третий параметр позволяет использовать tone без прерывания выполнения программы)
            if (Alarmed == 0) {
                tone(pin, Hertz);
            }
            else {};
        }

        static void playForMs(int Hertz, int ms, int Alarmed) {
            // тут уже с третьим параметром
            if (Alarmed == 0) {
                tone(pin, Hertz, ms);
            }
            else {};
        }

        static void alarmPlay() {
                tone(pin, 3136, 86400000);
        }

        //метод для переключения состояния условиями
        static void switchCondition(int status) {
            if (status == 0) { Beeper::off(); }
            else if (status == 1) { Beeper::on(); }
            else { return; }
        }
    private:
        
};

