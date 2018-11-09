
/*realizar el algorimo k-NN con k=3*/
#include"datos_entrenamiento.h"// almacenadas en mi carpeta  local
#include"datos_test.h"
int col=0;//columnas 
int row=0;//filas
float distancia;
float dist_menor=1000;
float dist_menor1=1000;
float dist_menor2=1000;
int c=0;
int c1=0;
int c2=0;
void setup() {
 
  Serial.begin(9600);
}

void loop() {
  //dist1
 for(row=0;row<120;row++){// contador de filas
       distancia=sqrt(pow((matriz[row][0]-prueba[0][0]),2)+ 
                     pow((matriz[row][1]-prueba[0][1]),2)+
                     pow((matriz[row][2]-prueba[0][2]),2)+
                     pow((matriz[row][3]-prueba[0][3]),2)); 
       if(distancia<dist_menor)
       {
        dist_menor=distancia;
        Serial.println("opcion 1: ");
        // Serial.println(dist_menor);
        Serial.println(matriz[row][4]);
        c=matriz[row][4];
        }
      }
  //dist2
 for(row=0;row<120;row++){// contador de filas
       distancia=sqrt(pow((matriz[row][0]-prueba[11][0]),2)+ 
                     pow((matriz[row][1]-prueba[11][1]),2)+
                     pow((matriz[row][2]-prueba[11][2]),2)+
                     pow((matriz[row][3]-prueba[11][3]),2)); 
       if(distancia<dist_menor1)
       {
        dist_menor1=distancia;
        Serial.println("opcion 1: ");
        // Serial.println(dist_menor);
        Serial.println(matriz[row][4]);
        c1=matriz[row][4];
        }
      } 
//dist3
for(row=0;row<120;row++){// contador de filas
       distancia=sqrt(pow((matriz[row][0]-prueba[15][0]),2)+ 
                     pow((matriz[row][1]-prueba[15][1]),2)+
                     pow((matriz[row][2]-prueba[15][2]),2)+
                     pow((matriz[row][3]-prueba[15][3]),2)); 
       if(distancia<dist_menor2)
       {
        dist_menor2=distancia;
        Serial.println("opcion 1: ");
        // Serial.println(dist_menor);
        Serial.println(matriz[row][4]);
        c2=matriz[row][4];
        }
      }             
//Serial.println(c);
if((c==1 && c1==1 && c2==1)||(c==1 && c1==1)||(c1==1 && c2==1)||(c==1 && c2==1)){
  Serial.println("Por mayoria es del grupo: ");
  Serial.println("iris_setosa");
  delay(1000);
  }
else if((c==2 && c1==2 && c2==2)||(c==2 && c1==2)||(c1==2 && c2==2)||(c==2 && c2==2)){
  Serial.println("Por mayoria es del grupo: ");
  Serial.println("iris_versicolor");
  delay(1000);
  }      
else if((c==3 && c1==3 && c2==3)||(c==3 && c1==3)||(c1==3 && c2==3)||(c==3 && c2==3)){
  Serial.println("Por mayoria es del grupo: ");
  Serial.println("iris_virginica");
  delay(1000);
  }       

}
