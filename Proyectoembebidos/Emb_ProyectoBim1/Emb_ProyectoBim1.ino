#include <EEPROM.h>
#include"final.h"
float result;
int fil_s=0;//filas de matriz reducida de cnn
int col_s=0;//columnas de matriz reducida de cnn
int conteep =0;
int v=0;
String m;
float matriz_s[3][5]={{5.10,3.48,1.47,0.24,1}, 
                      {5.90,2.74,4.22,1.31,2}, 
                      {6.62,2.98,5.53,2.03,3}};
float test[1][5]={4.6,3.4,1.4,0.3,1};//1  dato nuevo para comprobar
void setup() {
 Serial.begin(9600);
//--------------codigo completo 
Serial.println(" Imprimientod Matriz s");
for(;fil_s<3;fil_s++){
     for(;col_s<5;col_s++){
      Serial.print("valore a guardar en la posicion: ");
      Serial.print(fil_s);
      Serial.print(",");
      Serial.println(col_s);
          Serial.print((int)(matriz_s[fil_s][col_s]*100)/6);
          Serial.println(',');
          
          //Serial.print((matriz_s[fil_s][col_s]*100)/6);
          EEPROM.write(conteep,((int)(matriz_s[fil_s][col_s]*100))/6);
         // Serial.println(EEPROM.read(conteep)/2);
         conteep++;
      }
      col_s=0;
      Serial.println(' ');
  }
  Serial.println(" fIN Imprimientod Matriz s");
conteep=0;
fil_s=0;
col_s=0;
Serial.println("Imprimeindo desde EEPROM");
//Serial.print((  (float)EEPROM.read(0))/100);
for(;fil_s<3;fil_s++){
     for(;col_s<5;col_s++){
        if(col_s==4){
          Serial.println(round((float)(EEPROM.read(conteep)*6)/100));
          matriz[fil_s][col_s]=(round((float)(EEPROM.read(conteep)*6)/100));
          conteep++;
         
        }else{
        Serial.print(((float)(EEPROM.read(conteep)*6)/100));
        Serial.print(','); 
         matriz[fil_s][col_s]=((float)(EEPROM.read(conteep)*6)/100);
        conteep++;
        }
       // conteep++;
      }
      col_s=0;
      Serial.println(' ');
  }conteep=0;
 Serial.println("FINAL Imprimeindo desde EEPROM");


 for(int r=0;r<3;r++){
  for(int a=0;a<5;a++){

    Serial.print(matriz[r][a]);
    Serial.print(" , ");
  }
  Serial.println("  ");
 }

result=knn(3,5,3,3,test[0]);

if (result==test[0][4]){
  Serial.println("Acierto");
  Serial.println(result);
  Serial.println("Dato desechado");
  
  }else{
    Serial.println("Fallo");
    Serial.println(result);
   
    }
}
void loop() {
}
float knn(int fila, int col, int k, int label, float datos[]){//parametros de entrada , datos=nueva infromación
  int c=0;// movernos en columnas
  int f=0;//movernos en fila
  
  float k_vecinos_dist[k];//vector de almacenamiento de k distancias menores
  float etiquetas[2][label];// matriz y conteo de etiquetas
  float dist=0; //variable que almacena cada distancia.
  float dist_total=0;// caribel para almacenamiento distancai
  //lenar vector k_vecinos_dist con valores altos
  float eti_menor[k];//vector de eqtiquetas de distancia menor
  int k_cont=0;//contador de k
  int i=0;//contador
  float clase; //return etiqueta
  float comparacion;// comparar k-vecino mayor
  for (;c<k;c++)
  {
    k_vecinos_dist[c]=2000.0+c; // valores altos y ordenados
  }
  c=0;//reiniciar variable
  //llenado de las k distancias menores
  for(;c<label; c++){
    etiquetas [0][c]=c+1;//lleno con valores d eetiqueta
    etiquetas [1][c]=0;//lleno con el conteo de etiquetas
    }
    c=0;// reinicio de variabel
    // distancia mas corta del nuevo punto hacia la amtriz
    for(;f<fila;f++)
    {
      for(;c<col-1;c++){
        dist=dist+pow(matriz[f][c]-datos[c],2);//distancia entre dos puntos 
        }
        dist_total=sqrt(dist);//raíz total de la formula
        //Serial.print(dist_total);
        for(;k_cont<k;k_cont++){// determinar las k distancias enores y ordenarlas
          if(dist_total<k_vecinos_dist[k_cont]){
            k_vecinos_dist[k_cont]=dist_total;// asignar nuevo valor a vetor de dsitancias
            eti_menor[k_cont]=matriz[f][col-1];//col=5,4 //ya se ordenos el vector
            }
          }
          k_cont=0;
          dist=0;
          dist_total=0;
          c=0;
      }//for fila
      
      // comparar cada una de las posiciones d ela matriz y comparar
      
      //seleccion del k vecino
      for(;c<label;c++){
        for(;k_cont<k;k_cont++){// recorro cad posicion de eti_menor y comparo con etiquetas y cuento si son iguales
          if(etiquetas[0][c]==eti_menor[k_cont]){
            i++;
            etiquetas[1][c]=i;
            }
          }
          k_cont=0;
          i=0;
        }
        //c=0;
        c=1;//para que en comparacion
        comparacion=etiquetas[1][0];
        clase=etiquetas[0][0];
        for(;c<label;c++){
          if(etiquetas[1][c]>comparacion){//omparacion entre valores de suma de etiqueta
         clase=etiquetas[0][c];//ponga neuva clase 
         comparacion=etiquetas[1][c];
         
         }
          }
          comparacion=0;
          c=1;
          return clase;
        
}

 
