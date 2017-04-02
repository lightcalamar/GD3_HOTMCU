///////MENU+//////////////
void next2()
{
while(1)

 {
  GD.cmd_dlstart();
  GD.ClearColorRGB(0,0,0);
  GD.Clear(1,1,1);  
  GD.wr(REG_PWM_DUTY, 12);//0-128 
  GD.get_inputs();  
  GD.ClearColorRGB(0x201000); 
  GD.Clear();
  //GD.ColorA(120); //transp. 0-255           
  GD.SaveContext();
  GD.cmd_romfont(14,33);
  GD.Tag(3);
  GD.cmd_text(290, 20, 14, 0, RTC.getTimeStr()); 
  GD.Tag(255);
  GD.RestoreContext();  
   if (GD.inputs.tag==3){delay(100);                         
       next1();
       }  
  GD.SaveContext();
  GD.ColorRGB(255,255,255);
  GD.cmd_fgcolor(0x055500); 
  GD.Tag(6);
  GD.cmd_button(60, 30, 160, 50, 30, 0,  "Bloob");
  GD.Tag(255);
  GD.RestoreContext();  
   if (GD.inputs.tag==6){delay(100);                       
       next3();
         }
  GD.SaveContext();
  GD.ColorRGB(255,255,255);
  GD.cmd_fgcolor(0x055500); 
  GD.Tag(7);
  GD.cmd_button(60, 110, 160, 50, 30, 0,  "Aqua");
  GD.Tag(255);
  GD.RestoreContext();  
   if (GD.inputs.tag==7){delay(100);                       
       aqua();
         }
  GD.SaveContext();
  GD.ColorRGB(255,255,255);
  GD.cmd_fgcolor(0x055500);
  GD.Tag(8);
  GD.cmd_button(60, 190, 160, 50, 30, 0,  "Next4");
  GD.Tag(255);
  GD.RestoreContext();  
   if (GD.inputs.tag==8){delay(100);                       
       next4();
         }
  GD.SaveContext();
  GD.ColorRGB(255,255,255);
  GD.cmd_fgcolor(0x055500); 
  GD.Tag(9);
  GD.cmd_button(60, 270, 160, 50, 30, 0,  "Next5");
  GD.Tag(255);
  GD.RestoreContext();  
   if (GD.inputs.tag==9){delay(100);                       
       next5();
         }
  GD.SaveContext();
  GD.ColorRGB(255,255,255);
  GD.cmd_fgcolor(0x055500); 
  GD.Tag(10);
  GD.cmd_button(60, 350, 160, 50, 30, 0,  "Next6");
  GD.Tag(255);
  GD.RestoreContext();  
   if (GD.inputs.tag==10){delay(100);                       
       next6();
         }
  GD.SaveContext();  
  GD.ColorRGB(255,255,255);
  GD.cmd_fgcolor(0xaa0000);
  GD.cmd_gradcolor(0xffffff);  
  GD.Tag(20);
  GD.cmd_button(340, 410, 160, 50, 30, 0,  "Restart");  
  GD.Tag(255);
  GD.RestoreContext(); 
   if (GD.inputs.tag==20){delay(100);                 
  GD.begin();
  ///GD.cmd_setrotate(0);
  GD.wr(REG_PWM_DUTY, 10);//0-128  backlight
  //GD.wr(REG_SWIZZLE, 0);
  GD.wr(REG_ROTATE, 0);
  GD .self_calibrate();   
  GD.play(0);    
      Menumain();
       }
GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_fgcolor(0x055500);
GD.cmd_gradcolor(0xffffff);
GD.cmd_button(250,130, 160,50, 28,0, " Dzwonek WL.");
GD.RestoreContext();

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_fgcolor(0xaa0000);
GD.cmd_gradcolor(0xffffff);
GD.cmd_button(250,210, 160,50, 28,0, "Dzwonek WYL.");
GD.RestoreContext();

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_fgcolor(0x055500);
GD.cmd_gradcolor(0xffffff);
GD.cmd_button(440,130, 160,50, 28,0, " Domofon WL.");
GD.RestoreContext();

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_fgcolor(0xaa0000);
GD.cmd_gradcolor(0xffffff);
GD.cmd_button(440,210, 160,50, 28,0, "Domofon WYL.");
GD.RestoreContext();

GD.SaveContext();
GD.ColorRGB(255,255,255);
GD.cmd_fgcolor(0x004444);
GD.cmd_gradcolor(0xffffff);
GD.cmd_button(340,310, 160,50, 28,0, "NOC/Cisza");
GD.RestoreContext();


  GD.SaveContext(); 
  GD.ColorRGB(255,255,255);
  GD.cmd_fgcolor(0x005500);
  GD.cmd_gradcolor(0xffffff); 
  GD.Tag(11);
  GD.cmd_button(600, 30, 160, 50, 30, 0,  "Pulpit");  
  GD.Tag(255);
  GD.RestoreContext();
   if (GD.inputs.tag==11){delay(100);                 
      Menumain();
       }
  
 GD.Display();
 GD.swap();
 }
 }

