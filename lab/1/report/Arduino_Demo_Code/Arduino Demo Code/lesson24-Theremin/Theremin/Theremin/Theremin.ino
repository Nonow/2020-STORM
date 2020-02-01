/*
 * Author: Elecrow Engle
 * Date:7/12/2017
 * IDE V1.8.2 
 * Email:engle@elecrow.com
 * Function:
 */
const int TrigPin = 2;
const int EchoPin = 3;
 int duration;
void setup(){
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

int takeSounding()
{
     digitalWrite(TrigPin, LOW);
     delayMicroseconds(2);
     digitalWrite(TrigPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(TrigPin, LOW);
     int duration = pulseIn(EchoPin,HIGH,3000);
     if(duration >3000) duration=3000;
    int i=map(duration,174,3000,0,14);  //5---52CM
    Serial.println(i);
     switch(i)
     {
        case 0:duration=0;break;
        case 1: duration=262;break;  //DO
        case 2: duration=294;break;  //RE
        case 3: duration=330;break;  //ME
        case 4: duration=349;break;  //FA
        case 5: duration=392;break;  //SO
        case 6: duration=440;break;  //LA
        case 7: duration=494;break;  //SI
        case 8: duration=523;break;  //DO
        case 9: duration=578;break;  //RE
        case 10: duration=659;break; //ME
        case 11: duration=698;break;  //FA
        case 12: duration=784;break;
        case 13: duration=880;break;
        case 14: duration=988;break;
     }
    // return duration;
     tone(8,duration,125);
}
void loop(){
     takeSounding();
    
}

