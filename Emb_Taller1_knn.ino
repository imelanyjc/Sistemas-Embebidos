#include"datos_entrenamiento.h"// almacenadas en mi carpeta  local
#include"datos_test.h"
int col=0;
int row=0;
float distancia;
float dist_menor=1000;
int a=9;
int c=0;

void setup() {
  Serial.begin(9600);
}
void loop() {
 distancias(3);
} 
void distancias(int k) {
  for(row=0;row<120;row++){// contador de filas
       distancia=sqrt(pow((matriz[row][0]-prueba[a][0]),2)+ 
                     pow((matriz[row][1]-prueba[a][1]),2)+
                     pow((matriz[row][2]-prueba[a][2]),2)+
                     pow((matriz[row][3]-prueba[a][3]),2));   
  
     if(distancia<dist_menor)
       {
        c++;
       
        dist_menor=distancia;
        
        Serial.println("la distancia menor es: ");
        Serial.println(dist_menor);
       // Serial.println(matriz[row][4]);
         a=matriz[row][4];
          Serial.println("Pertence a:  ");
         Serial.println(a);      
         if (c == 3) {
          Serial.print("  ");
          Serial.print(a);
          Serial.print("  ");
          c = 0;
        }
        } 
       // Serial.println(distancia);
      }
       //Serial.println(dist_menor);
    if (a == 1) {
      Serial.println("1 = iris_setosa");
      delay(1000);
      
    }
    if (a == 2) {
      Serial.println(" 2 =iris_versicolor");
      delay(1000);
    }
    if (a == 3) {
      Serial.println(" 3=iris_virginica");
      delay(1000);
    }
  }
