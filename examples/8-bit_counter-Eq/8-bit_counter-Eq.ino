  #include <Timer.h>
Timer t;

int y0;
int y1;
int y2;
int y3;
int y4;
int y5;
int y6;
int y7;

int up = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
upcount();
}

void loop() {
  // put your main code here, to run repeatedly:

if((up==0)&&(digitalRead(2)==HIGH)&&(digitalRead(3)==HIGH)&&(digitalRead(4)==HIGH)&&(digitalRead(5)==HIGH)&&(digitalRead(6)==HIGH)&&(digitalRead(7)==HIGH)&&(digitalRead(8)==HIGH)&&(digitalRead(9)==HIGH))
{
 up = 1;
  Serial.print("Ikkadiki");
t.stop(y0);
t.stop(y1);
t.stop(y2);
t.stop(y3);
t.stop(y4);
t.stop(y5);
t.stop(y6);
t.stop(y7);
delay(1100);
reverse();  
}
if((up==1)&&(digitalRead(2)==HIGH)&&(digitalRead(3)==HIGH)&&(digitalRead(4)==HIGH)&&(digitalRead(5)==HIGH)&&(digitalRead(6)==HIGH)&&(digitalRead(7)==HIGH)&&(digitalRead(8)==HIGH)&&(digitalRead(9)==HIGH))
{
 up = 1;
  Serial.print("Ikkadiki");
t.stop(y0);
t.stop(y1);
t.stop(y2);
t.stop(y3);
t.stop(y4);
t.stop(y5);
t.stop(y6);
t.stop(y7);
delay(1100);
reverse();  
}
t.update();
}

void upcount(){
 up = 0;
y0 = t.oscillate(2,100,LOW);
y1 = t.oscillate(3,200,LOW);
y2 = t.oscillate(4,400,LOW);
y3 = t.oscillate(5,800,LOW);
y4 = t.oscillate(6,1600,LOW);
y5 = t.oscillate(7,3200,LOW);
y6 = t.oscillate(8,6400,LOW);
y7 = t.oscillate(9,12800,LOW);  
}
void reverse()
{
y0 = t.oscillate(2,100,HIGH);
y1 = t.oscillate(3,200,HIGH);
y2 = t.oscillate(4,400,HIGH);
y3 =t.oscillate(5,800,HIGH);
y4= t.oscillate(6,1600,HIGH);
y5 = t.oscillate(7,3200,HIGH);
y6 = t.oscillate(8,6400,HIGH);
y7  =t.oscillate(9,12800,HIGH);  
}
