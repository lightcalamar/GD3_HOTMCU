//#include <EEPROM.h> //arduino MEGA/UNO  comentar para Due, A partir del IDE 1.6.9, se puede comentar al usarlo con el Teensy 3.X
#include <SPI.h>
#include <GD3.h>

#define MAX_IMAGESc  124
#define MAX_IMAGES 124  
char directory[MAX_IMAGES][8];
int num_jpgs = 0;

int delta = 0;
int Numrects = 50;
int ymov=2782; //funciona para almacenar la posición relativa del selector de archivos

int limsup = MAX_IMAGES * 26.5;

int picked;
int xTextJPG = 400 + 48;  
int NombreJPG = 116; //ID de la imagen inicial
int estado=0;


//Variables para armar el ingreso por teclado
char stCurrent[20]="";
int stCurrentLen=0;
char stLast[20]="";
int IDcambio=83;   //  ID de imagen nueva
//Variables para armar el ingreso por teclado

//Botones para ingreso por teclado
  int largogrupoT1 = 30, altogrupoT1 = 25, sepT = 5;  // grupo 1
  int xT11=10, yT11=10;          //Display
  int xT21=xT11, yT21=yT11+altogrupoT1+sepT; // "1"
  int xT31=xT11+largogrupoT1+sepT, yT31=yT21; // "2"
  int xT41=xT11+2*largogrupoT1+2*sepT, yT41=yT21; // "3"

  int xT51=xT11, yT51=yT11+2*altogrupoT1+2*sepT; // "4"
  int xT61=xT11+largogrupoT1+sepT, yT61=yT51; // "5"
  int xT71=xT11+2*largogrupoT1+2*sepT, yT71=yT51; // "6"

  int xT81=xT11, yT81=yT11+3*altogrupoT1+3*sepT; // "7"
  int xT91=xT11+largogrupoT1+sepT, yT91=yT81; // "8"
  int xT101=xT11+2*largogrupoT1+2*sepT, yT101=yT81; // "9"
  int xT111=xT11, yT111=yT11+4*altogrupoT1+4*sepT; // "0"  
  int xT121=xT11+largogrupoT1+sepT, yT121=yT111; // "==>"  
//Botones para ingreso por teclado

int Transp = 75;   // transparencia en botones
int32_t LoopFlag = 0,wbutton,hbutton,tagval,tagoption;
char TX[50];  

int Colorlista=255, Muestralista=0;  

void estadoboton()
{  GD.ColorRGB(0xeeee00);  GD.cmd_fgcolor(0x954500); 
   if(estado==0){GD.cmd_button(5, 5, 50, 35, 26, 0,  "Code");} 
   if(estado==1){GD.cmd_button(5, 5, 50, 35, 26, OPT_FLAT,  "Code");}    
}  

void LeenombreJPG()
{
  procesandolista();  
  ReadJPGname();  //Procesa la lista de nombres de archivos jpg
  GD.play(0); //detiene sonido en altavoz
    
  while(1)
  {
    GD.Clear();
    GD.get_inputs();
    GD.Begin(BITMAPS);  
       GD.Vertex2ii(0, 0); 
    
    GD.SaveContext();
     GD.LineWidth(48);   GD.Begin(RECTS);   GD.ColorRGB(0xcccccc);   GD.ColorA(0);
     GD.Vertex2f(16*345, 16*0);
     GD.Vertex2f(16*455, 16*450);
    GD.RestoreContext();
    
    showdir1(directory, num_jpgs, ymov, -1);
    
    GD.ColorA(255);
    GD.Tag(210);  GD.ColorRGB(0xff0000);  GD.cmd_text(120, 310, 18, OPT_RIGHTX, getdir(directory, NombreJPG));  //Nombre del archivo jpg seleccionado

     picked = GD.inputs.tag;     
     if ((picked>=1) && (picked<=MAX_IMAGES)) 
         {        
           NombreJPG = picked-1;           
           CargaJPG(NombreJPG);
           Muestralista = 0;
         }     
   
    GD.Tag(200); estadoboton();  GD.Tag(255);
    if (GD.inputs.tag==200){
        estado= estado+1;
        if (estado>=2){estado=0;}        
        delay(185);

        procesandoentorno();
        CargaJPG(IDcambio);       
        Tecladoselector();
      }     

    GD.Tag(201);
    GD.ColorRGB(0xeeee00);  
    GD.cmd_button(5, 45, 50, 35, 26, 0,  "Up");  
    if (GD.inputs.tag==201){
          Muestralista = 1;
          GD.cmd_button(5, 45, 50, 35, 26, OPT_FLAT,  "Up");
          ymov = ymov + 8; 
          if (ymov>= limsup){ymov=-450;}
      }

    GD.Tag(202);
    GD.cmd_button(5, 85, 50, 35, 26, 0,  "Dw");
    if (GD.inputs.tag==202){
          Muestralista = 1;
          GD.cmd_button(5, 85, 50, 35, 26, OPT_FLAT,  "Dw");
          ymov = ymov - 8; 
          if (ymov<=-450){ymov=limsup;}
      }

    GD.Tag(210);  GD.ColorRGB(0xffffff);  GD.printNfloat(100, 330, NombreJPG, 1, 30);  GD.printNfloat(90, 290, ymov, 1, 18);
    
        if (Muestralista==1){Colorlista=255; GD.Tag(209); GD.ColorRGB(0xeeee00); GD.cmd_button(5, 125, 50, 35, 26, 0,  "Hide");}
        if (Muestralista==0){Colorlista=0; GD.Tag(209); GD.ColorRGB(0xeeeeee); GD.cmd_button(5, 125, 50, 35, 26, 0,  "Show");}

    if (GD.inputs.tag==209){
          delay(120);
          Muestralista = Muestralista - 1; 
          if (Muestralista<=-1){Muestralista=1;}
      }
    GD.swap();
  }  
}
