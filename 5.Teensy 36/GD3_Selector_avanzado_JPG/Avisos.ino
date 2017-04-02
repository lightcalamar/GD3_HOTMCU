void procesandoentorno()
{
  GD.ClearColorRGB(0x103000);  
  GD.Clear();
  GD.ColorRGB(0xffffff);  
    GD.cmd_text(240, 120, 26,   OPT_CENTERX, "Procesando entorno visual...");
    delay(1000);
  GD.swap(); 
}  

void procesandolista()
{
  GD.ClearColorRGB(0x103000);  
  GD.Clear();
  GD.ColorRGB(0xffffff);  
    GD.cmd_text(240, 120, 26,   OPT_CENTERX, "Procesando lista...");
  GD.swap(); 
}
