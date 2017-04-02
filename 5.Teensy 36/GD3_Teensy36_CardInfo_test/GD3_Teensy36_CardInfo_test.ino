/*
  SD card test

 This example shows how use the utility libraries on which the'
 SD library is based in order to get info about your SD card.
 Very useful for testing a card when you're not sure whether its working or not.

 The circuit:
  * SD card attached to SPI bus as follows:
 ** MOSI - pin 11 on Arduino Uno/Duemilanove/Diecimila
 ** MISO - pin 12 on Arduino Uno/Duemilanove/Diecimila
 ** CLK - pin 13 on Arduino Uno/Duemilanove/Diecimila
 ** CS - depends on your SD card shield or module.
 		Pin 4 used here for consistency with other Arduino examples


 created  28 Mar 2011
 by Limor Fried
 modified 9 Apr 2012
 by Tom Igoe
 */
// include the SD library:
#include <SPI.h>
#include <SD.h>
#include <GD3.h>

#include "Icons2.h"        //ASSETS7b   //+switchs, +boton enc, -icono de advertencia, -iconos de audio

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
//SdFile root;

File root;



// change this to match your SD shield or module;
// Arduino Ethernet shield: pin 4
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
const int chipSelect = BUILTIN_SDCARD;
char TX[40];
int contador = 0;
uint32_t volumesize;
int ByteSize, KbSize, MBsize;


