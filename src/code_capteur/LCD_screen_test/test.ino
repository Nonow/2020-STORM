#include <LiquidCrystal.h>

    LiquidCrystal lcd(A0, A1, A2, A3, A4, A5); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)
    void setup() {
      lcd.begin(16,2);

    }
    void loop() {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Alarm will be");
        lcd.setCursor(0,1);
        lcd.print("activated in");
      }
    
