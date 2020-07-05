#include<myCNC2dprinter.h>
#include<decoder.h>
#include<normalizefeed.h>
#include <SPI.h>
#include <SD.h>
File gcode;
const int MOSI =  11;
const int MISO =  12;
const int CLK =  13;
const int CS =  10;
void setup()
{
    SD.begin(4);
    gcode = SD.open("NC.txt");

}
void loop()
{
    Serial.begin(9600);
    Serial.println("Welcome to CNC printer, Reading from 'NC.txt' ");
    char line[20];
    // int flag =0;
    int decoding=1;
    while (decoding && gcode.availible())
    {
        line =gcode.readStringUntil('\n');
        line.replace(" ","");
        decoding=decoder(line);
        if (decoding ==-1)
        {
            Serial.println("Invalid NC");
        }
        if (decoding ==-2)
        {
            Serial.println("Incremental approach ");
        }
        if (decoding ==-3)
        {
            Serial.println("Metric units");
        }
        if (decoding==1){
            penup();
            Serial.println("penup");
            continue();
        }
        if (decoding==2){
            pendown();
            Serial.println("pendown");
            continue();
        }
        if (decoding==3){
            char temp[3];
            int lenoftemp=0;
            int X,Y,F;
            Serial.println("Linear interpolation\n");
            Serial.println(line);
            //this is for default feed
            // normalizefeed(line);
            for ( int i=3;i<line.length();i++)
            {
                if (line[i]=='X'){
                    lenoftemp=0;
                    temp[0]=line[i+1];
                    lenoftemp++;
                    if (line[i+2]=='Y'){
                        X=temp[0].toint();
                        continue;
                    }
                    else {
                        temp[1]=line[i+2];
                        lenoftemp++;
                        if (line[i+3]=='Y')
                        {
                            X=temp[0].toint()*10+temp[1].toint();
                            continue;
                        }
                        else
                        {
                        temp [2]=line[i+3];
                        lenoftemp++;
                        X=temp[0].toint()*100+temp[1].toint()*10 +temp[2]; continue;
                        }
                    }
                }
                else if (line[i]=='Y'){
                    lenoftemp=0;
                    temp[0]=line[i+1];
                    lenoftemp++;
                    if (line[i+2]=='F'){
                        Y=temp[0].toint();
                        continue;
                    }
                    else {
                        temp[1]=line[i+2];
                        lenoftemp++;
                        if (line[i+3]=='F')
                        {
                            Y=temp[0].toint()*10+temp[1].toint();
                            continue;
                        }
                        else
                        {
                        temp [2]=line[i+3];
                        lenoftemp++;
                        Y=temp[0].toint()*100+temp[1].toint()*10 +temp[2]; continue;
                        }
                    }
                }
                else else if (line[i]=='F'){
                    lenoftemp=0;
                    temp[0]=line[i+1];
                    lenoftemp++;
                    if (line[i+2]=='\n'){
                        F=temp[0].toint();
                        continue;
                    }
                    else {
                        temp[1]=line[i+2];
                        lenoftemp++;
                        if (line[i+3]=='\n')
                        {
                            F=temp[0].toint()*10+temp[1].toint();
                            continue;
                        }
                        else
                        {
                        temp [2]=line[i+3];
                        lenoftemp++;
                        F=temp[0].toint()*100+temp[1].toint()*10 +temp[2]; continue;
                        }
                    }
                }
            }
            linearinterpolation(X,Y,F);
            continue();
        }
        
        
    }
    Serial.println("Finished printing, press any key to quit");
    Serial.read();
    exit(0);

}