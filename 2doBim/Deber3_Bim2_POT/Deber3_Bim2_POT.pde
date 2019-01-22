import controlP5.*;
import processing.serial.*;
Serial puerto;
Chart myChart;
int i;
String dato;
float valor;
float pot;
ControlP5 cp5;

void setup(){
  size(1200,600);
  background(165,165,165);
  println( Serial.list());
  puerto= new Serial(this, "COM5", 9600);
  cp5=new ControlP5(this);
  
  textSize(25);
  fill(255);
  text("Gráfica en contenedor",200,100);  
  
  textSize(25);
  fill(255);
  text("Gráfica voltaje-tiempo",600,100); 
  
  cp5.addButton("CONECTAR") //creacion del boton para graficar en contenedor
  .setPosition(250,200) //posicion
  .setSize(100,50)  //tamaño
  .setCaptionLabel("OFF") //cambiar el nombre del boton de la interfaz
  .setColorBackground(color(0,0,0));

   cp5.addButton("GRAFICAR") //boton para graficar en voltaje/tiempo
   .setPosition(650,200)
   .setSize(100,50)
   .setColorBackground(color(0,0,0)); //cambie el color de fondo del boton
   ;
   
   cp5.addSlider("CONTENEDOR")  //contenedor
   .setPosition(300,380)
   .setSize(50,200)
   .setRange(0,100)
   .setValue(0) 
   .setColorBackground(color(0,0,255))
   .setColorActive(color(0,0,155))
   .setColorForeground(color(155,0,0))
   .setNumberOfTickMarks(10)
   ;
   
    myChart=cp5.addChart("dato")
  .setPosition(650,300)
  .setSize(500,300)
  .setRange(0,100)
  .setView(Chart.BAR_CENTERED)
  .setStrokeWeight(50)
  .setColorCaptionLabel(color(255))
  .setValue(valor);
  ;
  myChart.addDataSet("incoming");
  myChart.setData("incoming", new float[100]);
   

}

void draw(){

while(puerto.available()>1){
  dato=puerto.readString();
  cp5.getController("CONTENEDOR").setValue(float(dato));
  if(dato==null){println("FALLO");}
    else if(dato!=null){
     valor = PApplet.parseFloat(dato);
     pot = PApplet.parseInt(valor);
    }
}  myChart.push("incoming", ((valor)));
}
public void CONECTAR(int on){
  i=1-i;
if (i==0){
  puerto= new Serial(this, "COM5", 9600);
  cp5.getController("CONECTAR").setCaptionLabel("ON");
  cp5.getController("CONECTAR").setColorBackground(color(0,200,200));
}
else {
   puerto.stop();
   cp5.getController("CONECTAR").setCaptionLabel("OFF");
   cp5.getController("CONECTAR").setColorBackground(color(0,0,0));   
}
}
