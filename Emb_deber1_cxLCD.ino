/* 1.- Realizar un sistema que ingrese por cx una palabra y se visualice 
 * en una LCD. Además, realice un rotación de letras dentro la LCD.
*/
#include <LiquidCrystal.h> //librería  LCD
LiquidCrystal lcd(12,11,10,9,8,7);//RS,EN,D4,D5,D6,D7
String dato; // recibir el dato de cx serial
int tam; // tamaño del dato
int i=0; 
int j=0;
void setup() {
  lcd.begin(16,2);  //seleccionar dimensión de LCD
  Serial.begin(9600);//inicializo cx serial
  Serial.println("INGRESE PALABRA: "); //mensaje al inicio del programa
}
void loop() {
  
  if(Serial.available()>0) // verifico si hay dato disponible
  {
    dato=Serial.readString(); // leer dato
    //Serial.println(dato);// Imprimr en la consola el dato recibido
    tam=dato.length();//determinar el tamaño del dato
    Serial.println(tam);// Imprimir el tamaño del dato
   // lcd.print(dato);// imprimir "dato" en la LCD
    char vector[tam+1];//crear el vector tipo char
    dato.toCharArray(vector,tam+1);//asignar el String al vector
   
    for(;i<tam+1;i++)//recorrer el vector ascendentemente de aucerdo al tamaño 
    {
      // Serial.println(vector[i]);//imprimir el dato pasado a  vector
       lcd.setCursor(i,0);
       lcd.print(vector[i]);//imprimir en la LCD el dato pasado a vector
       delay(200);//espera de 2s
       lcd.clear();//limpiar LCD
     //Serial.println(i); 
     }
    for(;i<=tam+1;i--)//recorrer el vector descendentemente de aucerdo al tamaño 
    {
      //Serial.println(vector[i]);//imprimir el dato pasado a  vector
        lcd.setCursor(i,0);//posición de comienzo LCD
        lcd.print(vector[i]);//imprimir en la LCD el dato pasado a vector
        delay(200);//espera de 2s
        lcd.clear();//limpiar LCD
      //Serial.println(i);
        if(i==0)
          {
            for(;i<tam+1;i++)//recorrer el vector ascendentemente de aucerdo al tamaño 
              {
              //Serial.println(vector[i]);//imprimir el dato pasado a  vector
                lcd.setCursor(i,0);
                lcd.print(vector[i]);//imprimir en la LCD el dato pasado a vector
                delay(200);//espera de 2s
                lcd.clear();//limpiar LCD
              //Serial.println(i);
               }
           }
     }
  }
}
