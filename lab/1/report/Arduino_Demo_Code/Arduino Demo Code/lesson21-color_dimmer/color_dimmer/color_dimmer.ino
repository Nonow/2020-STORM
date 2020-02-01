/*
 * Author: Elecrow Engle
 * Date:7/12/2017
 * IDE V1.8.2 
 * Email:engle@elecrow.com
 * Function:
 */
int redPin = 9;                // R – digital 9    
int greenPin = 10;             // G – digital 10
int bluePin = 11;              // B – digital 11
int potRedPin = 0;             // potentiometer1 – analog 0
int potGreenPin = 1;           // potentiometer2 – analog 1
int potBluePin = 2;            // potentiometer3 – analog 2

void setup(){
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  Serial.begin(9600);           
}

void loop(){
int potRed = analogRead(potRedPin);     
int potGreen = analogRead(potGreenPin); 
int potBlue = analogRead(potBluePin);  

int val1 = map(potRed,0,1023,0,255);     //By the map() function conversion of 0 ~ 255 value
int val2 = map(potGreen,0,1023,0,255);
int val3 = map(potBlue,0,1023,0,255);

//串口依次输出Red，Green，Blue对应值
Serial.print("Red:");                  
Serial.print(val1);
Serial.print("Green:");
Serial.print(val2);
Serial.print("Blue:");
Serial.println(val3);

colorRGB(val1,val2,val3);      //  RGB LED to present the corresponding color
}

//Be used to display colors
void colorRGB(int red, int green, int blue){     
analogWrite(redPin,constrain(red,0,255));
analogWrite(greenPin,constrain(green,0,255));
analogWrite(bluePin,constrain(blue,0,255));
}
