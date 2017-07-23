Following the pinout here:
https://geekhack.org/index.php?topic=84750.0

o -> contacts
The male PS2 plug:
   Clock 5 o  ||  o 6
    GND 3 o   ||   o 4 VCC +5V
     Data 1 o    o 2

This is the female plug (just for reference, we don't use it):
         6 o  ||  o 5 Clock
VCC +5V 4 o   ||   o 3 GND
          2 o    o 1 Data

black:    vcc      VCC
red:      clock    PD1
yellow:   data     PD0
white:    ground   GND

Connect Wires

Connect Vcc and GND.
Connect Clock and Data line.
*****
Interrupt: Clock is on PD1 and Data on PD0.(Recommended. Soarer's converter compatible)
*****
Busywait: Clock is on PD1 and Data on PD0.
USART: Clock is on PD5 and Data on PD2.
You need pull-up resistors. 1K-10K Ohm would be fine.
To change pin configuration edit config.h and Makefile.
