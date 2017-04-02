//#include <EEPROM.h> 
#include <SPI.h>
#include <GD3.h>

//http://educ8s.tv/esp8266-vs-arduino/

//#define ITERATIONS 50000000L    // number of iterations
//#define ITERATIONS 4400000L    // number of iterations
#define ITERATIONS 1000000L    // number of iterations
//#define ITERATIONS 2500000L    // number of iterations
//#define ITERATIONS 500000L    // number of iterations

//float ITERATIONS = 500000;
//float ITERATIONS = 1000000;

unsigned long Tiempo;
float PiCalc;

int iteracion=0, limite=2;
static unsigned int Dato;

void setup(void) {
 GD.begin();
  GD.cmd_setrotate(0);
  
  Serial.begin(115200);
  
  startCalculation();
  Serial.print("# of trials = "); Serial.println(ITERATIONS);
  Serial.print("Estimate of pi = ");
   String piString = String(PiCalc,7); Serial.println(piString);
  Serial.print("Time: "); Serial.print(Tiempo); Serial.println(" ms"); Serial.println();

 

  Estimacion();
}

void loop() {}

void MP() {
  while(1){
  GD.ClearColorRGB(0x000020);
  GD.Clear();

  MHzMCUGD3();

  GD.cmd_text(0, 0, 31, 0, "Iter:");
  //GD.cmd_number(300,2,31,0,ITERATIONS);
  //plotfloat(300, 2, ITERATIONS, 1, 31);
  GD.printNfloat(300, 2, ITERATIONS, 0, 31);

  GD.cmd_text(0, 50, 31, 0, "Pi:");
  GD.printNfloat(155, 52, PiCalc, 7, 31);

  GD.cmd_text(0, 100, 31, 0, "                     ms");
  GD.printNfloat(205, 102, Tiempo, 0, 31);
  
  GD.swap();  }
}

void startCalculation()
{
 unsigned long start, time;
 float x = 1.0, pi=1.0;
 start = millis();  
 for (unsigned long i = 2; i <= ITERATIONS; i++) {
   x *= -1.0;
   pi += x / (2.0f*(float)i-1.0f);   
 }
 time = millis() - start;
 pi = pi * 4.0;

 Tiempo = time; PiCalc = pi;
}
