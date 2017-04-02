///////Bloob//////////////
void next3()
{
 while(1)
 {
  GD.cmd_dlstart();
  GD.ClearColorRGB(0,0,0);
  GD.Clear(1,1,1);
  GD.wr(REG_PWM_DUTY, 12);//0-128 
  GD.get_inputs();
  GD.SaveContext();
  GD.Tag(12);  
  GD.cmd_button(600, 410, 160, 50, 30, 0,  "Menu+");  
  GD.Tag(255);
  GD.RestoreContext();
   if (GD.inputs.tag==12){delay(100);                
      next2();  
       } 
 static byte blob_i;
  GD.get_inputs();
  if (GD.inputs.x != -32768) {
    blobs[blob_i].x = GD.inputs.x << 4;
    blobs[blob_i].y = GD.inputs.y << 4;
  } else {
    blobs[blob_i].x = OFFSCREEN;
    blobs[blob_i].y = OFFSCREEN;
  }
  blob_i = (blob_i + 1) & (NBLOBS - 1);


  GD.Begin(POINTS);
  for (int i = 0; i < NBLOBS; i++) {
    
    GD.ColorA(i << 1);
    GD.PointSize((1024 + 16) - (i << 3));

   
    uint8_t j = (blob_i + i) & (NBLOBS - 1);
    byte r = j * 17;
    byte g = j * 23;
    byte b = j * 147;
    GD.ColorRGB(r, g, b);

    // Draw it!
    GD.Vertex2f(blobs[j].x, blobs[j].y);
  }
  
 GD.Display();
 GD.swap();
 }
 }

