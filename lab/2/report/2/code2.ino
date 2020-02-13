int led=12;
int ldr=A0;

void setup() {
 Serial.begin (9600);
 pinMode(led, OUTPUT);
 pinMode(ldr, INPUT);
}
void loop() {
 int ldrStatus = analogRead (ldr);

 if(ldrStatus <= 300){
   digitalWrite(led, HIGH);
   Serial.println("ldr ne détecte pas de lumière, on allume la led");
 }
 else {
   digitalWrite (led, LOW);
   Serial.println("ldr détecte de la lumière, on éteint la led");
 }
}
