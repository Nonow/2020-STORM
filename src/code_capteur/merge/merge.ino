#include <Password.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

// LCD
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)


// keypad
Password password = Password( "2456" );
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8,9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char keypressed;

void setup(){
  // keypad
  Serial.begin(9600);
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
  lcd.begin(16,2);
  lcd.clear();

}

void loop(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Alarm will be");
  // keypad
  keypressed = keypad.getKey();
    // just print the pressed key
  if (keypressed =='1'){
  lcd.setCursor(0,1);
  lcd.print("test");
  Serial.println(key);
  }
  //keypad.getKey();
}


void keypadEvent (KeypadEvent pass){
  switch (keypad.getState()){
   case PRESSED:
     //Serial.print("Pressed: ");
     //Serial.println(pass);
     switch (pass){
       case '*': guessPassword(); break;
       case '#': password.reset(); break;
        default:
              password.append(pass);
    }
 }
}

void guessPassword(){
     if (password.evaluate()){
                Serial.print("code bon");
     }else{
           Serial.print("faux");
           password.reset();
     }
}
