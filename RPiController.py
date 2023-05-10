#!/usr/bin/env python3
import serial
import time

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    ser.reset_input_buffer()

    led_state = 0

    while True:
        number = ser.read()
        if number != b'':
            if int.from_bytes(number, byteorder='big') == 18:
                led_state = (led_state + 1) % 3
                print('Button has been pressed')
                print('Sending number ' + str(led_state) + ' to Arduino')
                ser.write(str(led_state).encode('utf-8'))
