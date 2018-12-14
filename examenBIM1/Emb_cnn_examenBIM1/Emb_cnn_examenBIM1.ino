#include <EEPROM.h>
int conteep =0;
#include "datos_sillas.h"
// definicion de matricez de CNN
float matriz_s [60][5];  // datos validos
float matriz_d [80][5]; // datos de desecho
int col=0; // variable de recorrido de col de matriz de mayor volumen
int fil;  // variable de recorrido de filas de matriz de mayor volumen
int col_s=0; // variable que recorre columnas para matriz s
int fil_s=0;// variable que recorre filas matriz s
int fil_s1=4; // variable que recorre matriz s cuando realiza knn con matriz d
int fil_d=0; // variable que recorre filas en matriz d
int col_d=0; // variable que recorre columnas en matriz d
float promedio; // variable de promedio 
float sumatoria=0; //variable parcial para encontrar distancia mas corta
int etiqueta=1; // variable para ciclo de conteo entre etiquetas
int i=0; // variable de seleccion de etiquetas
float dist=0; // variable parcial para encontrar distancia mas corta
float dist_total; // variable global para almacenar distancia mas corta
float dist_mayor=2000; // variable para encontrar la distancia menor
float label; // variable que almacena etiqueta de distancia mas corta
void setup(){
  Serial.begin(9600);
  // ciclo que permite encontrar los puntos medios por cada etiqueta
  //recorre cada posicion de filas por etiquetas y encuentra el promedio de cada
  // columna
  for(;etiqueta<5;etiqueta++){ // ciclo que recorre por etiqueta
      for(;col<4;col++){ // ciclo que recorre por columna
        for(fil=i;fil<20*etiqueta;fil++){ // ciclo que recorre por filas
          sumatoria=sumatoria+matriz[fil][col]; // almacenamiento de sumatoria
         
        }
        
      promedio=sumatoria/20; // promedio por columna
      matriz_s[etiqueta-1][col]=promedio; // almacenar promedios en matriz 
      sumatoria=0; // vuelve a cero para siguiente columna
      fil=0;  // fila vuelve a cero para recorrer nuevamente filas
    }
    col=0; // variable vuelve a cero para recorrer nuevamente columnas
    i=20*etiqueta;  // variable que que cuenta determina el numero de datos por etiqueta 
 
 
 
 } 

 col=0; 
 fil=0;
 // metodo para llenar etiquetas en vector
 //una vez encontrado puntos medios
 for(;fil<4;fil++){
  matriz_s[fil][4]=fil+1; // llenar etiquetas en matriz S
  }
  fil=0;
}
void loop(){
  /*
   * Metodo para implementar el algoritmo CNN dentro de Arduino
   * La matriz almacenada en el archivo .h se encontraron los puntos medios
   * por cada etiqueta
   * se realiza k-nn por cada punto de la matriz de mayor volumen teniendo como matriz 
   * de entrenamiento a la matriz que solo contiene los puntos medios llamada matriz s
   * Cuando un dato ingresa desde la matriz de mayor volumen a knn y es clasificado adecuadamente se almacane en matriz d
   * caso contrario en matriz s.
   * con la matriz d con datos, se vuelve a realizar knn con matriz de entrenamiento la matriz s, si sigue 
   * clasificando adecuadamente se almacena en martiz d, caso contrario matriz s
   * Se conserva matriz s, el resto se descarta
   */

   // metodo de knn con matriz de mayor volumen y knn con matriz s  de entrenamiento 

   
   for(;fil<80;fil++){ // ciclo que recorre por cada fila de matriz de mayor volumen
          for(;fil_s<4;fil_s++){ // recorre por filas de la matriz s
              for(;col_s<4;col_s++){ // recorre por filas de ambas matrices
                dist=dist+ pow(matriz[fil][col_s]-matriz_s[fil_s][col_s],2); // distancia entre dos puntos
                }
                dist_total=sqrt(dist); // distancia entre dos puntos               
                if(dist_total<dist_mayor){ // comparacion para encontrar distancia menor
                    dist_mayor=dist_total;
                    label=matriz_s[fil_s][4]; // 
                  }// endif
                dist=0; // por cada lectura de fila se encera distancia 
                col_s=0;  //vuelve a cero para leer nuevamente columnas
            }//end for fil_S
            fil_s=0;
            dist_mayor=2000;
            // si el algoritmo knn clasifico correctamente, almacena en matriz d
           // caso contrario en matriz s
            if(label==matriz[fil][4]){
              // almacena los datos en matriz d
                for(;col_d<5;col_d++){
                   matriz_d[fil_d][col_d]=matriz[fil][col_d];
                  }
                col_d=0;
                fil_d++;
              }
              else{
                // almancena los datos en matriz s
                  for(;col_s<5;col_s++){
                   matriz_s[fil_s1][col_s]=matriz[fil][col_d];
                  }
                  col_s=0;
                  fil_s1++;
               }
  }
  // imprime los valores almacenados en matriz s
fil_s=0;
for(;fil_s<fil_s1;fil_s++){
     for(;col_s<5;col_s++){
        Serial.print(matriz_s[fil_s][col_s]);
        Serial.print(',');
      }
      col_s=0;
      Serial.println(' ');
  }
//////////////////////////////////////////////////
// una vez realizado el proceso en matriz de alto volumen
// se realiza el mismo proceso con matriz d
fil=0;
fil_s=0;
col_s=0;
 for(;fil<fil_d;fil++){ // recorre los datos filas de matriz d
          for(;fil_s<4;fil_s++){ // recorre los datos de filas de matriz s
              for(;col_s<4;col_s++){ // recorre las columnas de ambas matrices
                dist=dist+ pow(matriz_d[fil][col_s]-matriz_s[fil_s][col_s],2); //distancia entre dos puntos
                }
                dist_total=sqrt(dist);  // distancia entre dos puntos               
                if(dist_total<dist_mayor){ // compara con distancia menor
                    dist_mayor=dist_total;
                    label=matriz_s[fil_s][4]; // almacena etiqueta de distancia menor
                  }// endif
                dist=0;
                col_s=0;  
            }//end for fil_S
            fil_s=0;
            dist_mayor=2000;
            // si clasifica correctamente el sistema no realiza ninguna accion
            if(label==matriz_d[fil][4]){
                    }
              // si clasifica de forma erronea, almacena en matriz s
              else{
               for(;col_s<5;col_s++){
                   matriz_s[fil_s1][col_s]=matriz[fil][col_d];
                  }
                  col_s=0;
                  fil_s1++;
               }
  }
   // imprime los valores almacenados en matriz s
fil_s=0;
EEPROM.write(255,3);

Serial.println(" Imprimientod Matriz s");
for(;fil_s<4;fil_s++){
     for(;col_s<5;col_s++){
     //  Serial.print((int)(matriz_s[fil_s][col_s]*100)/6);
        Serial.print(',');
      //  Serial.println("valore a guardor");
        Serial.print(matriz_s[fil_s][col_s]);
        EEPROM.update(conteep,((int)(matriz_s[fil_s][col_s]*100))/6);
         Serial.println("valore a guardor");
        Serial.println(EEPROM.read(conteep));
       conteep++;
      }
      col_s=0;
      Serial.println(' ');
  }
  Serial.println(" fIN Imprimientod Matriz s");
 fil_s1=-1; 
conteep=0;
fil_s=0;
col_s=0;
Serial.println("Imprimeindo desde EEPROM");
//Serial.print((  (float)EEPROM.read(0))/100);
for(;fil_s<4;fil_s++){
     for(;col_s<5;col_s++){
        if(col_s>3){       
          Serial.println(round((float)(EEPROM.read(conteep)*6)/100));
          conteep++;
        }else{
        Serial.print(((float)(EEPROM.read(conteep)*6)/100));
        Serial.print(',');
      
        conteep++;
        }
        //conteep++;
      }
      col_s=0;
      Serial.println(' ');
  }
 Serial.println("FIN Imprimeindo desde EEPROM");
}
