/*
 * Melany Jingo
 *Un sistema que encienda leds de la siguiente forma:Después de 20s de encendido 
 *el sistema, prender led 1 por 10 segundos. En 25 segundos de encendido el 
 *sistema, prender led 2 por 15 segundos. En 30 segundos de encendido el sistema, 
 *prender led 3 por 5 segundos. Repite el ciclo. Se visualiza el contador en una 
 *lcd y que led o leds se encuentra encendido.
 */
 #include <LiquidCrystal.h>// libreria de LCD
#include <TimerOne.h> // libreria de Timer1
LiquidCrystal lcd(13,12,11,10,9,8);
int on=0; // variable de encendido del sistema
unsigned int cont=0; //variable del contador timer1
int led1=5; //variable para led1
int led2=6; //variable para led2
int led3=7; //variable para led3
void setup() {
   pinMode(led1,OUTPUT);//establece el pin digital de salida 5
   pinMode(led2,OUTPUT);//establece el pin digital de slaida 6
   pinMode(led3,OUTPUT);//establece el pin digital de salida 7
   attachInterrupt(digitalPinToInterrupt(2),encendido,LOW); // encendido del distema
   Timer1.initialize(1000000);  // timer1 a 1 seg.
   Timer1.attachInterrupt(contador); // metodo de timer
   lcd.begin(16, 2);
   lcd.setCursor(0,1);//posición en la LCD
   lcd.print("LEDs ON:");// muestra cual led o leds esta encendida
}
void loop() {
  
}
void encendido(){
  on =1-on; // varaible de encendido del sistema
  if (on==1){
     lcd.setCursor(0,0);
    lcd.print("Sistema on ");// mensaje de activación
    }else{
    cont=0;// reset de variable de conteo de timer1
    lcd.setCursor(8,1);
    lcd.print("        ");
    lcd.setCursor(0,0);
    lcd.print("Sistema off  ");//mensaje de desactivación
    
        } 
  }
   void contador(){
    if(on==1)
    {
    cont ++;
    lcd.setCursor(11,0);//posición para el contador
    lcd.print(cont);//mostrar contador
    lcd.print(' '); //espacio libre
      if(cont==20)
      {
        digitalWrite(led1,HIGH);//encender led1
        lcd.setCursor(8,1);
        lcd.print("1");//mostrar led1 encendida
       }
        if(cont==25)
      {
        digitalWrite(led2,HIGH);//encender led2
        lcd.setCursor(11,1);
        lcd.print("2");//mostrar led2 encendida
       }
        if(cont==30)
      {
        digitalWrite(led3,HIGH);//encender led3
        lcd.setCursor(14,1);
        lcd.print("3");//mostrar led3 encendida
        digitalWrite(led1,LOW);//apagar led1
        lcd.setCursor(8,1);
        lcd.print(" ");//borrar led1 encendida
       }
       if(cont==35)
      {
        digitalWrite(led3,LOW);//apagar led3
        lcd.setCursor(14,1);
        lcd.print(" ");//borrar led3 encendida
       }
       if(cont==40)
      {
        digitalWrite(led2,LOW);//apagar led2
        lcd.setCursor(11,1);
        lcd.print(" ");//borrar led2 encendida
        cont=0;//reiniciar contador timer
       }
   
    }
 }  
