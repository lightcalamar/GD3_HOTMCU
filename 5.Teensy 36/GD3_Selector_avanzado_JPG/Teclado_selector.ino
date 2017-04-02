void Tecladoselector()
{
  while(1){
        GD.Clear();
        GD.Begin(BITMAPS);  GD.Vertex2ii(0, 0); 
           GD.ColorRGB(0,255,0);                
           GD.cmd_button(xT11,yT11,(3*largogrupoT1+2*sepT),altogrupoT1,26,0,stCurrent);                

           GD.ColorRGB(0,255,255);
           sprintf(TX,"%03d", IDcambio);       
      	   GD.cmd_text(xT11+3*largogrupoT1+3*sepT,yT11+3, 26, 0, TX);  //Tamaño del texto: 16 a 31  
           int IDrespaldo = IDcambio;
             GD.get_inputs();
             GD.ColorRGB(0,255,0);

             if (GD.inputs.tag==237){
                        GD.ColorA(255);
                        GD.cmd_button(xT11,yT11,(3*largogrupoT1+2*sepT),altogrupoT1,26,OPT_FLAT,stCurrent); 
                        GD.play(PIANO, 60);
                        delay (190);
                        stCurrent[0]='\0';
                        stCurrentLen=0;
		            }
                GD.Tag(237);  GD.cmd_button(xT11,yT11,(3*largogrupoT1+2*sepT),altogrupoT1,26,0,stCurrent); GD.Tag(255); 


  GD.ColorA(200);
  GD.cmd_fgcolor(0x000075);
  GD.ColorRGB(255,255,255);
               if (GD.inputs.tag==226){
                     GD.ColorA(255);
                     GD.play(PIANO, 61);
                     delay (195);
                     updateStr('1');
		              }
   	   GD.Tag(226);  GD.cmd_button(xT21,yT21,largogrupoT1,altogrupoT1,26,tagoption,"1"); GD.Tag(255); 

   GD.ColorA(200);
                 if (GD.inputs.tag==227){
                       GD.ColorA(255);
                       GD.play(PIANO, 62);
                       delay (190);
                       updateStr('2');
                    }
	  GD.Tag(227); GD.cmd_button(xT31,yT31,largogrupoT1,altogrupoT1,26,tagoption,"2");	GD.Tag(255); 


   GD.ColorA(200);
             if (GD.inputs.tag==228){  
                     GD.ColorA(255);
                     GD.play(PIANO, 63);
                     delay (190);
                     updateStr('3');
		            }
		GD.Tag(228);  GD.cmd_button(xT41,yT41,largogrupoT1,altogrupoT1,26,tagoption,"3");

   GD.ColorA(200);
               if (GD.inputs.tag==229){
                     GD.ColorA(255);
                     GD.play(PIANO, 64);
                     delay (190);
                     updateStr('4');
		            }
		GD.Tag(229);  GD.cmd_button(xT51,yT51,largogrupoT1,altogrupoT1,26,tagoption,"4");

   GD.ColorA(200);
             if (GD.inputs.tag==230){
                     GD.ColorA(255);
                     GD.play(PIANO, 65);
                     delay (190);
                     updateStr('5');
		             }
		GD.Tag(230);  GD.cmd_button(xT61,yT61,largogrupoT1,altogrupoT1,26,tagoption,"5");
   
   GD.ColorA(200);   
               if (GD.inputs.tag==231){
                     GD.ColorA(255);
                     GD.play(PIANO, 66);
                     delay (190);
                     updateStr('6');
		             }
		GD.Tag(231);  GD.cmd_button(xT71,yT71,largogrupoT1,altogrupoT1,26,tagoption,"6");   

   GD.ColorA(200);
             if (GD.inputs.tag==232){  
                     GD.ColorA(255);
                     GD.play(PIANO, 67);
                     delay (190);
                     updateStr('7');
		             }
		GD.Tag(232);  GD.cmd_button(xT81,yT81,largogrupoT1,altogrupoT1,26,tagoption,"7");   

   GD.ColorA(200);
               if (GD.inputs.tag==233){
                     GD.ColorA(255);
                     GD.play(PIANO, 68);
                     delay (190);
                     updateStr('8');
		            }
		GD.Tag(233); GD.cmd_button(xT91,yT91,largogrupoT1,altogrupoT1,26,tagoption,"8");   

   GD.ColorA(200);
             if (GD.inputs.tag==234){  
                     GD.ColorA(255);
                     GD.play(PIANO, 69);
                     delay (190);
                     updateStr('9');
		           }
		GD.Tag(234);  GD.cmd_button(xT101,yT101,largogrupoT1,altogrupoT1,26,tagoption,"9");   
   
   
   GD.ColorA(200);
               if (GD.inputs.tag==235){
                     GD.ColorA(255);
                     GD.play(PIANO, 60);
                     delay (190);
                     updateStr('0');
		              }
		GD.Tag(235);   GD.cmd_button(xT111,yT111,largogrupoT1,altogrupoT1,26,tagoption,"0");      
   
   
  GD.ColorA(200);
  GD.cmd_fgcolor(0xff5000);
  GD.ColorRGB(255,255,255);   
               if (GD.inputs.tag==236){
                        GD.ColorA(255);
                        GD.play(PIANO, 70);

                        IDcambio = atoi(stCurrent);  //Convierte en número la cadena-numeros y borra buffer del teclado

                        if (IDcambio >= MAX_IMAGESc - 1)  //Verifica que el ID de la nueva imagen no supere la base de archivos
                           {
                             IDcambio = IDrespaldo;
                           }          
                        delay (190);
                        stCurrent[0]='\0';
                        stCurrentLen=0;

                        sprintf(TX,"%03d", IDcambio);       
                         CargaJPG(IDcambio);
                         GD.play(0);
                         delay (190);
		             }
		GD.Tag(236); GD.cmd_button(xT121,yT121,2*largogrupoT1+sepT,altogrupoT1,26,tagoption,">>>");         

  GD.ColorA(255);

    GD.Tag(200); estadoboton1();  GD.Tag(255);
    if (GD.inputs.tag==200){
        
        estado= estado+1;
        delay(145);        
        if (estado>=2){estado=0;} 
        procesandoentorno();
        CargaJPG(NombreJPG);
        Muestralista=0;
        GD.play(0);       
        LeenombreJPG();
         
      }  
  GD.swap();
  }
}


void estadoboton1()
{  GD.ColorRGB(0xeeee00);  GD.cmd_fgcolor(0x954500); 
   if(estado==0){GD.cmd_button(405, 5, 50, 35, 26, 0,  "MP");} 
   if(estado==1){GD.cmd_button(405, 5, 50, 35, 26, OPT_FLAT,  "MP");}    
}  


//Función que controla el ingreso de digitos por el teclado
void updateStr(int val)
{
  if (stCurrentLen<4)  //número de digitos máximo, 3 es el original
  {
    stCurrent[stCurrentLen]=val;
    stCurrent[stCurrentLen+1]='\0';
    stCurrentLen++;
  }
  else
  {
      GD.cmd_button(xT11,yT11,(3*largogrupoT1+2*sepT),altogrupoT1,26,0,"Fuera"); // borra el display 
      GD.play(0);          
      delay (500);
      stCurrent[0]='\0';
      stCurrentLen=0;      
  }
}
//Función que controla el ingreso de digitos por el teclado
