#include <EEPROM.h>
#include <SPI.h>
#include <GD3.h>

//http://gameduino2.proboards.com/thread/226/slider

float xReloj = 600, yReloj =400, yValor;

void setup() {
 Serial.begin(9600);
 GD.begin();
  espera();
 GD.cmd_loadimage(0, 0);
 GD.load("Fn1.jpg");  //si lo carga XD  800x480
}

void loop() {
  GD.Clear();
   GD.Begin(BITMAPS);  
   GD.Vertex2ii(0, 0); 
  GD.get_inputs();  

  if(xReloj>=850){xReloj=-150;}

//Draw clock
//  GD.ColorRGB(0x0000ff);  //color de las manecillas, sino se selecciona se dibujan en color blanco
 GD.cmd_bgcolor(0xff0000); //color de fondo
 GD.cmd_clock(xReloj,yReloj-yValor,50,OPT_FLAT,12,33,45,0);

  xReloj = xReloj+4;

 GD.ColorA(100);  
  sliderH();
  sliderV();
 GD.ColorA(255);  
   
  GD.swap();
}
