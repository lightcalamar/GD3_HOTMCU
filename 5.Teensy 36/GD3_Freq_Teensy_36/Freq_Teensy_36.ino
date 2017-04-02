static inline void fps(const int seconds){
  static unsigned long lastMillis;
  static unsigned long frameCount;
  static unsigned int framesPerSecond;
  
  unsigned long now = millis();
  frameCount ++;
  if (now - lastMillis >= seconds * 1000) {
    framesPerSecond = frameCount / seconds;
     iteracion=iteracion+1; //Serial.print(iteracion); 
     Dato = framesPerSecond;
     Serial.println(framesPerSecond);
    if(iteracion>=limite){
        //MHzMCU(); 
        MP();
       }
    frameCount = 0;
    lastMillis = now;
  }
}

void Estimacion(){while(1){fps(1);}}

void MHzMCU()
{
if ((Dato/1000>=20) && (Dato/1000<=100)){Serial.println("Arduino UNO 16 MHz");} 
   if ((Dato/1000>=1770) && (Dato/1000<=1800)){Serial.println("Arduino Due 84 MHz");}

   if ((Dato/1000>=11980) && (Dato/1000<=11992)){Serial.println("Teensy 3.6@180 MHz, Smallest Code");}
   if ((Dato/1000>=13820) && (Dato/1000<=13836)){Serial.println("Teensy 3.6@180 MHz, Fast/Faster");}
   
   if ((Dato/1000>=12780) && (Dato/1000<=12791)){Serial.println("Teensy 3.6@192 MHz, Smallest Code");}
   if ((Dato/1000>=14740) && (Dato/1000<=14759)){Serial.println("Teensy 3.6@192 MHz, Fast/Faster");}

   if ((Dato/1000>=14380) && (Dato/1000<=14392)){Serial.println("Teensy 3.6@216 MHz, Smallest Code");}
   if ((Dato/1000>=16580) && (Dato/1000<=16605)){Serial.println("Teensy 3.6@216 MHz, Fast/Faster");}

   if ((Dato/1000>=15980) && (Dato/1000<=15992)){Serial.println("Teensy 3.6@240 MHz, Smallest Code");}
   if ((Dato/1000>=18430) && (Dato/1000<=18451)){Serial.println("Teensy 3.6@240 MHz, Fast/Faster");}   
}

void MHzMCUGD3()
{
if ((Dato/1000>=20) && (Dato/1000<=100)){GD.cmd_text(400, 20, 27, OPT_CENTER, "Arduino UNO 16 MHz");}  
   if ((Dato/1000>=1770) && (Dato/1000<=1800)){GD.cmd_text(400, 20, 27, OPT_CENTER, "Arduino Due 84 MHz");}

   if ((Dato/1000>=11980) && (Dato/1000<=11992)){GD.cmd_text(400, 20, 27, OPT_CENTER, "Teensy 3.6@180 MHz, Smallest Code");}
   if ((Dato/1000>=13820) && (Dato/1000<=13836)){GD.cmd_text(400, 20, 27, OPT_CENTER, "Teensy 3.6@180 MHz, Fast/Faster");}
   
   if ((Dato/1000>=12780) && (Dato/1000<=12791)){GD.cmd_text(400, 20, 27, OPT_CENTER, "Teensy 3.6@192 MHz, Smallest Code");}
   if ((Dato/1000>=14740) && (Dato/1000<=14759)){GD.cmd_text(400, 20, 27, OPT_CENTER, "Teensy 3.6@192 MHz, Fast/Faster");}

   if ((Dato/1000>=14380) && (Dato/1000<=14392)){GD.cmd_text(400, 20, 27, OPT_CENTER, "Teensy 3.6@216 MHz, Smallest Code");}
   if ((Dato/1000>=16580) && (Dato/1000<=16605)){GD.cmd_text(400, 20, 27, OPT_CENTER, "Teensy 3.6@216 MHz, Fast/Faster");}

   if ((Dato/1000>=15980) && (Dato/1000<=15992)){GD.cmd_text(400, 20, 27, OPT_CENTER, "Teensy 3.6@240 MHz, Smallest Code");}
   if ((Dato/1000>=18430) && (Dato/1000<=18451)){GD.cmd_text(400, 20, 27, OPT_CENTER, "Teensy 3.6@240 MHz, Fast/Faster");
   }   
}
