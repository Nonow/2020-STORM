
Buzzer frequency
<img src="Sketch1.png" alt="Sketch_buzzer">
<img src="schematic1.png" alt="schematic_buzzer">
<img src="buzzer.jpg" alt="buzzer">

code :
<pre>
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
</pre>


LDR :

Sketch LDR :
<img src="Sketch2.png" alt="Sketch">

Schematic LDR :
<img src="schematic2.png" alt="schematic">

Ici nous avons une LDR avec une faible resistance donc notre led reste allumé.
<img src="low_ldr.jpg" alt="low resistance">




Avec un flash sur notre LDR notre led s'éteint.
<img src="high_ldr.jpg" alt="high resistance">



Code :
<pre>
int sensorPin = A0; // select the input pin for LDR

int sensorValue = 0; // variable to store the value coming from the sensor

void setup() {
Serial.begin(9600); //sets serial port for communication
}
void loop() {
sensorValue = analogRead(sensorPin); // read the value from the sensor
Serial.println(sensorValue); //prints the values coming from the sensor on the screen

delay(100);

}
</pre>

Image plot :
<img src="plot.png" alt="plot">

