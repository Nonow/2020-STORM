/*
 * Author: Elecrow Engle
 * Date:7/21/2017
 * IDE V1.8.2 
 * Email:engle@elecrow.com
 * Function:
 */
void setup(){
  Serial.begin(9600);
}

void loop(){ 
  Serial.print("Moisture Sensor Value:");
  Serial.println(analogRead(A0));  
  delay(100);
}
