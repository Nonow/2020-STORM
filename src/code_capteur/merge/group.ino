#include <Keypad.h>
#include <LiquidCrystal.h>

// LCD
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 

//buzzer
const int buzzer = 10; // arduino pin 10

//ultrason
int trig = 12;
int echo = 11;
long lecture_echo;
long cm;
long distance;
long new_distance;
int j=0;


// keypad
//Password password = Password( "2456" );
String password ="2456";
String pass="";
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

// variable 
boolean alarm=false;
boolean screen_lcd=true;
boolean alarm_on=false; 

void setup(){
  // keypad
  Serial.begin(9600);
  //keypad.addEventListener(keypadEvent); //add an event listener for this keypad
  lcd.begin(16,2); 
  pinMode(buzzer, OUTPUT); // sortie buzzer
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);

}
  
void loop(){
  if(!alarm){
    if(screen_lcd){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ACTIVER ALARME:A");
      screen_lcd=false;
    }
    keypressed = keypad.getKey();
    if(keypressed =='A'){
      //alarm=true;
      Serial.print(100);
    }
  }

  if(alarm){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Alarme active");
    lcd.setCursor(0,1);
    lcd.print("dans ");
    int countdown = 5; // compte à rebour avant alarm_on
    while (countdown != 0) {
      lcd.setCursor(5,1);
      lcd.print(countdown);
      countdown--;
      tone(buzzer, 500, 200);
      delay(1000);
    }
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("ALARME ACTIF");
    distance = Calculdistance();
    alarm = false;
    alarm_on = true;
  }
  
  if (alarm_on){
        new_distance = Calculdistance()+10;
        if(new_distance < distance){
          tone(buzzer, 1000);
            Testpassword();
        }
        if(keypressed){
          tone(buzzer, 1000);
          Testpassword();
        }
  }

}

long Calculdistance(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  lecture_echo = pulseIn(echo,HIGH);
  cm = lecture_echo /58;
  Serial.print("Distance en cm :");
  Serial.println(cm);
  delay(1500);
  return cm;
}


void Testpassword(){
  int i=0;
  pass="";
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("    ALARME !  ");
  lcd.setCursor(0,1);
  lcd.print("MDP:");
  lcd.setCursor(4,1);
  boolean mdp=true;
  while(mdp){
    keypressed = keypad.getKey();
    if (keypressed != NO_KEY){
        if(keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' || keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' || keypressed == '8' || keypressed == '9' ){
          pass += keypressed;
          lcd.print("*");
          i++;
        }
        if(i == 4){
          if(pass == password){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("MDP BON");
            lcd.setCursor(0,1);
            lcd.print("ALARME ETEINT");
            delay(2000);
            mdp=false;
            alarm_on=false;
            screen_lcd=true;
            noTone(buzzer);
          }
          else{
            i=0;
            pass="";
            lcd.setCursor(0,0);
            lcd.print("MDP ERRONE");
            delay(2000);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("    ALARME !  ");
            lcd.setCursor(0,1);
            lcd.print("MDP:");
            lcd.setCursor(4,1);
          }
        }
        else if(keypressed == '#'){
          i=0;
          pass="";
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("    ALARME !  ");
          lcd.setCursor(0,1);
          lcd.print("MDP:");
          lcd.setCursor(4,1);
        }
    }
  }
}
