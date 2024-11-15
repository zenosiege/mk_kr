template<int pin>
class BUTTON {
    public:
        Button() = delete;
        
        static void init() {
            pinMode(pin, INPUT_PULLUP);
        }
        

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