///////MENU5//////////////
void next5()
{
while(1)
 {
  GD.cmd_dlstart();
  GD.ClearColorRGB(0,0,0);
  GD.Clear(1,1,1);  
  GD.wr(REG_PWM_DUTY, 12);//0-128 
  GD.get_inputs();
  GD.SaveContext(); 
  GD.ColorRGB(0xffffff);   
  GD.Tag(16);
  GD.cmd_button(600, 410, 160, 50, 30, 0,  "Menu+");  
  GD.Tag(255);
  GD.RestoreContext();  
   if (GD.inputs.tag==16){delay(100);                        
      next2();   
       }
 GD.Display();
 GD.swap();
 }
 }

