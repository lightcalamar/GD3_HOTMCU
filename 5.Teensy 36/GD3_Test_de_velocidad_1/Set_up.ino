void setup()
{
  Serial.begin(9600);
  GD.begin();
  GD.cmd_setrotate(0);
  GD.play(0); //detiene sonido en altavoz

  hello();
  delay(2500);
  MCircular();
}
