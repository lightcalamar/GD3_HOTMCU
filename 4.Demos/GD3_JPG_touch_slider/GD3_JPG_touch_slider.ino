//#include <EEPROM.h>   //UNO/MEGA
#include <SPI.h>
#include <GD3.h>
//ID                      0           1          2          3         4         5          6          7          8
char GroupJPG1[10][15]={"T36a.jpg","T36b.jpg","DX16.jpg","Fn1.jpg","DX2.jpg","DX9.jpg","Fpez1.jpg","DX12.jpg","DX6.jpg"};  //800x480
int IDJPG=0;

void setup()
{
  GD.begin();
  GD.cmd_setrotate(0);
  // GD.self_calibrate();  //UNO/MEGA
  LoadGroupJPG1(IDJPG);
  MM();
}
void loop(){}

void LoadGroupJPG1(int IDJPG)
{
  GD.cmd_loadimage(0, 0);
  GD.load(GroupJPG1[IDJPG]);  //800x480
}

void MM()
{
  while(1)
  {
    GD.Clear();
    GD.get_inputs();
    GD.Begin(BITMAPS);
    
    GD.Tag(1);  GD.Vertex2ii(0, 0);  GD.Tag(255);
    GD.SaveContext();
      GD.ColorRGB(0,0,0);  GD.cmd_text(10, 2, 24, 0, GroupJPG1[IDJPG]);
    GD.RestoreContext();

    if (GD.inputs.tag==1)
       {delay(115);
        IDJPG=IDJPG+1;
        if(IDJPG>=9){IDJPG=0;}
        LoadGroupJPG1(IDJPG);
       }

    GD.swap();
  }
}
