void setup() {
  GD.begin();
  GD.cmd_setrotate(0);
  
 // GD.wr(REG_PWM_DUTY, 95);  //0-128  backlight para Gameduino en arduino Due, evita sobrecalentamiento 
 //GD.self_calibrate();  //Activar en caso de ser necesario
 
  procesandoentorno();
  GD.cmd_loadimage(0, 0);
  GD.load("HMI2.jpg");  //ID=116 en la tarjeta de pruebas, modificar por la favorita y determinar su ID
  LeenombreJPG();
}

void loop() {}
