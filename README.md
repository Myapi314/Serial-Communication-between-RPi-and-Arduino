# Serial-Communication-between-RPi-and-Arduino
A quick introductory program practicing serial communication between a Raspberry Pi 4 and an Arduino Uno using digital inputs and outputs.

## Requirements
This project requires the following hardware:
* Raspberry Pi
* Arduino Uno
* Two LEDs (I used a specific LED from another project I am working on, but the concept is the same)
* One push button
* 10kohm resistor
* Breadboard
* Male-to-male wires

The following software requirements are needed:
* Arduino IDE
* Install pySerial library on raspberry pi
  
  `python3 -m pip install pyserial`

## Configuration
Program the Arduino with the [ArduinoController.ino](ArduinoController.ino) code. This will handle the digital input from the button and the digital output of the LEDs. After programming the Arduino, it can be plugged in via the USB port on the raspberry pi. Run the [RPiController.py](RpiController.py) on the raspberry pi and you should be able to iterate through the 3 states: LED_RED ON, LED_BLUE ON, and ALL LEDs OFF. 

Connections for hardware to Arduino:
* LED_RED is connected to the A2 port
* LED_BLUE is connected to the A3 port
* Push Button is connected to A4 with a 10kohm pull-down resistor

[Demo Video](https://youtu.be/yhgiYZ2MCCU)

## Support and Resources
To build this project I referenced the following resources:
* [Robotics Back-end Raspberry Pi Arduino Serial Communication Tutorial](https://roboticsbackend.com/raspberry-pi-arduino-serial-communication/)
* [Arduino Docs](https://docs.arduino.cc/learn/microcontrollers/analog-input)
