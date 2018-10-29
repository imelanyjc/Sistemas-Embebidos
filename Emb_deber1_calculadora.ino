/*
 * Realice una calculadora mediante un teclado matricial y una lcd. 
 * Las funciones de la calculadora son: suma, resta, multiplicación 
 * y división.
 */ 
#include <LiquidCrystal.h>//librería LCD
#include <Keypad.h>//librería teclado amtricial

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
const byte FILAS = 4;//variable para filas
const byte COLUMNAS = 4;//variable para columnas
char keys [FILAS] [COLUMNAS] = {
{ '7','8','9', 'X' },
{ '4','5','6', '+' },
{ '1','2','3', '-' },
{ '0','=','/', '*' }

};
byte filasPins[FILAS] = {7,6,5,4}; //Define filas
byte colPins[COLUMNAS] = {3,2,1,0}; //Define columnas

Keypad myKeypad = Keypad( makeKeymap(keys), filasPins, colPins, FILAS, COLUMNAS );
boolean siguiente = false;
boolean valor = false;
boolean final = false;
String num1, num2,num3;//caracteres seleccionados 
char signo;// signo de operación
int total;
int movimiento;
void setup(){
      lcd.begin(16,2);
      lcd.setCursor(0,0);
      lcd.print("Calc:Suma Resta");
      lcd.setCursor(1,1);
      lcd.print("Multi Division");
      delay(400);
      lcd.clear();
}
void loop(){
char tecla = myKeypad.getKey();
if (tecla != NO_KEY && (tecla=='0'||tecla=='1'||tecla=='2'||tecla=='3'||tecla=='4'||
    tecla=='5'||tecla=='6'||tecla=='7'||tecla=='8'||tecla=='9')){
    if (valor != true){
        num1 = num1 + tecla;
        int numLength = num1.length(); //contar cuantos caracteres tiene
        movimiento = numLength;
        lcd.setCursor(0,0);
        lcd.print(num1);
        }
        else {
           num2 = num2 + tecla;
           int numLength = num2.length();
           lcd.setCursor(movimiento+1, 0);
           lcd.print(num2);
           final = true;
          }
      }
      else if (valor == false && tecla != NO_KEY && (tecla == '/' || tecla == '*' || 
         tecla == '-' || tecla == '+'))
        {
      if (valor == false)
        {
          valor = true;
          signo = tecla;
          lcd.setCursor(movimiento,0);
          lcd.print(signo);
          }
         }
      else if (final == true && tecla != NO_KEY && tecla == '=')
      {
            if (signo == '+')
            {
              total = num1.toInt() + num2.toInt();//operacion de suma
            }
            else if (signo == '-')
            {
              total = num1.toInt() - num2.toInt();//operacion de resta
            }
            else if (signo == '*'){
            total = num1.toInt() * num2.toInt();//operación multiplicación
            }
            else if (signo == '/')
            {
             if(num2.toInt()==0)
             {
                total =' ';
              }else{
              total = num1.toInt() / num2.toInt();// operación de divisiónn
              }
             }
            num3=String(total);
            lcd.clear();
            lcd.setCursor(15,0);
            lcd.autoscroll();
            if(total==' '){
            lcd.print("error");
            }else if(num3.length()>4)
            {
            lcd.print("sin  memoria");
            }else
            {
            lcd.print(total);
            }
            lcd.noAutoscroll();
            }
          else if (tecla != NO_KEY && tecla == 'X'){
            lcd.clear();
            valor = false;
            final = false;
            num1 = "";
            num2 = "";
            total = 0;
            signo = ' ';
}
}
