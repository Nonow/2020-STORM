/*
 * Author: Elecrow Keen
 * Date:4/21/2017
 * IDE V1.8.2 
 * Email:keen@elecrow.com
 * Function:
 */
 const int motorIn1 = 9;  //attach to one of the pin of the motor
const int motorIn2 = 10;  //attach to another pin of the motor
const int flame_sensor =A0;
const int Buzzer=5; 
const int LED = 4;  
void setup(){
  pinMode(Buzzer,OUTPUT); 
  pinMode(LED,OUTPUT); 
  pinMode(motorIn1,OUTPUT);  //initialize the motorIn1 pin as output 
  pinMode(motorIn2,OUTPUT);  //initialize the motorIn2 pin as output 
  Serial.begin(9600);
}
void loop(){
  int val;
  val=analogRead(flame_sensor);
  Serial.println(val,DEC);
  // According to the serial data to adjust.
  while(val<50){
    digitalWrite(Buzzer,HIGH); 
    clockwise(200);  //rotate clockwise 
    digitalWrite(LED,HIGH);
    delay(300);
    digitalWrite(LED,LOW);
    delay(300);
    val=analogRead(0);   
    Serial.println(val,DEC);
  }
  digitalWrite(Buzzer,LOW); 
  digitalWrite(LED,LOW);
  clockwise(0);  // to stop rotate  
  
}
void clockwise(int Speed)
{
  analogWrite(motorIn1,Speed);  //set the speed of motor
  analogWrite(motorIn2,0);  //stop the motorIn2 pin of motor
}

