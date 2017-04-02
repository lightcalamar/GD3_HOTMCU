#include "arm_math.h" 
//#include <EEPROM.h> 
#include <SPI.h>
#include <GD3.h>

long prevmillis;
long currmillis;
long intervalo;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;

int color; // stores the plasma value as integer value in range: 0-255
float32_t timeAnim=0.0f;
float32_t factorx, sqx, sqy,  sumxy, sumsqxy, sqrtsums, sin1, sin2, sin3, sin4; //needed for precalculate values
float32_t inv16 = 1.0f / 64.0f; //avoids doing division, I think this add up a small speedup
float32_t inv32 = 1.0f / 128.0f; //avoids doing division, I think this add up a small speedup
float32_t inv8= 1.0f / 32.0f; //avoids doing division, I think this add up a small speedup
float32_t inv7 = 1.0f / 28.0f; //avoids doing division, I think this add up a small speedup
float32_t x,y;//to traslate x, y integer values to float
 
  //global variable for store string length
  //const int TEXT_INITIAL_POS = SCREEN_WIDTH;
  const int TEXT_INITIAL_POS = 1400;
  int pos=TEXT_INITIAL_POS;
int flyerLength;
char flyerText[] = "Efecto de Plasma utilizando librerías U8g2 y CMSIS-DSP en la placa Teensy 3.5";

uint frms=0, frmsT; //used to count rendered frames, useful for benchmarking and alternate rendered objects;

void setup()
{
  GD.begin();
  GD.cmd_setrotate(0);
}

void draw(void)
{
  GD.Begin(POINTS);
 
  for(float32_t y = 0; y < SCREEN_HEIGHT; y+=32.0)//speed up by drawing interlaced half width screen
    for(float32_t x = 0; x < SCREEN_WIDTH; x+=32.0) //speed up by drawing interlaced half width screen
    {
      arm_sqrt_f32((x*x+y*y+timeAnim+1), &sqrtsums);
      color=int(128.0 + (128.0 * arm_sin_f32((x+timeAnim) * inv32)) +
                128.0 + (128.0 * arm_sin_f32((y-timeAnim) * inv8))  + 
                128.0 + (128.0 * arm_sin_f32((x+y+timeAnim) * inv16)) +
                128.0 + (128.0 * arm_sin_f32(sqrtsums * inv7)) )>>2; 
       GD.ColorRGB(color+color*256);
      //if ( (color > 120) && (color < 136))u8g2.drawPixel(x, y);
      GD.PointSize(color);
      GD.Vertex2ii((int)x,(int)y);
     frms=frms+1; 
  }
  
}

void loop()
{
    timeAnim+=2.1f;
     GD.ClearColorRGB(0x40205c);
     GD.Clear();
     draw();
     frmsT=frms;
     frms=0;
     GD.cmd_number(700, 50, 28, OPT_RIGHTX | OPT_SIGNED, frmsT); 
     
     GD.Begin(POINTS);
     //GD.ColorRGB(0xff8000);
     //GD.PointSize(color>>1);
     //GD.Vertex2ii(  400,240);
     GD.ColorRGB(0xff8030);
    GD.cmd_text(pos, GD.h / 2, 31, OPT_CENTER, "Animacion de Fondo con Circulos de Plasma");


    
      GD.swap();
    pos-=4;
    if (pos < -400) pos=TEXT_INITIAL_POS;
}
