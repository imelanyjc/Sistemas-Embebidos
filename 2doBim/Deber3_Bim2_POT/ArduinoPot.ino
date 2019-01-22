int potPin=A0;

int val=0;
char inicio='0';  
int medida; 

void setup() {
 Serial.begin(9600);

}

void loop() {
  val=analogRead(A0);
  int medida=map(val,0,1023,0,100);
  Serial.print(medida);
  delay(1000);

}
