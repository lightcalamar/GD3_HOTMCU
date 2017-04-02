///////SETUP///////////////
void setup()
{

  pinMode(PDPin, OUTPUT);
  digitalWrite(PDPin, HIGH);  
  delay(20);
  digitalWrite(PDPin, LOW);
  delay(20);
  digitalWrite(PDPin, HIGH);
  delay(20);

  Serial.begin(9600);
  GD.begin();
  //GD.cmd_setrotate(0);
  GD.wr(REG_PWM_DUTY, 10);//0-128  backlight
  //GD.wr(REG_SWIZZLE, 0);
  GD.wr(REG_ROTATE, 0);
  GD .self_calibrate(); 
  GD.play(0); 
  
  for (int i = 0; i < NBLOBS; i++) {
    blobs[i].x = OFFSCREEN;
    blobs[i].y = OFFSCREEN;
  }
    
  Wire.begin();
  RTC.begin();
  pressure.begin();
  sensors.begin();
  dht.begin();

  pinMode(A4, OUTPUT);
  digitalWrite(A4, HIGH);   // C.W. on/off
  pinMode(A5, OUTPUT);
  digitalWrite(A5, HIGH);   // dzwonek on/off
  pinMode(A6, OUTPUT);
  digitalWrite(A6, HIGH);   // domofon on/off




  // RTC.setDOW(SATURDAY);       // Set Day-of-Week to SUNDAY
  // RTC.setTime(00, 18, 00);     // Set the time to 12:00:00 (24hr format)
  // RTC.setDate(03, 12, 2016);   // Set the date to January 1st, 2014
 
//}

 Menumain();
}
void loop(){
  
  
} 


