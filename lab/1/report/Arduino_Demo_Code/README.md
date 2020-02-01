# Welcome to Introduction to IoT Lab 1!

## Materials:
### Arduino UNO
[Official Website](https://arduino.cc)

[Online IDE](https://create.arduino.cc/)

[Arduino IDE](https://www.arduino.cc/en/Main/Software)

[PlatformIO](https://platformio.org/)

[Starter Kit User Manual](https://www.elecrow.com/download/Starter%20Kit%20for%20Arduino(user%20manual).pdf) --- [Demo Codes](https://www.elecrow.com/download/Arduino_Demo_Code.zip)

[Language Reference](http://wiring.org.co/reference/) 

#### Device Summary
-   Operating Voltage: 5 Volts
-   Input Voltage: 7 to 20 Volts
-   Digital I/O Pins: 14 (6 provide PWM output)
-   Analog Input Pins: 6
-   DC Current per I/O Pin: 20 mA
-   DC Current for 3.3V Pin: 50 mA
-   Clock Speed: 16 MHz
-   ATmega328P
-   USB connection

Pin definition

![Pin](https://components101.com/sites/default/files/component_pin/Arduino-Uno-Pin-Diagram.png)
### ESP32
[NodeMCU-32S Documentation](https://nodemcu.readthedocs.io/en/dev-esp32/)

[NodeMCU-32S Datasheet](https://wiki.ai-thinker.com/_media/esp32/docs/nodemcu-32s_product_specification.pdf)

[ESP 32](http://esp32.net/)

[Installing ESP32 Add-on in Arduino IDE](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)
#### Device Summary
-   Microcontroller: Tensilica 32-bit Single-/Dual-core CPU Xtensa LX6
-   Operating Voltage: 3.3V  
-   Input Voltage: 7-12V
-   Digital I/O Pins (DIO): 28  
-   Analog Input Pins (ADC): 8
-   Analog Outputs Pins (DAC): 2 
-   UARTs: 3
-   SPIs: 2
-   I2Cs: 3
-   Flash Memory: 4 MB
-   SRAM: 520 KB
-   Clock Speed: 240 Mhz
-   Wi-Fi: IEEE 802.11 b/g/n/e/i:
- Bluetooth v4.2
  
ESP32-NodeMCU-32S pin definition
![ESP32-NodeMCU-32s](http://www.shenzhen2u.com/image/catalog/Module/NodeMCU-32S/nodemcu_32s_pin.png)
![enter image description here](https://docs.zerynth.com/latest/_images/nodemcu_esp32_pin.jpg)


# Report - Deadline=30/10/2019 23:59:59
 Please make a folder(`lab/1/report`) in your team's repository.
 
 1- upload all codes in this folder.
 
 2- Prepare a `README.md` inside and describe the codes(especially new functions like `writeAnalog()` ) and which kind of problem you encountered with.
 
 3- Put the circut's schematics (Connection diagram) inside `README.md` 
 
 - You can search for an online markdown editor or use [StackEdit.io](https://stackedit.io/app) for prettifying your `README.md` file.
 
 # Exercise - Deadline=11/11/2019 23:59:59
 Make a folder(`lab/1/excercise`) in your team's repository and put all your exercises on it . 
 
1- (Folder=`lab/1/excercise/1`) Control a LED Brightness with a variable resistance.
- Without a microcontroller
- With a microcontroller
  - input: variable resistance
  - output: with PWM signal
  
What are the differences?
Which one is more efficient? Explain in `README.md`.
- Take a photo and put it in `README.md`.

2-(Folder=`lab/1/excercise/2`) (Extra-Optional-Bonus) 
  - You can skip it but it has extra point.
  - Do lesson 15.
  - Do [Using Max7219 For 7 Segment](https://thecustomizewindows.com/2017/11/arduino-max-7219-cng-basic-circuit-led-7-segment-displays/)
     - Display the Date(day.month)
     - Take a photo and put it in `README.md`.


3- (Folder=`lab/1/excercise/3`) Do [Using Max7219 For LED Matrix](https://howtomechatronics.com/tutorials/arduino/8x8-led-matrix-max7219-tutorial-scrolling-text-android-control-via-bluetooth/) Until the section *Android App for Controlling 8×8 LED Matrix via Bluetooth*
- Consider that you have only one led matrix
- Use `PlatformIO` for programming Arduino
- Display Your team's name in the display.
- Display a random shape(An emoji or whatever you like)
- Take a photo and put it in `README.md`.

