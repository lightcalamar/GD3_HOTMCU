#include <EEPROM.h> 
#include <SPI.h>
#include <GD3.h>

void setup()
{
  GD.begin();
  GD.cmd_setrotate(0);
}

void loop()
{
  GD.ClearColorRGB(0x000020);
  GD.Clear();
  GD.cmd_text(0, 0, 24, 0, "Pantalla FT811");
  GD.cmd_button(625, 40, 150, 50, 29, 0, "Boton");
  GD.cmd_romfont(67, 34);    // Usando RON FONT NUMBER 34
  GD.cmd_text(GD.w / 2, GD.h / 2, 67, OPT_CENTER, "Hello world");
  // GD.cmd_text(GD.w / 2, GD.h / 2, 31, OPT_CENTER, "Hello world");
  GD.VertexTranslateX(16*460);
  //GD.VertexTranslateY(16*160);
  GD.cmd_text(245, 450, 24, 0, "800x600");
  GD.swap();
}
