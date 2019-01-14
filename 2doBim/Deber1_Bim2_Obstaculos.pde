// beginShape() subrutina para inicio de figura
int i=0;
int x=0;
int y=0;
int ob1=0;//lado1 del obstaculo
int ob2=0;//lado 2 del obstaculo
int ob3=0;//lado 3 del obstaculo
int ob4=0;//lado 4 del obstaculo
//----------------------------------------------------------------------------------------------------------------------------//
void setup(){
size(1200,900);
}
//----------------------------------------------------------------------------------------------------------------------------//
void draw(){
obstaculos();
fill(0);
figura();

}
//----------------------------------------------------------------------------------------------------------------------------//
void figura(){
beginShape();
fill(247,98,67);
vertex(10+x,20+y);
vertex(15+x,20+y);
vertex(15+x,15+y);
vertex(20+x,15+y);
vertex(20+x,10+y);
vertex(45+x,10+y);
vertex(45+x,15+y);
vertex(50+x,15+y);
vertex(50+x,20+y);
vertex(55+x,20+y);
vertex(55+x,30+y);
vertex(45+x,30+y);
vertex(45+x,25+y);
vertex(20+x,25+y);
vertex(20+x,30+y);
vertex(10+x,30+y);
vertex(10+x,20+y);
endShape();
//cara
beginShape();
fill(255,235,205);
vertex(15+x,30+y);
vertex(15+x,40+y);
vertex(20+x,40+y);
vertex(20+x,45+y);
vertex(45+x,45+y);
vertex(45+x,40+y);
vertex(50+x,40+y);
vertex(50+x,30+y);//
vertex(45+x,30+y);
vertex(45+x,25+y);
vertex(20+x,25+y);
vertex(20+x,30+y);
vertex(15+x,30+y);
endShape();
fill(0);
rect(25+x,25+y,5,7.5);
rect(35+x,25+y,5,7.5);
}
//----------------------------------------------------------------------------------------------------------------------------//
void obstaculos(){
fill(255,0,0);
rect(300,50,50,75);
rect(35,500,100,75);
rect(800,700,300,100);
 if(((x>245 && x<340)&&(y>5 && y<120))||((x>-20 && x<125)&&(y>455 && y<570))||((x>745 && x<1090)&&(y>655 && y<795)))
  {
    ob1=1;
  }
  else
  {
    ob1=0;
  }
if(((x>245 && x<340)&&(y>0 && y<75))||((x>-20 && x<125)&&(y>450 && y<525))||((x>745 && x<1090)&&(y>650 && y<750)))
  {
    ob2=1;
  }
  else
  {
    ob2=0;
  }
  if(((x>240 && x<340)&&(y>5 && y<115))||((x>-25 && x<125)&&(y>455 && y<565))||((x>740 && x<1090)&&(y>655 && y<790)))
  {
    ob3=1;
  }
  else
  {
    ob3=0;
  }
  if(((x>245 && x<345)&&(y>5 && y<115))||((x>-20 && x<130)&&(y>455 && y<565))||((x>745 && x<1095)&&(y>655 && y<790)))
  {
    ob4=1;
  }
  else
  {
    ob4=0;
  }
}
//----------------------------------------------------------------------------------------------------------------------------//
void keyPressed(){
background(255);  
switch(keyCode){
   case 38:
  //rect(35,500,100,75);
   if(ob1==1)
  {
  }
  else
  {
  if(y>-5 )
    y=y-5;
  else
  y=900;
  } 
  break;
  case 40:
  if(ob2==1)
  {
  }
  else
  {
  if(y<900)
    y=y+5;
  else
  y=0;
  }
  break;
  case 39:
  if(ob3==1)
  {
  }
  else
  {
  if(x<1170)
  x=x+5;
   else
  x=0;
  }
  break;
  case 37:
  if(ob4==1)
  {
  }
  else
  {
  if(x>-5)
  x=x-5;
  else
  x=1170;
  }
  break;
}

}