void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }  
  



  Serial.print("\nInitializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(chipSelect, OUTPUT);     // change this to 53 on a mega
  GD.begin();
  
  espera();
  carga_iconos();  
//  GD.swap();
    
  
  GD.wr(REG_PWM_DUTY, 65);  //0-128  intensidad de la retroiluminación XD
  GD.ClearColorRGB(0xffffff);
  GD.Clear(); 

  
  GD.ColorRGB(0x000000);        
  GD.cmd_text(150, 120, 18, 0, "Micro SD card checking...");
  GD.swap();
  delay(1000); 

  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  if (!card.init(SPI_FULL_SPEED, chipSelect)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card is inserted?");
    Serial.println("* Is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
//   GD.ClearColorRGB(0xffffff);
   GD.Clear();   
    GD.Begin(BITMAPS);
    GD.Vertex2ii(0, 95, 15, 0);
   
   GD.ColorRGB(0xff0000);        
   GD.cmd_text(10, 10, 18, 0, "Initialization failed. Things to check:");
   GD.ColorRGB(0xffff00);           
   GD.cmd_text(10, 25, 18, 0, "* Is a card is inserted?");
   GD.cmd_text(10, 40, 18, 0, "* Is your wiring correct?");   
   GD.cmd_text(10, 55, 18, 0, "* Did you change the chipSelect pin to match your shield");   
   GD.cmd_text(10, 70, 18, 0, "  or module?");   
   GD.swap();
   return;
  } else {
    Serial.println("Wiring is correct and a card is present.");
 //  GD.ClearColorRGB(0x103000);
   GD.Clear();     
    GD.Begin(BITMAPS);
    GD.Vertex2ii(0, 95, 15, 0);
   GD.ColorRGB(0xffffff);
   GD.cmd_text(10, 5, 18, 0, "Wiring is correct and a card is present in breakout reader");
   GD.cmd_text(10, 25, 18, 0, "\nCard type: ");      GD.ColorRGB(0xff0000);
  }



  // print the type of card
  Serial.print("\nCard type: ");
  switch (card.type()) {
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      GD.cmd_text(100, 25, 18, 0, "SD1");      
     // GD.swap();
      break;
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      GD.cmd_text(100, 25, 18, 0, "SD2");      
     // GD.swap();      
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      GD.cmd_text(100, 25, 18, 0, "SDHC");      
     // GD.swap();      
      break;
    default:
      Serial.println("Unknown");
      GD.cmd_text(100, 25, 18, 0, "Unknown");      
     // GD.swap();      
  }

  // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
  if (!volume.init(card)) {
    Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
    GD.ClearColorRGB(0xffffff);
    GD.Clear();               
    GD.ColorRGB(0xff0000);
    GD.cmd_text(10, 40, 18, 0, "Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");    
    GD.swap();         
    return;
  }

  Serial.print("\nVolume type is FAT");
  Serial.println(volume.fatType(), DEC);
  GD.ColorRGB(0xffffff);   GD.cmd_text(10, 45, 18, 0, "\nVolume type is FAT");        
  GD.ColorRGB(0xff0000);   GD.cmd_number(165, 45, 18, 0, volume.fatType());        
//  GD.swap();          
  Serial.println();



  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
  
  //volumesize *= 512;                            // SD card blocks are always 512 bytes
  //Serial.print("Volume size (bytes): ");
  //Serial.println(volumesize);

  if (volumesize < 8388608ul) {
    Serial.print("Volume size (bytes): ");
    Serial.println(volumesize * 512);        // SD card blocks are always 512 bytes
  }

  
  ByteSize=volumesize;
  GD.ColorRGB(0xffffff);   GD.cmd_text(10, 60, 18, 0, "  Volume size (bytes): "); 
  GD.ColorRGB(0xff0000);   GD.cmd_number(194, 60, 18, 0, ByteSize);        
  //GD.swap();            
  
  Serial.print("Volume size (Kbytes): ");
  ByteSize /= 1024;
  Serial.println(volumesize);
  KbSize = volumesize;
  GD.ColorRGB(0xffffff);   GD.cmd_text(10, 75, 18, 0, "  Volume size (Kbytes): "); 
  GD.ColorRGB(0xff0000);   GD.cmd_number(194, 75, 18, 0, KbSize);        
//  GD.swap();              
  
  
  Serial.print("Volume size (Mbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);
  MBsize=volumesize;
  GD.ColorRGB(0xffffff);  GD.cmd_text(10, 90, 18, 0, "  Volume size (Mbytes): "); 
  GD.ColorRGB(0xff0000);  GD.cmd_number(194, 90, 18, 0, MBsize);        
//  GD.swap();    

  int Totalsize = volumesize;  //valor previo
  volumesize /= 1024;          //solo deja el entero del valor previo
  
  int Deltasize= Totalsize-(volumesize*1000);   //conserva los 3 decimales del valor previo
  sprintf(TX,"%d.%d", volumesize, Deltasize); //almacena el valor previo con decimales
  
  GD.ColorRGB(0xffffff);  GD.cmd_text(10, 105, 18, 0, "  Volume size (Gbytes): "); 
  GD.ColorRGB(0xff0000);  GD.cmd_text(194, 105, 18, 0, TX);   
  GD.swap();            

//  root1.openRoot(volume);
//  root1 = SD.open("/");
//  printDirectory(root1, 0);

//  Serial.println("\nFiles found on the card (name, date and size in bytes): ");
//  root.openRoot(volume);
  // list all files in the card with date and size
//  root.ls(LS_R | LS_DATE | LS_SIZE);  
  
//  contador = contador+1;
//  GD.cmd_number(10, 120, 18, 0, contador);
//  GD.swap();            

  delay(5000);

 Serial.print("Initializing SD card...");
  if (!SD.begin(BUILTIN_SDCARD)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");


  root = SD.open("/");
  printDirectory(root, 0);
  Serial.println("done!");
  
}


void loop(void) {}


//void printDirectory1(File dir, int numTabs) {
void printDirectory1(File dir, int numTabs) { 
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}

int NumFile =0;
int TotalSize =0;

void printDirectory(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.println('\t');
    }
//    GD.ClearColorRGB(0x000025); //fondo de pantalla
    GD.Clear();   
    GD.Begin(BITMAPS);
    GD.Vertex2ii(0, 95, 15, 0);    

    GD.ColorRGB(0xffffff);   GD.cmd_text(10, 45, 18, 0, "\nVolume type is FAT");        
    GD.ColorRGB(0xff0000);   GD.cmd_number(165, 45, 18, 0, volume.fatType());        
  
    GD.ColorRGB(0xffffff);   GD.cmd_text(10, 60, 18, 0, "  Volume size (bytes): "); 
    GD.ColorRGB(0xff0000);   GD.cmd_number(194, 60, 18, 0, ByteSize);          
    GD.ColorRGB(0xffffff);   GD.cmd_text(10, 75, 18, 0, "  Volume size (Kbytes): "); 
    GD.ColorRGB(0xff0000);   GD.cmd_number(194, 75, 18, 0, KbSize);          
    GD.ColorRGB(0xffffff);  GD.cmd_text(10, 90, 18, 0, "  Volume size (Mbytes): "); 
    GD.ColorRGB(0xff0000);  GD.cmd_number(194, 90, 18, 0, MBsize);            
    GD.ColorRGB(0xffffff);  GD.cmd_text(10, 105, 18, 0, "  Volume size (Gbytes): "); 
    GD.ColorRGB(0xff0000);  GD.cmd_text(194, 105, 18, 0, TX);      

    GD.ColorRGB(0x00ffff);  GD.cmd_text(45, 123, 18, 0, "Accesando directorio principal...");              
    
    
    Serial.println(entry.name()); NumFile = NumFile + 1;
    GD.ColorRGB(0xffffff);  GD.cmd_text(150, 146, 18, OPT_RIGHTX, entry.name());      
    GD.ColorRGB(0xffff00);  GD.cmd_number(300, 146, 18, OPT_RIGHTX, NumFile); 
    
    
    if (entry.isDirectory()) {
      Serial.println("/");
    //  Serial.print("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      //Serial.print("\t\t");

     // Serial.print(entry.size(), DEC);
    GD.ColorRGB(0xff0000);  GD.cmd_number(250, 146, 18, OPT_RIGHTX, entry.size());    TotalSize =TotalSize + entry.size();
    GD.ColorRGB(0x00ff00);  GD.cmd_number(250, 175, 18, OPT_RIGHTX, TotalSize/1049194.3125);  GD.cmd_text(265, 175, 18, 0, "Mb");     
    GD.swap();       
    }
    entry.close();
  }
}
