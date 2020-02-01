/*
 * Author: Elecrow Engle
 * Date:7/21/2017
 * IDE V1.8.2 
 * Email:engle@elecrow.com
 * Function:
 */

int a;
void setup(){
  Serial.begin(9600);

  
}

void loop()
{
   a = analogRead(A1);
  Serial.println(a);
  delay(200);
}

