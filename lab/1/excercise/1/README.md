<h1>TP1</h1>
<strong>Exercice 1</strong>

Without a microcontroller

<img src="without_microcontroller.jpg" alt="without_microcontroller">

With a microcontroller
    input: variable resistance
    output: with PWM signal

<img src="with_microcontroller.jpg" alt="with_microcontroller">

code :
<pre>
int led = 1;

void setup() {
    pinMode(led, OUTPUT);
}

void loop() {
      digitalWrite(led,HIGH);
      delay(1000);
      digitalWrite(led,LOW);
      delay(1000);
}
</pre>
What are the differences? Which one is more efficient?

Avec le microcontrolleur nous pouvons appliquer du code et donc avoir plus de fonctionnalités(on, off, low, high) sur la led.
