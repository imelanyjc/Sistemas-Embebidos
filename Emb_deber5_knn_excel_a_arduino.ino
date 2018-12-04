#include"datos_entrenamiento.h"
float result;
float sum1;
float sum2;
float sum3;
float sum4;
float maxnor;
float distan;
float v1[40];
float nor[40];
float v2[40];
float rang = 0.2;
int fila; 
int col;
int coll, fil; 
int fi = 0;
float prom1 , prom2, prom3, prom4;
void setup() {
  Serial.begin(9600);
}

void loop() {
  efectivo();
}
void efectivo() {
//promedio
  for (; fila < 40; fila++) {//CONTADOR DE FILAS
    for (; col < 1; col++) {//CONTADOR DE COLUMNAS
      sum1 = (sum1 + matriz[fila][0]);
      sum2 = (sum2 + matriz[fila][1]);
      sum3 = (sum3 + matriz[fila][2]);
      sum4 = (sum4 + matriz[fila][3]);
      delay(25);

    }
    prom1 = sum1 / 40;
    prom2 = sum2 / 40;
    prom3 = sum3 / 40;
    prom4 = sum4 / 40;
    col = 0;

  }
  //Distancias
  for (;fil<40;fil++) {
    distan = sqrt(pow((matriz[fil][0] - prom1), 2) +
                  pow((matriz[fil][1] - prom2), 2 ) +
                  pow((matriz[fil][2] - prom3), 2 ) +
                  pow((matriz[fil][3] - prom4), 2));
    v1[fil] = distan;
    maxnor = max(maxnor, distan);
  }
  //normalizar
  fil = 0;
  for (; fil < 40; fil++) {
    nor[fil] = v1[fil] / maxnor;
  }
  for (; fi < 40; fi++) {
    if (nor[fi] <= rang) {
      v2[fi] = 1;
          }
    else {
      v2[fi] = 0;
          }
          //valores efectivos
    if (v2[fi] == 1) {
      Serial.print(matriz[fi][0]);
      Serial.print(" , ");
      Serial.print(matriz[fi][1]);
      Serial.print(" , ");
      Serial.print(matriz[fi][2]);
      Serial.print(" ,");
      Serial.print(matriz[fi][3]);
       Serial.println("  ");
    }
  }
  }
