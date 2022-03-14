int y =130;
int dy=1;
int x =180;
int dx=1;
int a =180;
int da=1;
int b =169;
int db=1;
int d =169;
int dd=1;
int c =210;
int dc=1;
void setup(){  
  size(600,600);

}
void draw() {
background(255,255,255);
// This is the background
fill(181,147,119);
rect(230,y,120,300,300,300,0,0);
//this is the body 
y= y + dy;
     if(y>300) {
       dy = -1;
     }
     if(y < 130){
     dy=1;
     }

fill(0,0,0);
ellipse(270,x,10,30);
ellipse(309,a,10,30);
strokeWeight(0);
//eyes 
x= x + dy;
     if(x>300) {
       dx = -1;
     }
     if(x < 130){
     dx=1;
     }
a= a + dy;
     if(a>300) {
       da = -1;
     }
     if(a < 130){
     da=1;
     }


fill(255,255,255);
ellipse(270,b,8,8);
ellipse(309,d,8,8);
// White part of the eyes 
b= b + dy;
     if(b>300) {
       db = -1;
     }
     if(b < 130){
     dy=1;
     }
d= d + dy;
     if(d>300) {
       dd = -1;
     }
     if(d < 130){
     dy=1;
     }
fill(239,187,210);
ellipse(290,c,50,30);
// The nose
c= c + dy;
     if(c>300) {
       dc = -1;
     }
     if(c < 130){
     dy=1;
     }










fill(205,99,40);
strokeWeight(0);
rect(0,300,600,300);
//This is the ground 

stroke(0,0,0);
fill(81,73,71);
strokeWeight(1);
rect(210,285,20,20,300,300,300,300);
rect(220,285,30,30,300,300,400,300);
rect(245,285,20,20,300,300,300,300);
rect(255,285,30,30,300,300,400,300);
rect(240,270,30,30,300,300,400,300);
rect(280,285,20,30,300,300,400,300);
rect(290,285,30,30,300,300,400,300);
rect(300,290,30,30,300,300,400,300);
rect(310,290,50,30,300,300,400,300);
rect(320,287,30,30,300,300,400,300);
//Darker rocks 

stroke(0,0,0);
fill( 145,142,133);
rect(290,270,20,20,300,300,400,300);
rect(265,270,30,20,300,300,400,300);
rect(255,266,20,30,300,300,400,300);
rect(245,270,20,20,300,300,400,300);
rect(230,270,30,30,300,300,400,300);
rect(210,270,30,30,300,300,400,300);
rect(200,280,30,30,300,300,400,300);
rect(300,270,30,30,300,300,400,300);
rect(320,270,20,20,300,300,400,300);
rect(336,270,20,20,300,300,400,300);
rect(340,280,20,20,300,300,400,300);
rect(350,275,30,30,300,300,400,300);
rect(350,278,30,30,300,300,400,300);
//Lighter rocks 
// Credited from “YouTube.” YouTube, YouTube, 23 Feb. 2014, www.youtube.com/watch?v=8KnV5xk5XaQ. 
}
