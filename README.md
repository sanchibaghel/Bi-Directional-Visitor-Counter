# Bi-Directional-Visitor-Counter
Bi-Directional Visitor Counter can be used for number of people entering a room

Components required:
    8051 Microcontroller
    IR sensors x2
    Keil uVision
    Proteus (for simulation) { Can use IR sensors and microcontroller in the same application}
    LCD Screen 16x2

You need to have Keil uVision and Proteus for this project
I have provided a keil file which will be used in Proteus.

For less complexity in the circuit, i have given only one IR sensor and other with a button which works same as ir sensor

This project basically counts the people walking in and out of a room, which has this device on the doors.
  +1 if first ir sensors trigger and then the second one
  -1 if second triggers initially and then the first one.

Keil uVision is used to create HEX file of the C code which will be used in Proteus

Also we can push the hex file if a hardware is made.
