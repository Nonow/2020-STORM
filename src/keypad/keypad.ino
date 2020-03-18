#include <Password.h>
#include <Keypad.h>


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

void setup(){
  // keypad
  Serial.begin(9600);
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad

}
  
void loop(){
  // keypad
  char key = keypad.getKey();
    // just print the pressed key
   if (key){
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
