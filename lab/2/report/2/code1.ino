int buzzer =8;
int nb=0;
void setup() {
pinMode(buzzer, OUTPUT);
Serial.begin(9600);
}
void loop() {
if(Serial.available()){
     nb = Serial.parseInt();
     tone(buzzer,nb,2000);
     Serial.println("frequency = ");
     Serial.print(nb);

   }
}
