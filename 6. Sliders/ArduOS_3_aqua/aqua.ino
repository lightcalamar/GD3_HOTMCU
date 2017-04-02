//////AQUA///////
void aqua()
{
  //CargaAssetF1();
  while(1)
  {      
    
    
    GD.get_inputs();
    GD.ClearColorRGB(0x000000);
    GD.Clear();
    GD.Begin(BITMAPS);
    LOAD_ASSETS1();  
    GD.BitmapHandle(15); 
    GD.cmd_loadimage(ASSETS_END, 0);
    GD.load("Fpez1.jpg");  
    GD.Vertex2ii(0, 0, 15); 

int Pez=2;
      GD.SaveContext();
      GD.Vertex2ii(80, 100, Pez);
      GD.Vertex2ii(200, 280, Pez);
      GD.RestoreContext();
//Pez
/*
//Burbujas
    GD.SaveContext();
      GD.VertexTranslateX(16*(BX));
      GD.Vertex2ii(0, BY, 5);
      BY = BY - 5;
     GD.RestoreContext();

    GD.SaveContext();
      GD.VertexTranslateX(16*(BX1));
      GD.Vertex2ii(0, BY1, 5);
      BY1 = BY1 - 10;
     GD.RestoreContext();     
  unsigned long currentMillisB = millis();        
  if(currentMillisB - previousMillisB > intervalB)
  {
    previousMillisB= currentMillisB;       
        BX = GD.random(75);
        BX1 = GD.random(75);
        BY=40, BY1=42;
  }
*/
//Burbujas
  GD.get_inputs();
  //GD.SaveContext(); 
  //GD.ColorRGB(0xffffff);   
  GD.ColorRGB(255,255,255);
  GD.cmd_fgcolor(0x055500);   
  GD.Tag(21);
  GD.cmd_button(600, 410, 160, 50, 30, 0,  "Menu+");  
  GD.Tag(255);
  //GD.RestoreContext();
   if (GD.inputs.tag==21){delay(1);                 
      next2();
       }    
    GD.swap();
  }
  }
  
  
