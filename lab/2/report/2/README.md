
Buzzer frequency
<img src="buzzer.jpg" alt="buzzer">

code :

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



LDR :

Sketch LDR :
<img src="Sketch2.png" alt="Sketch">

Schematic LDR :
<img src="schematic2.png" alt="schematic">


<img src="low_ldr.jpg" alt="low resistance">
Ici nous avons une LDR sans lumière à proximité donc notre led reste allumé.




<img src="high_ldr.jpg" alt="high resistance">
Avec un flash sur notre LDR(resis <=300) notre led s'éteint.


Code :

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

<img src="plot.png" alt="plot">
Nous avons pas réussi à lire les données arduino sur python (matplotlib).
