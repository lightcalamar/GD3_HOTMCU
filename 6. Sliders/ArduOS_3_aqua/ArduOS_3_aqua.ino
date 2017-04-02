//#include <EEPROM.h> 
#include <Wire.h>
#include <SPI.h>
#include <GD3.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DS3231.h>
#include <SFE_BMP180.h>
#include <DHT.h>

#include "pez1.h"  //6 imagenes: ID = 0-5

int BX = GD.random(750), BY=400, BY1=425, Burb=3, BX1= GD.random(750), Burb1=4;
long previousMillisB = 0;
long intervalB = 100; 

#define NBLOBS      128
#define OFFSCREEN   -16384
struct xy {
  int x, y;
} blobs[NBLOBS];

DS3231  RTC(SDA, SCL);

#define ONE_WIRE_BUS 2  // OX PIN DS THERMO
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

#define DHTPIN 5          // pin DHT
//#define DHTTYPE DHT11   // OX PIN 3
#define DHTTYPE DHT22 // OX pin 5
DHT dht(DHTPIN, DHTTYPE);

SFE_BMP180 pressure;
#define ALTITUDE 1025.0

#define PDPin 9
///////INFO//////////////
void Menumain()
{
 while(1) {

GD.wr(REG_PWM_DUTY, 10);//0-128 

float S1;
float S2;
float S3;
float S4;
float S5;
float S6;

///////DHT T,H//////////////
float DHTt = dht.readTemperature();
float DHTh = dht.readHumidity();
///////////////////////////

//////////LDR////////////// 
int sensorValue = analogRead(A2);
float LDR = sensorValue * (1024 / 1024.0);
///////////////////////////
 
////DS T///// 
sensors.requestTemperatures();     
/////////////

////BMP//////
double P,T;
pressure.startPressure(3);
pressure.getPressure(P,T);
/////////////

//////SENSOR DEV//////////
   S1 = dht.readTemperature();
   S2 = dht.readHumidity();
   S3 = analogRead(A2);
   S4 = sensors.getTempCByIndex(0);
   S5 = P+68;
// S6 = 

 
//////WIDGET/////////
GD.cmd_dlstart();
GD.ClearColorRGB(0,0,0);
GD.Clear(1,1,1); 
GD.get_inputs();

GD.SaveContext();
GD.cmd_romfont(14,34);   //FT81X: 31, 32, 33, 34
GD.ColorRGB(0xffffff);   
GD.Tag(3);
GD.cmd_text(375, 50, 14, OPT_CENTER, RTC.getTimeStr()); 
GD.cmd_text(384, 105, 31, OPT_CENTER, RTC.getDateStr());
GD.cmd_text(280, 140, 25, OPT_CENTER, RTC.getMonthStr()); 
GD.cmd_text(460, 140, 25, OPT_CENTER, RTC.getDOWStr());
GD.Tag(255);
GD.RestoreContext();
if (GD.inputs.tag==3){delay(100);                
GD.RestoreContext();         
       next1();
       }

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_bgcolor(0x3f040c);
GD.cmd_gauge(100,80,100,4352, 10,10,S3,1024);
GD.ColorRGB(0xff0000);
GD.cmd_text(80, 45, 29, 0, "LDR");
GD.ColorRGB(255,255,255);
GD.printNfloat(108, 120, S3, 1, 29);
GD.cmd_text(90, 90, 29, 0, "%lx");
GD.RestoreContext();

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_bgcolor(0x3f040c);
GD.ColorRGB(0xff0000);
GD.cmd_text(60, 200, 29, 0, "DHT T");
GD.ColorRGB(255,255,255);
GD.cmd_gauge(100,240,100,4352, 6,9,S1,60);
GD.printNfloat(100, 280, S1, 1, 29); 
GD.cmd_text(95, 250, 29, 0, "'C");
GD.RestoreContext();

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_bgcolor(0x3f040c);
GD.ColorRGB(0xff0000);
GD.cmd_text(60, 360, 29, 0, "DHT H:");
GD.ColorRGB(255,255,255);
GD.cmd_gauge(100,400,100,4352, 10,10,S2,100);
GD.printNfloat(100, 450, S2, 1, 29);
GD.cmd_text(60, 410, 29, 0, "% R.H.");
GD.RestoreContext();

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_bgcolor(0x3f040c);
GD.ColorRGB(0xff0000);
GD.cmd_text(240, 360, 29, 0, "DS T:");
GD.ColorRGB(255,255,255);
GD.printNfloat(280, 450, S4, 1, 29);
GD.cmd_gauge(280,400,100,4352, 10,9,S4,70);
GD.cmd_text(270, 410, 29, 0, "'C");
GD.RestoreContext();

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_bgcolor(0x3f040c);
GD.ColorRGB(0xff0000);
GD.cmd_text(430, 360, 29, 0, "BMP:");
GD.ColorRGB(255,255,255);
GD.cmd_gauge(460,400,100,4352, 10,10,S5,1500);
GD.printNfloat(475, 450, S5, 1, 29);
GD.cmd_text(430, 410, 29, 0, "hPa");
GD.RestoreContext();

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_bgcolor(0x3f040c);
GD.ColorRGB(0xff0000);
GD.cmd_text(640, 70, 30, 0, "C.W.T");
GD.ColorRGB(255,255,0);
GD.cmd_gauge(680,125,135,OPT_NOBACK, 10,10,S4,100);
GD.ColorRGB(255,255,255);
GD.printNfloat(685, 175, S4, 1, 31);
GD.cmd_text(670,140, 30, 0, "'C");
GD.RestoreContext();

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_fgcolor(0x005500);
GD.cmd_gradcolor(0xffffff);    
GD.Tag(1);
GD.cmd_button(600,240, 160,60, 30,0, "C.W.Start");
GD.Tag(255);       
if (GD.inputs.tag==1){delay(100); 
digitalWrite(A4, LOW); 
GD.cmd_fgcolor(0x000000); 
GD.cmd_bgcolor(0x000030); 
GD.ColorRGB(0x00ff00);
GD.cmd_button(600,240, 160,60, 30,0, "C.W.Start");
GD.RestoreContext();
//delay(250);              
//digitalWrite(A4, HIGH); 
}

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_fgcolor(0xaa0000);
GD.cmd_gradcolor(0xffffff);
GD.Tag(2);
GD.cmd_button(600,320, 160,60, 30,0, "C.W.Stop");
GD.Tag(255);
 if (GD.inputs.tag==2){delay(100); 
 //digitalWrite(A4, LOW);
 //delay(250);              
 digitalWrite(A4, HIGH); 
 GD.cmd_fgcolor(0x000000); 
 GD.cmd_bgcolor(0x000030); 
 GD.ColorRGB(0x00ff00);
 GD.cmd_button(600,320, 160,60, 30,0, "C.W.Stop");
 GD.RestoreContext();
 }
GD.SaveContext();
GD.ColorRGB(0,0,255);
GD.cmd_fgcolor(0x005500);
GD.cmd_bgcolor(0xaa0000);
GD.cmd_slider(225,207, 320,20, 0,50, 100);
GD.RestoreContext();

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_text(320,270,31, 1536, "Grzanie do:");
GD.RestoreContext();

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_number(455,270,31,1536,75);
GD.RestoreContext();

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_text(495,266,30, 1536, "'C");
GD.RestoreContext();

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_fgcolor(0x055500);
//GD.cmd_gradcolor(0xffffff);
GD.Tag(4);
GD.cmd_button(600, 410, 160, 50, 30, 0,  "Menu+");
GD.Tag(255);
GD.RestoreContext(); 
 if (GD.inputs.tag==4){delay(100);                        
       next2();
       }
  GD.Display();
  GD.swap();
}
}

