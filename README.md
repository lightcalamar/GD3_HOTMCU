# GD3_HOTMCU
Pantallas FT8xx compradas en http://HotMCU.com

Resolución 800 x 480 pixels

# PINOUT con Arduino MEGA
MISO = 50

MOSI = 51

SCLK = 52

CS   = 53

PD   =  7

INT  = None conection

Si usa Arduino UNO r3, modifique el PINOUT correspondiente. 

Modificar pin CS /transports/wiring.h

Modificar MISO, MOSI, SCLK y PD gd3.cpp
