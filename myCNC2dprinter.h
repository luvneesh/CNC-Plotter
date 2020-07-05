#include <Servo.h>    
#include <AccelStepper.h>
#include<MultiStepper.h>
#include<Math.h>
const int b_stepPin = 3; 
const int b_dirPin = 4; 
const int t_stepPin = 5; 
const int t_dirPin = 6; 
Servo pen;
const int servo =9;
pen.attach(servo);
AccelStepper ystepper(1, b_stepPin, b_dirPin);
AccelStepper xstepper(1, t_stepPin, t_dirPin);
Multistepper CNCplotter;

void cncsetup()

{
    pinMode(b_stepPin,OUTPUT); 
    pinMode(b_dirPin,OUTPUT);
    pinMode(t_stepPin,OUTPUT); 
    pinMode(t_dirPin,OUTPUT);
    pinMode(servo,OUTPUT);
    pen.write(0);
    xstepper.setAcceleration(500);
    yStepper.setAcceleration(500);
    yStepper.setMaxSpeed(10000);
    xStepper.setMaxSpeed(10000);
    CNCplotter.addStepper(xstepper);
    CNCplotter.addStepper(ystepper);

}
void linearinterpolation(int x, int y, int feed)

{   
    double target[2]={x*100,y*200};
    int feedy,feedx;
    if(x==0)
    {
        feedy=feed;
        feed x=0;
    }
    else if (y==0)
    {
        feedy=0;
        feedx=feed;

    }
    else 
    {
    int theeta = atan(abs(y)/abs(x));
    feedx  = feed*cos(theeta);
    feedy  = feed* sin(theeta);
    }
    xstepper.setSpeed(feedx*100);
    ystepper.setSpeed(feedy*100);
    CNCplotter.moveTo(target);
    CNCplotter.runSpeedToPosition(); 
}
void letsstart()
{
    penup();
    linearinterpolation(-144,-94,600);
    pendown();
    penup();
    pendown();
    penup();
    
}
void penup()
{
    pen.write(0);

}
void pendown()
{
    pen.write(30);
}
void moveX(int x,int feedx )
{   
    if (x>0){
        digitalWrite(t_dirPin,HIGH);
    }
    if (x<0){
        digitalWrite(t_dirPin,LOW);
        x=x-2*x;
    }
    double gap= (3.0/feedx)*100000;
    double pulses= (x/2.0)*200;
    for(int i = 0; i < pulses; i++)
    {
        digitalWrite(t_stepPin,HIGH); 
        delayMicroseconds(gap); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(gap); 
    }
}

void moveY(int y,int feedy)
{
    double gap= (3.0/feedy)*100000;
    double pulses= (y/2.0)*200;
    for(int i = 0; i < pulses; i++)
    {
        digitalWrite(t_stepPin,HIGH); 
        delayMicroseconds(gap); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(gap); 
    }
}

void circularinterpolation() {
  
}