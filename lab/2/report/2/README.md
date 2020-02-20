<h1>TP2</h1>
<br>
<h4>Buzzer frequency</h4>
<img src="Sketch1.png" alt="Sketch_buzzer">
<img src="schematic1.png" alt="schematic_buzzer">
<img src="buzzer.jpg" alt="buzzer">

<strong>code :</strong>
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

<br>
<strong>LDR </strong>
<br>
<strong>Sketch LDR :</strong>
<img src="Sketch2.png" alt="Sketch">

<strong>Schematic LDR :</strong>
<img src="schematic2.png" alt="schematic">

<p>Ici, nous avons une LDR avec une faible resistance donc notre led reste allumée.</p>
<img src="low_ldr.jpg" alt="low resistance">




<p>Avec un flash sur notre LDR, notre led s'éteint.</p>
<img src="high_ldr.jpg" alt="high resistance">



<strong>Code :</strong>
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
<br>

<strong>Image plot :</strong>
<img src="plot.png" alt="plot">

