void setup() { 
  Serial.begin(115200);
  GD.begin();
  GD.cmd_setrotate(0);
  Estimacion();
}
void loop(){}
