

int x;
int y=300;
int i=0;
 int x1=1000;
 int vel;
void setup(){
  size(1500,900);
  background(255);  
}
void draw(){
  fill(0);
 dinosaurio(); 
 
 
  fill(random(100,200),100,0);
ellipse(x1,330,20,20);

vel=int( random(1,7));
  if(x1>0){
    x1=x1-vel;
  }
    else{
    x1=550;
    }

}        
  
  void dinosaurio(){
beginShape();
fill(128,128,128);
vertex(1+x,10+y);
vertex(5+x,10+y);
vertex(5+x,14+y);
vertex(9+x,14+y);
vertex(9+x,18+y);
vertex(14+x,18+y);
vertex(14+x,22+y);
vertex(26+x,22+y);
vertex(42+x,6+y);//
vertex(42+x,-14+y);
vertex(46+x,-14+y);////
vertex(46+x,-18+y);
vertex(70+x,-18+y);
vertex(70+x,-14+y);
vertex(74+x,-14+y);
vertex(74+x,-2+y);
vertex(58+x,-2+y);//
/////
vertex(58+x,2+y);
vertex(70+x,2+y);
vertex(70+x,4+y);
vertex(54+x,4+y);
vertex(54+x,12+y);
vertex(62+x,12+y);
vertex(62+x,20+y);
vertex(58+x,20+y);
vertex(58+x,16+y);
vertex(54+x,16+y);
vertex(42+x,40+y);
vertex(42+x,56+y);
vertex(46+x,56+y);
vertex(46+x,60+y);
vertex(38+x,60+y);
vertex(38+x,48+y);
vertex(34+x,44+y);//
/////
vertex(30+x,44+y);
vertex(22+x,52+y);
vertex(22+x,56+y);
vertex(26+x,56+y);
vertex(26+x,60+y);
vertex(18+x,60+y);//

vertex(18+x,44+y);
vertex(5+x,28+y);
vertex(1+x,28+y);
vertex(1+x,10+y);//
endShape();




fill(255);
rect(50+x,(-10)+y,5,5);

}
void keyPressed(){
background(255);  
if(keyCode ==38){
  
    x=x+30;
  if(y>200)
   y=y-100;
   else{
y=300;
}
   
   
}
if(keyCode==40){

}



}
