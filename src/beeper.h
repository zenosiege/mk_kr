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

        // по сути плеер, костяк всего бипера
        // p.s. как-то заставить работать
        static void playSomething (int melody[], int tempo) {
            
            Serial.println(melody[0]);
            // there are two values per note (pitch and duration), so for each note there are four bytes
            int notes = sizeof(melody) / sizeof(melody[0]) / 2;

            // this calculates the duration of a whole note in ms
            int wholenote = (60000 * 4) / tempo;

            int divider = 0, noteDuration = 0;

            for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

                // calculates the duration of each note
                divider = melody[thisNote + 1];
                if (divider > 0) {
                // regular note, just proceed
                noteDuration = (wholenote) / divider;
                } else if (divider < 0) {
                // dotted notes are represented with negative durations!!
                noteDuration = (wholenote) / abs(divider);
                noteDuration *= 1.5; // increases the duration in half for dotted notes
                }

                // we only play the note for 90% of the duration, leaving 10% as a pause
                tone(pin, melody[thisNote], noteDuration * 0.9);

                // Wait for the specief duration before playing the next note.
                delay(noteDuration);

                // stop the waveform generation before the next note.
                noTone(pin);
  
            }
        }

        static void okayBeep() {
            
        }
        static void TakeOnMeAHA() {
            int melody[] = {

                // Take on me, by A-ha
                // Score available at https://musescore.com/user/27103612/scores/4834399
                // Arranged by Edward Truong

                NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
                REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
                NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
                REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
                NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
                
                REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
                NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
                REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
                NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
                REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
                
                NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
                REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
                
                };

                

            Beeper::playSomething(melody, 180);
        }

        static void SonicGreenHillZone() {
            int melody[] = {

            // Gren Hill Zone - Sonic the Hedgehog
            // Score available at https://musescore.com/user/248346/scores/461661
            // Theme by Masato Nakamura, arranged by Teddy Mason
            
            REST,2, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //1
            NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
            REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
            NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
            REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
            NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

            REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8, //7
            NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,2,
            REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
            NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
            REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
            NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

            REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //13
            NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
            REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8,
            NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8,
            NOTE_E4,-1,
            REST,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,-1,

            REST,8, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8, NOTE_F4,-1, //20
            REST,8, NOTE_D4,8, NOTE_F4,8, NOTE_E4,-1, //end 1

            //repeats from 1

            REST,2, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //1
            NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
            REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
            NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
            REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
            NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

            REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8, //7
            NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,2,
            REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
            NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
            REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
            NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

            REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //13
            NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
            REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8,
            NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8,
            NOTE_E4,-1,
            REST,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,-1,

            REST,8, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8, NOTE_F4,-1, //20
            REST,8, NOTE_D4,8, NOTE_F4,8, NOTE_E4,8, //end 2
            NOTE_E4,-2, NOTE_A4,8, NOTE_CS5,8, 
            NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8, NOTE_A5,-4,

            };
            

            Beeper::playSomething(melody, 160);
        }
        //метод для переключения состояния условиями
        static void switchCondition(int status) {
            if (status == 0) { Beeper::off(); }
            else if (status == 1) { Beeper::on(); }
            else { return; }
        }
    private:
        
};

