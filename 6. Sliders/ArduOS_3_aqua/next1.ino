///////NOC////////////////
void next1()
{
 while(1)
 {
  GD.cmd_dlstart();
  GD.ClearColorRGB(0,0,0);
  GD.Clear(1,1,1);
  //GD.ClearColorRGB(0x000000);        
  GD.Clear();        
  
  GD.wr(REG_PWM_DUTY, 1);//0-128 
  GD.get_inputs();

  GD.ColorA(120); //transp. 0-255           
  //GD.ColorRGB(0xffffff);
  GD.SaveContext();
  GD.cmd_romfont(14,34);   //FT81X: 31, 32, 33, 34
  GD.ColorRGB(0xffffff);   
  //GD.ColorRGB(0xff0000);
  GD.Tag(5);
  GD.cmd_text(375, 200, 14, OPT_CENTER, RTC.getTimeStr()); 
  GD.cmd_text(384, 255, 31, OPT_CENTER, RTC.getDateStr());
  GD.cmd_text(280, 290, 25, OPT_CENTER, RTC.getMonthStr()); 
  GD.cmd_text(460, 290, 25, OPT_CENTER, RTC.getDOWStr());
  GD.Tag(255);
  GD.RestoreContext();
   if (GD.inputs.tag==5){delay(100);                
          
      Menumain();
       }
 
 GD.Display();
 GD.swap();
 }
 }

